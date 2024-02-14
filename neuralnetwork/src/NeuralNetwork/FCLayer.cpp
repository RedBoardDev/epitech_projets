#include "FCLayer.hpp"

FCLayer::FCLayer(size_t nbInputNeurons, size_t nbOutputNeurons)
{
    _weights = Matrix(nbInputNeurons, nbOutputNeurons);
    for (size_t i = 0; i < nbInputNeurons; i++)
        for (size_t j = 0; j < nbOutputNeurons; j++)
            _weights(i, j) = getRandomNumber(-1, 1);

    _biases = Matrix(1, nbOutputNeurons);
    for (size_t i = 0; i < nbOutputNeurons; i++)
        _biases(0, i) = getRandomNumber(-1, 1);
}

Matrix FCLayer::forward(const Matrix &inputData)
{
    _input = inputData;
    _output = _input.dot(_weights) + _biases;
    return _output;
}

Matrix FCLayer::backward(const Matrix &outputError, double learningRate)
{
    Matrix inputError = outputError.dot(_weights.transpose());
    Matrix weightsError = _input.transpose().dot(outputError);

    _weights = _weights - (weightsError * learningRate);
    _biases = _biases - (outputError * learningRate);
    return inputError;
}

double FCLayer::getRandomNumber(double min, double max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}
