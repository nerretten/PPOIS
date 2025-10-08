#include <UnitTest++.h>
#include "../src/matrix.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>

Matrix make_matrix(int rows, int cols, const std::vector<double>& values) {
    Matrix m(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            m.set_data(i, j, values[i * cols + j]);
    return m;
}

TEST(Constructor_ValidSizes) {
        Matrix m(2, 3);
        CHECK_EQUAL(2, m.get_row());
        CHECK_EQUAL(3, m.get_col());
}

TEST(Constructor_InvalidSizes_Throws) {
        CHECK_THROW(Matrix(-1, 2), std::invalid_argument);
        CHECK_THROW(Matrix(0, 5), std::invalid_argument);
        CHECK_THROW(Matrix(3, -2), std::invalid_argument);
}

TEST(CopyConstructor) {
        Matrix m1 = make_matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = m1;
        CHECK(m1 == m2);
}

TEST(AssignmentOperator) {
        Matrix m1 = make_matrix(2, 2, {5, 6, 7, 8});
        Matrix m2(1, 1);
        m2 = m1;
        CHECK(m1 == m2);
}

TEST(SelfAssignment) {
        Matrix m1 = make_matrix(2, 2, {1, 0, 0, 1});
        m1 = m1;
        CHECK(m1.is_eye());
}

TEST(PreIncrement) {
        Matrix m = make_matrix(2, 2, {1, 2, 3, 4});
        ++m;
        Matrix expected = make_matrix(2, 2, {2, 3, 4, 5});
        CHECK(m == expected);
}

TEST(PostIncrement) {
        Matrix m = make_matrix(1, 2, {10, 20});
        Matrix old = m++;
        Matrix expected_old = make_matrix(1, 2, {10, 20});
        Matrix expected_new = make_matrix(1, 2, {11, 21});
        CHECK(old == expected_old);
        CHECK(m == expected_new);
}

TEST(PreDecrement) {
        Matrix m = make_matrix(2, 1, {5, 10});
        --m;
        Matrix expected = make_matrix(2, 1, {4, 9});
        CHECK(m == expected);
}

TEST(PostDecrement) {
        Matrix m = make_matrix(1, 3, {3, 2, 1});
        Matrix old = m--;
        CHECK(old == make_matrix(1, 3, {3, 2, 1}));
        CHECK(m == make_matrix(1, 3, {2, 1, 0}));
}

TEST(EqualityOperator_Same) {
        Matrix m1 = make_matrix(2, 2, {1, 2, 3, 4});
        Matrix m2 = make_matrix(2, 2, {1, 2, 3, 4});
        CHECK(m1 == m2);
}

TEST(EqualityOperator_DifferentSizes) {
        Matrix m1(2, 2);
        Matrix m2(2, 3);
        CHECK(!(m1 == m2));
}

TEST(EqualityOperator_DifferentValues) {
        Matrix m1 = make_matrix(1, 2, {1, 2});
        Matrix m2 = make_matrix(1, 2, {1, 3});
        CHECK(!(m1 == m2));
}

TEST(InequalityOperator) {
        Matrix m1(1, 1);
        Matrix m2(2, 2);
        CHECK(m1 != m2);
}

TEST(SubMatrix_Valid) {
        Matrix m = make_matrix(3, 3, {1,2,3,4,5,6,7,8,9});
        Matrix sub = m.sub_matrix(2, 2);
        Matrix expected = make_matrix(2, 2, {1,2,4,5});
        CHECK(sub == expected);
}

TEST(SubMatrix_TooBig_Throws) {
        Matrix m(2, 2);
        CHECK_THROW(m.sub_matrix(3, 2), std::invalid_argument);
        CHECK_THROW(m.sub_matrix(2, 5), std::invalid_argument);
}

TEST(Reshape_Valid) {
        Matrix m = make_matrix(2, 3, {1,2,3,4,5,6});
        m.reshape(3, 2);
        Matrix expected = make_matrix(3, 2, {1,2,3,4,5,6});
        CHECK(m == expected);
}

TEST(Reshape_InvalidSize_Throws) {
        Matrix m(2, 2);
        CHECK_THROW(m.reshape(1, 5), std::invalid_argument);
}

TEST(Transpose) {
        Matrix m = make_matrix(2, 3, {1,2,3,4,5,6});
        m.transpose();
        Matrix expected = make_matrix(3, 2, {1,4,2,5,3,6});
        CHECK(m == expected);
}

TEST(IsSquare) {
        CHECK(Matrix(3,3).is_square());
        CHECK(!Matrix(2,3).is_square());
}

TEST(IsDiagonal) {
        Matrix m = make_matrix(3,3, {2,0,0,0,3,0,0,0,4});
        CHECK(m.is_diagonal());
        Matrix not_diag = make_matrix(2,2, {1,1,0,1});
        CHECK(!not_diag.is_diagonal());
}

TEST(IsZero) {
        Matrix m(2, 3);
        CHECK(m.is_zero());
        m.set_data(0, 0, 1);
        CHECK(!m.is_zero());
}

TEST(IsEye) {
        Matrix eye(3,3);
        eye.set_data(0, 0, 1);
        eye.set_data(1,1,1);
        eye.set_data(2, 2, 1);
        CHECK(eye.is_eye());
        eye.set_data(0, 1, 1);
        CHECK(!eye.is_eye());
}

TEST(IsSymmetric) {
        Matrix sym = make_matrix(2,2, {1,2,2,3});
        CHECK(sym.is_symmetric());
        Matrix asym = make_matrix(2,2, {1,2,3,4});
        CHECK(!asym.is_symmetric());
}

TEST(IsUpperTriangle) {
        Matrix up = make_matrix(3,3, {1,2,3,0,4,5,0,0,6});
        CHECK(up.is_upper_triangle());
        up.set_data(2, 0, 1);
        CHECK(!up.is_upper_triangle());
}

TEST(IsDownTriangle) {
        Matrix down = make_matrix(3,3, {1,0,0,2,3,0,4,5,6});
        CHECK(down.is_down_triangle());
        down.set_data(0, 2, 1);
        CHECK(!down.is_down_triangle());
}

TEST(StreamOutput) {
        Matrix m = make_matrix(2, 2, {1.5, 2.5, 3.5, 4.5});
        std::ostringstream oss;
        oss << m;
        std::string expected = "1.5 2.5 \n3.5 4.5 \n";
        CHECK_EQUAL(expected, oss.str());
}

TEST(StreamInput_Valid) {
        std::istringstream iss("2 3\n1 2 3\n4 5 6");
        Matrix m;
        iss >> m;
        Matrix expected = make_matrix(2, 3, {1,2,3,4,5,6});
        CHECK(m == expected);
}

TEST(StreamInput_InvalidSizes_Throws) {
        std::istringstream iss("-1 2");
        Matrix m;
        CHECK_THROW(iss >> m, std::invalid_argument);
}

TEST(LoadFromFile_Valid) {
        std::ofstream tmp("/Users/nerretten/bsuir/2 курс/ППОИС/lab1/matrix/src/test_matrix.txt");
        tmp << "2 2\n1 2\n3 4";
        tmp.close();

        Matrix m = Matrix::load_from_file("test_matrix.txt");
        Matrix expected = make_matrix(2, 2, {1,2,3,4});
        CHECK(m == expected);

        std::remove("/Users/nerretten/bsuir/2 курс/ППОИС/lab1/matrix/src/test_matrix.txt");
}

TEST(LoadFromFile_FileNotFound_Throws) {
        CHECK_THROW(Matrix::load_from_file("nonexistent.txt"), std::runtime_error);
}

int main() {
    return UnitTest::RunAllTests();
}