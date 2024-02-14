/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Plane
*/

#pragma once

#include <memory>
#include "../../../Core/src/Primitives/IPrimitive.hpp"
#include <tgmath.h>
#include <limits>

namespace RayTracer {
    class Plane: public RayTracer::IPrimitive {
        public:
            Plane();
            Plane(Math::Point3D c, double r, Color color);
            Plane(const Plane& og);
            Plane operator=(const Plane& og);
            bool hits(RayTracer::Ray& ray);
            double racine(RayTracer::Ray& ray);
            const Color getColor() const;
            virtual ~Plane();
            Math::Point3D hitPoint(RayTracer::Ray& ray);
            Math::Vector3D getNormal(Math::Point3D hitPoint);
            void setParams(const std::vector<double> params);
        private:
            Math::Point3D center;
            Math::Vector3D normal;
            RayTracer::Color color;
            char axis;
    };
};
