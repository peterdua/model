#pragma once
#include "Model.h"


class CubeModel : public Model {
public:    
    
    CubeModel::CubeModel();    
    void draw() const override;

    void setSize(float size) override {
        cubeSize = size;
        setupCube(); 
    }

private:
    float cubeSize;
    void setupCube(); 
};
