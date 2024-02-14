/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

RayTracer::Rectangle3D::Rectangle3D()
{
    this->origin = Math::Point3D(0, 0, 0);
    this->bottom_side = Math::Vector3D(0, 0, 0);
    this->left_side = Math::Vector3D(0, 0, 0);
}
RayTracer::Rectangle3D::Rectangle3D(Math::Point3D o, Math::Vector3D b, Math::Vector3D l)
{
    this->origin = o;
    this->bottom_side = b;
    this->left_side = l;
}
RayTracer::Rectangle3D::Rectangle3D(const RayTracer::Rectangle3D& og)
{
    this->origin = og.origin;
    this->bottom_side = og.bottom_side;
    this->left_side = og.left_side;
}
RayTracer::Rectangle3D RayTracer::Rectangle3D::operator=(const RayTracer::Rectangle3D& og)
{
    this->origin = og.origin;
    this->bottom_side = og.bottom_side;
    this->left_side = og.left_side;
    this->height = og.height;
    this->width = og.width;
    return *this;
}

RayTracer::Rectangle3D::~Rectangle3D() {

};

Math::Point3D RayTracer::Rectangle3D::pointAt(double u, double v)
{
    return this->origin + (this->bottom_side * u) + (this->left_side * v);
}
