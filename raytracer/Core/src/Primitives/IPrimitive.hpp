/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** IPrimitive
*/

#pragma once

#include "Color.hpp"
#include "../Ray.hpp"
#include <vector>

namespace RayTracer {
    class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual const Color getColor() const = 0;
        virtual bool hits(RayTracer::Ray& ray) = 0;
        virtual double racine(RayTracer::Ray& ray) = 0;
        virtual Math::Vector3D getNormal(Math::Point3D hitPoint) = 0;
        virtual Math::Point3D hitPoint(RayTracer::Ray& ray) = 0;
        virtual void setParams(const std::vector<double> params) = 0;
    };
}
