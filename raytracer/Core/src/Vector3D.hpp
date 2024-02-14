/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Math
*/

#pragma once
#include <tgmath.h>

namespace Math {
class Vector3D {
public:
    Vector3D(double x = 0, double y = 0, double z = 0)
    {
        this->X = x;
        this->Y = y;
        this->Z = z;
    }

    Vector3D(Vector3D& v)
    {
        this->X = v.X;
        this->Y = v.Y;
        this->Z = v.Z;
    }

    Vector3D(Vector3D&& v)
    {
        this->X = v.X;
        this->Y = v.Y;
        this->Z = v.Z;
        v.X = 0;
        v.Y = 0;
        v.Z = 0;
    }

    ~Vector3D() {}

    int length(void)
    {
        return (sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2)));
    }

    Vector3D operator=(Vector3D const& v)
    {
        this->X = v.X;
        this->Y = v.Y;
        this->Z = v.Z;
        return (*this);
    }

    Vector3D operator=(Vector3D&& v)
    {
        this->X = v.X;
        this->Y = v.Y;
        this->Z = v.Z;
        v.X = 0;
        v.Y = 0;
        v.Z = 0;
        return (*this);
    }

    Vector3D operator+(const Vector3D& v2)
    {
        return Math::Vector3D(this->X + v2.X, this->Y + v2.Y, this->Z + v2.Z);
    }

    Vector3D operator-(const Vector3D& v2)
    {
        return Math::Vector3D(this->X - v2.X, this->Y - v2.Y, this->Z - v2.Z);
    }

    Vector3D operator+=(const Vector3D& v2)
    {
        this->X += v2.X;
        this->Y += v2.Y;
        this->Z += v2.Z;
        return *this;
    }

    Vector3D operator-=(const Vector3D& v2)
    {
        this->X -= v2.X;
        this->Y -= v2.Y;
        this->Z -= v2.Z;
        return *this;
    }

    Vector3D operator*(const Vector3D& v2)
    {
        return Math::Vector3D(this->X * v2.X, this->Y * v2.Y, this->Z * v2.Z);
    }

    Vector3D operator*=(const Vector3D& v2)
    {
        this->X *= v2.X;
        this->Y *= v2.Y;
        this->Z *= v2.Z;
        return *this;
    }

    Vector3D operator*(const double& v2)
    {
        return Math::Vector3D(this->X * v2, this->Y * v2, this->Z * v2);
    }

    Vector3D operator/(const double& v2)
    {
        return Math::Vector3D(this->X / v2, this->Y / v2, this->Z / v2);
    }

    Vector3D operator*=(const double& v2)
    {
        this->X *= v2;
        this->Y *= v2;
        this->Z *= v2;
        return *this;
    }

    Vector3D operator/=(const double& v2)
    {
        this->X /= v2;
        this->Y /= v2;
        this->Z /= v2;
        return *this;
    }

    double dot(const Vector3D& v2)
    {
        return (this->X * v2.X + this->Y * v2.Y + this->Z * v2.Z);
    }

    void normalize(void)
    {
        double length = sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2));
        this->X /= length;
        this->Y /= length;
        this->Z /= length;
    }

    double X;
    double Y;
    double Z;
};
}
