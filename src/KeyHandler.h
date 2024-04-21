#pragma once
#include "ofMain.h"
#include "Model.h"

class KeyHandler {


public:
    void handleKeyPress(std::shared_ptr<Model>& selectedModel, int key, std::vector<std::shared_ptr<Model>> models, std::shared_ptr<Model>& mainModel, bool spr, bool sphere, ofVec3f& pos2, ofVec3f& pos, ofVec3f& pos4, ofVec3f& pos5, ofVec3f& pos6, ofVec3f& pos7, ofVec3f& pos8, ofVec3f& pos9, ofVec3f& pos10, ofVec3f& pos11, ofVec3f& pos12, ofVec3f& pos13, ofVec3f& pos14, ofVec3f& pos15);

	float calculateNewPosition(float currentPos, float moveStep, float minPos);

	float calculateNewPositionplus(float currentPos, float moveStep, float maxPos);
	
		
};
