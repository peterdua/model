#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_NOTICE);
    cam.disableMouseInput(); // 初始时禁用，只有在按下Alt时才启用    

    cam.setPosition(ofVec3f(0, 0, 50)); 

    guiModel.setup("Model Creation"); 
    guiModel.add(cubeButton.setup("Cube"));
    guiModel.add(sphereButton.setup("Sphere"));
    guiModel.add(sphrEarButton.setup("Rabbit ear"));
    guiModel.add(leftCatEarButton.setup("Cat ear"));
    guiModel.add(loopButton.setup("Loop"));
    guiModel.add(modelSize.set("Size",10,1,50));
    guiModel.setPosition(10, 10); 

    int guiModelHeight1 = guiModel.getHeight();
    int spacing = 10;

    guiBasemodel.setup("Base holder");
    guiBasemodel.add(loadSphrBasemodelButton.setup("Sphare holder"));
    guiBasemodel.add(loadSphrCovermodelButton.setup("Sphare holder's cover"));
    guiBasemodel.add(loadModelButton.setup("Square holder"));
    guiBasemodel.add(loadBasemodelButton.setup("Square holder's cover"));
    guiBasemodel.setPosition(10, 10 + guiModelHeight1 + spacing);

    int guiModelHeight = guiBasemodel.getHeight();     
    guiRotate.setup("Rotation Control"); 
    guiRotate.add(rotateX.set("X", 0, -360, 360));   
    guiRotate.add(rotateY.set("Y", 0, -360, 360));
    guiRotate.add(rotateZ.set("Z", 0, -360, 360));
    guiRotate.setPosition(10, 20 + guiModelHeight + guiModelHeight1 + spacing); 

    cubeButton.addListener(this, &ofApp::cubeButtonPressed);
    sphereButton.addListener(this, &ofApp::sphereButtonPressed);
    sphrEarButton.addListener(this, &ofApp::loadSphrrabEarButtonPressed);
    loopButton.addListener(this, &ofApp::loadLoopButtonPressed);
    loadModelButton.addListener(this, &ofApp::loadModelButtonPressed);
    modelSize.addListener(this, &ofApp::modelSizeChanged);
    leftCatEarButton.addListener(this, &ofApp::catEarButtonPressed);

    loadBasemodelButton.addListener(this, &ofApp::loadBasemodelButtonPressed);
    loadSphrBasemodelButton.addListener(this, &ofApp::loadSphrBasemodelButtonPressed);
    loadSphrCovermodelButton.addListener(this, &ofApp::loadSphrCovermodelButtonPressed);

    rotateX.addListener(this, &ofApp::modelXrotationChanged);
    rotateY.addListener(this, &ofApp::modelYrotationChanged);
    rotateZ.addListener(this, &ofApp::modelZrotationChanged);

}

void ofApp::modelSizeChanged(int& size) {
    int step = 2; 
    int newSize = ((size + step / 2) / step) * step; 
    if (newSize != size) {
        modelSize.removeListener(this, &ofApp::modelSizeChanged);
        modelSize.set(newSize);
        modelSize.addListener(this, &ofApp::modelSizeChanged);
    }
    if (selectedModel) {
        selectedModel->setSize(newSize);
    }
}

void ofApp::exit() {
    modelSize.removeListener(this, &ofApp::modelSizeChanged);
    rotateX.removeListener(this, &ofApp::modelXrotationChanged);
    rotateY.removeListener(this, &ofApp::modelYrotationChanged);
    rotateZ.removeListener(this, &ofApp::modelZrotationChanged);
}

//--------------------------------------------------------------
void ofApp::update() {
   
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    cam.begin();    

    ofSetColor(128, 128, 128);
    ofDrawGrid(10.0f, 10, false, false, true, false); 
    for (auto& model : models) {
        model->draw(); 
    }
    if (selectedModel != nullptr) {
        selectedModel->applyRotation();
        ofVec3f position = selectedModel->getPosition();

        ofSetLineWidth(2);
        // X轴
        ofSetColor(ofColor::red);
        ofDrawLine(position, position + ofVec3f(10, 0, 0));
        // Y轴
        ofSetColor(ofColor::green);
        ofDrawLine(position, position + ofVec3f(0, 10, 0));
        // Z轴
        ofSetColor(ofColor::blue);
        ofDrawLine(position, position + ofVec3f(0, 0, 10));        

    }
    cam.end(); 
    guiRotate.draw(); 
    guiModel.draw(); 
    guiBasemodel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { 
    if (ear) {
        pos2 = rightEarModel->getPosition();
        pos3 = leftEarModel->getPosition();
    }

    keyHandler.handleKeyPress(selectedModel, key, models, mainModel, spr, sphere, pos2);      
    if (selectedModel->getType() == "leftcatear")
    {
        rightEarModel->setPosition(pos2);
    }

    switch (key) {
    case OF_KEY_ALT:
        altPressed = true;
        cam.enableMouseInput(); // 启用摄像机的鼠标输入
        break;
    case 'i': 
        if (selectedModel) {
            auto it = std::find_if(models.begin(), models.end(), [&](const auto& model) {
                return model == selectedModel;
                });
            if (it != models.end()) {
                models.erase(it); 
            }
            if (selectedModel->getType() == "zftbase"){
                spr = false;
            }
            else if (selectedModel->getType() == "yuanbase") {
                sphere = false;
            }
            else if (selectedModel->getType() == "leftcatear" || "rightcatear") {
                ear = false;
            }
            mainModel->removePart(selectedModel);
            selectedModel.reset(); 
            hasBaseModel = false;


            
            ofLogNotice() << "Selected model deleted.";
        }
        break;
    case 's': 
        if (selectedModel) {
            ofLogNotice() << "Exporting selected model to STL file.";
            mainModel->exportModelToSTL("test.stl"); 
            ofLogNotice() << "Selected model exported to STL file.";
        }
        else {
            ofLogError() << "No model selected for export.";
        }
        break;
    }        
}

void ofApp::cubeButtonPressed() {    
    std::shared_ptr<CubeModel> newCube = std::make_shared<CubeModel>("cube");
    newCube->setSize(modelSize.get()); 
    newCube->setPosition(ofVec3f(0, 0, 0));
    models.push_back(newCube); 
    selectedModel = newCube;
    mainModel->addPart(newCube);
}

void ofApp::sphereButtonPressed() {
    
}

void ofApp::loadModelButtonPressed() {
    if (hasBaseModel) {
        ofLogNotice("loadModelButtonPressed") << "抱歉，你只能创建一个基底模型，如果您想换其他的基底模型，请先删除当前模型。";
        return; 
    }
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>("zftbase");
    std::string modelPath = "zftbase.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);
        hasBaseModel = true; 
        spr = true;
    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::loadBasemodelButtonPressed() {    
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>("zftcover");
    std::string modelPath = "zftcover.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel); 
        selectedModel = newAssimpModel; 
        mainModel->addPart(newAssimpModel); 
    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::loadSphrBasemodelButtonPressed() {
    if (hasBaseModel) {
        ofLogNotice("loadModelButtonPressed") << "抱歉，你只能创建一个基底模型，如果您想换其他的基底模型，请先删除当前模型。";
        return; 
    }
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>("yuanbase");
    //std::string modelPath = "smpsphrbase.stl";
    std::string modelPath = "softv1.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);
        hasBaseModel = true;
        sphere = true;

    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::loadSphrCovermodelButtonPressed() {
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>("spherecover");
    std::string modelPath = "smpsphrcover.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);
    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::loadSphrrabEarButtonPressed() {
    std::shared_ptr<AccessoryModel> newAssimpModel = std::make_shared<AccessoryModel>("rabear");
    std::string modelPath = "erduo.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);

        ofVec3f newPosition = ofVec3f(0.0f, 25.0f, 0.0f);
        newAssimpModel->setPosition(newPosition); 
    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::loadLoopButtonPressed() {
    std::shared_ptr<AccessoryModel> newAssimpModel = std::make_shared<AccessoryModel>("loop");
    std::string modelPath = "loop.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);

        ofVec3f newPosition = ofVec3f(26.0f, 0.0f, 0.0f);
        newAssimpModel->setPosition(newPosition);
    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::catEarButtonPressed() {    
    ear = true;
    rightEarModel = std::make_shared<AccessoryModel>("rightcatear");
    std::string rightEar = "rightcatear.stl";
    if (rightEarModel->loadModel(rightEar)) {
        rightEarModel->adMeshes();
        models.push_back(rightEarModel);
        mainModel->addPart(rightEarModel);        

        ofVec3f leftPosition = ofVec3f(23.0f, 18.0f, 0.0f); 
        rightEarModel->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << rightEarModel;
    }

    
    leftEarModel = std::make_shared<AccessoryModel>("leftcatear");
    std::string rightModelPath = "leftcatear.stl";
    if (leftEarModel->loadModel(rightModelPath)) {
        leftEarModel->adMeshes();
        models.push_back(leftEarModel);
        mainModel->addPart(leftEarModel);        

        ofVec3f rightPosition = ofVec3f(-23.0f, 18.0f, .0f); 
        leftEarModel->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << leftEarModel;
    }
}

void ofApp::modelXrotationChanged(int& rotation) {
    int step = 15; 
    int newRotation = ((rotation + step / 2) / step) * step; 
    if (newRotation != rotation) {
        rotateX.removeListener(this, &ofApp::modelXrotationChanged);
        rotateX.set(newRotation);
        rotateX.addListener(this, &ofApp::modelXrotationChanged);
    }

    if (selectedModel) {
        selectedModel->setRotation(newRotation, ofVec3f(1,0,0));
    }
}

void ofApp::modelYrotationChanged(int& rotation) {
    int step = 15; 
    int newRotation = ((rotation + step / 2) / step) * step; 
    if (newRotation != rotation) {
        rotateY.removeListener(this, &ofApp::modelYrotationChanged);
        rotateY.set(newRotation);
        rotateY.addListener(this, &ofApp::modelYrotationChanged);
    }
    if (selectedModel) {
        selectedModel->setRotation(newRotation, ofVec3f(0, 1, 0));
    }
}

void ofApp::modelZrotationChanged(int& rotation) {
    int step = 5; 
    int newRotation = ((rotation + step / 2) / step) * step; 
    if (newRotation != rotation) {
        rotateZ.removeListener(this, &ofApp::modelZrotationChanged);
        rotateZ.set(newRotation);
        rotateZ.addListener(this, &ofApp::modelZrotationChanged);
    }
    if (selectedModel) {
        selectedModel->setRotation(newRotation, ofVec3f(0, 0, 1));
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == OF_KEY_ALT) {
        altPressed = false;
        cam.disableMouseInput(); 
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    if (isDragging && draggableModel && !altPressed) {
        std::string modelType = draggableModel->getType(); 

        if (modelType == "zftbase") {
           
        }
        else if (modelType == "TypeB") {
            ofVec3f newPos = cam.screenToWorld(ofVec3f(x, y) + dragOffset);
            draggableModel->setPosition(newPos);
        }
        else if (modelType == "yuanbase") {
            
        }
        else{
            ofVec3f newPos = cam.screenToWorld(ofVec3f(x, y) + dragOffset);
            draggableModel->setPosition(newPos);
        }
        
    }
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ofVec3f screenPoint(x, y);
    float closestDist = std::numeric_limits<float>::max();
    int closestIndex = -1;

    for (int i = 0; i < models.size(); i++) {
        ofVec3f modelScreenPos = cam.worldToScreen(models[i]->getPosition());
        float dist = modelScreenPos.distance(screenPoint);
        if (dist < closestDist) {
            closestDist = dist;
            closestIndex = i;
        }
    }
    if (closestIndex != -1) {
        selectedModel = models[closestIndex];         
        updateSelectedModel(selectedModel);
        isDragging = true;
        draggableModel = selectedModel;
        dragOffset = cam.worldToScreen(draggableModel->getPosition()) - screenPoint;
    }
    else {
        std::cout << "No model selected." << std::endl;
        selectedModel = nullptr;     
        isDragging = false;
    }
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {    
    ofVec3f axis;
    ofVec3f xaxis = ofVec3f(1, 0, 0);
    ofVec3f yaxis = ofVec3f(0, 1, 0);
    ofVec3f zaxis = ofVec3f(0, 0, 1);

    if (isDragging && draggableModel) {
        isDragging = false;

        std::vector<ofVec3f> presetPositions;
        std::vector<ofVec3f> presetPositions2;
        std::string modelType = draggableModel->getType(); 

        if (spr == true && modelType == "loop") {
            presetPositions = { ofVec3f(-23.0f, 0.0f, 0.0f), ofVec3f(26.0f, 0.0f, 0.0f), ofVec3f(0.0f, 29.0f, 0.0f), ofVec3f(0.0f, -29.0f, 0.0f) };
        }
        else if (sphere == true && modelType == "loop") {
            presetPositions = { ofVec3f(-31.5f, -2.0f, 0.0f), ofVec3f(30.0f, -2.0f, 0.0f), ofVec3f(0.0f, 24.0f, 0.0f), ofVec3f(0.0f, -25.5f, 0.0f) };

        }
        else if (sphere == true && modelType == "rabear") {
            presetPositions = { ofVec3f(-30.0f, 0.0f, 0.0f), ofVec3f(30.0f, 0.0f, 0.0f), ofVec3f(0.0f, 32.0f, 0.0f), ofVec3f(0.0f, -32.0f, 0.0f) };

        }
        else if (spr == true && modelType == "rabear") {
            presetPositions = { ofVec3f(-25.0f, 0.0f, 0.0f), ofVec3f(25.0f, 0.0f, 0.0f), ofVec3f(0.0f, 27.0f, 0.0f), ofVec3f(0.0f, -27.0f, 0.0f) };

        }
        else if (sphere == true && modelType == "leftcatear") {
            presetPositions = { ofVec3f(-28.0f, -11.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 20.0f, 0.0f), ofVec3f(20.0f, -21.0f, 0.0f) };
            presetPositions2 = { ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 20.0f, 0.0f), ofVec3f(-20.0f, -21.0f, 0.0f) };

        }
        else if (sphere == true && modelType == "rightcatear") {
            presetPositions = { ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 19.0f, 0.0f), ofVec3f(-20.0f, -21.0f, 0.0f) };
            presetPositions2 = { ofVec3f(-28.0f, -13.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 19.0f, 0.0f), ofVec3f(20.0f, -21.0f, 0.0f) };


        }
        else{
            presetPositions = {};

        }

        if (!presetPositions.empty()) {
            ofVec3f currentPos = draggableModel->getPosition();
            float minDistance = std::numeric_limits<float>::max();
            int closestIndex = -1;

            for (int i = 0; i < presetPositions.size(); i++) {
                float distance = currentPos.distance(presetPositions[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
            if (closestIndex != -1 && altPressed == false) {
                draggableModel->setPosition(presetPositions[closestIndex]);
                auto& otherEarModel = (modelType == "leftcatear") ? getRightEarModel() : getLeftEarModel();
                otherEarModel->setPosition(presetPositions2[closestIndex]);

                if (modelType == "loop") {
                    if (closestIndex == 0) { 
                        draggableModel->setRotation(180, yaxis);
                        draggableModel->setRotation(0, zaxis);
                        draggableModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        draggableModel->setRotation(0, yaxis);
                        draggableModel->setRotation(0, zaxis);
                        draggableModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        draggableModel->setRotation(90, zaxis);
                        draggableModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        draggableModel->setRotation(-90, zaxis);
                        draggableModel->setDirection("down");
                    }
                }
                else if (modelType == "rabear") {
                    if (closestIndex == 0) { 
                        draggableModel->setRotation(90, zaxis);
                        draggableModel->setRotation(0, yaxis);
                        draggableModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        draggableModel->setRotation(-90, zaxis);
                        draggableModel->setRotation(0, yaxis);
                        draggableModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        draggableModel->setRotation(0, zaxis);
                        draggableModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        draggableModel->setRotation(180, zaxis);
                        //draggableModel->setRotation(0, zaxis);
                        draggableModel->setDirection("down");
                    }
                }  
                else if (modelType == "leftcatear") {
                    if (closestIndex == 0) {
                        draggableModel->setRotation(90, zaxis);
                        draggableModel->setRotation(0, yaxis);   

                        otherEarModel->setRotation(90, zaxis);
                        otherEarModel->setRotation(0, yaxis);
                        draggableModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        draggableModel->setRotation(-90, zaxis);
                        draggableModel->setRotation(0, yaxis);

                        otherEarModel->setRotation(-90, zaxis);
                        otherEarModel->setRotation(0, yaxis);
                        draggableModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        draggableModel->setRotation(0, zaxis);

                        otherEarModel->setRotation(0, zaxis);
                        draggableModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        draggableModel->setRotation(180, zaxis);

                        otherEarModel->setRotation(180, zaxis);
                        //draggableModel->setRotation(0, zaxis);                       
                        draggableModel->setDirection("down");
                    }
                }
                else if (modelType == "rightcatear") {
                    if (closestIndex == 0) {
                        draggableModel->setRotation(90, zaxis);
                        draggableModel->setRotation(0, yaxis);

                        otherEarModel->setRotation(90, zaxis);
                        otherEarModel->setRotation(0, yaxis);
                        draggableModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        draggableModel->setRotation(-90, zaxis);
                        draggableModel->setRotation(0, yaxis);

                        otherEarModel->setRotation(-90, zaxis);
                        otherEarModel->setRotation(0, yaxis);
                        draggableModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        draggableModel->setRotation(0, zaxis);

                        otherEarModel->setRotation(0, zaxis);
                        draggableModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        draggableModel->setRotation(180, zaxis);

                        otherEarModel->setRotation(180, zaxis);
                        //draggableModel->setRotation(0, zaxis);                       
                        draggableModel->setDirection("down");
                    }
                }
                
                
            }
        }
    }
}



//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::updateSelectedModel(std::shared_ptr<Model> newModel) {
    selectedModel = newModel; 

    if (selectedModel) {
        std::string modelType = selectedModel->getType(); 
       
        if (modelType == "cube") {
            rotateX.setMin(0);
            rotateX.setMax(360);            
        }
        else if (modelType == "loop") {
            rotateX.setMin(-30);
            rotateX.setMax(30);
            rotateY.setMin(-30);
            rotateY.setMax(30); 
            rotateZ.setMin(-15); 
            rotateZ.setMax(15);
        }
        else if (modelType == "rabear") {
            rotateX.setMin(-180);
            rotateX.setMax(180);
            rotateY.setMin(-180);
            rotateY.setMax(180);
            rotateZ.setMin(-180);
            rotateZ.setMax(180);
        }
        else {
            rotateX.setMin(-360);
            rotateX.setMax(360);
        }
    }
}

std::shared_ptr<AccessoryModel> ofApp::getLeftEarModel() {
    return leftEarModel;
}

std::shared_ptr<AccessoryModel> ofApp::getRightEarModel() {
    return rightEarModel;
}
