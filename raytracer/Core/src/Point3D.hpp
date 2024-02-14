/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Math
*/

#pragma once
#include "Vector3D.hpp"

namespace Math {
class Point3D {
public:
    Point3D()
    {
        X = 0;
        Y = 0;
        Z = 0;
    }

    Point3D(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    Point3D(const Point3D& og)
    {
        X = og.X;
        Y = og.Y;
        Z = og.Z;
    }

    ~Point3D() {};
    Point3D operator=(const Point3D& og)
    {
        X = og.X;
        Y = og.Y;
        Z = og.Z;
        return *this;
    }

    Point3D operator+(const Vector3D& v2)
    {
        return Point3D(X + v2.X, Y + v2.Y, Z + v2.Z);
    }

    Point3D operator-(const Vector3D& v2)
    {
        return Point3D(X - v2.X, Y - v2.Y, Z - v2.Z);
    }

    Point3D operator+=(const Vector3D& v2)
    {
        X += v2.X;
        Y += v2.Y;
        Z += v2.Z;
        return *this;
    }

    Point3D operator-=(const Vector3D& v2)
    {
        X -= v2.X;
        Y -= v2.Y;
        Z -= v2.Z;
        return *this;
    }

    Vector3D operator-(const Point3D& v2)
    {
        return Vector3D(X - v2.X, Y - v2.Y, Z - v2.Z);
    }

    double X;
    double Y;
    double Z;
};
}
