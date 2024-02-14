#include <iostream>
#include <memory>
#include <iomanip>

#include "NeuralNetwork/ActivationLayer.hpp"
#include "NeuralNetwork/FCLayer.hpp"
#include "NeuralNetwork/NeuralNetwork.hpp"

std::ostream &operator<<(std::ostream &os, const std::vector<Matrix> &matrix)
{
    os << "[ ";
    for (const auto &m: matrix)
        os << m << " ";
    os << "]";
    return os;
}

Matrix tanh_matrix(const Matrix &x)
{
    return x.apply([](double v) { return std::tanh(v); });
}

Matrix tanh_prime_matrix(const Matrix &x)
{
    return x.apply([](double v) { return 1 - std::tanh(v) * std::tanh(v); });
}

double mean_squared_error(const Matrix &y, const Matrix &yPred)
{
    Matrix tmp = y - yPred;
    tmp = tmp.apply([](double v) { return v * v; });
    double sum = 0;
    for (size_t i = 0; i < tmp.getNbRows(); i++)
        for (size_t j = 0; j < tmp.getNbCols(); j++)
            sum += tmp(i, j);
    return sum / (tmp.getNbRows() * tmp.getNbCols());
}

Matrix mean_squared_error_prime(const Matrix &y, const Matrix &yPred)
{
    return (yPred - y) * 2 / (y.getNbRows() * y.getNbCols());
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    std::cout << std::fixed << std::setprecision(10);

    NeuralNetwork nn(mean_squared_error, mean_squared_error_prime);
    nn.add(std::make_unique<FCLayer>(2, 3));
    nn.add(std::make_unique<ActivationLayer>(tanh_matrix, tanh_prime_matrix));
    nn.add(std::make_unique<FCLayer>(3, 1));
    nn.add(std::make_unique<ActivationLayer>(tanh_matrix, tanh_prime_matrix));

    std::vector<Matrix> inputData = {
        Matrix(1, 2, std::vector<double>({ 0, 0 })),
        Matrix(1, 2, std::vector<double>({ 0, 1 })),
        Matrix(1, 2, std::vector<double>({ 1, 0 })),
        Matrix(1, 2, std::vector<double>({ 1, 1 }))
    };
    std::vector<Matrix> expectedOutput = {
        Matrix(1, 1, 0),
        Matrix(1, 1, 1),
        Matrix(1, 1, 1),
        Matrix(1, 1, 0)
    };

    nn.train(inputData, expectedOutput, 10000, 0.1);

    std::vector<Matrix> res = nn.predict(inputData);
    std::cout << res << std::endl;

    return 0;
}
