#include "Model.h"

void Model::setPosition(const ofVec3f& pos) {
    position = pos;
}

ofVec3f Model::getPosition() const {
    return position;
}
float Model::getRotationX() const {
    return rotation.x;
}

float Model::getRotationY() const {
    return rotation.y;
}

float Model::getRotationZ() const {
    return rotation.z;
}

void Model::setSize(float size)
{
    ofLogNotice() << "set";
}

void Model::setRotation(float angle, const ofVec3f& axis) { 
    rotation.x = angle;
    rotation.y = angle;
    rotation.z = angle;   
}

ofVec3f Model::getRotation() const {
    return rotation;
}

void Model::rotate(float angle, const ofVec3f& axis) {
    if (axis == ofVec3f(1, 0, 0)) { // X轴
        rotation.x += angle;
    }
    else if (axis == ofVec3f(0, 1, 0)) { // Y轴
        rotation.y += angle;
    }
    else if (axis == ofVec3f(0, 0, 1)) { // Z轴
        rotation.z += angle;
    }

    rotation.x = fmod(rotation.x, 360);
    rotation.y = fmod(rotation.y, 360);
    rotation.z = fmod(rotation.z, 360);
}

void Model::applyRotation() {
    ofPushMatrix();
    ofTranslate(position); 
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    ofPopMatrix();
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
   
    for (auto& part : parts) {
        ofMesh partMesh = part->getMesh();
        glm::mat4 globalTransform = part->getGlobalTransformMatrix();

        for (auto& vert : partMesh.getVertices()) {
         
            glm::vec4 globalVert = globalTransform * glm::vec4(vert, 1.0f);
            vert.x = globalVert.x;
            vert.y = globalVert.y;
            vert.z = globalVert.z;
        }

        combinedMesh.append(partMesh);
    }
}

glm::mat4 Model::getGlobalTransformMatrix() const {
    glm::vec3 glmPosition = glm::vec3(position.x, position.y, position.z);
    
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glmPosition) *
        glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0)) * 
        glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0, 1, 0)) * 
        glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0, 0, 1)); 
    return transform;
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
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
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
