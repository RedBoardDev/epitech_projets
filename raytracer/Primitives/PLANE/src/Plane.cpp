#include "../include/Plane.hpp"

RayTracer::Plane::Plane() {
    this->center = Math::Point3D(0, 0, 0);
    this->axis = 'Z';
    this->color = RayTracer::Color(0, 0, 0);
}

RayTracer::Plane::Plane(Math::Point3D c, double r, Color color) {
    this->center = c;
    this->axis = 'Z';
    this->color = color;
}

RayTracer::Plane::Plane(const RayTracer::Plane& og) {
    this->center = og.center;
    this->axis = og.axis;
    this->color = og.color;
}

RayTracer::Plane RayTracer::Plane::operator=(const RayTracer::Plane& og)
{
    return *this;
}

bool RayTracer::Plane::hits(RayTracer::Ray& ray)
{
    Math::Vector3D d = ray.direction;
    double tmpDot = this->normal.dot(d);
    if (tmpDot == 0)
        return false;
    Math::Vector3D tmp_v = this->center - ray.origin;
    double tmp = tmp_v.dot(this->normal) / tmpDot;
    if (tmp > 0.0001) {
        return true;
    }
    return false;
}

RayTracer::Plane::~Plane() {}

const RayTracer::Color RayTracer::Plane::getColor() const
{
    return this->color;
}

Math::Point3D RayTracer::Plane::hitPoint(RayTracer::Ray& ray)
{
    Math::Vector3D d = ray.direction;
    double tmpDot = this->normal.dot(d);
    Math::Vector3D tmp_v = this->center - ray.origin;
    double tmp = tmp_v.dot(this->normal) / tmpDot;
    return (ray.origin + ray.getDirection() * tmp);
}

Math::Vector3D RayTracer::Plane::getNormal(Math::Point3D point)
{
    Math::Vector3D tmp(this->normal.X - point.X, this->normal.Y - point.Y, this->normal.Z - point.Z);
    double tmpDot = tmp.dot(tmp);
    if (tmpDot != 0) {
        tmp.normalize();
    }
    return tmp;
}

void RayTracer::Plane::setParams(const std::vector<double> params) {
    this->normal.X = params[0];
    this->normal.Y = params[1];
    this->normal.Z = params[2];
    this->center.X = params[3];
    this->center.Y = params[4];
    this->center.Z = params[5];
    this->color.setRColor(params[6]);
    this->color.setGColor(params[7]);
    this->color.setBColor(params[8]);
}

double RayTracer::Plane::racine(RayTracer::Ray& ray)
{
    Math::Vector3D origin(ray.origin.X - this->center.X, ray.origin.Y - this->center.Y, ray.origin.Z - this->center.Z);
    Math::Vector3D d(ray.direction.X - ray.origin.X, ray.direction.Y - ray.origin.Y, ray.direction.Z - ray.origin.Z);
    double calc_a = d.dot(d);
    double calc_b = 2 * origin.dot(d);
    double calc_c = origin.dot(origin);
    double det = pow(calc_b, 2) - 4 * calc_a * calc_c;
    if (det == 0)
        return (-calc_b / 2 * calc_a);
    double racine_1 = (-calc_b - sqrt(det)) / 2 * calc_a;
    double racine_2 = (-calc_b + sqrt(det)) / 2 * calc_a;
    return ((racine_1 < racine_2 ? racine_1 : racine_2));
}

extern "C" {
std::unique_ptr<RayTracer::IPrimitive> entryPoint()
{
    return std::make_unique<RayTracer::Plane>();
}

bool isPrim()
{
    return true;
}

std::string getName()
{
    return "plane";
}
}
