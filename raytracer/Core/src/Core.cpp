/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-leo.baldachino
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(std::string path, std::string sce) : parse(sce)
{
    std::string tmp;
    try {
    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
        throw Error("Wrong directory.");
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
        exit(84);
    }
    RayTracer::SceneBuilder builder;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        tmp = entry.path();
        if (tmp.substr(tmp.find_last_of(".") + 1) == "so") {
            this->dl_vector.push_back(std::make_unique<DLLoader>(tmp));
            bool (*f)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<bool ()>("isPrim");
            std::string (*f1)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::string ()>("getName");
            if (f()) {
                std::unique_ptr<RayTracer::IPrimitive> (*f2)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::unique_ptr<RayTracer::IPrimitive>()>(std::string("entryPoint"));
                this->parse.p_factory.primitiveMap[f1()] = f2;
            } else {
                std::unique_ptr<RayTracer::ILights> (*f2)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::unique_ptr<RayTracer::ILights>()>(std::string("entryPoint"));
                this->parse.p_factory.lightMap[f1()] = f2;
            }
            builder.addOnFactoryMap(tmp);
        }
    }
    this->parse.parse_all(builder);
    this->_scene = builder.buildScene();
}

Core::~Core()
{
}

void Core::render(void)
{
    RayTracer::Scene finalScene = this->_scene;

    int width = finalScene.camera.screen.width;
    int height = finalScene.camera.screen.height;
    int tmp_i;
    int tmp_distance;
    // Directional d(Math::Point3D(200, 200, 90), Math::Vector3D(2, 3, 1)); // to change
    std::cout << "P3" << std::endl << width << " " << height << std::endl
    << "255" << std::endl;

    for (double y = 0; y < width; ++y) {
        for (double x = 0; x < height; ++x) {
            double u = y / width;
            double v = x / height;
            tmp_i = -1;
            tmp_distance = -1;
            Math::Point3D tmp_hitPoint;
            RayTracer::Ray r = finalScene.camera.ray(u, v);
            std::vector<double> tmp_light_color = {0, 0, 0};
            for (size_t i = 0; i < finalScene.primitives.size(); i++) {
                if (finalScene.primitives[i]->hits(r)) {
                    Math::Point3D hitPoint = finalScene.primitives[i]->hitPoint(r);
                    if (tmp_distance == -1 ||
                    finalScene.primitives[i]->racine(r) < tmp_distance) {
                        tmp_distance = finalScene.primitives[i]->racine(r);
                        tmp_i = i;
                        tmp_hitPoint = hitPoint;
                    }
                }
            }
            std::vector<double> tmp_li;
            if (tmp_i != -1) {
                for (size_t i = 0; i < finalScene.lights.size(); i++) {
                    tmp_li = finalScene.lights[i]->cast(*finalScene.primitives[tmp_i].get(), tmp_hitPoint);
                    if (tmp_li[0] > tmp_light_color[0])
                        tmp_light_color[0] = tmp_li[0];
                    if (tmp_li[1] > tmp_light_color[1])
                        tmp_light_color[1] = tmp_li[1];
                    if (tmp_li[2] > tmp_light_color[2])
                        tmp_light_color[2] = tmp_li[2];
                }
            }
            std::cout << tmp_light_color[0] << " " << tmp_light_color[1] << " " << tmp_light_color[2] << std::endl;
        }
    }
}
