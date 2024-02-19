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
        // X��
        ofSetColor(ofColor::red);
        ofDrawLine(position, position + ofVec3f(100, 0, 0));
        // Y��
        ofSetColor(ofColor::green);
        ofDrawLine(position, position + ofVec3f(0, 100, 0));
        // Z��
        ofSetColor(ofColor::blue);
        ofDrawLine(position, position + ofVec3f(0, 0, 100));
    }
    cam.end(); 
    gui.draw(); // ��ȾGUI����
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { 
    float moveStep = 10.0; 
    ofVec3f pos = selectedModel->getPosition(); // ��ȡ��ǰλ��

    switch (key) {
    case OF_KEY_LEFT:
        pos.x -= moveStep; // �����ƶ�
        break;
    case OF_KEY_RIGHT:
        pos.x += moveStep; // �����ƶ�
        break;
    case OF_KEY_UP:
        pos.y += moveStep; // �����ƶ�
        break;
    case OF_KEY_DOWN:
        pos.y -= moveStep; // �����ƶ�
        break;
    case 'Q':
        pos.z -= moveStep; // �����ƶ�
        break;
    case 'E':
        pos.z += moveStep; // �����ƶ�
        break;
    case 'S':
    {
        ofxSTLExporter exporter;
        exporter.useASCIIFormat(true); 
        exporter.beginModel("ExportedModel");

        for (auto* model : models) {
            model->addToSTL(exporter);
        }

        exporter.saveModel(outputSTLPath); // ����STL�ļ�
        ofLogNotice() << "All models exported to STL file.";
    }

    }

    selectedModel->setPosition(pos); // ����ģ��λ��   
   
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
        // ��ģ�͵���������λ��ת��Ϊ��Ļ����
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


