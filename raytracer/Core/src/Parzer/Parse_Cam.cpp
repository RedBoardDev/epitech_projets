/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Parse_Cam
*/

#include "Parser.hpp"
#include <iostream>
#include "../Errors/Critical.hpp"
#include <fstream>

void RayTracer::Parser::checkCamera(void)
{
    try {
        cfg.getRoot()["scene"];
    } catch (const std::exception& e) {
        throw Critical("No scene in config file.");
    }
    libconfig::Setting &scene = cfg.getRoot()["scene"];
    try {
        scene["camera"];
    } catch (const std::exception& e) {
        throw Critical("No camera in scene.");
        exit(1);
    }
    try {
        scene["camera"]["position"];
        scene["camera"]["rotation"];
        scene["camera"]["resolution"];
        scene["camera"]["fieldOfView"];
    } catch (const std::exception& e) {
        throw Critical("Incomplete / Missing camera parameters.");
        exit(1);
    }
}

void RayTracer::Parser::ParseCamera(SceneBuilder &builder)
{
    this->checkCamera();
    cfg.getRoot()["scene"]["camera"];
    libconfig::Setting &cam = cfg.getRoot()["scene"]["camera"];

    libconfig::Setting &pos = cam["position"];
    double x = pos["x"];
    double y = pos["y"];
    double z = pos["z"];

    libconfig::Setting &rot = cam["rotation"];
    double rx = rot["x"];
    double ry = rot["y"];
    double rz = rot["z"];

    libconfig::Setting &res = cam["resolution"];
    double width = res["width"];
    double height = res["height"];
    double fov = cam["fieldOfView"];

    // with builder
    RayTracer::Camera camera;
    camera.origin.X = x;
    camera.origin.Y = y;
    camera.origin.Z = z;
    camera.rotation.X = rx;
    camera.rotation.Y = ry;
    camera.rotation.Z = rz;
    camera.screen.width = width;
    camera.screen.height = height;
    camera.screen.origin = Math::Point3D(-width / 20, -height / 20, 0);
    camera.screen.bottom_side = Math::Vector3D(width / 10, 0, 0);
    camera.screen.left_side = Math::Vector3D(0, height / 10, 0);
    camera.fieldOfView = fov;
    builder.setCamera(camera);
}
