#include <memory>
#include <vector>
#include <string>
#include "ofMain.h"  
#include "Model.h"

class EarModel : public Model{
public:
    
    std::shared_ptr<EarModel> pairedModel; 
    std::vector<ofVec3f> presetPositions; 
    std::vector<ofVec3f> pairedPresetPositions; 

    EarModel(std::string type) : Model(type) {}


    void EarModel::setPresetPositions(const std::vector<ofVec3f>& positions) {
        presetPositions = positions;
    }

    void EarModel::setPairedPresetPositions(const std::vector<ofVec3f>& positions) {
        pairedPresetPositions = positions;
    }

    void EarModel::setPairedModel(std::shared_ptr<EarModel> model) {
        pairedModel = model;
    }   

    void EarModel::updatePosition(int index, bool altPressed) {
        if (index >= 0 && index < presetPositions.size() && !altPressed) {
            setPosition(presetPositions[index]);
            ofLogNotice() << "setposition";
            if (pairedModel && index < pairedPresetPositions.size()) {
                pairedModel->setPosition(pairedPresetPositions[index]);
                ofLogNotice() << "setposition2";

            }
        }
    }

    ofxAssimpModelLoader modelLoader;   

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
