/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Camera
*/

#pragma once
#include "../Point3D.hpp"
#include "../Primitives/Rectangle3D.hpp"
#include "../Ray.hpp"

namespace RayTracer {
    class Camera {
    public:
        Math::Point3D origin;
        Math::Point3D rotation;
        Rectangle3D screen;
        float fieldOfView;
        Camera();
        Camera(Math::Point3D o, Rectangle3D s);
        Camera(const Camera& og);
        Camera operator=(const Camera& og);
        ~Camera();
        Ray ray(double u, double v);

    private:
    };
};
