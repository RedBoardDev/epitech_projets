/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include "../Errors/Critical.hpp"


RayTracer::Parser::Parser(std::string file_path)
{
    this->filename = file_path;
    try {
        try {
            this->cfg.readFile(this->filename.c_str());
        }
        catch(const libconfig::FileIOException &fioex)
        {
            throw Critical("I/O error while reading file (" + this->filename + ").");
        }
        catch(const libconfig::ParseException &pex)
        {
            throw Critical("Parse error at " + std::to_string(pex.getLine()) + ": " + pex.getError());
        }
    } catch(const std::exception &err) {
        std::cout << err.what() << std::endl;
        exit(84);
    }
}

void RayTracer::Parser::parse_all(SceneBuilder &builder)
{
    try {
        ParseCamera(builder);
        parsePrimitives(builder);
        parseLights(builder);
    } catch(const std::exception &err) {
        std::cout << err.what() << std::endl;
        exit(84);
    }
}
