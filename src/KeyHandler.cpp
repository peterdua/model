#include "KeyHandler.h"

void KeyHandler::handleKeyPress(std::shared_ptr<Model>& selectedModel, int key, std::vector<std::shared_ptr<Model>> models, std::shared_ptr<Model>& mainModel, bool spr, bool sphere, ofVec3f& pos2) {
    //if (!selectedModel) return; // 如果没有选定的模型，直接返回

    float moveStep = 1.0;
    ofVec3f pos = selectedModel->getPosition();      
    float minPosX = -30.0;
    float maxPosX = 30.0;
    float ear = 10;
    
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
                    minPosX = -33;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 29; 
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = -10; 
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -10; 
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
                    maxPosX = 32; 
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 10; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 10; 
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
                    maxPosX = 4;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 4; 
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25; 
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -25; 
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
                    minPosX = -8;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = -8;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 22;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -28; 
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
                    minPosX = -33;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 29;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = -10;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -10;
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
                    maxPosX = 32;
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 10;
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 10;
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
                    maxPosX = 4;
                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 4;
                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 25;
                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -25;
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
                    minPosX = -8;
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = -8;
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 22;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -28;
                }
            }
            pos.y = calculateNewPosition(pos.y, moveStep, minPosX);
            break;
        }
        }
        else if (modelType == "leftcatear") {
            float moveStep = 0.5f;
            switch (key) {
            case OF_KEY_LEFT:
                if (spr) {
                    if (selectedModel->getDirection() == "left") {
                        minPosX = -30;
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
                        minPosX = -28.5;
                        ear = -28.5; 
                        pos2.x = calculateNewPosition(pos2.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "right") {
                        minPosX = 22;                      
                        ear = 22;
                        pos2.x = calculateNewPosition(pos2.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "up") {
                        minPosX = -21;                        
                        ear = 21;
                        pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "down") {
                        minPosX = 8;                      
                        ear = -8;
                        pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);

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
                        maxPosX = -23;
                        ear = -23;
                        pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);


                    }
                    else if (selectedModel->getDirection() == "right") {
                        maxPosX = 27;
                        ear = 27;
                        pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        maxPosX = -12;
                        ear = 10.5;
                        pos2.x = calculateNewPosition(pos2.x, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        maxPosX = 21;
                        ear = -21;                     
                        pos2.x = calculateNewPosition(pos2.x, moveStep, ear);

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
                        maxPosX = -2;
                        
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
                        maxPosX = -8;
                        ear = 8;
                        pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "right") {
                        maxPosX = 13;
                        ear = -15;
                        
                        pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        maxPosX = 20.5;
                        ear = 20.5;
                        pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        maxPosX = -19;
                        ear = -19;
                        pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                    }
                }
                pos.y = calculateNewPositionplus(pos.y, moveStep, maxPosX);
                break;
            case OF_KEY_DOWN:
                if (spr) {
                    if (selectedModel->getDirection() == "left") {
                        minPosX = -16;

                    }
                    else if (selectedModel->getDirection() == "right") {
                        minPosX = -16;
                    }
                    else if (selectedModel->getDirection() == "up") {
                        minPosX = 16;
                    }
                    else if (selectedModel->getDirection() == "down") {
                        minPosX = -23;
                    }
                }
                else if (sphere) {
                    if (selectedModel->getDirection() == "left") {
                        minPosX = -13;
                        ear = 13;
                        pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "right") {
                        minPosX = 6;
                        ear = -8;                        
                        pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        minPosX = 20;
                        ear = 20;
                        pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        minPosX = -24;
                        ear = -24;
                        pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

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