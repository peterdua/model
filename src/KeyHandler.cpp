#include "KeyHandler.h"

void KeyHandler::handleKeyPress(std::shared_ptr<Model>& selectedModel, int key, std::vector<std::shared_ptr<Model>> models, std::shared_ptr<Model>& mainModel, bool spr, bool sphere) {
    //if (!selectedModel) return; // 如果没有选定的模型，直接返回

    float moveStep = 1.0;
    ofVec3f pos = selectedModel->getPosition();    
    float minPosX = -30.0;
    float maxPosX = 30.0;
    float newPos;
    std::string modelType = selectedModel->getType();
    ofLogNotice() << "type:" << modelType;

    if (modelType == "cube") {
        switch (key) {
        case OF_KEY_LEFT:
            pos.x -= moveStep;
            break;
        case OF_KEY_RIGHT:
            pos.x += moveStep;
            break;
        case OF_KEY_UP:
            pos.y += moveStep;
            break;
        case OF_KEY_DOWN:
            pos.y -= moveStep;
            break;
        }       
    }
    else if (modelType == "loop") {
        float moveStep = 0.5f; 
        switch (key) {
        case OF_KEY_LEFT:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -26.5;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 24;
                }
                else { 
                    minPosX = -10;
                }
            }
            else if (sphere) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 25; 
                }
            }
            pos.x = calculateNewPosition(pos.x, moveStep, minPosX);           
            break;

        case OF_KEY_RIGHT:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -23.0;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 27.5;
                }
                else { 
                    maxPosX = 10;
                }
            }
            else if (sphere) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 25; 
                }
            }
            pos.x = calculateNewPositionplus(pos.x, moveStep, maxPosX);
            break;

        case OF_KEY_UP:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = 10;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 10;
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 31; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -28; 
                }
            }
            else if (sphere) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 25; 
                }
            }
            pos.y = calculateNewPositionplus(pos.y, moveStep, maxPosX);
            break;
        case OF_KEY_DOWN:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -10;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = -10;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 28;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -31;
                }
            }
            else if (sphere) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 30;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 25;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 25; 
                }
            }
            pos.y = calculateNewPosition(pos.y, moveStep, minPosX);
            break;
        }
    }
    else if (modelType == "rabear") {
        float moveStep = 0.5f;
        switch (key) {
        case OF_KEY_LEFT:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -26.5;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 24;
                }
                else { 
                    minPosX = -10;
                }
            }
            else if (sphere) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 25; 
                }
            }
            pos.x = calculateNewPosition(pos.x, moveStep, minPosX);
            break;

        case OF_KEY_RIGHT:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -23.0;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 27.5;
                }
                else { 
                    maxPosX = 10;
                }
            }
            else if (sphere) {
                
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 25;
                }
            }
            pos.x = calculateNewPositionplus(pos.x, moveStep, maxPosX);
            break;

        case OF_KEY_UP:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    maxPosX = 10;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 10;
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 31; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -28;
                }
            }
            else if (sphere) {
               
                if (selectedModel->getDirection() == "left") {
                    maxPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 30;
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 25; 
                }
            }
            pos.y = calculateNewPositionplus(pos.y, moveStep, maxPosX);
            break;
        case OF_KEY_DOWN:
            if (spr) {
                if (selectedModel->getDirection() == "left") {
                    minPosX = -10;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = -10;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 28; 
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -31; 
                }
            }
            else if (sphere) {
                
                if (selectedModel->getDirection() == "left") {
                    minPosX = -30;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 30; 
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 25; 
                }
            }
            pos.y = calculateNewPosition(pos.y, moveStep, minPosX);
            break;
        }
        }

    selectedModel->setPosition(pos); 
}

float KeyHandler::calculateNewPosition(float currentPos, float moveStep, float minPos) {
    float newPos = currentPos - moveStep;
    return std::max(newPos, minPos); 
}

float KeyHandler::calculateNewPositionplus(float currentPos, float moveStep, float maxPos) {
    float newPos = currentPos + moveStep;
    return std::min(newPos, maxPos); 
}