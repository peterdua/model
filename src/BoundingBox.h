#pragma once
#include "Model.h"

class BoundingBox {
public:
    glm::vec3 min, max;
    BoundingBox() : min(glm::vec3(FLT_MAX)), max(glm::vec3(-FLT_MAX)) {} 

    bool contains(const glm::vec3& point) const {
        //ofLogNotice() << min << min;
        //ofLogNotice() << max << max;

        return (point.x >= min.x && point.x <= max.x) &&
            (point.y >= min.y && point.y <= max.y) &&
            (point.z >= min.z && point.z <= max.z);
    }

    void expandToInclude(const glm::vec3& point) {
        min = glm::min(min, point);
        max = glm::max(max, point);
    }

    glm::vec3 getCenter() const {
        return (min + max) * 0.5f;
    }

    // 静态方法，计算给定ofxAssimpModelLoader对象的模型的边界盒
    static BoundingBox calculateFromMesh(const ofMesh& mesh) {
        BoundingBox box;
        for (const auto& vertex : mesh.getVertices()) {
            box.expandToInclude(vertex);
        }
        ofLogNotice() << "计算边界";

        return box;
    }
};
