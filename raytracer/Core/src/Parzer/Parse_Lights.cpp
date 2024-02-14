/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Parse_Lights
*/

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include "../Errors/Warning.hpp"

void RayTracer::Parser::parseLight_directional(SceneBuilder &builder, libconfig::Setting& lights)
{
    libconfig::Setting &directs = lights["directional"];
    if (directs.getLength() > 0) {
        for (auto it = directs.begin(); it != directs.end(); ++it) {
            const libconfig::Setting &dire = *it;
            double x;
            dire.lookupValue("x", x);
            double y;
            dire.lookupValue("y", y);
            double z;
            dire.lookupValue("z", z);
            libconfig::Setting &direction = dire["direction"];
            double dx;
            direction.lookupValue("x", dx);
            double dy;
            direction.lookupValue("y", dy);
            double dz;
            direction.lookupValue("z", dz);

            // with builder
            try {
                builder.addLight("directional", {x, y, z, dx, dy, dz});
            } catch(const std::exception &err) {
                std::cout << err.what() << std::endl;
                exit(84);
            }
        }
    }
}

void RayTracer::Parser::parseLights(SceneBuilder &builder)
{
    libconfig::Setting& scene = cfg.getRoot()["scene"];
    try {
        libconfig::Setting &lights = scene["lights"];
        lights.getLength();
    } catch (const std::exception& e) {
        throw Warning("No lights found.");
    }
    // parseLight_ambient(scene["lights"]);
    // parseLight_diffuse(scene['lights']);
    parseLight_directional(builder, scene["lights"]);
    double ambient;
    scene["lights"].lookupValue("ambient", ambient);
    try {
        builder.addLight("ambient", {ambient});
    } catch(const std::exception &err) {
        std::cout << err.what() << std::endl;
        exit(84);
    }
}
