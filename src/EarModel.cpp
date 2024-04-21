
#include "EarModel.h"

void EarModel::adMeshes() {
    mesh.clear();
    for (int i = 0; i < modelLoader.getNumMeshes(); i++) {
        ofMesh tempMesh = modelLoader.getMesh(i);
        if (tempMesh.getNumIndices() % 3 == 0) {
            for (int j = 0; j < tempMesh.getNumVertices(); j++) {
                mesh.addVertex(tempMesh.getVertex(j));
                if (tempMesh.hasNormals()) {
                    mesh.addNormal(tempMesh.getNormal(j));
                }
            }
            for (int k = 0; k < tempMesh.getNumIndices(); k++) {
                mesh.addIndex(tempMesh.getIndex(k));
            }
        }
        else {
            ofLogNotice() << "Mesh " << i << " 的索引数量不是3的倍数，已跳过。";
        }
    }
}

void EarModel::draw()const {
    material.begin();
    ofPushMatrix();
    ofTranslate(position);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);

    if (isWireframeMode) {
        mesh.drawWireframe();
    }
    else {
        mesh.draw();
    }

    ofPopMatrix();
    material.end();
}