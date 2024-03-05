#include "Model.h"
#include "ofxAssimpModelLoader.h"

class Cover : public Model {
public:
    Cover() {}
    virtual ~Cover() {}

    ofxAssimpModelLoader modelLoader;

    bool loadModel(const std::string& filepath) {
        modelLoader.setScaleNormalization(false);

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

    ofVec3f getSceneCenter() {
        return modelLoader.getSceneCenter();
    }

    virtual void draw()const override {
        ofxAssimpModelLoader& loader = const_cast<ofxAssimpModelLoader&>(modelLoader);

        ofPushMatrix();
        ofTranslate(position);
        ofRotateX(rotation.x);
        ofRotateY(rotation.y);
        ofRotateZ(rotation.z);

        loader.drawWireframe();

        ofPopMatrix();
    }
};
