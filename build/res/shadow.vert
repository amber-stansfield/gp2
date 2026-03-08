#version 140

attribute vec3 position;

uniform mat4 model;
uniform mat4 shadowMatrices[1];

varying vec3 worldPos;

void main()
{
    vec4 world = model * vec4(position, 1.0);
    worldPos = world.xyz;
    gl_Position = shadowMatrices[0] * world;
}
