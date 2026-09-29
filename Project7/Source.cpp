#include <iostream>
#include <vector>
using namespace std;
class Point {
public:
    int x;
    int y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other) const
    {
        return Point(x - other.x, y - other.y);
    }
    Point operator*(const Point& other) const
    {
        return Point(x * other.x, y * other.y);
    }
    Point operator/(const Point& other) const
    {
        return Point(other.x != 0 ? x / other.x : 0, other.y != 0 ? y / other.y : 0);
    }

    bool operator<(const Point& other) const
    {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }
    bool operator>(const Point& other) const
    {
        return (x * x + y * y) > (other.x * other.x + other.y * other.y);
    }
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& pt) {
        os << "(" << pt.x << ", " << pt.y << ")";
        return os;
    }
};
template <class T>
class matrix
{
    int** p;
    int row, col;
public:
    matrix() : p(nullptr) row(0), col(0) {}
    matrix(int r, int c)
    {
        p = new T * [s];
        for (int i = 0; i < s; i++)
        {
            p[i] = new T * [s];
        }
    }
    matrix(const matrix& other) : row(other.row), col(other.col)
    {
        p = new T * [row];
        for (int i = 0; i < row; i++)
        {
            p[i] = new T[col];
            for (int j = 0; j < col; ++j)
            {
                p[i][j] = other.p[i][j];
            }
        }
    }
    matrix(matrix&& other) :p(other.p), row(other.row), col(other.col)
    {
        other.p = nullptr;
        other.row = 0;
        other.col = 0;
    }
    ~matrix()
    {
        for (int i = 0; i < row; ++i)
        {
            delete[]p[i];
        }
        delete[] p;
    }
    ///////////////////////////////////////////////////////

    matrix& operator = (const matrix&)
    {
        if (this == &other)
        {
            return *this;
        }
        if (p)
        {
            for (int i = 0; i < row; ++i)
            {
                delete[] p[i];
                delete[] p;
            }
            row = other.row;
            col = other.col;
            p = new T * [row];
            for (int i = 0; i < row; ++i)
            {
                p[i] = new T[col];
                for (int j = 0; j < col; ++j)
                {
                    p[i][j] = other.p[i][j];
                }
            }
            return *this;
        }
    }
    matrix& operator = (matrix&& other)
    {
        if (this == &other)
        {
            return *this;
        }
        if (p)
        {
            for (int i = 0; i < row; ++i)
            {
                delete[] p[i];
                delete[]p
            }
            p = other.p;
            row = other.row;
            col = other.col;
            other.p = nullptr;
            other.row = 0;
            other.col = 0;
            return *this;
        }
    }
    ///////////////////////////////////////////////////////

    matrix& operator ++()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                ++p[i][j];
            }
            return *this;
        }
    }
    matrix operator ++(int)
    {
        matrix temp(*this);
        ++(*this);
        return temp;
    }
    ///////////////////////////////////////////////////////

    matrix& operator --()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                --p[i][j];
            }
            return *this;
        }
    }
    matrix operator --(int)
    {
        matrix temp(*this);
        --(*this);
        return temp;
    }
    ///////////////////////////////////////////////////////

    matrix operator+(const matrix&) const
    {
        matrix result(row, col);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j = col; ++j)
            {
                result.p[i][j] = p[i][j] + other.p[i][j];
            }
            return result;
        }
    }
    matrix operator*(const matrix& other) const
    {
        matrix result(row, other.col);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < other.col; ++j)
            {
                result.p[i][j] = T(0);
                for (int k = 0; k < col; ++k)
                {
                    result.p[i][j] += p[i][k] * other.p[k][j];
                }
            }
        }
        return result;
    }
    T& operator()(int r, int c)
    {
        return p[r][c];
    }
    ///////////////////////////////////////////////////////

    const T& operator()(int r, int c) const
    {
        return p[r][c];
    }
    ///////////////////////////////////////////////////////

    friend std::ostream& operator<<(std::ostream& os, const matrix<T>& m) {
        for (int i = 0; i < m.row; ++i) {
            for (int j = 0; j < m.col; ++j) {
                os << m.p[i][j] << "\t";
            }
            os << "\n";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, matrix<T>& m) {
        for (int i = 0; i < m.row; ++i) {
            for (int j = 0; j < m.col; ++j) {
                is >> m.p[i][j];
            }
        }
        return is;
    }
    ///////////////////////////////////////////////////////
};
int main()
{
    matrix<int> m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;
    cout << "Matrix m1...\n" << m1 << endl;
    return 0;
}