#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_NOTICE);
    cam.disableMouseInput(); // 初始时禁用，只有在按下Alt时才启用    
    ofEnableDepthTest();
    pointLight.setDiffuseColor(ofColor(255, 255, 255)); // 设置光源的漫反射颜色
    pointLight.setPointLight(); // 设置为点光源
    myFont.load("Cute-Aurora-2.ttf", 32);
    myFont20.load("Cute-Aurora-2.ttf", 20);
    cam.setPosition(ofVec3f(0, 0, 50)); 

    guiModel.setup("Decorations");      
    guiModel.add(leftCatEarButton.setup("Cat ear"));
    guiModel.add(catFoot.setup("Cat foot"));
    guiModel.add(tealDragonwing.setup("Bat Wings"));
    guiModel.add(batWings.setup("Teal Dragonwings"));
    guiModel.add(butterflyWings.setup("Butterfly Wings"));
    guiModel.add(horn.setup("Dragon horns"));
    guiModel.add(rabbitear.setup("rabbit ear"));

    guiModel.add(loopButton.setup("Loop"));
    //guiModel.add(modelSize.set("Size",10,1,50));
    guiModel.setPosition(10, 10); 

    int guiModelHeight1 = guiModel.getHeight();
    int spacing = 10;

    guiBasemodel.setup("Base holder");
    guiBasemodel.add(loadSphrBasemodelButton.setup("Sphare holder"));    
    guiBasemodel.setPosition(10, 10 + guiModelHeight1 + spacing);

    int guiModelHeight = guiBasemodel.getHeight();     
    guiRotate.setup("Rotation Control"); 
    guiRotate.add(rotateX.set("X", 0, -360, 360));   
    guiRotate.add(rotateY.set("Y", 0, -360, 360));
    guiRotate.add(rotateZ.set("Z", 0, -360, 360));
    guiRotate.setPosition(10, 20 + guiModelHeight + guiModelHeight1 + spacing); 

    sphrEarButton.addListener(this, &ofApp::loadSphrrabEarButtonPressed);
    loopButton.addListener(this, &ofApp::loadLoopButtonPressed);
    loadModelButton.addListener(this, &ofApp::loadModelButtonPressed);
    modelSize.addListener(this, &ofApp::modelSizeChanged);
    leftCatEarButton.addListener(this, &ofApp::catEarButtonPressed);
    catFoot.addListener(this, &ofApp::catFootButtonPressed);
    tealDragonwing.addListener(this, &ofApp::tealDragonwingButtonPressed);
    batWings.addListener(this, &ofApp::batWingsButtonPressed);
    butterflyWings.addListener(this, &ofApp::butterflyWingsButtonPressed);
    horn.addListener(this, &ofApp::hornButtonPressed);
    rabbitear.addListener(this, &ofApp::rabbitearButtonPressed);

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
    pointLight.disable();

    ofBackgroundGradient(ofColor::white, ofColor::gray);
    std::string message = "Watch Crafter!";
    float textWidth = myFont.stringWidth(message); 
    float xPosition = (ofGetWidth() / 2) - (textWidth / 2); 
    float yPosition = 50;
    myFont.drawString(message, xPosition, yPosition);
    myFont20.drawString("Hold the 'Alt' key and ", 240, 30);
    myFont20.drawString("drag with the left mouse button", 240, 60);
    myFont20.drawString("to rotate the entire view.", 240, 90);
    myFont20.drawString("Press keyboard: S", 240, 130);
    myFont20.drawString("To save your model.", 240, 160);

    myFont20.drawString("Press keyboard: 1", 240, 200);
    myFont20.drawString("Switch model to wireframe or solid", 240, 230);


    myFont20.drawString("Press keyboard：", 50, 350);
    myFont20.drawString("LEFT RIGHT UP DOWN", 50, 400);
    myFont20.drawString("To move Decorations", 50, 450);

    cam.begin();    
    pointLight.enable(); // 启用光源
    pointLight.setPosition(ofVec3f(0, 0, -70)); 


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
    pointLight.disable();
    ofDisableLighting();
    ofDisableDepthTest();

    cam.end(); 
    guiRotate.draw(); 
    guiModel.draw(); 
    guiBasemodel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { 
    if (selectedModel)
    {   
    if (selectedModel == rightEarModel || selectedModel == leftEarModel) {
        pos2 = rightEarModel->getPosition();
        pos = leftEarModel->getPosition();        
    
    }
    else if (selectedModel == catfootr || selectedModel == catfootl) {
        pos4 = catfootr->getPosition();
        pos5 = catfootl->getPosition();
    }
    else if (selectedModel == tealwingr || selectedModel == tealwingl) {
        pos6 = tealwingr->getPosition();
        pos7 = tealwingl->getPosition();
    }
    else if (selectedModel == batwingl || selectedModel == batwingr) {
        pos8 = batwingr->getPosition();
        pos9 = batwingl->getPosition();
    }
    else if (selectedModel == butterwingl || selectedModel == butterwingr) {
        pos10 = butterwingr->getPosition();
        pos11 = butterwingl->getPosition();
    }
    else if (selectedModel == hornl || selectedModel == hornr) {
        pos12 = hornr->getPosition();
        pos13 = hornl->getPosition();
    }
    else if (selectedModel == rabearl || selectedModel == rabearr) {
        pos14 = rabearr->getPosition();
        pos15 = rabearl->getPosition();
    }

    keyHandler.handleKeyPress(selectedModel, key, models, mainModel, spr, sphere, pos2, pos, pos4, pos5,pos6,pos7,pos8,pos9,pos10,pos11,pos12,pos13,pos14,pos15);
    if (selectedModel->getType() == "leftcatear")
    {
        rightEarModel->setPosition(pos2);
    }
    else if (selectedModel->getType() == "rightcatear") {
        leftEarModel->setPosition(pos);
    }
    else if (selectedModel->getType() == "catfootl") {
        catfootr->setPosition(pos4);
    }
    else if (selectedModel->getType() == "catfootr") {
        catfootl->setPosition(pos5);
    }
    else if (selectedModel->getType() == "tealwingl") {
        tealwingr->setPosition(pos6);
    }
    else if (selectedModel->getType() == "tealwingr") {
        tealwingl->setPosition(pos7);
    }
    else if (selectedModel->getType() == "batwingl") {
        batwingr->setPosition(pos8);
    }
    else if (selectedModel->getType() == "batwingr") {
        batwingl->setPosition(pos9);
    }
    else if (selectedModel->getType() == "butterwingl") {
        butterwingr->setPosition(pos10);
    }
    else if (selectedModel->getType() == "butterwingr") {
        butterwingl->setPosition(pos11);
    }
    else if (selectedModel->getType() == "hornl") {
        hornr->setPosition(pos12);
        ofLogNotice() << "hornl 12";
    }
    else if (selectedModel->getType() == "hornr") {
        hornl->setPosition(pos13);
        ofLogNotice() << "hornr 13";

    }
    else if (selectedModel->getType() == "rabearl") {
        rabearr->setPosition(pos14);
    }
    else if (selectedModel->getType() == "rabearr") {
        rabearl->setPosition(pos15);
    }
    }

    switch (key) {
    case '1': {
        for (auto& model : models) {
            model->toggleWireframeMode();
        }
    }
            break;
        
    case OF_KEY_ALT:
        altPressed = true;
        cam.enableMouseInput(); // 启用摄像机的鼠标输入
        break;
    case OF_KEY_BACKSPACE:
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
            mainModel->exportModelToSTL("yourModel.stl"); 
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
    std::shared_ptr<EarModel> newAssimpModel = std::make_shared<EarModel>("loop");
    std::string modelPath = "loop.stl";
    if (newAssimpModel->loadModel(modelPath)) {
        newAssimpModel->adMeshes();
        models.push_back(newAssimpModel);
        selectedModel = newAssimpModel;
        mainModel->addPart(newAssimpModel);

        ofVec3f newPosition = ofVec3f(26.0f, 0.0f, 0.0f);
        newAssimpModel->setPosition(newPosition);
        newAssimpModel->setPresetPositions({ ofVec3f(-31.5f, -2.0f, 0.0f), ofVec3f(30.0f, -2.0f, 0.0f), ofVec3f(0.0f, 24.0f, -3.0f), ofVec3f(0.0f, -25.5f, 0.0f) });

    }
    else {
        ofLogError("AssimpModelButtonPressed") << "Failed to load model: " << modelPath;
    }
}

void ofApp::catEarButtonPressed() {    
    ear = true;
    rightEarModel = std::make_shared<EarModel>("rightcatear");
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

    
    leftEarModel = std::make_shared<EarModel>("leftcatear");
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
    leftEarModel->setPairedModel(rightEarModel); 
    rightEarModel->setPairedModel(leftEarModel); 

    leftEarModel->setPresetPositions({ ofVec3f(-28.0f, -11.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 20.0f, 0.0f), ofVec3f(20.0f, -21.0f, 0.0f) });
    leftEarModel->setPairedPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 20.0f, 0.0f), ofVec3f(-20.0f, -21.0f, 0.0f) });

    rightEarModel->setPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 20.0f, 0.0f), ofVec3f(-20.0f, -21.0f, 0.0f) });
    rightEarModel->setPairedPresetPositions({ ofVec3f(-28.0f, -11.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 20.0f, 0.0f), ofVec3f(20.0f, -21.0f, 0.0f) });

}

void ofApp::catFootButtonPressed() {
    catfoot = true;
    catfootr = std::make_shared<EarModel>("catfootr");
    std::string rightEar = "catfoot.stl";
    if (catfootr->loadModel(rightEar)) {
        catfootr->adMeshes();
        models.push_back(catfootr);
        mainModel->addPart(catfootr);
        ofVec3f leftPosition = ofVec3f(8.5f, 24.0f, -3.3f);
        catfootr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << catfootr;
    }

    catfootl = std::make_shared<EarModel>("catfootl");
    std::string rightModelPath = "catfoot.stl";
    if (catfootl->loadModel(rightModelPath)) {
        catfootl->adMeshes();
        models.push_back(catfootl);
        mainModel->addPart(catfootl);

        ofVec3f rightPosition = ofVec3f(-10.0f, 24.0f, -3.3f);
        catfootl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << catfootl;
    }
    catfootl->setPairedModel(catfootr); 
    catfootr->setPairedModel(catfootl); 

    catfootl->setPresetPositions({ ofVec3f(-28.0f, -13.0f, 0.0f), ofVec3f(28.0f, 9.0f, 0.0f), ofVec3f(-10.0f, 24.0f, -3.3f), ofVec3f(10.0f, -26.0f, -3.3f) });
    catfootl->setPairedPresetPositions({ ofVec3f(-28.0f, 9.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(8.5f, 24.0f, -3.3f), ofVec3f(-10.0f, -26.0f, -3.3f) });

    catfootr->setPresetPositions({ ofVec3f(-28.0f, 9.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(8.5f, 24.0f, -3.3f), ofVec3f(-10.0f, -26.0f, -3.3f) });
    catfootr->setPairedPresetPositions({ ofVec3f(-28.0f, -13.0f, 0.0f), ofVec3f(28.0f, 9.0f, 0.0f), ofVec3f(-10.0f, 24.0f, -3.3f), ofVec3f(10.0f, -26.0f, -3.3f) });

}

void ofApp::tealDragonwingButtonPressed() {
    tealwing = true;
    tealwingr = std::make_shared<EarModel>("tealwingr");
    std::string rightEar = "tealwingr.stl";
    if (tealwingr->loadModel(rightEar)) {
        tealwingr->adMeshes();
        models.push_back(tealwingr);
        mainModel->addPart(tealwingr);
        ofVec3f leftPosition = ofVec3f(34.0f, 4.0f, 0.0f);
        tealwingr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << tealwingr;
    }

    tealwingl = std::make_shared<EarModel>("tealwingl");
    std::string rightModelPath = "tealwingl.stl";
    if (tealwingl->loadModel(rightModelPath)) {
        tealwingl->adMeshes();
        models.push_back(tealwingl);
        mainModel->addPart(tealwingl);

        ofVec3f rightPosition = ofVec3f(-35.0f, 4.0f, .0f);
        tealwingl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << tealwingl;
    }
    tealwingl->setPairedModel(tealwingr); // 设置配对模型
    tealwingr->setPairedModel(tealwingl); // 相互配对

    // 为每个耳朵模型设置位置
    tealwingl->setPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });
    tealwingl->setPairedPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });

    tealwingr->setPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, -4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });
    tealwingr->setPairedPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, -4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });

}

void ofApp::batWingsButtonPressed() {
    batwingr = std::make_shared<EarModel>("batwingr");
    std::string rightEar = "batwingr.stl";
    if (batwingr->loadModel(rightEar)) {
        batwingr->adMeshes();
        models.push_back(batwingr);
        mainModel->addPart(batwingr);
        ofVec3f leftPosition = ofVec3f(34.0f, 4.0f, 0.0f);
        batwingr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << batwingr;
    }

    batwingl = std::make_shared<EarModel>("batwingl");
    std::string rightModelPath = "batwingl.stl";
    if (batwingl->loadModel(rightModelPath)) {
        batwingl->adMeshes();
        models.push_back(batwingl);
        mainModel->addPart(batwingl);

        ofVec3f rightPosition = ofVec3f(-35.0f, 4.0f, .0f);
        batwingl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << batwingl;
    }
    batwingl->setPairedModel(batwingr); // 设置配对模型
    batwingr->setPairedModel(batwingl); // 相互配对

    // 为每个耳朵模型设置位置
    batwingl->setPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });
    batwingl->setPairedPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });

    batwingr->setPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, -4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });
    batwingr->setPairedPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, -4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });
}

void ofApp::butterflyWingsButtonPressed() {
    butterwingr = std::make_shared<EarModel>("butterwingr");
    std::string rightEar = "butterwingr.stl";
    if (butterwingr->loadModel(rightEar)) {
        butterwingr->adMeshes();
        models.push_back(butterwingr);
        mainModel->addPart(butterwingr);
        ofVec3f leftPosition = ofVec3f(34.0f, 4.0f, -4.8f);
        butterwingr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << butterwingr;
    }

    butterwingl = std::make_shared<EarModel>("butterwingl");
    std::string rightModelPath = "butterwingl.stl";
    if (butterwingl->loadModel(rightModelPath)) {
        butterwingl->adMeshes();
        models.push_back(butterwingl);
        mainModel->addPart(butterwingl);

        ofVec3f rightPosition = ofVec3f(-35.0f, 4.0f, -4.8f);
        butterwingl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << butterwingl;
    }
    butterwingl->setPairedModel(butterwingr); // 设置配对模型
    butterwingr->setPairedModel(butterwingl); // 相互配对

    // 为每个耳朵模型设置位置
    butterwingl->setPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });
    butterwingl->setPairedPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });

    butterwingr->setPresetPositions({ ofVec3f(34.0f, 4.0f, 0.0f), ofVec3f(-35.0f, -4.0f, 0.0f), ofVec3f(0.0f, -31.0f, -4.8f), ofVec3f(0.0f, 28.0f, -4.8f) });
    butterwingr->setPairedPresetPositions({ ofVec3f(-35.0f, 4.0f, 0.0f), ofVec3f(34.0f, -4.0f, 0.0f), ofVec3f(0.0f, 28.0f, -4.8f), ofVec3f(0.0f, -31.0f, -4.8f) });
}

void ofApp::hornButtonPressed() {    
    hornr = std::make_shared<EarModel>("hornr");
    std::string rightEar = "hornr.stl";
    if (hornr->loadModel(rightEar)) {
        hornr->adMeshes();
        models.push_back(hornr);
        mainModel->addPart(hornr);
        ofVec3f leftPosition = ofVec3f(23.0f, 18.0f, -2.0f);
        hornr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << hornr;
    }


    hornl = std::make_shared<EarModel>("hornl");
    std::string rightModelPath = "hornl.stl";
    if (hornl->loadModel(rightModelPath)) {
        hornl->adMeshes();
        models.push_back(hornl);
        mainModel->addPart(hornl);

        ofVec3f rightPosition = ofVec3f(-23.0f, 18.0f, -2.0f);
        hornl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << hornl;
    }
    hornl->setPairedModel(hornr); // 设置配对模型
    hornr->setPairedModel(hornl); // 相互配对

    // 为每个耳朵模型设置位置
    hornl->setPresetPositions({ ofVec3f(-28.0f, -15.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 23.0f, -2.0f), ofVec3f(20.0f, -27.0f, -2.0f) });
    hornl->setPairedPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -15.0f, 0.0f), ofVec3f(18.5f, 23.0f, -2.0f), ofVec3f(-20.0f, -27.0f, -2.0f) });

    hornr->setPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -15.0f, 0.0f), ofVec3f(18.5f, 23.0f, 0.0f), ofVec3f(-20.0f, -27.0f, -2.0f) });
    hornr->setPairedPresetPositions({ ofVec3f(-28.0f, -15.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 23.0f, 0.0f), ofVec3f(20.0f, -27.0f, -2.0f) });

}

void ofApp::rabbitearButtonPressed() {
    rabearr = std::make_shared<EarModel>("rabearr");
    std::string rightEar = "rabearr.stl";
    if (rabearr->loadModel(rightEar)) {
        rabearr->adMeshes();
        models.push_back(rabearr);
        mainModel->addPart(rabearr);
        ofVec3f leftPosition = ofVec3f(23.0f, 18.0f, -3.8f);
        rabearr->setPosition(leftPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load left ear model: " << rabearr;
    }


    rabearl = std::make_shared<EarModel>("rabearl");
    std::string rightModelPath = "rabearl.stl";
    if (rabearl->loadModel(rightModelPath)) {
        rabearl->adMeshes();
        models.push_back(rabearl);
        mainModel->addPart(rabearl);

        ofVec3f rightPosition = ofVec3f(-23.0f, 18.0f, -3.8f);
        rabearl->setPosition(rightPosition);
    }
    else {
        ofLogError("catEarButtonPressed") << "Failed to load right ear model: " << rabearl;
    }
    rabearl->setPairedModel(rabearr); // 设置配对模型
    rabearr->setPairedModel(rabearl); // 相互配对

    // 为每个耳朵模型设置位置
    rabearl->setPresetPositions({ ofVec3f(-28.0f, -11.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 20.0f, -3.8f), ofVec3f(20.0f, -21.0f,  -3.8f) });
    rabearl->setPairedPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 20.0f,  -3.8f), ofVec3f(-20.0f, -21.0f,  -3.8f) });

    rabearr->setPresetPositions({ ofVec3f(-28.0f, 11.0f, 0.0f), ofVec3f(28.0f, -13.0f, 0.0f), ofVec3f(18.5f, 20.0f,  -3.8f), ofVec3f(-20.0f, -21.0f,  -3.8f) });
    rabearr->setPairedPresetPositions({ ofVec3f(-28.0f, -11.0f, 0.0f), ofVec3f(28.0f, 11.0f, 0.0f), ofVec3f(-20.0f, 20.0f, -3.8f), ofVec3f(20.0f, -21.0f,  -3.8f) });

}

void ofApp::modelXrotationChanged(int& rotation) {
    int step = 2; 
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
    int step = 2; 
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
    int step = 2; 
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
    if (closestIndex != -1 && closestIndex < models.size()) {
        selectedModel = models[closestIndex];         
        if (selectedModel) {
            updateSelectedModel(selectedModel);
            isDragging = true;
            draggableModel = selectedModel;
            earModel = dynamic_cast<EarModel*>(selectedModel.get());
            if (draggableModel) {
                dragOffset = cam.worldToScreen(draggableModel->getPosition()) - screenPoint;
            }
        }
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

    if (isDragging && earModel && sphere) {
        isDragging = false;

        std::string modelType = earModel->getType();       

        if (!earModel->presetPositions.empty()) {
            ofVec3f currentPos = earModel->getPosition();
            float minDistance = std::numeric_limits<float>::max();
            int closestIndex = -1;

            // 使用 EarModel 中的 presetPositions 来查找最近的位置
            for (int i = 0; i < earModel->presetPositions.size(); i++) {
                float distance = currentPos.distance(earModel->presetPositions[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = i;
                }
            }
            if (closestIndex != -1 && altPressed == false) {

                earModel->updatePosition(closestIndex, altPressed);


                if (modelType == "loop") {
                    if (closestIndex == 0) { 
                        earModel->setRotation(180, yaxis);
                        earModel->setRotation(0, zaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(0, yaxis);
                        earModel->setRotation(0, zaxis);
                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(90, zaxis);
                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setDirection("down");
                    }
                }
                else if (modelType == "rabear") {
                    if (closestIndex == 0) { 
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(0, zaxis);
                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(180, zaxis);
                        //earModel->setRotation(0, zaxis);
                        earModel->setDirection("down");
                    }
                }  
                else if (modelType == "leftcatear") {
                    if (closestIndex == 0) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);   

                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);                        
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);
                        
                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);                      


                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(0, zaxis);

                        earModel->pairedModel->setRotation(0, zaxis);

                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(180, zaxis);

                        earModel->pairedModel->setRotation(180, zaxis);
                      
                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                }
                else if (modelType == "rightcatear") {
                    if (closestIndex == 0) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);

                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);

                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);

                       
                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);

                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(0, zaxis);

                        earModel->pairedModel->setRotation(0, zaxis);

                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(180, zaxis);

                        earModel->pairedModel->setRotation(180, zaxis);

                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                }
                else if (modelType == "catfootl") {
                    if (closestIndex == 0) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);

                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);

                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);


                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(0, zaxis);

                        earModel->pairedModel->setRotation(0, zaxis);

                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(180, zaxis);

                        earModel->pairedModel->setRotation(180, zaxis);

                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                    }
                else if (modelType == "catfootr") {
                        if (closestIndex == 0) {
                            earModel->setRotation(90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("left");
                        }
                        else if (closestIndex == 1) {
                            earModel->setRotation(-90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(-90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("right");
                        }
                        else if (closestIndex == 2) {
                            earModel->setRotation(0, zaxis);
                            earModel->pairedModel->setRotation(0, zaxis);
                            earModel->setDirection("up");
                        }
                        else if (closestIndex == 3) {
                            earModel->setRotation(180, zaxis);
                            earModel->pairedModel->setRotation(180, zaxis);
                            //earModel->setRotation(0, zaxis);                       
                            earModel->setDirection("down");
                        }
                        }
                else if (modelType == "tealwingl") {
                    if (closestIndex == 0) {
                        earModel->setRotation(0, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(0, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {                        
                        earModel->setRotation(180, yaxis);
                        earModel->setRotation(0, zaxis);
                        earModel->pairedModel->setRotation(180, yaxis);
                        earModel->pairedModel->setRotation(0, zaxis);                        

                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {                        
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {                        
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                    }
                else if (modelType == "tealwingr") {
                    if (closestIndex == 0) {
                        earModel->setRotation(0, yaxis);
                        earModel->setRotation(0, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(0, zaxis);
                        earModel->setDirection("left");
                       
                    }
                    else if (closestIndex == 1) {                            

                        earModel->setRotation(180, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(180, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("right");                       

                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                    }
                else if (modelType == "batwingl") {
                    if (closestIndex == 0) {
                        earModel->setRotation(0, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(0, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(180, yaxis);
                        earModel->setRotation(0, zaxis);
                        earModel->pairedModel->setRotation(180, yaxis);
                        earModel->pairedModel->setRotation(0, zaxis);

                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);
                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                    }
                else if (modelType == "batwingr") {
                        if (closestIndex == 0) {
                            earModel->setRotation(0, yaxis);
                            earModel->setRotation(0, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(0, zaxis);
                            earModel->setDirection("left");

                        }
                        else if (closestIndex == 1) {

                            earModel->setRotation(180, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(180, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("right");

                        }
                        else if (closestIndex == 2) {
                            earModel->setRotation(-90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(-90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("up");
                        }
                        else if (closestIndex == 3) {
                            earModel->setRotation(90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            //earModel->setRotation(0, zaxis);                       
                            earModel->setDirection("down");
                        }
                        }
                else if (modelType == "butterwingl") {
                            if (closestIndex == 0) {
                                earModel->setRotation(0, zaxis);
                                earModel->setRotation(0, yaxis);
                                earModel->pairedModel->setRotation(0, zaxis);
                                earModel->pairedModel->setRotation(0, yaxis);
                                earModel->setDirection("left");
                            }
                            else if (closestIndex == 1) {
                                earModel->setRotation(180, yaxis);
                                earModel->setRotation(0, zaxis);
                                earModel->pairedModel->setRotation(180, yaxis);
                                earModel->pairedModel->setRotation(0, zaxis);

                                earModel->setDirection("right");
                            }
                            else if (closestIndex == 2) {
                                earModel->setRotation(-90, zaxis);
                                earModel->setRotation(0, yaxis);
                                earModel->pairedModel->setRotation(-90, zaxis);
                                earModel->pairedModel->setRotation(0, yaxis);
                                earModel->setDirection("up");
                            }
                            else if (closestIndex == 3) {
                                earModel->setRotation(90, zaxis);
                                earModel->setRotation(0, yaxis);
                                earModel->pairedModel->setRotation(90, zaxis);
                                earModel->pairedModel->setRotation(0, yaxis);
                                //earModel->setRotation(0, zaxis);                       
                                earModel->setDirection("down");
                            }
                            }
                else if (modelType == "butterwingr") {
                                if (closestIndex == 0) {
                                    earModel->setRotation(0, yaxis);
                                    earModel->setRotation(0, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(0, zaxis);
                                    earModel->setDirection("left");

                                }
                                else if (closestIndex == 1) {

                                    earModel->setRotation(180, zaxis);
                                    earModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(180, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    earModel->setDirection("right");

                                }
                                else if (closestIndex == 2) {
                                    earModel->setRotation(-90, zaxis);
                                    earModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(-90, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    earModel->setDirection("up");
                                }
                                else if (closestIndex == 3) {
                                    earModel->setRotation(90, zaxis);
                                    earModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(90, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    //earModel->setRotation(0, zaxis);                       
                                    earModel->setDirection("down");
                                }
                                }

                else if (modelType == "hornl") {
                    if (closestIndex == 0) {
                        earModel->setRotation(90, zaxis);
                        earModel->setRotation(0, yaxis);

                        earModel->pairedModel->setRotation(90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);
                        earModel->setDirection("left");
                    }
                    else if (closestIndex == 1) {
                        earModel->setRotation(-90, zaxis);
                        earModel->setRotation(0, yaxis);

                        earModel->pairedModel->setRotation(-90, zaxis);
                        earModel->pairedModel->setRotation(0, yaxis);


                        earModel->setDirection("right");
                    }
                    else if (closestIndex == 2) {
                        earModel->setRotation(0, zaxis);

                        earModel->pairedModel->setRotation(0, zaxis);

                        earModel->setDirection("up");
                    }
                    else if (closestIndex == 3) {
                        earModel->setRotation(180, zaxis);

                        earModel->pairedModel->setRotation(180, zaxis);

                        //earModel->setRotation(0, zaxis);                       
                        earModel->setDirection("down");
                    }
                    }
                else if (modelType == "hornr") {
                        if (closestIndex == 0) {
                            earModel->setRotation(90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("left");
                        }
                        else if (closestIndex == 1) {
                            earModel->setRotation(-90, zaxis);
                            earModel->setRotation(0, yaxis);
                            earModel->pairedModel->setRotation(-90, zaxis);
                            earModel->pairedModel->setRotation(0, yaxis);
                            earModel->setDirection("right");
                        }
                        else if (closestIndex == 2) {
                            earModel->setRotation(0, zaxis);
                            earModel->pairedModel->setRotation(0, zaxis);
                            earModel->setDirection("up");
                        }
                        else if (closestIndex == 3) {
                            earModel->setRotation(180, zaxis);
                            earModel->pairedModel->setRotation(180, zaxis);
                            //earModel->setRotation(0, zaxis);                       
                            earModel->setDirection("down");
                        }
                        }

                else if (modelType == "rabearl") {
                            if (closestIndex == 0) {
                                earModel->setRotation(90, zaxis);
                                earModel->setRotation(0, yaxis);

                                earModel->pairedModel->setRotation(90, zaxis);
                                earModel->pairedModel->setRotation(0, yaxis);
                                earModel->setDirection("left");
                            }
                            else if (closestIndex == 1) {
                                earModel->setRotation(-90, zaxis);
                                earModel->setRotation(0, yaxis);

                                earModel->pairedModel->setRotation(-90, zaxis);
                                earModel->pairedModel->setRotation(0, yaxis);


                                earModel->setDirection("right");
                            }
                            else if (closestIndex == 2) {
                                earModel->setRotation(0, zaxis);

                                earModel->pairedModel->setRotation(0, zaxis);

                                earModel->setDirection("up");
                            }
                            else if (closestIndex == 3) {
                                earModel->setRotation(180, zaxis);

                                earModel->pairedModel->setRotation(180, zaxis);

                                //earModel->setRotation(0, zaxis);                       
                                earModel->setDirection("down");
                            }
                            }
                else if (modelType == "rabearr") {
                                if (closestIndex == 0) {
                                    earModel->setRotation(90, zaxis);
                                    earModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(90, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    earModel->setDirection("left");
                                }
                                else if (closestIndex == 1) {
                                    earModel->setRotation(-90, zaxis);
                                    earModel->setRotation(0, yaxis);
                                    earModel->pairedModel->setRotation(-90, zaxis);
                                    earModel->pairedModel->setRotation(0, yaxis);
                                    earModel->setDirection("right");
                                }
                                else if (closestIndex == 2) {
                                    earModel->setRotation(0, zaxis);
                                    earModel->pairedModel->setRotation(0, zaxis);
                                    earModel->setDirection("up");
                                }
                                else if (closestIndex == 3) {
                                    earModel->setRotation(180, zaxis);
                                    earModel->pairedModel->setRotation(180, zaxis);
                                    //earModel->setRotation(0, zaxis);                       
                                    earModel->setDirection("down");
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
        else if (modelType == "yuanbase") {
            rotateX.setMin(0);
            rotateX.setMax(0);
            rotateY.setMin(0);
            rotateY.setMax(0);
            rotateZ.setMin(0);
            rotateZ.setMax(0);
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
            rotateX.setMin(-10);
            rotateX.setMax(10);
            rotateY.setMin(-10);
            rotateY.setMax(10);
            rotateZ.setMin(-10);
            rotateZ.setMax(10);
        }
    }
}

std::shared_ptr<EarModel> ofApp::getLeftEarModel() {
    return leftEarModel;
}

std::shared_ptr<EarModel> ofApp::getRightEarModel() {
    return rightEarModel;
}
