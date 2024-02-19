#pragma once
#include "Model.h"


class CubeModel : public Model {
public:
    
    CubeModel::CubeModel();
    void CubeModel::setupCube();
    void draw() const override;
    
};
