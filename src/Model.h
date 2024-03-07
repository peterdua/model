// Model.h
#pragma once
#include "ofMain.h"
#include "ofxSTLExporter.h"
#include "ofxAssimpModelLoader.h"
#include <glm/gtx/transform.hpp> 
#include <memory> 



class Model {

public:
    Model() {}
    virtual ~Model() {}

    void exportModelToSTL(const std::string& filePath);

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

    void setRotation(float angle, const ofVec3f& axis);
    ofVec3f getRotation() const;
   
    //glm::vec3 getRotationAxis() const;
    void rotate(float angle, const ofVec3f& axis);
    void applyRotation();
    virtual bool loadModel(const std::string& filepath) {      
        return false;
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

    //ofVec3f calculateModelCenter() const;
    //void setModelCenter(const ofVec3f& center);

    std::vector<std::shared_ptr<Model>> parts;

protected:
    ofVec3f position;
    ofVec3f rotation; 
    ofMesh combinedMesh; // 用于存储组合后的网格
    ofMesh meshes;
    ofMesh mesh; 
    //ofxAssimpModelLoader modelLoader;
};