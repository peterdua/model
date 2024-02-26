//#include "AssimpModel.h"
//
//bool AssimpModel::loadModel(const std::string& filepath) {
//    bool loaded = modelLoader.loadModel(filepath);
//    if (loaded) {
//        ofLogNotice() << "Model loaded, mesh count: " << modelLoader.getMeshCount();
//
//        // 遍历所有网格并打印详细信息
//        for (int i = 0; i < modelLoader.getMeshCount(); i++) {
//            ofMesh mesh = modelLoader.getMesh(i);
//            auto& vertices = mesh.getVertices();
//            auto& indices = mesh.getIndices();
//            auto& normals = mesh.getNormals();
//            auto& texCoords = mesh.getTexCoords();
//
//            // 打印每个网格的顶点、索引、法线和纹理坐标的数量
//            ofLogNotice() << "Mesh " << i << ": Vertex Count = " << vertices.size();
//            ofLogNotice() << "Mesh " << i << ": Index Count = " << indices.size();
//            ofLogNotice() << "Mesh " << i << ": Normal Count = " << normals.size();
//            ofLogNotice() << "Mesh " << i << ": TexCoords Count = " << texCoords.size();
//
//        }
//        // 新增：将加载的网格数据转移到Model结构中
//        for (int i = 0; i < modelLoader.getMeshCount(); i++) {
//            ofMesh mesh = modelLoader.getMesh(i);
//            // 打印出每个网格的基本信息
//            ofLogNotice() << "Mesh " << i << ": Vertex Count = " << mesh.getNumVertices();
//            ofLogNotice() << "Mesh " << i << ": Index Count = " << mesh.getNumIndices();
//            ofLogNotice() << "Mesh " << i << ": Normal Count = " << mesh.getNumNormals();
//
//            // 可选：打印前几个顶点的坐标，以确认数据
//            for (size_t j = 0; j < std::min(mesh.getNumVertices(), static_cast<size_t>(5)); ++j) {
//                ofLogNotice() << "Vertex " << j << ": " << mesh.getVertex(j);
//            }
//
//            this->addMesh(mesh); // 假设Model类或AssimpModel类有这样一个方法
//        }
//
//    }
//
//    return loaded;
//}