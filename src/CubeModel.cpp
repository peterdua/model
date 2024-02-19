#include "CubeModel.h"


void CubeModel::setupCube() {
    mesh.clear();

    float size = 50.0f; // ������߳���һ��

    // ���������Ķ���
    mesh.addVertex(ofPoint(-size, -size, size));  // 0 ����ǰ
    mesh.addVertex(ofPoint(size, -size, size));  // 1 ����ǰ
    mesh.addVertex(ofPoint(size, size, size));  // 2 ����ǰ
    mesh.addVertex(ofPoint(-size, size, size));  // 3 ����ǰ
    mesh.addVertex(ofPoint(-size, -size, -size));  // 4 ���º�
    mesh.addVertex(ofPoint(size, -size, -size));  // 5 ���º�
    mesh.addVertex(ofPoint(size, size, -size));  // 6 ���Ϻ�
    mesh.addVertex(ofPoint(-size, size, -size));  // 7 ���Ϻ�

    // ǰ��
    mesh.addIndex(0); mesh.addIndex(1); mesh.addIndex(2);
    mesh.addIndex(2); mesh.addIndex(3); mesh.addIndex(0);

    // ����
    mesh.addIndex(1); mesh.addIndex(5); mesh.addIndex(6);
    mesh.addIndex(6); mesh.addIndex(2); mesh.addIndex(1);

    // ����
    mesh.addIndex(5); mesh.addIndex(4); mesh.addIndex(7);
    mesh.addIndex(7); mesh.addIndex(6); mesh.addIndex(5);

    // ����
    mesh.addIndex(4); mesh.addIndex(0); mesh.addIndex(3);
    mesh.addIndex(3); mesh.addIndex(7); mesh.addIndex(4);

    // ����
    mesh.addIndex(4); mesh.addIndex(5); mesh.addIndex(1);
    mesh.addIndex(1); mesh.addIndex(0); mesh.addIndex(4);

    // ����
    mesh.addIndex(3); mesh.addIndex(2); mesh.addIndex(6);
    mesh.addIndex(6); mesh.addIndex(7); mesh.addIndex(3);

    mesh.enableNormals();  
    mesh.clearNormals();

    ofVec3f normals[] = {
        ofVec3f(0, 0, 1),  // ǰ�淨��
        ofVec3f(1, 0, 0),  // ���淨��
        ofVec3f(0, 0, -1), // ���淨��
        ofVec3f(-1, 0, 0), // ���淨��
        ofVec3f(0, -1, 0), // ���淨��
        ofVec3f(0, 1, 0)   // ���淨��
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


