#include "Model.h"

void Model::setPosition(const ofVec3f& pos) {
    position = pos;
}

// 获取模型位置
ofVec3f Model::getPosition() const {
    return position;
}

// 设置模型旋转
void Model::setRotation(float angle, const ofVec3f& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
}

void Model::draw() const {
    
}

void Model::addToSTL(ofxSTLExporter& exporter) const {
    for (int i = 0; i < mesh.getIndices().size(); i += 3) {
        int idx1 = mesh.getIndex(i);
        int idx2 = mesh.getIndex(i + 1);
        int idx3 = mesh.getIndex(i + 2);

        ofPoint vert1 = mesh.getVertex(idx1);
        ofPoint vert2 = mesh.getVertex(idx2);
        ofPoint vert3 = mesh.getVertex(idx3);

        vert1 += position;
        vert2 += position;
        vert3 += position;

        ofVec3f normal = ((vert2 - vert1).cross(vert3 - vert1)).normalized();

        exporter.addTriangle(vert1, vert2, vert3, normal);
    }
}
