#include <iostream>
#include "set.h"

using namespace std;

int main(){
    int x;
    while(true){
        cout << "Выберите операцию: \n1.Объединение множеств \n2.Пересечение \n3.Разность"
                "\n4.Найти мощность множества \n5.Найти булеан множества \n6.Завершить программу\n";
        cin >> x;
        cin.ignore();
        switch (x) {
            case 1:
            {
                cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                string s;
                getline(cin, s);
                Set set1(s);
                cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                getline(cin, s);
                Set set2(s);
                cout << "Пересечение множеств: " << set1 + set2 << '\n';
                break;
            }
            case 2:
            {
                cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                string s;
                getline(cin, s);
                Set set1(s);
                cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                getline(cin, s);
                Set set2(s);
                cout << "Пересечение множеств: " << set1 * set2 << '\n';
                break;
            }
            case 3:
            {
                cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                string s;
                getline(cin, s);
                Set set1(s);
                cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                getline(cin, s);
                Set set2(s);
                cout << "Пересечение множеств: " << set1 - set2 << '\n';
                break;
            }
            case 4:
            {
                cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                string s;
                getline(cin, s);
                Set set1(s);
                cout << "Мощность множества: " << set1.power() << '\n';
                break;
            }
            case 5:
            {
                cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                string s;
                getline(cin, s);
                Set set1(s);
                cout << "Булеан множества: " << set1.boolean() << '\n';
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                cout << "Такой операции нет\n";
            }
        }
    }
}

