#include "CubeModel.h"


CubeModel::CubeModel()
{
    setupCube();
}

void CubeModel::setupCube() {
    mesh.clear();

    float halfSize = 1.0f;

    // ���������Ķ���
    mesh.addVertex(ofPoint(-cubeSize * halfSize, -cubeSize * halfSize, cubeSize * halfSize));  // 0 ����ǰ
    mesh.addVertex(ofPoint(cubeSize * halfSize, -cubeSize * halfSize, cubeSize * halfSize));  // 1 ����ǰ
    mesh.addVertex(ofPoint(cubeSize * halfSize, cubeSize * halfSize, cubeSize * halfSize));  // 2 ����ǰ
    mesh.addVertex(ofPoint(-cubeSize * halfSize, cubeSize * halfSize, cubeSize * halfSize));  // 3 ����ǰ
    mesh.addVertex(ofPoint(-cubeSize * halfSize, -cubeSize * halfSize, -cubeSize * halfSize));  // 4 ���º�
    mesh.addVertex(ofPoint(cubeSize * halfSize, -cubeSize * halfSize, -cubeSize * halfSize));  // 5 ���º�
    mesh.addVertex(ofPoint(cubeSize * halfSize, cubeSize * halfSize, -cubeSize * halfSize));  // 6 ���Ϻ�
    mesh.addVertex(ofPoint(-cubeSize * halfSize, cubeSize * halfSize, -cubeSize * halfSize));  // 7 ���Ϻ�

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




void CubeModel::draw() const {    
    ofPushMatrix();
    ofTranslate(position);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    mesh.draw();
    ofPopMatrix();
}




