#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_NOTICE);
    gui.setup();
    gui.add(cubeButton.setup("Cube"));
    gui.add(sphereButton.setup("Sphere"));

    gui.add(loadModelButton.setup("Load Model"));

    cubeButton.addListener(this, &ofApp::cubeButtonPressed);
    sphereButton.addListener(this, &ofApp::sphereButtonPressed);

    loadModelButton.addListener(this, &ofApp::loadModelButtonPressed);
}

//--------------------------------------------------------------
void ofApp::update() {
   
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor::white, ofColor::gray);

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
    case 'q':
        pos.z -= moveStep; // �����ƶ�
        break;
    case 'e':
        pos.z += moveStep; // �����ƶ�
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

    selectedModel->setPosition(pos);  
   
}

void ofApp::cubeButtonPressed() {
    Model* newCube = new CubeModel(); 
   
    newCube->setPosition(ofVec3f(0, 0, 0));
    models.push_back(newCube); 
    selectedModel = newCube;
    mainModel->addPart(*newCube); 

}

void ofApp::sphereButtonPressed() {
    
}

void ofApp::loadModelButtonPressed() {
    string filepath = "holder1.stl"; 
    //string filepath = "sphere.stl"; 
    //string filepath = "2.stl"; 

    AssimpModel* newModel = new AssimpModel(); 
    if (newModel->loadModel(filepath)) { 
        ofLogNotice("Model Loaded") << "Model loaded successfully with mesh count: " << newModel->modelLoader.getMeshCount();
        for (int i = 0; i < newModel->modelLoader.getMeshCount(); ++i) {
            ofMesh mesh = newModel->modelLoader.getMesh(i);
            ofLogNotice("Model Loaded") << "Mesh " << i << ": Vertex Count = " << mesh.getNumVertices();
            ofLogNotice("Model Loaded") << "Mesh " << i << ": Index Count = " << mesh.getNumIndices();
            ofLogNotice("Model Loaded") << "Mesh " << i << ": Normal Count = " << mesh.getNumNormals();
            ofLogNotice("Model Loaded") << "Mesh " << i << ": TexCoords Count = " << mesh.getNumTexCoords();
        }
        models.push_back(newModel); 
        selectedModel = newModel; 

        for (int i = 0; i < newModel->modelLoader.getMeshCount(); ++i) {
            ofMesh mesh = newModel->modelLoader.getMesh(i);
          
            std::vector<ofIndexType> indices = mesh.getIndices();

            if (indices.size() % 3 == 0) {
                
                mainModel->combineMeshes(mesh);
            }
            else {
             
                ofLogNotice() << "Mesh " << i << " ��������������3�ı�������������";
               
            }
        }

        mainModel->addPart(*newModel); 
        
        
        ofLogNotice("MainModel Info") << "MainModel now has " << mainModel->parts.size() << " parts.";
        mainModel->printMeshInfo();
    }
    else {
        ofLogError("Model Loading") << "Failed to load model: " << filepath;
        delete newModel; 
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


