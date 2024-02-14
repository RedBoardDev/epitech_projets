/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Directional
*/

#pragma once
#include "../../../Core/src/Lights/ILights.hpp"
#include "../../../Core/src/Primitives/IPrimitive.hpp"
#include <iostream>
#include <memory>

namespace RayTracer {
    class Directional : public RayTracer::ILights {
        public:
            Directional();
            ~Directional();
            Directional(Math::Point3D position, Math::Vector3D direction);
            bool hits(RayTracer::Ray& ray);
            std::vector<double> cast(RayTracer::IPrimitive &sphere, Math::Point3D& hitPoint);
            void setParams(const std::vector<double> params);

        private:
            Math::Point3D position;
            Math::Vector3D direction;
    };
}
