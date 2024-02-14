#pragma once

#include <iostream>
#include <vector>
#include "Matrix.hpp"

class Layer {
    public:
        Layer() = default;
        ~Layer() = default;

        virtual Matrix forward(const Matrix &inputData) = 0;
        virtual Matrix backward(const Matrix &outputError, double learningRate) = 0;

    protected:
        Matrix _input;
        Matrix _output;
};
