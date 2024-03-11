#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_NOTICE);
    cam.setPosition(ofVec3f(0, 0, 50)); 

    guiModel.setup("Model Creation"); 
    guiModel.add(cubeButton.setup("Cube"));
    guiModel.add(sphereButton.setup("Sphere"));
    guiModel.add(sphrEarButton.setup("Cat ear"));
    guiModel.add(loadModelButton.setup("BaseModel-1"));
    guiModel.add(loadBasemodelButton.setup("CoverModel-1"));
    guiModel.add(modelSize.set("Size",10,1,50));
    guiModel.setPosition(10, 10); 


    int guiModelHeight1 = guiModel.getHeight();
    int spacing = 10;

    guiBasemodel.setup("Base holder");
    guiBasemodel.add(loadSphrBasemodelButton.setup("Square holder"));
    guiBasemodel.add(loadSphrCovermodelButton.setup("Square holder's cover"));
    guiBasemodel.setPosition(10, 10 + guiModelHeight1 + spacing);

    int guiModelHeight = guiBasemodel.getHeight();     
    guiRotate.setup("Rotation Control"); 
    guiRotate.add(rotateX.set("X", 0, 0, 360));
    guiRotate.add(rotateY.set("Y", 0, 0, 360));
    guiRotate.add(rotateZ.set("Z", 0, 0, 360));       
    guiRotate.setPosition(10, 20 + guiModelHeight + guiModelHeight1 + spacing); 

    cubeButton.addListener(this, &ofApp::cubeButtonPressed);
    sphereButton.addListener(this, &ofApp::sphereButtonPressed);
    sphrEarButton.addListener(this, &ofApp::loadSphrrabEarButtonPressed);
    loadModelButton.addListener(this, &ofApp::loadModelButtonPressed);
    modelSize.addListener(this, &ofApp::modelSizeChanged);

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
    float moveStep = 10.0; 
    ofVec3f pos = selectedModel->getPosition(); 

    switch (key) {
    case OF_KEY_LEFT:
        pos.x -= moveStep; // 向左移动
        break;
    case OF_KEY_RIGHT:
        pos.x += moveStep; // 向右移动
        break;
    case OF_KEY_UP:
        pos.y += moveStep; // 向上移动
        break;
    case OF_KEY_DOWN:
        pos.y -= moveStep; // 向下移动
        break;
    case 'q':
        pos.z -= moveStep; // 向里移动
        break;
    case 'e':
        pos.z += moveStep; // 向外移动
        break;    
    case 'i':
        if (selectedModel) {
            auto it = std::find(models.begin(), models.end(), selectedModel);
            if (it != models.end()) {
                models.erase(it); 
            }

            mainModel->removePart(selectedModel);

            selectedModel.reset(); 

            ofLogNotice() << "Selected model deleted.";
        }
        break;
    case 's':
    {
        if (selectedModel != nullptr) {
            ofLogNotice() << "Exporting selected model to STL file.";
            mainModel->exportModelToSTL(outputSTLPath); 
            ofLogNotice() << "Selected model exported to STL file.";
        }
        else {
            ofLogError() << "No model selected for export.";
        }
        break;
    }

    }
    if (selectedModel) { 
        selectedModel->setPosition(pos);
        ofLogNotice() << "位置" << pos;
    }
   
}

void ofApp::cubeButtonPressed() {    
    std::shared_ptr<CubeModel> newCube = std::make_shared<CubeModel>();   
    newCube->setSize(modelSize.get()); 
    newCube->setPosition(ofVec3f(0, 0, 0));
    models.push_back(newCube); 
    selectedModel = newCube;
    mainModel->addPart(newCube);
}

void ofApp::sphereButtonPressed() {
    
}

void ofApp::loadModelButtonPressed() {
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>();    
    std::string modelPath = MODEL_FILE_PATH;
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

void ofApp::loadBasemodelButtonPressed() {    
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>();
    std::string modelPath = "smpsqrcover.stl";
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
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>();
    //std::string modelPath = "smpsphrbase.stl";
    std::string modelPath = "2.stl";
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

void ofApp::loadSphrCovermodelButtonPressed() {
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>();
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
    std::shared_ptr<AssimpModel> newAssimpModel = std::make_shared<AssimpModel>();
    std::string modelPath = "sphrrabbitear.stl";
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
    int step = 15; 
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

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ofVec3f screenPoint(x, y);
    float closestDist = std::numeric_limits<float>::max();
    int closestIndex = -1;

    // 遍历所有模型，找到最接近点击点的模型
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
    }
    else {
        std::cout << "No model selected." << std::endl;
        selectedModel = nullptr;        
    }
}




//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    

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

