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

void Model::addPart(std::shared_ptr<Model> part) {
    parts.push_back(part);
}

void Model::removePart(std::shared_ptr<Model> part) {
    parts.erase(std::remove(parts.begin(), parts.end(), part), parts.end());
}


void Model::addMesh(const ofMesh& mesh) {
    combinedMesh.append(mesh);
    ofLogNotice("Model::addMesh") << "Added mesh with " << mesh.getNumVertices() << " vertices. Combined mesh now has " << combinedMesh.getNumVertices() << " vertices.";

}

void Model::combineMeshes() {
    //combinedMesh.clear();

    for (auto& part : parts) {
        
        ofMesh partMesh = part->getMesh();
        ofVec3f position = part->getPosition();
        ofLogNotice() << "position:" << position;

        for (auto& vert : partMesh.getVertices()) {
            vert += position;
        }

        combinedMesh.append(partMesh);
    }

    ofLogNotice("Model::applyTransformsAndCombine") << "动态变换并合并完成，combinedMesh 中的顶点数为：" << combinedMesh.getNumVertices();
}



void Model::exportModelToSTL(const std::string& filePath) {  

    combineMeshes();
    ofxSTLExporter stlExporter;
    stlExporter.useASCIIFormat(false); 
    stlExporter.beginModel("CombinedModel");

    auto& vertices = combinedMesh.getVertices();
    auto& indices = combinedMesh.getIndices();
    ofLogNotice("Model::addMesh") << "Combined mesh now has " << vertices.size() << " vertices and " << indices.size() << " indices.";

    if (indices.size() % 3 != 0) {
        ofLogError() << "Combined mesh has invalid index count. Cannot export.";
        return; 
    }

    for (size_t i = 0; i < indices.size(); i += 3) {
        if (indices[i] >= vertices.size() || indices[i + 1] >= vertices.size() || indices[i + 2] >= vertices.size()) {
            ofLogError() << "Index out of range. Skipping invalid triangle.";
            continue; 
        }

        ofPoint vert1 = vertices[indices[i]];
        ofPoint vert2 = vertices[indices[i + 1]];
        ofPoint vert3 = vertices[indices[i + 2]];

        ofPoint normal = ((vert2 - vert1).cross(vert3 - vert1)).normalized();

        ofLogNotice() << "顶点1: " << vert1 << ", 顶点2: " << vert2 << ", 顶点3: " << vert3 << ", 法线: " << normal;

        stlExporter.addTriangle(vert1, vert2, vert3, normal);
    }

    stlExporter.saveModel(filePath);
    ofLogNotice() << "Model exported to STL file: " << filePath;
    combinedMesh.clear();

}

void Model::draw() const {
   
    ofPushMatrix();
    ofTranslate(position);
    ofRotateDeg(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    combinedMesh.drawWireframe(); 

    ofPopMatrix();
}



//ofVec3f Model::calculateModelCenter() const {
//    if (mesh.getVertices().empty()) return ofVec3f(0, 0, 0);
//
//    ofVec3f minVertex = mesh.getVertices()[0];
//    ofVec3f maxVertex = minVertex;
//
//    for (const auto& vertex : mesh.getVertices()) {
//        minVertex.x = std::min(minVertex.x, vertex.x);
//        minVertex.y = std::min(minVertex.y, vertex.y);
//        minVertex.z = std::min(minVertex.z, vertex.z);
//
//        maxVertex.x = std::max(maxVertex.x, vertex.x);
//        maxVertex.y = std::max(maxVertex.y, vertex.y);
//        maxVertex.z = std::max(maxVertex.z, vertex.z);
//    }
//
//    // 计算并返回边界的中心点
//    return (minVertex + maxVertex) / 2.0f;
//}

//void Model::setModelCenter(const ofVec3f& center) {
//    
//    // 计算模型当前中心点与新中心点之间的偏移
//    ofVec3f offset = -center;
//    // 更新模型的位置以应用这个偏移
//    setPosition(getPosition() + offset);
//
//}
