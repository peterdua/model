// Model.h
#pragma once
#include "ofMain.h"
#include "ofxSTLExporter.h"
#include "ofxAssimpModelLoader.h"


class Model {
public:
    Model() {}
    virtual ~Model() {}


    void exportModelToSTL(const std::string& filePath);

    virtual void draw() const;
    void addPart(const Model& part);
    void Model::combineMeshes(const ofMesh& newMesh);
    void setPosition(const ofVec3f& pos);
    ofVec3f getPosition() const;
    void setRotation(float angle, const ofVec3f& axis);
    virtual bool loadModel(const std::string& filepath) {
        // Ĭ��ʵ�ֻ������false
        return false;
    }


    const ofMesh& getMesh() const {
        return mesh;
    }
    void Model::addMesh(const ofMesh& mesh);
    
    void Model::printMeshInfo() const {
        ofLogNotice("Model::printMeshInfo") << "��ӡMainModel�е�Mesh��Ϣ:";
        for (const auto& part : parts) {
            const ofMesh& mesh = part.getMesh();
            ofLogNotice("Model::printMeshInfo") << "һ��������Mesh������: " << mesh.getNumVertices();
            // ���������Ӹ���mesh��Ϣ�Ĵ�ӡ����������
        }
    }

    //ofVec3f calculateModelCenter() const;
    //void setModelCenter(const ofVec3f& center);

    std::vector<Model> parts; // �洢ģ�Ͳ���
protected:
    ofVec3f position;
    float rotationAngle = 0.0f;
    ofVec3f rotationAxis = ofVec3f(0, 1, 0);
    
    ofMesh combinedMesh; // ���ڴ洢��Ϻ������
    ofMesh mesh; 
    //ofxAssimpModelLoader modelLoader;
};