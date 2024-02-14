#pragma once

#include <iostream>
#include <vector>
#include <functional>

class Matrix {
    public:
        Matrix() = default;
        Matrix(size_t nbRows, size_t nbCols);
        Matrix(size_t nbRows, size_t nbCols, double value);
        Matrix(size_t nbRows, size_t nbCols, const std::vector<double> &data);
        Matrix(const Matrix &other);
        ~Matrix() = default;

        Matrix transpose() const;
        Matrix dot(const Matrix &other) const;
        Matrix apply(std::function<double (double)> func) const;

        Matrix &operator=(const Matrix &other);
        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
        Matrix operator*(double value) const;
        Matrix operator/(double value) const;
        Matrix operator-() const;

        double &operator()(size_t row, size_t col);
        double operator()(size_t row, size_t col) const;

        size_t getNbRows() const;
        size_t getNbCols() const;

    private:
        std::vector<double> &operator[](size_t index);
        const std::vector<double> &operator[](size_t index) const;

        size_t _nbRows;
        size_t _nbCols;
        std::vector<std::vector<double>> _data;
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
