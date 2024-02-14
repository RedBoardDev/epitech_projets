#include "ActivationLayer.hpp"

ActivationLayer::ActivationLayer(std::function<Matrix (const Matrix &)> activationFunction, std::function<Matrix (const Matrix &)> derivedActivationFunction):
    _activationFunction(activationFunction),
    _derivedActivationFunction(derivedActivationFunction)
{}

Matrix ActivationLayer::forward(const Matrix &inputData)
{
    _input = inputData;
    _output = _activationFunction(_input);
    return _output;
}

Matrix ActivationLayer::backward(const Matrix &outputError, double learningRate)
{
    (void)learningRate;
    return _derivedActivationFunction(_input) * outputError;
}
