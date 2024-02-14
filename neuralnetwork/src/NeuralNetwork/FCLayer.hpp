#pragma once

#include <iostream>
#include <random>
#include "Layer.hpp"

class FCLayer: public Layer {
    public:
        FCLayer(size_t nbInputNeurons, size_t nbOutputNeurons);
        ~FCLayer() = default;

        virtual Matrix forward(const Matrix &inputData) override;
        virtual Matrix backward(const Matrix &outputError, double learningRate) override;

    private:
        double getRandomNumber(double min, double max);

        Matrix _weights;
        Matrix _biases;
};
