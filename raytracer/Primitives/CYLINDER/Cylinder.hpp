#pragma once
#include <memory>
#include <tgmath.h>
#include <iostream>
#include "../../Core/src/Point3D.hpp"
#include "../../Core/src/Vector3D.hpp"
#include "../../Core/src/Primitives/Color.hpp"
#include "../../Core/src/Primitives/IPrimitive.hpp"

namespace RayTracer {
    class Cylinder : public IPrimitive {
        public:
            Cylinder();
            Cylinder(Math::Point3D c, double r, Color color);
            Cylinder(const Cylinder& og);
            Cylinder(float radius, float x, float y, float z, float r, float g, float b);
            ~Cylinder();
            Cylinder operator=(const Cylinder& og);
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
