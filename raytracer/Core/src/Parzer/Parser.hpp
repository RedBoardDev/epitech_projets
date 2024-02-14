#pragma once

#include "../Primitives/Factory.hpp"
#include "../Scene/Scene.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <libconfig.h++>
#include <memory>
#include "../builder/SceneBuilder.hpp"

namespace RayTracer {
    class Parser {
    public:
        Parser(std::string filename);
        ~Parser() {};
        void parse_all(SceneBuilder &builder);
        RayTracer::Factory p_factory;

    private:
        void checkCamera();
        void ParseCamera(SceneBuilder &builder);
        void parsePrimitives(SceneBuilder &builder);
        void parsePrimitive_sphere(SceneBuilder &builder, libconfig::Setting &prims);
        void parsePrimitive_plane(SceneBuilder &builder, libconfig::Setting &prims);
        void parsePrimitive_cylinder(SceneBuilder &builder, libconfig::Setting &prims);
        void parseLights(SceneBuilder &builder);
        void parseLight_directional(SceneBuilder &builder, libconfig::Setting& lights);
        libconfig::Config cfg;
        std::string filename;
    };
}
