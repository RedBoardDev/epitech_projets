/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Rectangle3D
*/

#pragma once
#include "../Vector3D.hpp"
#include "../Point3D.hpp"

namespace RayTracer {
class Rectangle3D {
public:
    int height;
    int width;
    Math::Point3D origin;
    Math::Vector3D bottom_side;
    Math::Vector3D left_side;
    Rectangle3D();
    Rectangle3D(Math::Point3D o, Math::Vector3D b, Math::Vector3D l);
    Rectangle3D(const Rectangle3D& og);
    Rectangle3D operator=(const Rectangle3D& og);
    ~Rectangle3D();
    Math::Point3D pointAt(double u, double v);
};
};
