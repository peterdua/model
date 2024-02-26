#pragma once

#include "ofMain.h"
#include "ofxSTL.h" 
#include "ofxSTLFacet.h" 
#include "ofxSTLBase.h" 
#include "ofxGui.h"
#include "Model.h"
#include "CubeModel.h"
#include "ofxAssimpModelLoader.h"
#include "AssimpModel.h"

#include <vector>



class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	

	ofxPanel gui;
	ofxButton cubeButton;
	ofxButton sphereButton;
	ofxButton loadModelButton;

	
	std::vector<ofBoxPrimitive> cubes;	
	int selectedCubeIndex = -1; 
	float moveStep = 1;
	ofVec3f moveDirection;	

	ofBoxPrimitive cube;
	bool drawCube = false; 
	char selectedAxis = 'none'; 

	ofxSTLImporter stlImporter;
	ofxSTLExporter stlExporter;
	ofxSTLBase stlModel;
	string inputSTLPath = "cube.stl";
	string outputSTLPath = "test.stl";
	ofMesh mesh;
	ofEasyCam cam;

	void cubeButtonPressed();
	void sphereButtonPressed();
	void loadModelButtonPressed();

	std::vector<Model*> models; // 存储所有模型的指针
	Model* selectedModel = nullptr; // 指向当前选中模型的指针
	Model* mainModel = new Model(); // 作为所有模型部分的容器

};
