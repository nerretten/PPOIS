#include <iostream>
#include <string>
#include "src/set.h"

using namespace std;

int main() {
    int x;
    while (true) {
        cout << "Выберите операцию: \n"
             << "1. Объединение множеств \n"
             << "2. Пересечение \n"
             << "3. Разность \n"
             << "4. Найти мощность множества \n"
             << "5. Найти булеан множества \n"
             << "6. Завершить программу\n";
        cin >> x;
        cin.ignore();

        switch (x) {
            case 1: {
                try {
                    cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                    string s;
                    getline(cin, s);
                    Set set1(s);

                    cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                    getline(cin, s);
                    Set set2(s);

                    cout << "Объединение множеств: " << set1 + set2 << '\n';
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what();
                }
                break;
            }
            case 2: {
                try {
                    cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                    string s;
                    getline(cin, s);
                    Set set1(s);

                    cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                    getline(cin, s);
                    Set set2(s);

                    cout << "Пересечение множеств: " << set1 * set2 << '\n';
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what();
                }
                break;
            }
            case 3: {
                try {
                    cout << "Введите первое множество. Пример формата {a, {b,c}}\n";
                    string s;
                    getline(cin, s);
                    Set set1(s);

                    cout << "Введите второе множество. Пример формата {a, {b,c}}\n";
                    getline(cin, s);
                    Set set2(s);

                    cout << "Разность множеств: " << set1 - set2 << '\n';
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what();
                }
                break;
            }
            case 4: {
                try {
                    cout << "Введите множество. Пример формата {a, {b,c}}\n";
                    string s;
                    getline(cin, s);
                    Set set1(s);

                    cout << "Мощность множества: " << set1.power() << '\n';
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what();
                }
                break;
            }
            case 5: {
                try {
                    cout << "Введите множество. Пример формата {a, {b,c}}\n";
                    string s;
                    getline(cin, s);
                    Set set1(s);

                    cout << "Булеан множества: " << set1.boolean() << '\n';
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what();
                }
                break;
            }
            case 6: {
                cout << "Выход из программы.\n";
                return 0;
            }
            default: {
                cout << "Такой операции нет\n";
            }
        }
    }
}