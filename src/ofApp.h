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
#include "AccessoryModel.h"
#include "Cover.h"
#include "KeyHandler.h"
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
	void updateSelectedModel(std::shared_ptr<Model> newModel);

	void gotMessage(ofMessage msg);
	
	// GUIÔªËØ
	ofxPanel guiModel; 
	ofxPanel guiRotate; 
	ofxPanel guiBasemodel; 

	ofxFloatSlider rotateXSlider;
	ofxFloatSlider rotateYSlider;
	ofxFloatSlider rotateZSlider;
	
	ofxButton cubeButton;
	ofxButton sphereButton;
	ofxButton sphrEarButton;
	ofxButton loopButton;
	ofxButton loadModelButton;
	ofxButton loadBasemodelButton;
	ofxButton loadSphrCovermodelButton;
	ofxButton loadSphrBasemodelButton;

	ofParameter <int>modelSize;
	ofParameter <int>rotateX;
	ofParameter <int>rotateY;
	ofParameter <int>rotateZ;


	
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
	const std::string MODEL_FILE_PATH = "smpsqrbase.stl";

	ofMesh mesh;
	ofEasyCam cam;
	KeyHandler keyHandler;

	void cubeButtonPressed();
	void sphereButtonPressed();
	void loadModelButtonPressed();
	void loadBasemodelButtonPressed();
	void loadSphrBasemodelButtonPressed();
	void loadSphrCovermodelButtonPressed();

	void loadSphrrabEarButtonPressed();
	void loadLoopButtonPressed();

	void modelXrotationChanged(int& rotation);
	void modelYrotationChanged(int& rotation);
	void modelZrotationChanged(int& rotation);

	std::vector<std::shared_ptr<Model>> models;
	std::shared_ptr<Model> selectedModel = nullptr;
	std::shared_ptr<Model> mainModel = std::make_shared<Model>(); 
	bool isDragging = false;
	ofVec3f dragOffset; 
	std::shared_ptr<Model> draggableModel;
	bool altPressed = false;
	bool hasBaseModel = false; 
	bool spr = false;
	bool sphere = false;
};
