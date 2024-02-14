/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Sphere
*/

#pragma once

#include <memory>
#include <tgmath.h>
#include <iostream>
#include "../../../Core/src/Point3D.hpp"
#include "../../../Core/src/Vector3D.hpp"
#include "../../../Core/src/Primitives/Color.hpp"
#include "../../../Core/src/Primitives/IPrimitive.hpp"

namespace RayTracer {
    class Sphere : public RayTracer::IPrimitive {
        public:
            Sphere();
            Sphere(Math::Point3D c, double r, Color color);
            Sphere(const Sphere& og);
            Sphere(float radius, float x, float y, float z, float r, float g, float b);
            ~Sphere();
            Sphere operator=(const Sphere& og);
            bool hits(RayTracer::Ray& ray);
            double racine(RayTracer::Ray& ray);
            const Color getColor() const;
            Math::Point3D getCenter() const {
                return this->center;
            }
            Math::Point3D hitPoint(RayTracer::Ray& ray);
            Math::Vector3D getNormal(Math::Point3D hitPoint);
            void translate(float x, float y, float z);
            Math::Point3D getCenter() {return this->center;};
            double getRadius() {return this->radius;};
            void setColor(RayTracer::Color color) {this->color = color;};
            void setParams(const std::vector<double> params);
        private:
            Math::Point3D center;
            double radius;
            RayTracer::Color color;
    };
};
