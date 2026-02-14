#version 120

varying vec2 texCoord0;

uniform sampler2D diffuse;

varying float wibble0;

varying float Counter;

void main()

{
if (wibble0 > 0.5f)
{
	gl_FragColor = texture2D(diffuse, texCoord0 + (cos(Counter) / 4));
}
else
{
	gl_FragColor = texture2D(diffuse, texCoord0 * 12);
}


}
