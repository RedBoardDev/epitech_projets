/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Scene
*/

#pragma once

#include <vector>
#include <memory>
#include "Camera.hpp"
#include "../Primitives/IPrimitive.hpp"
#include "../Lights/ILights.hpp"

namespace RayTracer {
    class Scene {
        public:
            Scene();
            ~Scene();
            void setCamera(const RayTracer::Camera &camera);
            const RayTracer::Camera &getCamera() const;
            void setPrimitives(const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives);
            const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &getPrimitives() const;
            void setLights(const std::vector<std::shared_ptr<RayTracer::ILights>> &lights);
            const std::vector<std::shared_ptr<RayTracer::ILights>> &getLights() const;

            // to remove
            RayTracer::Camera camera;
            std::vector<std::shared_ptr<RayTracer::IPrimitive>> primitives;
            std::vector<std::shared_ptr<RayTracer::ILights>> lights;

        private:
            RayTracer::Camera _camera;
            std::vector<std::shared_ptr<RayTracer::IPrimitive>> _primitives;
            std::vector<std::shared_ptr<RayTracer::ILights>> _lights;
    };
}
