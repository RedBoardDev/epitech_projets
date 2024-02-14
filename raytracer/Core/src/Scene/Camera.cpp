/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera()
{
    this->origin = Math::Point3D(0, 0, 0);
    this->screen = RayTracer::Rectangle3D();
}

RayTracer::Camera::Camera(Math::Point3D o, RayTracer::Rectangle3D s)
{
    this->origin = o;
    this->screen = s;
}
RayTracer::Camera::Camera(const RayTracer::Camera& og)
{
    this->origin = og.origin;
    this->screen = og.screen;
}
RayTracer::Camera RayTracer::Camera::operator=(const RayTracer::Camera& og)
{
    this->origin = og.origin;
    this->screen = og.screen;
    return *this;
}

RayTracer::Camera::~Camera() {

};

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D p = screen.pointAt(u, v);
    Math::Vector3D d(p.X, p.Y, p.Z);

    return Ray(this->origin, d);
}
