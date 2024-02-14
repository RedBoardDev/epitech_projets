#include "Matrix.hpp"

Matrix::Matrix(size_t nbRows, size_t nbCols):
    _nbRows(nbRows),
    _nbCols(nbCols),
    _data(nbRows, std::vector<double>(nbCols, 0.0))
{}

Matrix::Matrix(size_t nbRows, size_t nbCols, double value):
    _nbRows(nbRows),
    _nbCols(nbCols),
    _data(nbRows, std::vector<double>(nbCols, value))
{}

Matrix::Matrix(size_t nbRows, size_t nbCols, const std::vector<double> &data):
    _nbRows(nbRows),
    _nbCols(nbCols),
    _data(nbRows, data)
{}

Matrix::Matrix(const Matrix &other):
    _nbRows(other._nbRows),
    _nbCols(other._nbCols),
    _data(other._data)
{}

Matrix Matrix::transpose() const
{
    Matrix result(_nbCols, _nbRows);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[j][i] = _data[i][j];
    return result;
}

Matrix Matrix::dot(const Matrix &other) const
{
    if (_nbCols != other._nbRows)
        throw std::runtime_error("dot: Matrix sizes are not compatible");
    Matrix result(_nbRows, other._nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < other._nbCols; j++)
            for (size_t k = 0; k < _nbCols; k++)
                result[i][j] += _data[i][k] * other._data[k][j];
    return result;
}

Matrix Matrix::apply(std::function<double (double)> func) const
{
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[i][j] = func(_data[i][j]);
    return result;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    _nbRows = other._nbRows;
    _nbCols = other._nbCols;
    _data = other._data;
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (_nbRows != other._nbRows || _nbCols != other._nbCols)
        throw std::runtime_error("operator+: Matrix sizes are not compatible");
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++) {
        for (size_t j = 0; j < _nbCols; j++) {
            result[i][j] = _data[i][j] + other._data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (_nbRows != other._nbRows || _nbCols != other._nbCols)
        throw std::runtime_error("operator-: Matrix sizes are not compatible");
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++) {
        for (size_t j = 0; j < _nbCols; j++) {
            result[i][j] = _data[i][j] - other._data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (_nbRows != other._nbRows || _nbCols != other._nbCols)
        throw std::runtime_error("operator*: Matrix sizes are not compatible");
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[i][j] = _data[i][j] * other._data[i][j];
    return result;
}

Matrix Matrix::operator*(double value) const
{
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[i][j] = _data[i][j] * value;
    return result;
}

Matrix Matrix::operator/(double value) const
{
    if (value == 0)
        throw std::runtime_error("Division by zero");
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[i][j] = _data[i][j] / value;
    return result;
}

Matrix Matrix::operator-() const
{
    Matrix result(_nbRows, _nbCols);
    for (size_t i = 0; i < _nbRows; i++)
        for (size_t j = 0; j < _nbCols; j++)
            result[i][j] = -_data[i][j];
    return result;
}

double &Matrix::operator()(size_t row, size_t col)
{
    if (row >= _nbRows || col >= _nbCols)
        throw std::runtime_error("Index out of bounds");
    return _data[row][col];
}

double Matrix::operator()(size_t row, size_t col) const
{
    if (row >= _nbRows || col >= _nbCols)
        throw std::runtime_error("Index out of bounds");
    return _data[row][col];
}

size_t Matrix::getNbRows() const
{
    return _nbRows;
}

size_t Matrix::getNbCols() const
{
    return _nbCols;
}

std::vector<double> &Matrix::operator[](size_t index)
{
    return _data[index];
}

const std::vector<double> &Matrix::operator[](size_t index) const
{
    return _data[index];
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << "[";
    for (size_t i = 0; i < matrix.getNbRows(); i++) {
        os << "[";
        for (size_t j = 0; j < matrix.getNbCols(); j++)
            os << matrix(i, j) << (j < matrix.getNbCols() - 1 ? " " : "");
        os << "]" << (i < matrix.getNbRows() - 1 ? " " : "");
    }
    os << "]";
    return os;
}
