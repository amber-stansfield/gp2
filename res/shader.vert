#version 140

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;


varying vec3 position0;

varying vec3 normal0;

varying float wibble0;
uniform float wibble;

varying vec3 fragPos0;
varying vec3 fragPos;


varying vec2 texCoord0;
varying float counter0;

uniform mat4 model;


uniform float counter;
uniform mat4 transform;
 
void main()

{
if (wibble > 0.5f)
{
gl_Position = transform * vec4(vec3(position.x * sin(counter),position.y * sin(counter) / 2,position.z * cos(counter)), 1.0);

}

else
{
gl_Position = transform * vec4(position, 1.0);
}

mat3 normalMatrix = mat3(transpose(inverse(model)));
normal0 = normalize(normalMatrix * normal);

fragPos0 = vec3(model * vec4(position, 1.0f));
position0 = position;

wibble0 = wibble;
texCoord0 = texCoord;
counter0 = counter;

}
