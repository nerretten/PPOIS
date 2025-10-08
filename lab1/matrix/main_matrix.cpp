#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

int main() {
    int x;
    while (true) {
        cout << "\nВыберите операцию:\n"
             << "1. Создать матрицу вручную\n"
             << "2. Загрузить матрицу из файла\n"
             << "3. Вывести матрицу\n"
             << "4. Проверить свойства матрицы (квадратная, диагональная и т.д.)\n"
             << "5. Транспонировать матрицу\n"
             << "6. Изменить размер матрицы (reshape)\n"
             << "7. Получить подматрицу\n"
             << "8. Инкремент/декремент матрицы\n"
             << "9. Сравнить две матрицы\n"
             << "10. Завершить программу\n";
        cin >> x;
        cin.ignore();

        static Matrix current_matrix;

        switch (x) {
            case 1: {
                try {
                    current_matrix = Matrix();
                    cout << "Введите размеры матрицы, а затем ее элементы\n";
                    cin >> current_matrix;
                    cout << "Матрица успешно создана.\n";
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
                break;
            }
            case 2: {
                string filename;
                cout << "Введите имя файла: ";
                getline(cin, filename);
                try {
                    current_matrix = Matrix::load_from_file(filename);
                    cout << "Матрица успешно загружена из файла.\n";
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
                break;
            }
            case 3: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                } else {
                    cout << "Текущая матрица:\n" << current_matrix;
                }
                break;
            }
            case 4: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                    break;
                }
                cout << "Свойства матрицы:\n";
                cout << "- Квадратная: " << (current_matrix.is_square() ? "Да" : "Нет") << '\n';
                cout << "- Диагональная: " << (current_matrix.is_diagonal() ? "Да" : "Нет") << '\n';
                cout << "- Единичная: " << (current_matrix.is_eye() ? "Да" : "Нет") << '\n';
                cout << "- Нулевая: " << (current_matrix.is_zero() ? "Да" : "Нет") << '\n';
                cout << "- Симметричная: " << (current_matrix.is_symmetric() ? "Да" : "Нет") << '\n';
                cout << "- Верхнетреугольная: " << (current_matrix.is_upper_triangle() ? "Да" : "Нет") << '\n';
                cout << "- Нижнетреугольная: " << (current_matrix.is_down_triangle() ? "Да" : "Нет") << '\n';
                break;
            }
            case 5: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                } else {
                    current_matrix.transpose();
                    cout << "Матрица транспонирована.\n";
                }
                break;
            }
            case 6: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                    break;
                }
                int new_rows, new_cols;
                cout << "Введите новые размеры (строки столбцы): ";
                cin >> new_rows >> new_cols;
                try {
                    current_matrix.reshape(new_rows, new_cols);
                    cout << "Размер матрицы изменён.\n";
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
                break;
            }
            case 7: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                    break;
                }
                int sub_rows, sub_cols;
                cout << "Введите размеры подматрицы (строки столбцы): ";
                cin >> sub_rows >> sub_cols;
                try {
                    Matrix sub = current_matrix.sub_matrix(sub_rows, sub_cols);
                    cout << "Подматрица:\n" << sub;
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
                break;
            }
            case 8: {
                if (current_matrix.get_row() == 0) {
                    cout << "Матрица ещё не создана.\n";
                    break;
                }
                int op;
                cout << "Выберите операцию:\n1. Инкремент (++mat)\n2. Декремент (--mat)\n";
                cin >> op;
                if (op == 1) {
                    ++current_matrix;
                    cout << "Матрица инкрементирована.\n";
                } else if (op == 2) {
                    --current_matrix;
                    cout << "Матрица декрементирована.\n";
                } else {
                    cout << "Неверный выбор.\n";
                }
                break;
            }
            case 9: {
                Matrix other;
                int rows, cols;
                cout << "Введите размеры второй матрицы: ";
                cin >> rows >> cols;
                try {
                    other = Matrix(rows, cols);
                    cout << "Введите элементы второй матрицы:\n";
                    cin >> other;
                    if (current_matrix == other) {
                        cout << "Матрицы равны.\n";
                    } else {
                        cout << "Матрицы не равны.\n";
                    }
                } catch (const exception& e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
                break;
            }
            case 10: {
                cout << "Выход из программы.\n";
                return 0;
            }
            default: {
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }
}