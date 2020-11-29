//
// Created by Charles on 11/29/2020.
//

#ifndef MINIENGINE_GLDRAWQUAD_H
#define MINIENGINE_GLDRAWQUAD_H

#include <glm/vec3.hpp>
#include "../IModule.h"
#include <learnopengl/shader.h>

class GLDrawQuad : public IModule {
public:
    virtual void Init();

    virtual void Update();

    virtual void OnWindowResize();

    virtual void Draw();

    virtual void Destroy();

    virtual ~GLDrawQuad();

private:
    Shader *shader;
    int texture0;
    int texture1;
    int VAO;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -2.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float deltaTime = 0.0f;    // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame

    int CreateTexture(char const *filename, int mode);

    int InitVAO();

};

#endif //MINIENGINE_GLDRAWQUAD_H
