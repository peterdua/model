// Model.h
#pragma once
#include "ofMain.h"
#include "ofxSTLExporter.h"

class Model {
public:
    Model() {}
    virtual ~Model() {}

    virtual void draw() const = 0; 
    void addToSTL(ofxSTLExporter& exporter) const; 

    void setPosition(const ofVec3f& pos);
    ofVec3f getPosition() const;
    void setRotation(float angle, const ofVec3f& axis);

    const ofMesh& getMesh() const {
        return mesh;
    }

protected:
    ofVec3f position;
    float rotationAngle = 0.0f;
    ofVec3f rotationAxis = ofVec3f(0, 1, 0);
    ofMesh mesh; 
};