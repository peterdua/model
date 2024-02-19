#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {   
    
    gui.setup(); 
    gui.add(cubeButton.setup("Cube")); 
    gui.add(sphereButton.setup("Sphere")); 

    cubeButton.addListener(this, &ofApp::cubeButtonPressed);
    sphereButton.addListener(this, &ofApp::sphereButtonPressed);
}

//--------------------------------------------------------------
void ofApp::update() {
   
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(255);

    cam.begin(); 
    ofSetColor(128, 128, 128);

    for (auto& model : models) {
        model->draw(); 
    }
    if (selectedModel != nullptr) {
        ofVec3f position = selectedModel->getPosition();
        ofSetLineWidth(2);
        // X轴
        ofSetColor(ofColor::red);
        ofDrawLine(position, position + ofVec3f(100, 0, 0));
        // Y轴
        ofSetColor(ofColor::green);
        ofDrawLine(position, position + ofVec3f(0, 100, 0));
        // Z轴
        ofSetColor(ofColor::blue);
        ofDrawLine(position, position + ofVec3f(0, 0, 100));
    }
    cam.end(); 
    gui.draw(); // 渲染GUI界面
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { 
    float moveStep = 10.0; 
    ofVec3f pos = selectedModel->getPosition(); // 获取当前位置

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
    case 'Q':
        pos.z -= moveStep; // 向里移动
        break;
    case 'E':
        pos.z += moveStep; // 向外移动
        break;
    case 'S':
    {
        ofxSTLExporter exporter;
        exporter.useASCIIFormat(true); 
        exporter.beginModel("ExportedModel");

        for (auto* model : models) {
            model->addToSTL(exporter);
        }

        exporter.saveModel(outputSTLPath); // 保存STL文件
        ofLogNotice() << "All models exported to STL file.";
    }

    }

    selectedModel->setPosition(pos); // 更新模型位置   
   
}

void ofApp::cubeButtonPressed() {
    Model* newCube = new CubeModel(); 
   
    newCube->setPosition(ofVec3f(0, 0, 0));
    models.push_back(newCube); 
    selectedModel = newCube;
}

void ofApp::sphereButtonPressed() {
    
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

    for (int i = 0; i < models.size(); i++) {
        // 将模型的世界坐标位置转换为屏幕坐标
        ofVec3f modelScreenPos = cam.worldToScreen(models[i]->getPosition());

        float dist = modelScreenPos.distance(screenPoint);

        //std::cout << "Model " << i << " screen position: " << modelScreenPos << ", Dist: " << dist << std::endl;

        if (dist < closestDist) {
            closestDist = dist;
            closestIndex = i;
        }
    }

    if (closestIndex != -1) {
        selectedModel = models[closestIndex];
        //std::cout << "Selected model index: " << closestIndex << std::endl;
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


