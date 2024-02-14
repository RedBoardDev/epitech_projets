#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(std::function<double (const Matrix &, const Matrix &)> mse, std::function<Matrix (const Matrix &y, const Matrix &yPred)> derivedMse):
    _loss(mse),
    _derivedLoss(derivedMse)
{}

void NeuralNetwork::add(std::unique_ptr<Layer> &&layer)
{
    _layers.push_back(std::move(layer));
}

void NeuralNetwork::train(const std::vector<Matrix> &inputData, const std::vector<Matrix> &expectedOutput, size_t iterations, double learningRate)
{
    if (inputData.size() != expectedOutput.size())
        throw std::runtime_error("Input data and expected output must have the same size");

    for (size_t i = 0; i < iterations; i++) {
        double err = 0.0;
        for (size_t j = 0; j < inputData.size(); j++) {
            Matrix output = inputData[j];
            for (const auto &layer: _layers)
                output = layer->forward(output);
            err += _loss(expectedOutput[j], output);
            Matrix error = _derivedLoss(expectedOutput[j], output);
            for (auto it = _layers.rbegin(); it != _layers.rend(); it++)
                error = (*it)->backward(error, learningRate);
        }
        err /= inputData.size();
        // std::cout << "Iteration: " << i + 1 << " / " << iterations << " -> Error: " << err << std::endl;
    }
}

std::vector<Matrix> NeuralNetwork::predict(const std::vector<Matrix> &inputData)
{
    std::vector<Matrix> res;
    for (const auto &input: inputData) {
        Matrix tmp = input;
        for (const auto &layer: _layers)
            tmp = layer->forward(tmp);
        res.push_back(tmp);
    }
    return res;
}
