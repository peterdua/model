#include "KeyHandler.h"

void KeyHandler::handleKeyPress(std::shared_ptr<Model>& selectedModel, int key, std::vector<std::shared_ptr<Model>> models, std::shared_ptr<Model>& mainModel, bool spr, bool sphere, ofVec3f& pos2, ofVec3f& pos, ofVec3f& pos4, ofVec3f& pos5, ofVec3f& pos6, ofVec3f& pos7, ofVec3f& pos8, ofVec3f& pos9, ofVec3f& pos10, ofVec3f& pos11, ofVec3f& pos12, ofVec3f& pos13, ofVec3f& pos14, ofVec3f& pos15) {
    if (!selectedModel) return; // 如果没有选定的模型，直接返回

    float moveStep = 1.0;
    float minPosX = -30.0;
    float maxPosX = 30.0;
    float ear = 10;
    ofVec3f pos3 = selectedModel->getPosition();
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
        selectedModel->setPosition(pos);

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
            pos3.x = calculateNewPositionplus(pos3.x, moveStep, minPosX);
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
            pos3.x = calculateNewPosition(pos3.x, moveStep, maxPosX);
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
            pos3.y = calculateNewPosition(pos3.y, moveStep, maxPosX);
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
                    minPosX = 24;
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -28;
                }
            }
            pos3.y = calculateNewPositionplus(pos3.y, moveStep, minPosX);
            break;
        }
        selectedModel->setPosition(pos3);
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
            pos3.x = calculateNewPositionplus(pos3.x, moveStep, minPosX);
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
            pos3.x = calculateNewPosition(pos3.x, moveStep, maxPosX);
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
            pos3.y = calculateNewPosition(pos3.y, moveStep, maxPosX);
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
            pos3.y = calculateNewPositionplus(pos3.y, moveStep, minPosX);
            break;
        }
        selectedModel->setPosition(pos3);
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
                    pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 22;
                    ear = 22;
                    pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = -21;
                    ear = 19.5;
                    pos2.x = calculateNewPosition(pos2.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 8;
                    ear = -8;
                    pos2.x = calculateNewPosition(pos2.x, moveStep, ear);

                }
            }
            pos.x = calculateNewPositionplus(pos.x, moveStep, minPosX);

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
                    pos2.x = calculateNewPosition(pos2.x, moveStep, ear);


                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 27;
                    ear = 27;
                    pos2.x = calculateNewPosition(pos2.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = -12;
                    ear = 10.5;
                    pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 21;
                    ear = -21;
                    pos2.x = calculateNewPositionplus(pos2.x, moveStep, ear);

                }
            }
            pos.x = calculateNewPosition(pos.x, moveStep, maxPosX);
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
                    pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 13;
                    ear = -15;

                    pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 20.5;
                    ear = 20.5;
                    pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -19;
                    ear = -19;
                    pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                }
            }
            pos.y = calculateNewPosition(pos.y, moveStep, maxPosX);
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
                    pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 6;
                    ear = -8;
                    pos2.y = calculateNewPosition(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 20;
                    ear = 20;
                    pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -24;
                    ear = -24;
                    pos2.y = calculateNewPositionplus(pos2.y, moveStep, ear);

                }
            }
            pos.y = calculateNewPositionplus(pos.y, moveStep, minPosX);
            break;
        }
        selectedModel->setPosition(pos);

    }
    else if (modelType == "rightcatear") {
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
                    pos.x = calculateNewPositionplus(pos.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 22;
                    ear = 22;
                    pos.x = calculateNewPositionplus(pos.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 10.5;
                    ear = -12;
                    pos.x = calculateNewPosition(pos.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -21;
                    ear = 21;
                    pos.x = calculateNewPosition(pos.x, moveStep, ear);

                }
            }
            pos2.x = calculateNewPositionplus(pos2.x, moveStep, minPosX);

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
                    pos.x = calculateNewPosition(pos.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 27;
                    ear = 27;
                    pos.x = calculateNewPosition(pos.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 19.5;
                    ear = -21;
                    pos.x = calculateNewPositionplus(pos.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -8;
                    ear = 8;
                    pos.x = calculateNewPositionplus(pos.x, moveStep, ear);

                }
            }
            pos2.x = calculateNewPosition(pos2.x, moveStep, maxPosX);
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
                    maxPosX = 13;
                    ear = -13;
                    pos.y = calculateNewPositionplus(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = -8;
                    ear = 6;

                    pos.y = calculateNewPositionplus(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 20.5;
                    ear = 20.5;
                    pos.y = calculateNewPosition(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -19;
                    ear = -19;
                    pos.y = calculateNewPosition(pos.y, moveStep, ear);

                }
            }
            pos2.y = calculateNewPosition(pos2.y, moveStep, maxPosX);
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
                    minPosX = 8;
                    ear = -8;
                    pos.y = calculateNewPosition(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = -15;
                    ear = 13;
                    pos.y = calculateNewPosition(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 20;
                    ear = 20;
                    pos.y = calculateNewPositionplus(pos.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -24;
                    ear = -24;
                    pos.y = calculateNewPositionplus(pos.y, moveStep, ear);

                }
            }
            pos2.y = calculateNewPositionplus(pos2.y, moveStep, minPosX);
            break;
        }
        selectedModel->setPosition(pos2);

    }
    else if (modelType == "catfootl") {
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
                    minPosX = -29.5;
                    ear = -29.5;
                    pos4.x = calculateNewPositionplus(pos4.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 25;
                    ear = 25;
                    pos4.x = calculateNewPositionplus(pos4.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = -15;
                    ear = 13.5;
                    pos4.x = calculateNewPosition(pos4.x, moveStep, ear);
                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = 6;
                    ear = -6;
                    pos4.x = calculateNewPosition(pos4.x, moveStep, ear);

                }
            }
            pos5.x = calculateNewPositionplus(pos5.x, moveStep, minPosX);

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
                    maxPosX = -25;
                    ear = -25;
                    pos4.x = calculateNewPosition(pos4.x, moveStep, ear);


                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 29;
                    ear = 29;
                    pos4.x = calculateNewPosition(pos4.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = -10;
                    ear = 8.5;
                    pos4.x = calculateNewPositionplus(pos4.x, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = 15;
                    ear = -15;
                    pos4.x = calculateNewPositionplus(pos4.x, moveStep, ear);

                }
            }
            pos5.x = calculateNewPosition(pos5.x, moveStep, maxPosX);
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
                    ear = 4;
                    pos4.y = calculateNewPositionplus(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    maxPosX = 11;
                    ear = -15;

                    pos4.y = calculateNewPositionplus(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    maxPosX = 24;
                    ear = 24;
                    pos4.y = calculateNewPosition(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    maxPosX = -24.5;
                    ear = -24.5;
                    pos4.y = calculateNewPosition(pos4.y, moveStep, ear);

                }
            }
            pos5.y = calculateNewPosition(pos5.y, moveStep, maxPosX);
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
                    minPosX = -15;
                    ear = 11;
                    pos4.y = calculateNewPosition(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "right") {
                    minPosX = 4;
                    ear = -8;
                    pos4.y = calculateNewPosition(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "up") {
                    minPosX = 23.5;
                    ear = 23.5;
                    pos4.y = calculateNewPositionplus(pos4.y, moveStep, ear);

                }
                else if (selectedModel->getDirection() == "down") {
                    minPosX = -26;
                    ear = -26;
                    pos4.y = calculateNewPositionplus(pos4.y, moveStep, ear);

                }
            }
            pos5.y = calculateNewPositionplus(pos5.y, moveStep, minPosX);
            break;
        }
        selectedModel->setPosition(pos5);
        ofLogNotice() << "select pos5";

        }
    else if (modelType == "catfootr") {
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
                        minPosX = -29.5;
                        ear = -29.5;
                        pos5.x = calculateNewPositionplus(pos5.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "right") {
                        minPosX = 25;
                        ear = 25;
                        pos5.x = calculateNewPositionplus(pos5.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "up") {
                        minPosX = 8.5;
                        ear = -10;
                        pos5.x = calculateNewPosition(pos5.x, moveStep, ear);
                    }
                    else if (selectedModel->getDirection() == "down") {
                        minPosX = -15;
                        ear = 15;
                        pos5.x = calculateNewPosition(pos5.x, moveStep, ear);

                    }
                }
                pos4.x = calculateNewPositionplus(pos4.x, moveStep, minPosX);

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
                        maxPosX = -25;
                        ear = -25;
                        pos5.x = calculateNewPosition(pos5.x, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "right") {
                        maxPosX = 29;
                        ear = 29;
                        pos5.x = calculateNewPosition(pos5.x, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        maxPosX = 13.5;
                        ear = -15;
                        pos5.x = calculateNewPositionplus(pos5.x, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        maxPosX = -6;
                        ear = 6;
                        pos5.x = calculateNewPositionplus(pos5.x, moveStep, ear);

                    }
                }
                pos4.x = calculateNewPosition(pos4.x, moveStep, maxPosX);
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
                        maxPosX = 11;
                        ear = -15;
                        pos5.y = calculateNewPositionplus(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "right") {
                        maxPosX = -8;
                        ear = 4;

                        pos5.y = calculateNewPositionplus(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        maxPosX = 24;
                        ear = 24;
                        pos5.y = calculateNewPosition(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        maxPosX = -24.5;
                        ear = -24.5;
                        pos5.y = calculateNewPosition(pos5.y, moveStep, ear);

                    }
                }
                pos4.y = calculateNewPosition(pos4.y, moveStep, maxPosX);
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
                        minPosX = 4;
                        ear = -8;
                        pos5.y = calculateNewPosition(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "right") {
                        minPosX = -15;
                        ear = 11;
                        pos5.y = calculateNewPosition(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "up") {
                        minPosX = 23.5;
                        ear = 23.5;
                        pos5.y = calculateNewPositionplus(pos5.y, moveStep, ear);

                    }
                    else if (selectedModel->getDirection() == "down") {
                        minPosX = -26;
                        ear = -26;
                        pos5.y = calculateNewPositionplus(pos5.y, moveStep, ear);

                    }
                }
                pos4.y = calculateNewPositionplus(pos4.y, moveStep, minPosX);
                break;
            }
            selectedModel->setPosition(pos4);
            ofLogNotice() << "select pos4";
            }
            else if (modelType == "tealwingl") {
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
                            minPosX = -36;
                            ear = 35;
                            pos6.x = calculateNewPosition(pos6.x, moveStep, ear);
                            
                        }
                        else if (selectedModel->getDirection() == "right") {
                            minPosX = 30;
                            ear = -31;
                            pos6.x = calculateNewPosition(pos6.x, moveStep, ear);
                            
                        }
                        else if (selectedModel->getDirection() == "up") {
                            minPosX = -2;
                            ear = -2;
                            pos6.x = calculateNewPositionplus(pos6.x, moveStep, ear);
                          
                        }
                        else if (selectedModel->getDirection() == "down") {
                            minPosX = -10;
                            ear = -10;
                            pos6.x = calculateNewPositionplus(pos6.x, moveStep, ear);                    

                        }
                    }                    
                    pos7.x = calculateNewPositionplus(pos7.x, moveStep, minPosX);

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
                            maxPosX = -31;
                            ear = 30;
                            pos6.x = calculateNewPositionplus(pos6.x, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "right") {
                            maxPosX = 35;
                            ear = -36;
                            pos6.x = calculateNewPositionplus(pos6.x, moveStep, ear);
                        }
                        else if (selectedModel->getDirection() == "up") {
                            maxPosX = 10;
                            ear = 10;
                            pos6.x = calculateNewPosition(pos6.x, moveStep, ear);
                        }
                        else if (selectedModel->getDirection() == "down") {
                            maxPosX = 2;
                            ear = 2;
                            pos6.x = calculateNewPosition(pos6.x, moveStep, ear);
                        }
                    }
                    pos7.x = calculateNewPosition(pos7.x, moveStep, maxPosX);
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
                            maxPosX = 6;
                            ear = 6;
                            pos6.y = calculateNewPosition(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "right") {
                            maxPosX = 6;
                            ear = 6;

                            pos6.y = calculateNewPosition(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "up") {
                            maxPosX = 28.5;
                            ear = -31.5;
                            pos6.y = calculateNewPositionplus(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "down") {
                            maxPosX = -30.0;
                            ear = 27.0;
                            pos6.y = calculateNewPositionplus(pos6.y, moveStep, ear);

                        }
                    }
                    pos7.y = calculateNewPosition(pos7.y, moveStep, maxPosX);
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
                            minPosX = 0.0;
                            ear = 0.0;
                            pos6.y = calculateNewPositionplus(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "right") {
                            minPosX = 0.0;
                            ear = 0.0;
                            pos6.y = calculateNewPositionplus(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "up") {
                            minPosX = 27;
                            ear = -30;
                            pos6.y = calculateNewPosition(pos6.y, moveStep, ear);

                        }
                        else if (selectedModel->getDirection() == "down") {
                            minPosX = -31.5;
                            ear = 28.5;
                            pos6.y = calculateNewPosition(pos6.y, moveStep, ear);

                        }
                    }
                    pos7.y = calculateNewPositionplus(pos7.y, moveStep, minPosX);
                    break;
                }
                selectedModel->setPosition(pos7);
                ofLogNotice() << "select pos7";

                }
            else if (modelType == "tealwingr") {
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
                                minPosX = 30;
                                ear = -31;
                               
                                pos7.x = calculateNewPosition(pos7.x, moveStep, ear);
                            }
                            else if (selectedModel->getDirection() == "right") {
                                minPosX = -36;
                                ear = 35;
                                pos7.x = calculateNewPosition(pos7.x, moveStep, ear);
                            }
                            else if (selectedModel->getDirection() == "up") {
                                minPosX = -2;
                                ear = -2;
                                pos7.x = calculateNewPositionplus(pos7.x, moveStep, ear);
                            }
                            else if (selectedModel->getDirection() == "down") {
                                minPosX = -10;
                                ear = -10;
                                pos7.x = calculateNewPositionplus(pos7.x, moveStep, ear);

                            }
                        }
                        pos6.x = calculateNewPositionplus(pos6.x, moveStep, minPosX);

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
                                maxPosX = 35;
                                ear = -36;
                                pos7.x = calculateNewPositionplus(pos7.x, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "right") {
                                maxPosX = -31;
                                ear = 30;
                                pos7.x = calculateNewPositionplus(pos7.x, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "up") {
                                maxPosX = 10;
                                ear = 10;
                                pos7.x = calculateNewPosition(pos7.x, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "down") {
                                maxPosX = 2;
                                ear = 2;
                                pos7.x = calculateNewPosition(pos7.x, moveStep, ear);

                            }
                        }
                        pos6.x = calculateNewPosition(pos6.x, moveStep, maxPosX);
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
                                maxPosX = 6;
                                ear = 6;
                                pos7.y = calculateNewPosition(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "right") {
                                maxPosX = -2.0;
                                ear = -2.0;

                                pos7.y = calculateNewPosition(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "up") {
                                maxPosX = -30;
                                ear = 27.;

                                pos7.y = calculateNewPositionplus(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "down") {
                                maxPosX = 28.5;
                                ear = -31.5;
                                pos7.y = calculateNewPositionplus(pos7.y, moveStep, ear);

                            }
                        }
                        pos6.y = calculateNewPosition(pos6.y, moveStep, maxPosX);
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
                                minPosX = 0;
                                ear = 0;
                                pos7.y = calculateNewPositionplus(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "right") {
                                minPosX = -10;
                                ear = -10;
                                pos7.y = calculateNewPositionplus(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "up") {
                                minPosX = -31.5;
                                ear = 28.5;
                                pos7.y = calculateNewPosition(pos7.y, moveStep, ear);

                            }
                            else if (selectedModel->getDirection() == "down") {
                                minPosX = 27;
                                ear = -30;
                                pos7.y = calculateNewPosition(pos7.y, moveStep, ear);

                            }
                        }
                        pos6.y = calculateNewPositionplus(pos6.y, moveStep, minPosX);
                        break;
                    }
                    selectedModel->setPosition(pos6);                    
                    }
                    //--------------------------------------tealdragon---------------------------------------------------------
                    else if (modelType == "batwingl") {
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
                                    minPosX = -36;
                                    ear = 35;
                                    pos8.x = calculateNewPosition(pos8.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    minPosX = 30;
                                    ear = -31;
                                    pos8.x = calculateNewPosition(pos8.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    minPosX = -2;
                                    ear = -2;
                                    pos8.x = calculateNewPositionplus(pos8.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    minPosX = -10;
                                    ear = -10;
                                    pos8.x = calculateNewPositionplus(pos8.x, moveStep, ear);

                                }
                            }
                            pos9.x = calculateNewPositionplus(pos9.x, moveStep, minPosX);

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
                                    maxPosX = -31;
                                    ear = 30;
                                    pos8.x = calculateNewPositionplus(pos8.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    maxPosX = 35;
                                    ear = -36;
                                    pos8.x = calculateNewPositionplus(pos8.x, moveStep, ear);
                                }
                                else if (selectedModel->getDirection() == "up") {
                                    maxPosX = 10;
                                    ear = 10;
                                    pos8.x = calculateNewPosition(pos8.x, moveStep, ear);
                                }
                                else if (selectedModel->getDirection() == "down") {
                                    maxPosX = 2;
                                    ear = 2;
                                    pos8.x = calculateNewPosition(pos8.x, moveStep, ear);
                                }
                            }
                            pos9.x = calculateNewPosition(pos9.x, moveStep, maxPosX);
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
                                    maxPosX = 6;
                                    ear = 6;
                                    pos8.y = calculateNewPosition(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    maxPosX = 6;
                                    ear = 6;

                                    pos8.y = calculateNewPosition(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    maxPosX = 28.5;
                                    ear = -31.5;
                                    pos8.y = calculateNewPositionplus(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    maxPosX = -30.0;
                                    ear = 27.0;
                                    pos8.y = calculateNewPositionplus(pos8.y, moveStep, ear);

                                }
                            }
                            pos9.y = calculateNewPosition(pos9.y, moveStep, maxPosX);
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
                                    minPosX = 0.0;
                                    ear = 0.0;
                                    pos8.y = calculateNewPositionplus(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    minPosX = 0.0;
                                    ear = 0.0;
                                    pos8.y = calculateNewPositionplus(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    minPosX = 27;
                                    ear = -30;
                                    pos8.y = calculateNewPosition(pos8.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    minPosX = -31.5;
                                    ear = 28.5;
                                    pos8.y = calculateNewPosition(pos8.y, moveStep, ear);

                                }
                            }
                            pos9.y = calculateNewPositionplus(pos9.y, moveStep, minPosX);
                            break;
                        }
                        selectedModel->setPosition(pos9);
                        ofLogNotice() << "select pos9";

                        }
                    else if (modelType == "batwingr") {
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
                                        minPosX = 30;
                                        ear = -31;

                                        pos9.x = calculateNewPosition(pos9.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        minPosX = -36;
                                        ear = 35;
                                        pos9.x = calculateNewPosition(pos9.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        minPosX = -2;
                                        ear = -2;
                                        pos9.x = calculateNewPositionplus(pos9.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        minPosX = -10;
                                        ear = -10;
                                        pos9.x = calculateNewPositionplus(pos9.x, moveStep, ear);

                                    }
                                }
                                pos8.x = calculateNewPositionplus(pos8.x, moveStep, minPosX);

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
                                        maxPosX = 35;
                                        ear = -36;
                                        pos9.x = calculateNewPositionplus(pos9.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        maxPosX = -31;
                                        ear = 30;
                                        pos9.x = calculateNewPositionplus(pos9.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        maxPosX = 10;
                                        ear = 10;
                                        pos9.x = calculateNewPosition(pos9.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        maxPosX = 2;
                                        ear = 2;
                                        pos9.x = calculateNewPosition(pos9.x, moveStep, ear);

                                    }
                                }
                                pos8.x = calculateNewPosition(pos8.x, moveStep, maxPosX);
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
                                        maxPosX = 6;
                                        ear = 6;
                                        pos9.y = calculateNewPosition(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        maxPosX = -2.0;
                                        ear = -2.0;

                                        pos9.y = calculateNewPosition(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        maxPosX = -30;
                                        ear = 27.;

                                        pos9.y = calculateNewPositionplus(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        maxPosX = 28.5;
                                        ear = -31.5;
                                        pos9.y = calculateNewPositionplus(pos9.y, moveStep, ear);

                                    }
                                }
                                pos8.y = calculateNewPosition(pos8.y, moveStep, maxPosX);
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
                                        minPosX = 0;
                                        ear = 0;
                                        pos9.y = calculateNewPositionplus(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        minPosX = -10;
                                        ear = -10;
                                        pos9.y = calculateNewPositionplus(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        minPosX = -31.5;
                                        ear = 28.5;
                                        pos9.y = calculateNewPosition(pos9.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        minPosX = 27;
                                        ear = -30;
                                        pos9.y = calculateNewPosition(pos9.y, moveStep, ear);

                                    }
                                }
                                pos8.y = calculateNewPositionplus(pos8.y, moveStep, minPosX);
                                break;
                            }
                            selectedModel->setPosition(pos8);
                            }
                            //--------------------------------------butterfly---------------------------------------------------------
                    else if (modelType == "butterwingl") {
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
                                    minPosX = -36;
                                    ear = 35;
                                    pos10.x = calculateNewPosition(pos10.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    minPosX = 30;
                                    ear = -31;
                                    pos10.x = calculateNewPosition(pos10.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    minPosX = -2;
                                    ear = -2;
                                    pos10.x = calculateNewPositionplus(pos10.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    minPosX = -10;
                                    ear = -10;
                                    pos10.x = calculateNewPositionplus(pos10.x, moveStep, ear);

                                }
                            }
                            pos11.x = calculateNewPositionplus(pos11.x, moveStep, minPosX);

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
                                    maxPosX = -31;
                                    ear = 30;
                                    pos10.x = calculateNewPositionplus(pos10.x, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    maxPosX = 35;
                                    ear = -36;
                                    pos10.x = calculateNewPositionplus(pos10.x, moveStep, ear);
                                }
                                else if (selectedModel->getDirection() == "up") {
                                    maxPosX = 10;
                                    ear = 10;
                                    pos10.x = calculateNewPosition(pos10.x, moveStep, ear);
                                }
                                else if (selectedModel->getDirection() == "down") {
                                    maxPosX = 2;
                                    ear = 2;
                                    pos10.x = calculateNewPosition(pos10.x, moveStep, ear);
                                }
                            }
                            pos11.x = calculateNewPosition(pos11.x, moveStep, maxPosX);
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
                                    maxPosX = 6;
                                    ear = 6;
                                    pos10.y = calculateNewPosition(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    maxPosX = 6;
                                    ear = 6;

                                    pos10.y = calculateNewPosition(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    maxPosX = 28.5;
                                    ear = -31.5;
                                    pos10.y = calculateNewPositionplus(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    maxPosX = -30.0;
                                    ear = 27.0;
                                    pos10.y = calculateNewPositionplus(pos10.y, moveStep, ear);

                                }
                            }
                            pos11.y = calculateNewPosition(pos11.y, moveStep, maxPosX);
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
                                    minPosX = 0.0;
                                    ear = 0.0;
                                    pos10.y = calculateNewPositionplus(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "right") {
                                    minPosX = 0.0;
                                    ear = 0.0;
                                    pos10.y = calculateNewPositionplus(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "up") {
                                    minPosX = 27;
                                    ear = -30;
                                    pos10.y = calculateNewPosition(pos10.y, moveStep, ear);

                                }
                                else if (selectedModel->getDirection() == "down") {
                                    minPosX = -31.5;
                                    ear = 28.5;
                                    pos10.y = calculateNewPosition(pos10.y, moveStep, ear);

                                }
                            }
                            pos11.y = calculateNewPositionplus(pos11.y, moveStep, minPosX);
                            break;
                        }
                        selectedModel->setPosition(pos11);
                        ofLogNotice() << "select pos11";

                        }
                    else if (modelType == "butterwingr") {
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
                                        minPosX = 30;
                                        ear = -31;

                                        pos11.x = calculateNewPosition(pos11.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        minPosX = -36;
                                        ear = 35;
                                        pos11.x = calculateNewPosition(pos11.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        minPosX = -2;
                                        ear = -2;
                                        pos11.x = calculateNewPositionplus(pos11.x, moveStep, ear);
                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        minPosX = -10;
                                        ear = -10;
                                        pos11.x = calculateNewPositionplus(pos11.x, moveStep, ear);

                                    }
                                }
                                pos10.x = calculateNewPositionplus(pos10.x, moveStep, minPosX);

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
                                        maxPosX = 35;
                                        ear = -36;
                                        pos11.x = calculateNewPositionplus(pos11.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        maxPosX = -31;
                                        ear = 30;
                                        pos11.x = calculateNewPositionplus(pos11.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        maxPosX = 10;
                                        ear = 10;
                                        pos11.x = calculateNewPosition(pos11.x, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        maxPosX = 2;
                                        ear = 2;
                                        pos11.x = calculateNewPosition(pos11.x, moveStep, ear);

                                    }
                                }
                                pos10.x = calculateNewPosition(pos10.x, moveStep, maxPosX);
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
                                        maxPosX = 6;
                                        ear = 6;
                                        pos11.y = calculateNewPosition(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        maxPosX = -2.0;
                                        ear = -2.0;

                                        pos11.y = calculateNewPosition(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        maxPosX = -30;
                                        ear = 27.;

                                        pos11.y = calculateNewPositionplus(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        maxPosX = 28.5;
                                        ear = -31.5;
                                        pos11.y = calculateNewPositionplus(pos11.y, moveStep, ear);

                                    }
                                }
                                pos10.y = calculateNewPosition(pos10.y, moveStep, maxPosX);
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
                                        minPosX = 0;
                                        ear = 0;
                                        pos11.y = calculateNewPositionplus(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "right") {
                                        minPosX = -10;
                                        ear = -10;
                                        pos11.y = calculateNewPositionplus(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "up") {
                                        minPosX = -31.5;
                                        ear = 28.5;
                                        pos11.y = calculateNewPosition(pos11.y, moveStep, ear);

                                    }
                                    else if (selectedModel->getDirection() == "down") {
                                        minPosX = 27;
                                        ear = -30;
                                        pos11.y = calculateNewPosition(pos11.y, moveStep, ear);

                                    }
                                }
                                pos10.y = calculateNewPositionplus(pos10.y, moveStep, minPosX);
                                break;
                            }
                            selectedModel->setPosition(pos10);
                            }
                            //-------------------------------------------------------horn--------------------------------------------------
                            else if (modelType == "hornl") {
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
                                            minPosX = -31;
                                            ear = -31;
                                            pos12.x = calculateNewPositionplus(pos12.x, moveStep, ear);
                                        }
                                        else if (selectedModel->getDirection() == "right") {
                                            minPosX = 25;
                                            ear = 25;
                                            pos12.x = calculateNewPositionplus(pos12.x, moveStep, ear);
                                        }
                                        else if (selectedModel->getDirection() == "up") {
                                            minPosX = -19;
                                            ear = 17.5;
                                            pos12.x = calculateNewPosition(pos12.x, moveStep, ear);
                                        }
                                        else if (selectedModel->getDirection() == "down") {
                                            minPosX = 6;
                                            ear = -6;
                                            pos12.x = calculateNewPosition(pos12.x, moveStep, ear);

                                        }
                                    }
                                    pos13.x = calculateNewPositionplus(pos13.x, moveStep, minPosX);

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
                                            maxPosX = -25;
                                            ear = -25;
                                            pos12.x = calculateNewPosition(pos12.x, moveStep, ear);


                                        }
                                        else if (selectedModel->getDirection() == "right") {
                                            maxPosX = 31;
                                            ear = 31;
                                            pos12.x = calculateNewPosition(pos12.x, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "up") {
                                            maxPosX = -13;
                                            ear = 11.5;
                                            pos12.x = calculateNewPositionplus(pos12.x, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "down") {
                                            maxPosX = 17;
                                            ear = -17;
                                            pos12.x = calculateNewPositionplus(pos12.x, moveStep, ear);

                                        }
                                    }
                                    pos13.x = calculateNewPosition(pos13.x, moveStep, maxPosX);
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
                                            ear = 4;
                                            pos12.y = calculateNewPositionplus(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "right") {
                                            maxPosX = 11;
                                            ear = -15;

                                            pos12.y = calculateNewPositionplus(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "up") {
                                            maxPosX = 24.5;
                                            ear = 24.5;
                                            pos12.y = calculateNewPosition(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "down") {
                                            maxPosX = -26.5;
                                            ear = -26.5;
                                            pos12.y = calculateNewPosition(pos12.y, moveStep, ear);

                                        }
                                    }
                                    pos13.y = calculateNewPosition(pos13.y, moveStep, maxPosX);
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
                                            minPosX = -15;
                                            ear = 11;
                                            pos12.y = calculateNewPosition(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "right") {
                                            minPosX = 4;
                                            ear = -8;
                                            pos12.y = calculateNewPosition(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "up") {
                                            minPosX = 23.5;
                                            ear = 23.5;
                                            pos12.y = calculateNewPositionplus(pos12.y, moveStep, ear);

                                        }
                                        else if (selectedModel->getDirection() == "down") {
                                            minPosX = -28;
                                            ear = -28;
                                            pos12.y = calculateNewPositionplus(pos12.y, moveStep, ear);

                                        }
                                    }
                                    pos13.y = calculateNewPositionplus(pos13.y, moveStep, minPosX);
                                    break;
                                }
                                selectedModel->setPosition(pos13);
                                ofLogNotice() << "select pos13";

                                }
                            else if (modelType == "hornr") {
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
                                                minPosX = -31;
                                                ear = -31;
                                                pos13.x = calculateNewPositionplus(pos13.x, moveStep, ear);
                                            }
                                            else if (selectedModel->getDirection() == "right") {
                                                minPosX = 25;
                                                ear = 25;
                                                pos13.x = calculateNewPositionplus(pos13.x, moveStep, ear);
                                            }
                                            else if (selectedModel->getDirection() == "up") {
                                                minPosX = 11.5;
                                                ear = -13;
                                                pos13.x = calculateNewPosition(pos13.x, moveStep, ear);
                                            }
                                            else if (selectedModel->getDirection() == "down") {
                                                minPosX = -17;
                                                ear = 17;
                                                pos13.x = calculateNewPosition(pos13.x, moveStep, ear);

                                            }
                                        }
                                        pos12.x = calculateNewPositionplus(pos12.x, moveStep, minPosX);

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
                                                maxPosX = -25;
                                                ear = -25;
                                                pos13.x = calculateNewPosition(pos13.x, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "right") {
                                                maxPosX = 31;
                                                ear = 31;
                                                pos13.x = calculateNewPosition(pos13.x, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "up") {
                                                maxPosX = 17.5;
                                                ear = -19;
                                                pos13.x = calculateNewPositionplus(pos13.x, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "down") {
                                                maxPosX = -6;
                                                ear = 6;
                                                pos13.x = calculateNewPositionplus(pos13.x, moveStep, ear);

                                            }
                                        }
                                        pos12.x = calculateNewPosition(pos12.x, moveStep, maxPosX);
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
                                                maxPosX = 11;
                                                ear = -15;
                                                pos13.y = calculateNewPositionplus(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "right") {
                                                maxPosX = -8;
                                                ear = 4;

                                                pos13.y = calculateNewPositionplus(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "up") {
                                                maxPosX = 24.5;
                                                ear = 24.5;
                                                pos13.y = calculateNewPosition(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "down") {
                                                maxPosX = -26.5;
                                                ear = -26.5;
                                                pos13.y = calculateNewPosition(pos13.y, moveStep, ear);

                                            }
                                        }
                                        pos12.y = calculateNewPosition(pos12.y, moveStep, maxPosX);
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
                                                minPosX = 4;
                                                ear = -8;
                                                pos13.y = calculateNewPosition(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "right") {
                                                minPosX = -15;
                                                ear = 11;
                                                pos13.y = calculateNewPosition(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "up") {
                                                minPosX = 23.5;
                                                ear = 23.5;
                                                pos13.y = calculateNewPositionplus(pos13.y, moveStep, ear);

                                            }
                                            else if (selectedModel->getDirection() == "down") {
                                                minPosX = -28;
                                                ear = -28;
                                                pos13.y = calculateNewPositionplus(pos13.y, moveStep, ear);

                                            }
                                        }
                                        pos12.y = calculateNewPositionplus(pos12.y, moveStep, minPosX);
                                        break;
                                    }
                                    selectedModel->setPosition(pos12);
                                    ofLogNotice() << "select pos12";
                                    }
                                    //---------------------------------------------rabbit--------------------------------------

                                    else if (modelType == "rabearl") {
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
                                                    pos14.x = calculateNewPositionplus(pos14.x, moveStep, ear);
                                                }
                                                else if (selectedModel->getDirection() == "right") {
                                                    minPosX = 22;
                                                    ear = 22;
                                                    pos14.x = calculateNewPositionplus(pos14.x, moveStep, ear);
                                                }
                                                else if (selectedModel->getDirection() == "up") {
                                                    minPosX = -21;
                                                    ear = 19.5;
                                                    pos14.x = calculateNewPosition(pos14.x, moveStep, ear);
                                                }
                                                else if (selectedModel->getDirection() == "down") {
                                                    minPosX = 8;
                                                    ear = -8;
                                                    pos14.x = calculateNewPosition(pos14.x, moveStep, ear);

                                                }
                                            }
                                            pos15.x = calculateNewPositionplus(pos15.x, moveStep, minPosX);

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
                                                    pos14.x = calculateNewPosition(pos14.x, moveStep, ear);


                                                }
                                                else if (selectedModel->getDirection() == "right") {
                                                    maxPosX = 27;
                                                    ear = 27;
                                                    pos14.x = calculateNewPosition(pos14.x, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "up") {
                                                    maxPosX = -12;
                                                    ear = 10.5;
                                                    pos14.x = calculateNewPositionplus(pos14.x, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "down") {
                                                    maxPosX = 21;
                                                    ear = -21;
                                                    pos14.x = calculateNewPositionplus(pos14.x, moveStep, ear);

                                                }
                                            }
                                            pos15.x = calculateNewPosition(pos15.x, moveStep, maxPosX);
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
                                                    pos14.y = calculateNewPositionplus(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "right") {
                                                    maxPosX = 13;
                                                    ear = -15;

                                                    pos14.y = calculateNewPositionplus(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "up") {
                                                    maxPosX = 20.5;
                                                    ear = 20.5;
                                                    pos14.y = calculateNewPosition(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "down") {
                                                    maxPosX = -19;
                                                    ear = -19;
                                                    pos14.y = calculateNewPosition(pos14.y, moveStep, ear);

                                                }
                                            }
                                            pos15.y = calculateNewPosition(pos15.y, moveStep, maxPosX);
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
                                                    pos14.y = calculateNewPosition(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "right") {
                                                    minPosX = 6;
                                                    ear = -8;
                                                    pos14.y = calculateNewPosition(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "up") {
                                                    minPosX = 20;
                                                    ear = 20;
                                                    pos14.y = calculateNewPositionplus(pos14.y, moveStep, ear);

                                                }
                                                else if (selectedModel->getDirection() == "down") {
                                                    minPosX = -24;
                                                    ear = -24;
                                                    pos14.y = calculateNewPositionplus(pos14.y, moveStep, ear);

                                                }
                                            }
                                            pos15.y = calculateNewPositionplus(pos15.y, moveStep, minPosX);
                                            break;
                                        }
                                        selectedModel->setPosition(pos15);

                                        }
                                        //---------------------------------------------rabbit--------------------------------------
                                    else if (modelType == "rabearr") {
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
                                                        pos15.x = calculateNewPositionplus(pos15.x, moveStep, ear);
                                                    }
                                                    else if (selectedModel->getDirection() == "right") {
                                                        minPosX = 22;
                                                        ear = 22;
                                                        pos15.x = calculateNewPositionplus(pos15.x, moveStep, ear);
                                                    }
                                                    else if (selectedModel->getDirection() == "up") {
                                                        minPosX = 10.5;
                                                        ear = -12;
                                                        pos15.x = calculateNewPosition(pos15.x, moveStep, ear);
                                                    }
                                                    else if (selectedModel->getDirection() == "down") {
                                                        minPosX = -21;
                                                        ear = 21;
                                                        pos15.x = calculateNewPosition(pos15.x, moveStep, ear);

                                                    }
                                                }
                                                pos14.x = calculateNewPositionplus(pos14.x, moveStep, minPosX);

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
                                                        pos15.x = calculateNewPosition(pos15.x, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "right") {
                                                        maxPosX = 27;
                                                        ear = 27;
                                                        pos15.x = calculateNewPosition(pos15.x, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "up") {
                                                        maxPosX = 19.5;
                                                        ear = -21;
                                                        pos15.x = calculateNewPositionplus(pos15.x, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "down") {
                                                        maxPosX = -8;
                                                        ear = 8;
                                                        pos15.x = calculateNewPositionplus(pos15.x, moveStep, ear);

                                                    }
                                                }
                                                pos14.x = calculateNewPosition(pos14.x, moveStep, maxPosX);
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
                                                        maxPosX = 13;
                                                        ear = -13;
                                                        pos15.y = calculateNewPositionplus(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "right") {
                                                        maxPosX = -8;
                                                        ear = 6;

                                                        pos15.y = calculateNewPositionplus(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "up") {
                                                        maxPosX = 20.5;
                                                        ear = 20.5;
                                                        pos15.y = calculateNewPosition(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "down") {
                                                        maxPosX = -19;
                                                        ear = -19;
                                                        pos15.y = calculateNewPosition(pos15.y, moveStep, ear);

                                                    }
                                                }
                                                pos14.y = calculateNewPosition(pos14.y, moveStep, maxPosX);
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
                                                        minPosX = 8;
                                                        ear = -8;
                                                        pos15.y = calculateNewPosition(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "right") {
                                                        minPosX = -15;
                                                        ear = 13;
                                                        pos15.y = calculateNewPosition(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "up") {
                                                        minPosX = 20;
                                                        ear = 20;
                                                        pos15.y = calculateNewPositionplus(pos15.y, moveStep, ear);

                                                    }
                                                    else if (selectedModel->getDirection() == "down") {
                                                        minPosX = -24;
                                                        ear = -24;
                                                        pos15.y = calculateNewPositionplus(pos15.y, moveStep, ear);

                                                    }
                                                }
                                                pos14.y = calculateNewPositionplus(pos14.y, moveStep, minPosX);
                                                break;
                                            }
                                            selectedModel->setPosition(pos14);

                                            }

}

float KeyHandler::calculateNewPositionplus(float currentPos, float moveStep, float minPos) {
    float newPos = currentPos - moveStep;
    return std::max(newPos, minPos);
}

float KeyHandler::calculateNewPosition(float currentPos, float moveStep, float maxPos) {
    float newPos = currentPos + moveStep;
    return std::min(newPos, maxPos);
}