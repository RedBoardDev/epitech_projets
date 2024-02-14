/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Ray
*/

#pragma once
#include "Point3D.hpp"

namespace RayTracer {
class Ray {
public:
    Math::Point3D origin;
    Math::Vector3D direction;
    Ray() {
        this->origin = Math::Point3D(0, 0, 0);
        this->direction = Math::Vector3D(0, 0, 0);
    }

    Ray(Math::Point3D o, Math::Vector3D d) {
        this->origin = o;
        this->direction = d;
    }

    Ray(const Ray& og) {
        this->origin = og.origin;
        this->direction = og.direction;
    }

    Ray operator=(const Ray& og) {
        this->origin = og.origin;
        this->direction = og.direction;
        return *this;
    }

    ~Ray() {};
    Math::Vector3D getDirection() {
        return this->direction;
    }

private:
};
};
