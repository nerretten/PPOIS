#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

#include <stdexcept>
#include <string>

class Matrix {
private:
    int n_col, n_row;
    double **data;
    void clear_memory();
    void allocate_memory();
public:
    Matrix();
    Matrix(int n, int m);
    ~Matrix();
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
    Matrix sub_matrix(int n, int m);
    Matrix& reshape(int n, int m);
    Matrix& transpose();
    static Matrix load_from_file(const std::string& filename);
    bool is_square() const;
    bool is_diagonal() const;
    bool is_zero() const;
    bool is_eye() const;
    bool is_symmetric() const;
    bool is_upper_triangle() const;
    bool is_down_triangle() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& s);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    int get_row();
    int get_col();
    void set_data(int i, int j, double val);
};
#endif
