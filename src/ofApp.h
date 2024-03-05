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
#include "Cover.h"
#include <memory> 
#include <vector>



class ofApp : public ofBaseApp {

public:
	void setup();
	void modelSizeChanged(int& size);
	
	void update();
	void draw();
	void exit();

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
	
	// GUI元素
	ofxPanel guiModel; // 用于模型创建的GUI面板
	ofxPanel guiRotate; // 用于旋转控制的GUI面板

	ofxFloatSlider rotateXSlider;
	ofxFloatSlider rotateYSlider;
	ofxFloatSlider rotateZSlider;
	ofxButton rotateXPlus;
	ofxButton rotateXMinus;
	ofxButton rotateYPlus;
	ofxButton rotateYMinus;
	ofxButton rotateZPlus;
	ofxButton rotateZMinus;
	ofxButton cubeButton;
	ofxButton sphereButton;
	ofxButton loadModelButton;
	ofxButton loadBasemodelButton;
	ofParameter <int>modelSize;


	
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
	void loadBasemodelButtonPressed();

	void rotateXPlusClicked();
	void rotateXMinusClicked();
	void rotateYPlusClicked();
	void rotateYMinusClicked();
	void rotateZPlusClicked();
	void rotateZMinusClicked();

	int getSize();
	

	std::vector<std::shared_ptr<Model>> models;
	std::shared_ptr<Model> selectedModel = nullptr;
	std::shared_ptr<Model> mainModel = std::make_shared<Model>(); 
	

};
