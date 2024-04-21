// Model.h
#pragma once
#include "ofMain.h"
#include "ofxSTLExporter.h"
#include "ofxAssimpModelLoader.h"
#include <glm/gtx/transform.hpp> 
#include <memory> 



class Model {   

private:
    std::string type;
    string direction;  

public:
    Model() {}
    virtual ~Model() {}
    Model(std::string type) : type(type) {}

    void exportModelToSTL(const std::string& filePath);
    bool isWireframeMode = false;
    ofMaterial material;

    virtual void draw() const;
    void Model::addPart(std::shared_ptr<Model> part);
    void removePart(std::shared_ptr<Model> part);
    void Model::combineMeshes();
    glm::mat4 getGlobalTransformMatrix() const;
    void setPosition(const ofVec3f& pos);
    ofVec3f getPosition() const;
    float getRotationX() const;
    float getRotationY() const;
    float getRotationZ() const;
    virtual void setSize(float size);
    std::string getType() const {
        return type;
    }

    void setRotation(float angle, const ofVec3f& axis);
    ofVec3f getRotation() const;
   
    //glm::vec3 getRotationAxis() const;
    void rotate(float angle, const ofVec3f& axis);
    void applyRotation();
    virtual bool loadModel(const std::string& filepath) {      
        return false;
    }
    void toggleWireframeMode() {
        isWireframeMode = !isWireframeMode;
    }

    const ofMesh& getMesh() const {
        return mesh;
    }
    void Model::addMesh(const ofMesh& mesh);
    
    void Model::printMeshInfo() const {
        //ofLogNotice("Model::printMeshInfo") << "打印MainModel中的Mesh信息:";
        //for (const auto& part : parts) {
        //    const ofMesh& mesh = part.getMesh();
        //    ofLogNotice("Model::printMeshInfo") << "一个部件的Mesh顶点数: " << mesh.getNumVertices();
        
    }
    void setupMaterial() {
        
        material.setDiffuseColor(ofColor(255, 0, 0)); 

        material.setSpecularColor(ofColor(255, 255, 255)); 

        material.setShininess(64); 
    }
    void setDirection(const std::string& dir) {
        direction = dir;
    }
    std::string getDirection() const {
        return direction;
    }    

    std::vector<std::shared_ptr<Model>> parts;
protected:
    ofVec3f position;
    ofVec3f rotation; 
    ofMesh combinedMesh; 
    ofMesh meshes;
    ofMesh mesh; 
    //ofxAssimpModelLoader modelLoader;
};