// AssimpModel.h
#ifndef ASSIMPMODEL_H
#define ASSIMPMODEL_H

#include "Model.h"

class AssimpModel : public Model {
public:
    AssimpModel() {}
    virtual ~AssimpModel() {}   
    AssimpModel(std::string type) : Model(type) {}


    ofxAssimpModelLoader modelLoader;

    bool loadModel(const std::string& filepath) {
        modelLoader.setScaleNormalization(false);
        bool loaded = modelLoader.loadModel(filepath);     

        return loaded;
    }

    ofVec3f getSceneCenter()  {
        return modelLoader.getSceneCenter();
    }    


    
    void adMeshes();

    void draw() const;

};

#endif // ASSIMPMODEL_H
