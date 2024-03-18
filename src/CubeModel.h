#pragma once
#include "Model.h"


class CubeModel : public Model {
public:    
    
    CubeModel::CubeModel();    
    CubeModel(std::string type) : Model(type) {}
    void draw() const override;


    void setSize(float size) override {
        cubeSize = size;
        setupCube(); 
    }

private:
    float cubeSize;
    void setupCube(); 
};
