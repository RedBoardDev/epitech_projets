/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Ambiant
*/

#include "../include/Ambiant.hpp"

RayTracer::AmbientLight::AmbientLight() {}

RayTracer::AmbientLight::AmbientLight(double intensitys) {
    this->intensity = intensitys;
}

RayTracer::AmbientLight::~AmbientLight() {}

std::vector<double> RayTracer::AmbientLight::cast(RayTracer::IPrimitive &prim, Math::Point3D& hitPoint) {
    RayTracer::Color color = prim.getColor();
    color.setRColor(color.getRColor() * ( this->intensity));
    color.setGColor(color.getGColor() * ( this->intensity));
    color.setBColor(color.getBColor() * ( this->intensity));
    return std::vector<double> {(double)color.getRColor(), (double)color.getGColor(), (double)color.getBColor()};
}

bool RayTracer::AmbientLight::hits(RayTracer::Ray& ray) {
    return true;
}

void RayTracer::AmbientLight::setParams(const std::vector<double> params) {
    this->intensity = (params[0]);
}

extern "C" {
std::unique_ptr<RayTracer::ILights> entryPoint()
{
    return std::make_unique<RayTracer::AmbientLight>();
}

bool isPrim()
{
    return false;
}

std::string getName()
{
    return "ambient";
}
}
