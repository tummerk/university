#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename = enable_if_t<
                    is_arithmetic_v<T> && !is_same_v<T, char> && !is_same_v<T, bool>>>
class Matrix{
public:
    Matrix(size_t rows, size_t cols) : m(rows), n(cols), data(rows, vector<T>(cols)) {}

    Matrix(const Matrix& other) {
        data = other.data;
        m = other.m;
        n = other.n;
    }
    

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        data = other.data;
        m = other.m;
        n = other.n;

        return *this;
    }
    friend ostream& operator<<(ostream& out, const Matrix<T>& matr) {
        for (size_t i = 0; i < matr.m; i++) {
            for (size_t j = 0; j < matr.n; j++) {
                out << matr.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Matrix& matr) {
        for (int i = 0; i < matr.m; i++) {
            for (int j = 0; j < matr.n; j++) {
                in >> matr.matrix[i][j];
            }
        }
        return in;
    }

    Matrix operator+(const Matrix& other){
        if (n != other.n || m != other.m)
            return *this;
        Matrix<T> res(m, n);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                res.data[i][j]=data[i][j] + other.data[i][j];
            }
        }
        return res;
    }
    Matrix& operator+=(const Matrix& other){
        *this = *this + other;
        return *this;
    }

    Matrix operator*(const Matrix& other) {
        if (n != other.m)
            return *this;
        Matrix<T> res(m, other.n);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < other.n; j++) {
                for (size_t k = 0; k < n; k++) {
                    res.data[i][j] += (data[i][k] * other.data[k][j]);
               }
            }
        }
        return res;
    }

    Matrix& operator*=(const Matrix& other) {
        *this = *this * other;
        return *this;
    }

    Matrix& operator++() {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                data[i][j]++;
            }
        }
        return *this;
    }

    T det() {
        if ((m != n) || (m == 0 && n == 0))
            return 0;
        if (m == 1) {
            return data[0][0];
        }
        if (m == 2) {
            return data[0][0] * data[1][1] - data[1][0] * data[0][1];
        }
        T res = 0;
        for (size_t i = 0; i < m; i++) {
            res += ((i % 2 == 0) ? 1 : -1) * data[0][i] * this->minor(0, i).det();
        }
        return res;
    }

    T& operator()(size_t row, size_t col) {
        return data[row][col];
    }

    
private:
    vector<vector<T>> data;
    size_t m;
    size_t n;

    Matrix<T> minor(int row, int col) {
        Matrix<T> res(m - 1, n - 1);
        size_t resRow = 0;
        for (size_t i = 0; i < m; ++i) {
            if (i == row) continue;
            size_t resCol = 0;
            for (size_t j = 0; j < n; ++j) {
                if (j == col) continue;
                res(resRow, resCol) = data[i][j];
                ++resCol;
            }
            ++resRow;
        }
        return res;
    }
};


int main() {
    Matrix<int> A(3, 3);
    Matrix<int> B(3, 1);
    cout<<++A;
    A(1, 1) = 5;
    cout << A;
    return 0;
}