//#include "AssimpModel.h"
//
//bool AssimpModel::loadModel(const std::string& filepath) {
//    bool loaded = modelLoader.loadModel(filepath);
//    if (loaded) {
//        ofLogNotice() << "Model loaded, mesh count: " << modelLoader.getMeshCount();
//
//        // �����������񲢴�ӡ��ϸ��Ϣ
//        for (int i = 0; i < modelLoader.getMeshCount(); i++) {
//            ofMesh mesh = modelLoader.getMesh(i);
//            auto& vertices = mesh.getVertices();
//            auto& indices = mesh.getIndices();
//            auto& normals = mesh.getNormals();
//            auto& texCoords = mesh.getTexCoords();
//
//            // ��ӡÿ������Ķ��㡢���������ߺ��������������
//            ofLogNotice() << "Mesh " << i << ": Vertex Count = " << vertices.size();
//            ofLogNotice() << "Mesh " << i << ": Index Count = " << indices.size();
//            ofLogNotice() << "Mesh " << i << ": Normal Count = " << normals.size();
//            ofLogNotice() << "Mesh " << i << ": TexCoords Count = " << texCoords.size();
//
//        }
//        // �����������ص���������ת�Ƶ�Model�ṹ��
//        for (int i = 0; i < modelLoader.getMeshCount(); i++) {
//            ofMesh mesh = modelLoader.getMesh(i);
//            // ��ӡ��ÿ������Ļ�����Ϣ
//            ofLogNotice() << "Mesh " << i << ": Vertex Count = " << mesh.getNumVertices();
//            ofLogNotice() << "Mesh " << i << ": Index Count = " << mesh.getNumIndices();
//            ofLogNotice() << "Mesh " << i << ": Normal Count = " << mesh.getNumNormals();
//
//            // ��ѡ����ӡǰ������������꣬��ȷ������
//            for (size_t j = 0; j < std::min(mesh.getNumVertices(), static_cast<size_t>(5)); ++j) {
//                ofLogNotice() << "Vertex " << j << ": " << mesh.getVertex(j);
//            }
//
//            this->addMesh(mesh); // ����Model���AssimpModel��������һ������
//        }
//
//    }
//
//    return loaded;
//}