#include "AccessoryModel.h"
#include "AssimpModel.h"

void AccessoryModel::adMeshes() {
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

void AccessoryModel::draw()const {
    ofxAssimpModelLoader& loader = const_cast<ofxAssimpModelLoader&>(modelLoader);

    ofPushMatrix();
    ofTranslate(position);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);

    mesh.drawWireframe();

    ofPopMatrix();
}

//int calculateInternalVertices(const ofMesh& accessoryMesh, const BoundingBox& baseModelBox) {
//    int count = 0;
//    for (const auto& vertex : accessoryMesh.getVertices()) {
//        if (baseModelBox.contains(vertex)) {
//            count++;
//        }
//    }
//    return count;
//}
//
//void tryMoveAccessoryModel(AccessoryModel& accessory, const BoundingBox& baseModelBox, const glm::vec3& direction) {
//    const int minInternalVertices = 10;
//    const int maxInternalVertices = 200;
//    // 保存原始位置以便可能的回滚
//    glm::vec3 originalPosition = accessory.getPosition();
//
//    // 尝试移动模型
//    accessory.setPosition(originalPosition + direction);
//
//    // 计算移动后的内部顶点数
//    int internalVertices = calculateInternalVertices(accessory.getMesh(), baseModelBox);
//
//    // 检查内部顶点数是否在阈值范围内
//    if (internalVertices < minInternalVertices || internalVertices > maxInternalVertices) {
//        // 如果不在范围内，撤销移动
//        accessory.setPosition(originalPosition);
//    }
//}
