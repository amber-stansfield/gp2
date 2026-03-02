#version 330

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;



out data
{
 vec3 position;
 vec3 normal;
 float wibble;
 vec3 fragPos;
 vec2 texCoord;
 float counter;
 float UVScale;
} vert;


uniform float UVScale;
uniform mat4 model;
uniform float wibble;
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
vert.normal = normalize(normalMatrix * normal);

vert.fragPos = vec3(model * vec4(position, 1.0f));
vert.position = position;
vert.wibble = wibble;
vert.texCoord = texCoord;
vert.counter = counter;
vert.UVScale = UVScale;

}
