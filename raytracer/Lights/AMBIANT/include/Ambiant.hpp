/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Ambient
*/

#pragma once
#include "../../../Core/src/Lights/ILights.hpp"
#include "../../../Core/src/Primitives/IPrimitive.hpp"
#include <iostream>
#include <memory>

namespace RayTracer {
    class AmbientLight : public ILights {
    public:
        AmbientLight();
        AmbientLight(double intensitys);
        ~AmbientLight();
        std::vector<double> cast(RayTracer::IPrimitive &prim, Math::Point3D& hitPoint);
        bool hits(RayTracer::Ray& ray);
        void setParams(const std::vector<double> params);
    private:
        double intensity;
    };
}
