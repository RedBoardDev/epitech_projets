/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** ILights
*/


#pragma once
#include "../Point3D.hpp"
#include "../Primitives/Color.hpp"
#include "../Primitives/IPrimitive.hpp"
#include "../Vector3D.hpp"

namespace RayTracer {
    class ILights {
        public:
            virtual ~ILights() = default;
            virtual std::vector<double> cast(RayTracer::IPrimitive & sphere, Math::Point3D& hitPoint) = 0;
            virtual void setParams(const std::vector<double> params) = 0;

        protected:
        private:
    };
}
