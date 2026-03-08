#version 140

uniform vec3 lightPos;
uniform float farPlane;

varying vec3 worldPos;

void main()
{
    float dist = length(worldPos - lightPos);
    dist = dist / farPlane;
    gl_FragDepth = dist;
}
