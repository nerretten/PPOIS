#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Set{
private:
    vector <string> items;
    vector <Set> subsets;

public:
    Set(){

    }
    Set(const string& s){
        if(s.empty() || s[0] != '{' || s[s.size()-1] != '}')
            throw invalid_argument("The format of string is incorrect\n");
        int lst = 0, cnt_open = 0, cnt_close = 0, pos_open = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{')
                cnt_open++;
            if(s[i] == '}')
                cnt_close++;
            if(cnt_close > cnt_open){
                throw invalid_argument("The format of string is incorrect\n");
            }
        }
        if(cnt_open != cnt_close){
            throw invalid_argument("The format of string is incorrect\n");
        }
        cnt_open = 0;
        cnt_close = 0;
        string new_s = s;
        auto bgn = remove(new_s.begin(), new_s.end(), ' ');
        new_s.erase(bgn, new_s.end());
        if(new_s.size() == 2){
            return;
        }
        new_s[new_s.size()-1] =',';
        for(int i = 1; i < new_s.size(); i++){
            if(new_s[i] == ',' && cnt_open == 0){
                if(i == lst+1){
                    throw invalid_argument("The format of string is incorrect\n");
                }
                string temp_str = new_s.substr(lst+1, i-lst-1);
                this->add_element(temp_str);
                lst=i;
            }
            if(new_s[i] == '{'){
                cnt_open++;
                if(pos_open == -1)
                    pos_open = i;
            }
            if(new_s[i] == '}'){
                cnt_close++;
                if(cnt_open == cnt_close){
                    if(i == cnt_open+1){
                        this->add_element(Set());
                    }
                    else{
                        string temp_str = new_s.substr(pos_open+1, i-pos_open-1);
                        this->add_element(Set("{"+temp_str+"}"));
                    }
                    pos_open = -1;
                    cnt_open = cnt_close = 0;
                    lst = i+1;
                    i++;
                }
            }
        }
    }
    Set(const char* str) : Set(string(str)){}
    bool is_empty() const{
        return items.empty() && subsets.empty();
    }
    bool operator[](const string& s) const{
        bool flag = false;
        for(string x: items){
            if(x == s){
                flag = true;
                break;
            }
        }
        return flag;
    }

    bool operator[](const Set& s) const{
        bool flag = false;
        for(Set x: subsets){
            if(x == s){
                flag = true;
                break;
            }
        }
        return flag;
    }
    void add_element(const string &s){
         if(!(*this)[s])
             items.push_back(s);
    }
    void add_element(const Set& s){
        if(!(*this)[s])
            subsets.push_back(s);
    }
    void delete_element(const string& s){
        for(int i = 0; i < items.size(); i++){
            if(items[i] == s){
                items.erase(items.begin() + i);
                break;
            }
        }
    }
    void delete_element(const Set& set){
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i] == set){
                subsets.erase(subsets.begin()+i);
            }
        }
    }
    int power(){
        return items.size()+subsets.size();
    }

    bool operator ==(const Set& set) const{
        int cnt = 0;
        for(string s1: items){
            for(string s2: set.items){
                if(s1 == s2){
                    cnt++;
                    break;
                }
            }
        }
        for(Set s1: subsets){
            for(Set s2: set.subsets){
                if(s1 == s2){
                    cnt++;
                    break;
                }
            }
        }
        return ((items.size()+subsets.size()) == cnt && items.size()==set.items.size() &&
                subsets.size() == set.subsets.size());
    }

    bool operator !=(const Set& set) const{
        return !(set==(*this));
    }


    Set operator +(const Set& set) const{
        Set result;
        for(string s: items){
            result.add_element(s);
        }
        for(string s: set.items){
            result.add_element(s);
        }
        for(Set s: subsets){
            result.subsets.push_back(s);
        }
        for(Set s1: set.subsets){
            result.add_element(s1);
        }
        return result;
    }

    Set& operator +=(const Set& set){
        for(string s: set.items){
            this->add_element(s);
        }
        for(Set s: set.subsets){
            this->add_element(s);
        }
        return *this;
    }

    Set operator -(const Set& set){
        Set result;
        for(string s: items){
            if(!set[s])
                result.items.push_back(s);
        }
        for(Set s: subsets){
            if(!set[s]){
                result.subsets.push_back(s);
            }
        }

        return result;
    }

    Set& operator -=(const Set& set){
        for(string s: items){
            if(set[s]){
                this->delete_element(s);
            }
        }
        for(Set s: subsets){
            if(set[s]){
                this->delete_element(s);
            }
        }

        return *this;
    }

    Set operator *(const Set& set) const{
        Set result;
        for(string s: items){
            if(set[s])
                result.items.push_back(s);
        }
        for(Set s: subsets){
            if(set[s]){
                result.subsets.push_back(s);
            }
        }

        return result;
    }

    Set& operator *=(const Set& set){
        for(string s: items){
            if(!set[s]){
                this->delete_element(s);
            }
        }
        for(Set s: subsets){
            if(!set[s]){
                this->delete_element(s);
            }
        }

        return *this;
    }

    friend ostream& operator<<(ostream& os, const Set& s);
    friend istream& operator>>(istream& os, Set& s);

    Set boolean() const{
        Set result;
        result.subsets.push_back(Set());
        for(string s: items){
            int sz = result.subsets.size();
            Set temp_set;
            temp_set.add_element(s);
            for(int i = 0; i < sz; i++){
                result.add_element(temp_set+result.subsets[i]);
            }
        }
        for(Set s: subsets){
            int sz = result.subsets.size();
            for(int i = 0; i < sz; i++){
                result.add_element(s+result.subsets[i]);
            }
        }

        return result;
    }

};

ostream& operator<<(ostream& os, const Set& s){
    cout << "{";
    for(int i = 0; i < s.items.size(); i++){
        cout << s.items[i];
        if(i != s.items.size()-1 || !s.subsets.empty())
            cout << ", ";
    }
    for(Set x: s.subsets){
        cout << x;
    }
    cout << "}";
    return os;
}

istream& operator>>(istream& is, Set& s){
    string str;
    getline(is, str);
    try {
        s = Set(str);
    }catch (const invalid_argument& e){
        is.setstate(ios::failbit);
    }
    return is;
}

