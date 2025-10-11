#include "set.h"
#include <stdexcept>

bool is_balanced_braces(const std::string&s) {
    int cnt_open = 0, cnt_close=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '{')
            cnt_open++;
        if(s[i] == '}')
            cnt_close++;
        if(cnt_close > cnt_open){
            return false;
        }
    }
    if(cnt_open != cnt_close){
        return false;
    }
    return true;
}
void check_comma(int& lst, Set &s, const std::string& new_s, int i, int cnt_open){
    if(new_s[i] == ',' && cnt_open == 0){
        if(i == lst+1){
            throw std::invalid_argument("Неверный формат строки\n");
        }
        std::string temp_str = new_s.substr(lst+1, i-lst-1);
        s.add_element(temp_str);
        lst=i;
    }
}
void check_open_brace(const std::string& new_s, int i, int& cnt_open, int &pos_open){
    if(new_s[i] == '{'){
        cnt_open++;
        if(pos_open == -1)
            pos_open = i;
    }
}
void check_close_brace(const std::string &new_s, int &cnt_close, int &cnt_open, int &i, Set& s, int&pos_open, int& lst){
    if(new_s[i] == '}'){
        cnt_close++;
        if(cnt_open == cnt_close){
            if(i == cnt_open+1){
                s.add_element(Set());
            }
            else{
                std::string temp_str = new_s.substr(pos_open+1, i-pos_open-1);
                s.add_element(Set("{"+temp_str+"}"));
            }
            pos_open = -1;
            cnt_open = cnt_close = 0;
            lst = i+1;
            i++;
        }
    }
}
Set::Set() = default;
Set::Set(const std::string& s){
        if(s.empty() || s[0] != '{' || s[s.size()-1] != '}' || !is_balanced_braces(s))
            throw std::invalid_argument("Неверный формат строки\n");
        std::string new_s = s;
        auto bgn = remove(new_s.begin(), new_s.end(), ' ');
        new_s.erase(bgn, new_s.end());
        if(new_s.size() == 2){
            return;
        }
        int lst = 0, cnt_open = 0, cnt_close = 0, pos_open = -1;
        new_s[new_s.size()-1] =',';
        for(int i = 1; i < new_s.size(); i++){
            try{
                check_comma(lst, *this, new_s, i, cnt_open);
            }
            catch (const std::exception& e){
                throw e;
            }
            check_open_brace(new_s, i, cnt_open, pos_open);
            check_close_brace(new_s, cnt_close, cnt_open, i, *this, pos_open, lst);
        }
}

Set::Set(const char* str) : Set(std::string(str)){}

bool Set::is_empty() const{
        return items.empty() && subsets.empty();
    }
bool Set::operator[](const std::string& s) const{
        bool flag = false;
        for(std::string x: items){
            if(x == s){
                flag = true;
                break;
            }
        }
        return flag;
    }
bool Set::operator[](const Set& s) const{
        bool flag = false;
        for(Set x: subsets){
            if(x == s){
                flag = true;
                break;
            }
        }
        return flag;
    }
void Set::add_element(const std::string &s){
         if(!(*this)[s])
             items.push_back(s);
    }
void Set::add_element(const Set& s){
        if(!(*this)[s])
            subsets.push_back(s);
    }
void Set::delete_element(const std::string& s){
        for(int i = 0; i < items.size(); i++){
            if(items[i] == s){
                items.erase(items.begin() + i);
                break;
            }
        }
    }
void Set::delete_element(const Set& set){
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i] == set){
                subsets.erase(subsets.begin()+i);
            }
        }
    }
int Set::power() const{
        return items.size()+subsets.size();
    }

bool Set::operator ==(const Set& set) const{
        int cnt = 0;
        for(std::string s1: items){
            for(std::string s2: set.items){
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
bool Set::operator !=(const Set& set) const{
        return !(set==(*this));
    }


Set Set::operator +(const Set& set) const{
        Set result;
        for(std::string s: items){
            result.add_element(s);
        }
        for(std::string s: set.items){
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
Set& Set::operator +=(const Set& set){
        for(std::string s: set.items){
            this->add_element(s);
        }
        for(Set s: set.subsets){
            this->add_element(s);
        }
        return *this;
    }

Set Set::operator -(const Set& set){
        Set result;
        for(std::string s: items){
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
Set& Set::operator -=(const Set& set){
        for(std::string s: items){
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

Set Set::operator *(const Set& set) const{
        Set result;
        for(std::string s: items){
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
Set& Set::operator *=(const Set& set){
    *this = *this * set;
    return *this;
    }

Set Set::boolean() const{
        Set result;
        result.subsets.push_back(Set());

        for(std::string s: items){
            int sz = result.subsets.size();
            Set temp_set;
            temp_set.add_element(s);
            for(int i = 0; i < sz; i++){
                result.add_element(temp_set+result.subsets[i]);
            }
        }
        for(Set s: subsets){
            int sz = result.subsets.size();
            Set temp_set;
            temp_set.add_element(s);
            for(int i = 0; i < sz; i++){
                result.add_element(temp_set+result.subsets[i]);
            }
        }

        return result;
    }


std::ostream& operator<<(std::ostream& os, const Set& s){
    os << "{";
    for(int i = 0; i < s.items.size(); i++){
        os << s.items[i];
        if(i != s.items.size()-1 || !s.subsets.empty())
            os << ", ";
    }
    for(int i = 0; i < s.subsets.size(); i++){
        os << s.subsets[i];
        if(i != s.subsets.size()-1)
            os<< ", ";
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Set& s){
    std::string str;
    getline(is, str);
    try {
        s = Set(str);
    }catch (const std::invalid_argument& e){
        is.setstate(std::ios::failbit);
    }
    return is;
}

