#include "matrix.h"
#include <sstream>
#include <fstream>
#include <iostream>

void Matrix::clear_memory() {
    if (data) {
        for (int i = 0; i < n_row; i++) {
            delete [] data[i];
        }
        delete [] data;
        data = nullptr;
    }
}

void Matrix::allocate_memory(){
    data = new double*[n_row];
    for(int i = 0; i < n_row; i++){
        data[i] = new double[n_col];
    }
}
Matrix::Matrix() : n_row(0), n_col(0), data(nullptr) {}
Matrix::Matrix(int n, int m){
    if(n <= 0 || m <= 0)
        throw std::invalid_argument("Размеры матрицы должны быть положительными\n");
    n_row = n, n_col = m;
    allocate_memory();
}

Matrix::~Matrix(){
    for(int i = 0; i < n_row; i++){
        delete [] data[i];
    }
    delete [] data;
}

Matrix::Matrix(const Matrix& m){
    n_col = m.n_col, n_row = m.n_row;
    allocate_memory();
    for(int i =0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            data[i][j] = m.data[i][j];
        }
    }
}

int Matrix::get_row(){
    return n_row;
}

int Matrix::get_col(){
    return n_col;
}

void Matrix::set_data(int i, int j, double val){
    if(i >= n_row || j >= n_col)
        throw std::invalid_argument("Некорректный индекс\n");
    data[i][j] = val;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        clear_memory();
        n_row = m.n_row;
        n_col = m.n_col;
        allocate_memory();
        for(int i = 0; i < n_row; i++) {
            for(int j = 0; j < n_col; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator++(){
    for(int i = 0; i < this->n_row; i++){
        for(int j = 0; j < this->n_col; j++){
            ++data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator++(int){
    Matrix temp = (*this);
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--(){
    for(int i = 0; i < this->n_row; i++){
        for(int j = 0; j < this->n_col; j++){
            --data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator--(int){
    Matrix temp = (*this);
    --(*this);
    return temp;
}

bool Matrix::operator==(const Matrix& m) const{
    if(m.n_row != n_row || m.n_col != n_col)
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(data[i][j] != m.data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const{
    return !(m==*this);
}

Matrix Matrix::sub_matrix(int n, int m){
    if(n > n_row || m > n_col){
        throw std::invalid_argument("Длина строк и столбоцов должна быть не больше текущих размеров матрицыn\n");
    }
    Matrix new_matrix = Matrix(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            new_matrix.data[i][j] = data[i][j];
        }
    }
    return new_matrix;
}

Matrix& Matrix::reshape(int n, int m){
    if(n*m != n_col*n_row){
        throw std::invalid_argument("Количество элементов в матрице должно остаться прежним\n");
    }
    Matrix temp_matrix = Matrix(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int pos = i*m+j;
            temp_matrix.data[i][j] = data[pos/n_col][pos%n_col];
        }
    }
    *this = temp_matrix;
    return *this;
}

Matrix& Matrix::transpose(){
    Matrix temp_matrix = Matrix(n_col, n_row);
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            temp_matrix.data[j][i] = data[i][j];
        }
    }
    *this = temp_matrix;
    return *this;
}

Matrix Matrix::load_from_file(const std::string& filename) {
    std::ifstream file("/Users/nerretten/bsuir/2 курс/ППОИС/lab1/matrix/src/"+filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл\n");
    }
    std::string line;
    int rows = 0, cols = 0;
    if (!std::getline(file, line)) {
        throw std::runtime_error("Файл пуст или не может быть прочитан\n");
    }
    std::istringstream size_stream(line);
    if (!(size_stream >> rows >> cols)) {
        throw std::runtime_error("Неверный формат первой строки. Ожидается: строки столбцы\n");
    }
    if (rows <= 0 || cols <= 0) {
        throw std::runtime_error("Размеры матрицы должны быть положительными\n");
    }
    Matrix result(rows, cols);
    int current_row = 0;
    while (std::getline(file, line) && current_row < rows) {
        if (line.empty()) continue;
        std::istringstream data_stream(line);
        double value;
        int current_col = 0;
        while (data_stream >> value && current_col < cols) {
            result.data[current_row][current_col] = value;
            current_col++;
        }
        if (current_col != cols) {
            throw std::runtime_error("Недостаточно данных в строке\n");
        }
        current_row++;
    }
    if (current_row != rows) {
        throw std::runtime_error("Недостаточно строк в файле\n");
    }
    file.close();
    return result;
}

bool Matrix::is_square() const{
    return n_row == n_col;
}

bool Matrix::is_diagonal() const{
    if(!this->is_square())
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(i != j && data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::is_zero() const{
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::is_eye() const{
    if(!this->is_diagonal())
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(i == j && data[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool Matrix::is_symmetric() const{
    if(!this->is_square())
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(data[i][j] != data[j][i])
                return false;
        }
    }
    return true;
}

bool Matrix::is_upper_triangle() const{
    if(!this->is_square())
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(i > j && data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::is_down_triangle() const{
    if(!this->is_square())
        return false;
    for(int i = 0; i < n_row; i++){
        for(int j =0; j < n_col; j++){
            if(i < j && data[i][j])
                return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& s){
    for(int i = 0; i < s.n_row; i++){
        for(int j = 0; j < s.n_col; j++){
            os << s.data[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int rows, cols;
    if (!(is >> rows >> cols)) {
        throw std::runtime_error("Ошибка чтения размеров матрицы\n");
    }
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Размеры матрицы должны быть положительными\n");
    }
    matrix.clear_memory();
    matrix.n_row = rows;
    matrix.n_col = cols;
    matrix.allocate_memory();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(is >> matrix.data[i][j])) {
                throw std::runtime_error("Ошибка чтения элемента матрицы\n");
            }
        }
    }
    return is;
}