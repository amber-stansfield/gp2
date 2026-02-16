#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying float wibble0;
uniform float wibble;

varying float UVScale0;
uniform float UVScale;

varying vec2 texCoord0;
varying float Counter;

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
UVScale0 = UVScale;
wibble0 = wibble;
texCoord0 = texCoord;
Counter = counter;

}
