/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Directional
*/

#include "../include/Directional.hpp"

RayTracer::Directional::Directional() {}

RayTracer::Directional::~Directional() {}

RayTracer::Directional::Directional(Math::Point3D position, Math::Vector3D direction)
{
    this->position = position;
    this->direction = direction;
}

std::vector<double> RayTracer::Directional::cast(RayTracer::IPrimitive& prim, Math::Point3D& hitPoint)
{
    Math::Vector3D normal = prim.getNormal(hitPoint);
    double k = this->direction.dot(normal);
    RayTracer::Color color(255 * k, 255 * k, 255 * k);
    double prim_r = prim.getColor().getRColor();
    double prim_g = prim.getColor().getGColor();
    double prim_b = prim.getColor().getBColor();
    RayTracer::Color res(color.getRColor() + prim_r, color.getGColor() + prim_g, color.getBColor() + prim_b);
    if (res.getRColor() > 255)
        res.setRColor(255);
    if (res.getGColor() > 255)
        res.setGColor(255);
    if (res.getBColor() > 255)
        res.setBColor(255);
    if (res.getRColor() < 0)
        res.setRColor(0);
    if (res.getGColor() < 0)
        res.setGColor(0);
    if (res.getBColor() < 0)
        res.setBColor(0);
    //std::cout << res.getRColor() << " " << res.getGColor() << " " << res.getBColor() << std::endl;
    //return std::vector<double> {prim_r, prim_g, prim_b};
    return std::vector<double> {(double)res.getRColor(), (double)res.getGColor(), (double)res.getBColor()};
}

void RayTracer::Directional::setParams(const std::vector<double> params)
{
    this->position.X = params[0];
    this->position.Y = params[1];
    this->position.Z = params[2];
    this->direction.X = params[3];
    this->direction.Y = params[4];
    this->direction.Z = params[5];
}

bool RayTracer::Directional::hits(RayTracer::Ray& ray) {
    return false;
}

extern "C" {
std::unique_ptr<RayTracer::ILights> entryPoint()
{
    return std::make_unique<RayTracer::Directional>();
}

bool isPrim()
{
    return false;
}

std::string getName()
{
    return "directional";
}
}
