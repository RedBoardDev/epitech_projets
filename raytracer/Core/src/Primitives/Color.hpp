/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Color.hpp
*/

#pragma once

namespace RayTracer {
    class Color {
        public:
            Color(int r = 0, int g = 0, int b = 0) {
                this->_r = r;
                this->_g = g;
                this->_b = b;
            }

            int getRColor() const {
                return this->_r;
            }
            int getGColor() const {
                return this->_g;
            }
            int getBColor() const {
                return this->_b;
            }
            int setRColor(int r) {
                this->_r = r;
                return this->_r;
            }
            int setGColor(int g) {
                this->_g = g;
                return this->_g;
            }
            int setBColor(int b) {
                this->_b = b;
                return this->_b;
            }
            ~Color() {}
        private:
            int _r;
            int _g;
            int _b;
    };
}