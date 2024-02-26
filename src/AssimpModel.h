// AssimpModel.h
#ifndef ASSIMPMODEL_H
#define ASSIMPMODEL_H

#include "Model.h"
#include "ofxAssimpModelLoader.h"

class AssimpModel : public Model {
public:
    AssimpModel() {}
    virtual ~AssimpModel() {}

    ofxAssimpModelLoader modelLoader;

    bool loadModel(const std::string& filepath) {
        bool loaded = modelLoader.loadModel(filepath);
        if (loaded) {
            ofLogNotice() << "Model loaded, mesh count: " << modelLoader.getMeshCount();

            for (int i = 0; i < modelLoader.getMeshCount(); i++) {
                ofMesh mesh = modelLoader.getMesh(i);
                auto& vertices = mesh.getVertices();
                auto& indices = mesh.getIndices();
                auto& normals = mesh.getNormals();
                auto& texCoords = mesh.getTexCoords();

                ofLogNotice() << "Mesh " << i << ": Vertex Count = " << vertices.size();
                ofLogNotice() << "Mesh " << i << ": Index Count = " << indices.size();
                ofLogNotice() << "Mesh " << i << ": Normal Count = " << normals.size();
                ofLogNotice() << "Mesh " << i << ": TexCoords Count = " << texCoords.size();

                for (size_t j = 0; j < vertices.size() && j < 5; ++j) { 
                    ofLogNotice() << "Vertex " << j << ": " << vertices[j];
                }
                if (vertices.size() > 5) {
                    ofLogNotice() << "More vertices available...";
                }
            }
        }

        return loaded;
    }

    ofVec3f getSceneCenter()  {
        return modelLoader.getSceneCenter();
    }

    virtual void draw()const override {
        ofxAssimpModelLoader& loader = const_cast<ofxAssimpModelLoader&>(modelLoader);

        ofPushMatrix();
        ofTranslate(position);
        ofRotate(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);

        loader.drawWireframe();

        ofPopMatrix();
    }

    void AssimpModel::extractModelData() {
        ofLogNotice("Model Center") << "Center: " ;
    }

    //void AssimpModel::exportModelToSTL(const std::string& filePath) {
    //    ofLogNotice() << "exportmodel";

    //    ofxSTLExporter stlExporter;
    //    stlExporter.useASCIIFormat(true); // 根据需要选择格式
    //    stlExporter.beginModel("ExportedModel");

    //    // 遍历模型的所有网格
    //    for (int i = 0; i < modelLoader.getMeshCount(); i++) {
    //        ofLogNotice() << "Processing mesh " << i;
    //        ofMesh mesh = modelLoader.getMesh(i);
    //        auto& vertices = mesh.getVertices();
    //        auto& indices = mesh.getIndices();
    //        ofLogNotice() << "Vertices: " << vertices.size() << ", Indices: " << indices.size();



    //        // 假设每个面都是由三个顶点组成（三角形）
    //        for (int j = 0; j < indices.size(); j += 3) {
    //            // 直接使用顶点和计算的法线
    //            ofPoint vert1 = vertices[indices[j]];
    //            ofPoint vert2 = vertices[indices[j + 1]];
    //            ofPoint vert3 = vertices[indices[j + 2]];

    //            // 计算法线
    //            ofPoint v1 = vert2 - vert1;
    //            ofPoint v2 = vert3 - vert1;
    //            ofPoint normal = v1.crossed(v2).normalized();

    //            // 添加三角形到STL导出器
    //            stlExporter.addTriangle(vert1, vert2, vert3, normal);
    //        }
    //    }

    //    // 保存模型为STL文件
    //    stlExporter.saveModel(filePath);
    //}





};

#endif // ASSIMPMODEL_H
