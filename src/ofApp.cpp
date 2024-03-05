#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_NOTICE);
    cam.setPosition(ofVec3f(0, 0, 50)); 

    guiModel.setup("Model Creation"); 
    guiModel.add(cubeButton.setup("Cube"));
    guiModel.add(sphereButton.setup("Sphere"));
    guiModel.add(loadModelButton.setup("BaseModel-1"));
    guiModel.add(loadBasemodelButton.setup("CoverModel-1"));
    guiModel.add(modelSize.set("Size",10,1,50));
    
    guiModel.setPosition(10, 10); 

    int guiModelHeight = guiModel.getHeight();
    int spacing = 10; 
    guiRotate.setup("Rotation Control"); 
    guiRotate.add(rotateXPlus.setup("Rotate X+"));
    guiRotate.add(rotateXMinus.setup("Rotate X-"));
    guiRotate.add(rotateYPlus.setup("Rotate Y+"));
    guiRotate.add(rotateYMinus.setup("Rotate Y-"));
    guiRotate.add(rotateZPlus.setup("Rotate Z+"));
    guiRotate.add(rotateZMinus.setup("Rotate Z-"));
    guiRotate.setPosition(10, 10 + guiModelHeight + spacing); 

    cubeButton.addListener(this, &ofApp::cubeButtonPressed);
    sphereButton.addListener(this, &ofApp::sphereButtonPressed);
    loadModelButton.addListener(this, &ofApp::loadModelButtonPressed);
    modelSize.addListener(this, &ofApp::modelSizeChanged);
    loadBasemodelButton.addListener(this, &ofApp::loadBasemodelButtonPressed);

    rotateXPlus.addListener(this, &ofApp::rotateXPlusClicked);
    rotateXMinus.addListener(this, &ofApp::rotateXMinusClicked);
    rotateYPlus.addListener(this, &ofApp::rotateYPlusClicked);
    rotateYMinus.addListener(this, &ofApp::rotateYMinusClicked);
    rotateZPlus.addListener(this, &ofApp::rotateZPlusClicked);
    rotateZMinus.addListener(this, &ofApp::rotateZMinusClicked);

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
    //string filepath = "holdertest.obj"; 
    //string filepath = "sphere.stl"; 
    //string filepath = "2.stl"; 
    //string filepath = "smpgaizi.stl"; 
    string filepath = "smpbase.stl"; 

    std::shared_ptr<AssimpModel> newModel = std::make_shared<AssimpModel>();
    if (newModel->loadModel(filepath)) {        
        models.push_back(newModel); 
        selectedModel = newModel; 
        for (int i = 0; i < newModel->modelLoader.getMeshCount(); ++i) {
            ofMesh mesh = newModel->modelLoader.getMesh(i);          
            std::vector<ofIndexType> indices = mesh.getIndices();
            if (indices.size() % 3 == 0) {                
                mainModel->addMesh(mesh);
            }
            else {             
                ofLogNotice() << "Mesh " << i << " 的索引数量不是3的倍数，已跳过。";               
            }
        }
        mainModel->addPart(newModel);         
        
        ofLogNotice("MainModel Info") << "MainModel now has " << mainModel->parts.size() << " parts.";
        mainModel->printMeshInfo();
    }
    else {
        ofLogError("Model Loading") << "Failed to load model: " << filepath;
        
    }
}

void ofApp::loadBasemodelButtonPressed() {    
    string filepath = "smpgaizi.stl";

    std::shared_ptr<Cover> newModel = std::make_shared<Cover>();
    if (newModel->loadModel(filepath)) {
        models.push_back(newModel);
        selectedModel = newModel;
        for (int i = 0; i < newModel->modelLoader.getMeshCount(); ++i) {
            ofMesh mesh = newModel->modelLoader.getMesh(i);
            std::vector<ofIndexType> indices = mesh.getIndices();
            if (indices.size() % 3 == 0) {
                mainModel->addMesh(mesh);
            }
            else {
                ofLogNotice() << "Mesh " << i << " 的索引数量不是3的倍数，已跳过。";
            }
        }
        mainModel->addPart(newModel);

        ofLogNotice("MainModel Info") << "MainModel now has " << mainModel->parts.size() << " parts.";
        mainModel->printMeshInfo();
    }
    else {

        ofLogError("Model Loading") << "Failed to load model: " << filepath;
    }
}

void ofApp::rotateXPlusClicked() {
    if (selectedModel != nullptr) {
        selectedModel->rotate(15, ofVec3f(1, 0, 0));
        ofLogNotice() << "x+";
        selectedModel->combineMeshes();

    }
}

void ofApp::rotateXMinusClicked() {
    if (selectedModel != nullptr) {
        selectedModel->rotate(-15, ofVec3f(1, 0, 0));
        ofLogNotice() << "x-";

    }
}

void ofApp::rotateYPlusClicked() {
    if (selectedModel != nullptr) {
       
        selectedModel->rotate(15, ofVec3f(0, 1, 0)); // 绕Y轴正向旋转15度
    }
}

void ofApp::rotateYMinusClicked() {
    if (selectedModel != nullptr) {
        
        selectedModel->rotate(-15, ofVec3f(0, 1, 0)); // 绕Y轴反向旋转15度
    }
}

void ofApp::rotateZPlusClicked() {
    if (selectedModel != nullptr) {
        
        selectedModel->rotate(15, ofVec3f(0, 0, 1)); // 绕Z轴正向旋转15度
    }
}

void ofApp::rotateZMinusClicked() {
    if (selectedModel != nullptr) {
        
        selectedModel->rotate(-15, ofVec3f(0, 0, 1)); // 绕Z轴反向旋转15度
    }
}

int ofApp::getSize()
{
    return modelSize;
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

