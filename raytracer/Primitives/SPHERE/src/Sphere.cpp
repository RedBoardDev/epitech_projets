#include "../include/Sphere.hpp"

void RayTracer::Sphere::translate(float x, float y, float z)
{
    this->center.X += x;
    this->center.Y += y;
    this->center.Z += z;
}

RayTracer::Sphere::Sphere()
{
    this->center = Math::Point3D(0, 0, 0);
    this->radius = 0;
    this->color = RayTracer::Color(0, 0, 0);
}

Math::Point3D RayTracer::Sphere::hitPoint(RayTracer::Ray& ray)
{
    Math::Vector3D origin(ray.origin.X - this->center.X, ray.origin.Y - this->center.Y, ray.origin.Z - this->center.Z);
    Math::Vector3D d(ray.direction.X - ray.origin.X, ray.direction.Y - ray.origin.Y, ray.direction.Z - ray.origin.Z);
    double calc_a = 2 * origin.dot(d);
    double calc_b = d.dot(d);
    double calc_c = origin.dot(origin) - pow(radius, 2);
    double test = pow(calc_b, 2) - 4 * calc_a * calc_c;
    double res;
    if (test == 0)
        res = (-calc_b) / (2 * calc_a);
    else {
        double root1 = (-calc_b + sqrt(test)) / (2 * calc_a);
        double root2 = (-calc_b - sqrt(test)) / (2 * calc_a);
    if (root1 < root2)
        res = root1;
    else
        res = root2;
    }
    Math::Point3D hitPoint(ray.origin.X + ray.direction.X * res, ray.origin.Y + ray.direction.Y * res, ray.origin.Z + ray.direction.Z * res);
    return (hitPoint);
}

RayTracer::Sphere::Sphere(Math::Point3D c, double r, Color color)
{
    this->center = c;
    this->radius = r;
    this->color = color;
}

RayTracer::Sphere::Sphere(const RayTracer::Sphere& og)
{
    this->center = og.center;
    this->radius = og.radius;
    this->color = og.color;
}

RayTracer::Sphere RayTracer::Sphere::operator=(const RayTracer::Sphere& og)
{
    this->center = og.center;
    this->radius = og.radius;
    this->color = og.color;
    return *this;
}

bool RayTracer::Sphere::hits(RayTracer::Ray& ray)
{
    Math::Vector3D origin(ray.origin.X - this->center.X, ray.origin.Y - this->center.Y, ray.origin.Z - this->center.Z);
    Math::Vector3D d(ray.direction.X - ray.origin.X, ray.direction.Y - ray.origin.Y, ray.direction.Z - ray.origin.Z);
    double calc_a = d.dot(d);
    double calc_b = 2 * origin.dot(d);
    double calc_c = origin.dot(origin) - pow(radius, 2);
    return (pow(calc_b, 2) - 4 * calc_a * calc_c) < 0 ? false : true;
}

double RayTracer::Sphere::racine(RayTracer::Ray& ray)
{
    Math::Vector3D origin(ray.origin.X - this->center.X, ray.origin.Y - this->center.Y, ray.origin.Z - this->center.Z);
    Math::Vector3D d(ray.direction.X - ray.origin.X, ray.direction.Y - ray.origin.Y, ray.direction.Z - ray.origin.Z);
    double calc_a = d.dot(d);
    double calc_b = 2 * origin.dot(d);
    double calc_c = origin.dot(origin) - pow(radius, 2);
    double det = pow(calc_b, 2) - 4 * calc_a * calc_c;
    if (det == 0)
        return (-calc_b / 2 * calc_a);
    double racine_1 = (-calc_b - sqrt(det)) / 2 * calc_a;
    double racine_2 = (-calc_b + sqrt(det)) / 2 * calc_a;
    return ((racine_1 < racine_2 ? racine_1 : racine_2));
}

RayTracer::Sphere::~Sphere() {
}

const RayTracer::Color RayTracer::Sphere::getColor() const
{
    return this->color;
}

RayTracer::Sphere::Sphere(float radius, float x, float y, float z, float r, float g, float b)
{
    this->center = Math::Point3D(x, y, z);
    this->radius = radius;
    this->color = RayTracer::Color(r, g, b);
}

Math::Vector3D RayTracer::Sphere::getNormal(Math::Point3D point)
{
    Math::Vector3D tmp(point.X - center.X, point.Y - center.Y, point.Z - center.Z);
    double tmpDot = tmp.dot(tmp);
    if (tmpDot != 0.0)
        tmp /= sqrt(tmpDot);
    return (tmp);
}

void RayTracer::Sphere::setParams(const std::vector<double> params)
{
    this->radius = params[0];
    this->center.X = params[1];
    this->center.Y = params[2];
    this->center.Z = params[3];
    this->color.setRColor(params[4]);
    this->color.setGColor(params[5]);
    this->color.setBColor(params[6]);
    this->translate(params[7], params[8], params[9]);
}

extern "C" {
std::unique_ptr<RayTracer::IPrimitive> entryPoint()
{
    return std::make_unique<RayTracer::Sphere>();
}

bool isPrim()
{
    return true;
}

std::string getName()
{
    return "sphere";
}
}
