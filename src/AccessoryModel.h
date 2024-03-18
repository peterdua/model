#pragma once
#include "Model.h"

class AccessoryModel : public Model {
public:
    AccessoryModel() {}
    virtual ~AccessoryModel() {}
    AccessoryModel(std::string type) : Model(type) {}

    ofxAssimpModelLoader modelLoader;
    const int minInternalVertices = 10;
    const int maxInternalVertices = 200;

    bool loadModel(const std::string& filepath) {
        modelLoader.setScaleNormalization(false);
        bool loaded = modelLoader.loadModel(filepath);
        return loaded;
    }
    ofVec3f getSceneCenter() {
        return modelLoader.getSceneCenter();
    }
    void adMeshes();
    void draw() const;


};

