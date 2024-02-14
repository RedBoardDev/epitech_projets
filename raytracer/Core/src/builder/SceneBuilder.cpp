#include "SceneBuilder.hpp"
#include "../Errors/Warning.hpp"
#include "../Errors/Critical.hpp"

RayTracer::SceneBuilder::SceneBuilder() {}

void RayTracer::SceneBuilder::setCamera(const Camera &camera) {
    this->_camera = camera;
}

void RayTracer::SceneBuilder::addPrimitive(const std::string &PrimType, const std::vector<double> &params) {
    this->_primitives.push_back(this->_factory.createPrimitive(PrimType));
    this->_primitives[this->_primitives.size() - 1]->setParams(params);
}

void RayTracer::SceneBuilder::addLight(const std::string& LightType, const std::vector<double> &params) {
    this->_lights.push_back(this->_factory.createLight(LightType));
    this->_lights[this->_lights.size() - 1]->setParams(params);
}

RayTracer::Scene RayTracer::SceneBuilder::buildScene() {
    Scene sc = Scene();
    sc.camera = this->_camera;
    sc.primitives = this->_primitives;
    sc.lights = this->_lights;
    return sc;
}

void RayTracer::SceneBuilder::addOnFactoryMap(std::string tmp) {
    this->dl_vector.push_back(std::make_unique<DLLoader>(tmp));
    bool (*f)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<bool ()>("isPrim");
    std::string (*f1)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::string ()>("getName");
    if (f()) {
        std::unique_ptr<RayTracer::IPrimitive> (*f2)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::unique_ptr<RayTracer::IPrimitive>()>(std::string("entryPoint"));
        this->_factory.primitiveMap[f1()] = f2;
    } else {
        std::unique_ptr<RayTracer::ILights> (*f2)() = this->dl_vector[this->dl_vector.size() - 1]->getInstance<std::unique_ptr<RayTracer::ILights>()>(std::string("entryPoint"));
        this->_factory.lightMap[f1()] = f2;
    }
}
