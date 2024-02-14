/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Core
*/

#pragma once

#include <filesystem>
#include <vector>
#include "Errors/Log.hpp"
#include "Primitives/Factory.hpp"
#include "Errors/Error.hpp"
#include "Parzer/Parser.hpp"
#include "DLLoader.hpp"
#include "Point3D.hpp"

class Core {
    public:
        Core(std::string path, std::string sce);
        ~Core();
        void render(void);
        std::vector<std::unique_ptr<DLLoader>> dl_vector;
        RayTracer::Parser parse;
        RayTracer::Scene _scene;
        std::vector<std::string> plugins_path;
};
