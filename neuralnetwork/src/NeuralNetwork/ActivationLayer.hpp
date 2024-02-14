#pragma once

#include <iostream>
#include <functional>
#include "Layer.hpp"

class ActivationLayer: public Layer {
    public:
        ActivationLayer(std::function<Matrix (const Matrix &)> activationFunction, std::function<Matrix (const Matrix &)> derivedActivationFunction);
        ~ActivationLayer() = default;

        virtual Matrix forward(const Matrix &inputData) override;
        virtual Matrix backward(const Matrix &outputError, double learningRate) override;

    private:
        std::function<Matrix (const Matrix &)> _activationFunction;
        std::function<Matrix (const Matrix &)> _derivedActivationFunction;
};
