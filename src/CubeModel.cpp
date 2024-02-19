#include "CubeModel.h"


void CubeModel::setupCube() {
    mesh.clear();

    float size = 50.0f; // 立方体边长的一半

    // 添加立方体的顶点
    mesh.addVertex(ofPoint(-size, -size, size));  // 0 左下前
    mesh.addVertex(ofPoint(size, -size, size));  // 1 右下前
    mesh.addVertex(ofPoint(size, size, size));  // 2 右上前
    mesh.addVertex(ofPoint(-size, size, size));  // 3 左上前
    mesh.addVertex(ofPoint(-size, -size, -size));  // 4 左下后
    mesh.addVertex(ofPoint(size, -size, -size));  // 5 右下后
    mesh.addVertex(ofPoint(size, size, -size));  // 6 右上后
    mesh.addVertex(ofPoint(-size, size, -size));  // 7 左上后

    // 前面
    mesh.addIndex(0); mesh.addIndex(1); mesh.addIndex(2);
    mesh.addIndex(2); mesh.addIndex(3); mesh.addIndex(0);

    // 右面
    mesh.addIndex(1); mesh.addIndex(5); mesh.addIndex(6);
    mesh.addIndex(6); mesh.addIndex(2); mesh.addIndex(1);

    // 后面
    mesh.addIndex(5); mesh.addIndex(4); mesh.addIndex(7);
    mesh.addIndex(7); mesh.addIndex(6); mesh.addIndex(5);

    // 左面
    mesh.addIndex(4); mesh.addIndex(0); mesh.addIndex(3);
    mesh.addIndex(3); mesh.addIndex(7); mesh.addIndex(4);

    // 下面
    mesh.addIndex(4); mesh.addIndex(5); mesh.addIndex(1);
    mesh.addIndex(1); mesh.addIndex(0); mesh.addIndex(4);

    // 上面
    mesh.addIndex(3); mesh.addIndex(2); mesh.addIndex(6);
    mesh.addIndex(6); mesh.addIndex(7); mesh.addIndex(3);

    mesh.enableNormals();  
    mesh.clearNormals();

    ofVec3f normals[] = {
        ofVec3f(0, 0, 1),  // 前面法线
        ofVec3f(1, 0, 0),  // 右面法线
        ofVec3f(0, 0, -1), // 后面法线
        ofVec3f(-1, 0, 0), // 左面法线
        ofVec3f(0, -1, 0), // 下面法线
        ofVec3f(0, 1, 0)   // 上面法线
    };

    for (int i = 0; i < 6; ++i) { 
        for (int j = 0; j < 4; ++j) { 
            mesh.addNormal(normals[i]); 
        }
    }
}


CubeModel::CubeModel() {
    setupCube(); 
}

void CubeModel::draw() const {    
    ofPushMatrix();
    ofTranslate(position);
    ofRotate(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    mesh.draw();
    ofPopMatrix();
}


