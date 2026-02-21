#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
class ShadowMap 
{
    public:
        GLuint fbo = 0;
        GLuint depthCube = 0;
        int width, height;

        float nearPlane = 1.0f;
        float farPlane = 50.0f;

        ShadowMap() {}
        ~ShadowMap() {}

        void init(int w, int h) {
            width = w;
            height = h;

            glGenFramebuffers(1, &fbo);

            glGenTextures(1, &depthCube);
            glBindTexture(GL_TEXTURE_CUBE_MAP, depthCube);

            for (int i = 0; i < 6; i++) {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT,
                    width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
            }

            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

            glBindFramebuffer(GL_FRAMEBUFFER, fbo);
            glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCube, 0);
            glDrawBuffer(GL_NONE);
            glReadBuffer(GL_NONE);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        void bindForWriting() {
            glViewport(0, 0, width, height);
            glBindFramebuffer(GL_FRAMEBUFFER, fbo);
            glClear(GL_DEPTH_BUFFER_BIT);
        }

        void unbind() {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }
    };