#pragma once
#include "ofMain.h"
#include "Model.h"

class KeyHandler {


public:
    void handleKeyPress(std::shared_ptr<Model>& selectedModel, int key, std::vector<std::shared_ptr<Model>> models, std::shared_ptr<Model>& mainModel, bool spr, bool sphere, ofVec3f& pos2);

	float calculateNewPosition(float currentPos, float moveStep, float minPos);

	float calculateNewPositionplus(float currentPos, float moveStep, float maxPos);
	
		
};
