#pragma once
#include "../Scene/Scene.hpp"
#include "../Primitives/Factory.hpp"
#include "../DLLoader.hpp"
#include <vector>

namespace RayTracer {
    // class SceneBuilder : public ISceneBuilder {
    class SceneBuilder {

    public:
        SceneBuilder();
        ~SceneBuilder() {};
        void addOnFactoryMap(std::string tmp);
        void setCamera(const Camera &camera);
        void addPrimitive(const std::string &PrimType, const std::vector<double> &params);
        void addLight(const std::string &LightType, const std::vector<double> &params);
        RayTracer::Scene buildScene();
        RayTracer::Factory _factory;

    private:
        Scene scene;
        Camera _camera;
        std::vector<std::unique_ptr<DLLoader>> dl_vector;
        std::vector<std::shared_ptr<IPrimitive>> _primitives;
        std::vector<std::shared_ptr<RayTracer::ILights>> _lights;
    };
}
