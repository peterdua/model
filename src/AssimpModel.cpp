#include "assimpmodel.h"

void AssimpModel::adMeshes() {
    mesh.clear(); // 清空当前mesh数据

    for (int i = 0; i < modelLoader.getNumMeshes(); i++) {
        ofMesh tempMesh = modelLoader.getMesh(i);

        // 检查当前mesh的索引数量是否为3的倍数
        if (tempMesh.getNumIndices() % 3 == 0) {
            // 复制顶点
            for (int j = 0; j < tempMesh.getNumVertices(); j++) {
                mesh.addVertex(tempMesh.getVertex(j));
                if (tempMesh.hasNormals()) { // 检查并复制法线
                    mesh.addNormal(tempMesh.getNormal(j));
                }
            }
            // 复制索引
            for (int k = 0; k < tempMesh.getNumIndices(); k++) {
                mesh.addIndex(tempMesh.getIndex(k));
            }
        }
        else {
            ofLogNotice() << "Mesh " << i << " 的索引数量不是3的倍数，已跳过。";
        }
    }
}



void AssimpModel:: draw()const {
    ofxAssimpModelLoader& loader = const_cast<ofxAssimpModelLoader&>(modelLoader);

    ofPushMatrix();
    ofTranslate(position);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);

    mesh.drawWireframe();

    ofPopMatrix();
}