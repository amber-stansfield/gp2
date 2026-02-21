#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include "shadowMap.cpp"

class Light {
public:

    Light() {};
    glm::vec3 position;
    glm::vec3 colour;

    ShadowMap shadow;

    Light(glm::vec3 pos, glm::vec3 col)
        : position(pos), colour(col) {
    }
};
