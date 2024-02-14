#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include "Matrix.hpp"
#include "Layer.hpp"

class NeuralNetwork {
    public:
        NeuralNetwork(std::function<double (const Matrix &, const Matrix &)> mse, std::function<Matrix (const Matrix &y, const Matrix &yPred)> derivedMse);
        ~NeuralNetwork() = default;

        void add(std::unique_ptr<Layer> &&layer);
        void train(const std::vector<Matrix> &inputData, const std::vector<Matrix> &expectedOutput, size_t iterations, double learningRate);
        std::vector<Matrix> predict(const std::vector<Matrix> &inputData);

    private:
        std::function<double (const Matrix &, const Matrix &)> _loss;
        std::function<Matrix (const Matrix &y, const Matrix &yPred)> _derivedLoss;
        std::vector<std::unique_ptr<Layer>> _layers;
};
