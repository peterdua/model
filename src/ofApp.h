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
#include "EarModel.h"
#include "ofTrueTypeFont.h"




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

	std::shared_ptr<EarModel> getLeftEarModel();

	std::shared_ptr<EarModel> getRightEarModel();

	void gotMessage(ofMessage msg);

	ofTrueTypeFont myFont;
	ofTrueTypeFont myFont20;
	
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
	ofxButton leftCatEarButton;
	ofxButton catFoot;
	ofxButton tealDragonwing;
	ofxButton batWings;
	ofxButton butterflyWings;
	ofxButton horn;
	ofxButton rabbitear;

	ofxButton loopButton;
	ofxButton loadModelButton;
	ofxButton loadBasemodelButton;
	ofxButton loadSphrCovermodelButton;
	ofxButton loadSphrBasemodelButton;

	ofParameter <int>modelSize;
	ofParameter <int>rotateX;
	ofParameter <int>rotateY;
	ofParameter <int>rotateZ;

	ofLight pointLight;

	EarModel* earModel;
	
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
	void catEarButtonPressed();
	void catFootButtonPressed();
	void tealDragonwingButtonPressed();
	void batWingsButtonPressed();
	void butterflyWingsButtonPressed();
	void hornButtonPressed();
	void rabbitearButtonPressed();

	void loadSphrrabEarButtonPressed();
	void loadLoopButtonPressed();

	void modelXrotationChanged(int& rotation);
	void modelYrotationChanged(int& rotation);
	void modelZrotationChanged(int& rotation);

	std::vector<std::shared_ptr<Model>> models;
	std::shared_ptr<Model> selectedModel = nullptr;
	std::shared_ptr<Model> mainModel = std::make_shared<Model>(); 
	std::shared_ptr<EarModel> leftEarModel;
	std::shared_ptr<EarModel> rightEarModel;
	std::shared_ptr<EarModel> catfootl;
	std::shared_ptr<EarModel> catfootr;
	std::shared_ptr<EarModel> tealwingl;
	std::shared_ptr<EarModel> tealwingr;
	std::shared_ptr<EarModel> batwingl;
	std::shared_ptr<EarModel> batwingr;
	std::shared_ptr<EarModel> butterwingr;
	std::shared_ptr<EarModel> butterwingl;
	std::shared_ptr<EarModel> hornl;
	std::shared_ptr<EarModel> hornr;
	std::shared_ptr<EarModel> rabearl;
	std::shared_ptr<EarModel> rabearr;


	ofVec3f pos2;
	ofVec3f pos;
	ofVec3f pos4;
	ofVec3f pos5;
	ofVec3f pos6;
	ofVec3f pos7;
	ofVec3f pos8;
	ofVec3f pos9;
	ofVec3f pos10;
	ofVec3f pos11;
	ofVec3f pos12;
	ofVec3f pos13;
	ofVec3f pos14;
	ofVec3f pos15;
	bool ear = false;
	bool catfoot = false;
	bool tealwing = false;
	bool isDragging = false;
	ofVec3f dragOffset; 
	std::shared_ptr<Model> draggableModel;
	bool altPressed = false;
	bool hasBaseModel = false; 
	bool spr = false;
	bool sphere = false;
};
