/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Scene
*/

#include "Scene.hpp"

RayTracer::Scene::Scene()
{
}

RayTracer::Scene::~Scene()
{
}

void RayTracer::Scene::setCamera(const RayTracer::Camera &camera) {
    this->_camera = camera;
}

const RayTracer::Camera &RayTracer::Scene::getCamera() const {
    return this->_camera;
}

void RayTracer::Scene::setPrimitives(const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &primitives) {
    this->_primitives = primitives;
}

const std::vector<std::shared_ptr<RayTracer::IPrimitive>> &RayTracer::Scene::getPrimitives() const {
    return this->_primitives;
}

void RayTracer::Scene::setLights(const std::vector<std::shared_ptr<RayTracer::ILights>> &lights) {
    this->_lights = lights;
}

const std::vector<std::shared_ptr<RayTracer::ILights>> &RayTracer::Scene::getLights() const {
    return this->_lights;
}
