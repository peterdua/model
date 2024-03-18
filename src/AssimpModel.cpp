#include "assimpmodel.h"

void AssimpModel::adMeshes() {
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