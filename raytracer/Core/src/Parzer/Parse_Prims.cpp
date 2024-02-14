/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Parse_Prims
*/

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include "../Errors/Warning.hpp"

void RayTracer::Parser::parsePrimitive_plane(SceneBuilder &builder, libconfig::Setting &prims)
{
    try {
        libconfig::Setting &planes = prims["planes"];
        planes.getLength();
    } catch (const std::exception& e) {
        Warning("No planes found.");
        return;
    }
    libconfig::Setting &planes = prims["planes"];
    if (planes.getLength() > 0) {
        for (auto it = planes.begin(); it != planes.end(); ++it) {
            const libconfig::Setting &plane = *it;
            libconfig::Setting &origin = plane["position"];
            double x;
            origin.lookupValue("x", x);
            double y;
            origin.lookupValue("y", y);
            double z;
            origin.lookupValue("z", z);
            libconfig::Setting &normal = plane["normal"];
            double xn;
            normal.lookupValue("x", xn);
            double yn;
            normal.lookupValue("y", yn);
            double zn;
            normal.lookupValue("z", zn);
            libconfig::Setting &color = plane["color"];
            double r;
            color.lookupValue("r", r);
            double g;
            color.lookupValue("g", g);
            double b;
            color.lookupValue("b", b);

            // with builder
            try {
                builder.addPrimitive("plane", {xn, yn, zn, x, y, z, r, g, b});
            } catch(const std::exception &err) {
                std::cout << err.what() << std::endl;
                exit(84);
            }
        }
    }
}

void RayTracer::Parser::parsePrimitive_sphere(SceneBuilder &builder, libconfig::Setting &prims)
{
    try {
        libconfig::Setting &spheres = prims["spheres"];
        spheres.getLength();
    } catch (const std::exception& e) {
        Warning("No spheres found.");
        return;
    }
    libconfig::Setting &spheres = prims["spheres"];
    if (spheres.getLength() > 0) {
        for (auto it = spheres.begin(); it != spheres.end(); ++it) {
            const libconfig::Setting &sphere = *it;
            double radius;
            sphere.lookupValue("r", radius);
            double x;
            sphere.lookupValue("x", x);
            double y;
            sphere.lookupValue("y", y);
            double z;
            sphere.lookupValue("z", z);
            libconfig::Setting &color = sphere["color"];
            double r;
            color.lookupValue("r", r);
            double g;
            color.lookupValue("g", g);
            double b;
            color.lookupValue("b", b);
            libconfig::Setting &translation = sphere["translation"];
            double tx;
            translation.lookupValue("x", tx);
            double ty;
            translation.lookupValue("y", ty);
            double tz;
            translation.lookupValue("z", tz);

            // with builder
            try {
                builder.addPrimitive("sphere", {radius, x, y, z, r, g, b, tx, ty, tz});
            } catch(const std::exception &err) {
                std::cout << err.what() << std::endl;
                exit(84);
            }
        }
    }
}

void RayTracer::Parser::parsePrimitive_cylinder(SceneBuilder &builder, libconfig::Setting &prims)
{
    try {
        libconfig::Setting &cylinders = prims["cylinders"];
        cylinders.getLength();
    } catch (const std::exception& e) {
        Warning("No cynlinder found.");
        return;
    }
    libconfig::Setting &cylinders = prims["cylinders"];
    if (cylinders.getLength() > 0) {
        for (auto it = cylinders.begin(); it != cylinders.end(); ++it) {
            const libconfig::Setting &cylinder = *it;
            double radius;
            cylinder.lookupValue("r", radius);
            double x;
            cylinder.lookupValue("x", x);
            double y;
            cylinder.lookupValue("y", y);
            double z;
            cylinder.lookupValue("z", z);
            libconfig::Setting &color = cylinder["color"];
            double r;
            color.lookupValue("r", r);
            double g;
            color.lookupValue("g", g);
            double b;
            color.lookupValue("b", b);

            // with builder
            try {
                builder.addPrimitive("cylinder", {radius, x, y, z, r, g, b});
            } catch(const std::exception &err) {
                std::cout << err.what() << std::endl;
                exit(84);
            }
        }
    }
}


void RayTracer::Parser::parsePrimitives(SceneBuilder &builder)
{
    libconfig::Setting &scene = cfg.getRoot()["scene"];
    try {
        scene["primitives"];
    } catch (const std::exception& e) {
        throw Warning("No primitives found.");
    }
    parsePrimitive_sphere(builder, scene["primitives"]);
    parsePrimitive_plane(builder, scene["primitives"]); // pourquoi si on a pas de plane y'a une erreur ???
    parsePrimitive_cylinder(builder, scene["primitives"]);
}
