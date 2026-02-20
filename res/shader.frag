#version 120

varying vec2 texCoord0;

uniform sampler2D diffuse;

varying float wibble0;

varying float UVScale0;

varying float Counter;

void main()

{
if (wibble0 > 0.5f)
{
	gl_FragColor = texture2D(diffuse, vec2(texCoord0.x, texCoord0.y *-1) * UVScale0);
}
else
{
	gl_FragColor = texture2D(diffuse, vec2(texCoord0.x, texCoord0.y *-1) * UVScale0);
}


}
