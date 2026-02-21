#version 140

varying vec2 texCoord0;


varying vec3 normal0;

varying vec3 position0;

varying vec3 fragPos0;

varying float wibble0;

uniform sampler2D diffuse;

uniform float UVScale0;

uniform vec3 lightPos0;

uniform vec3 lightColour0;

uniform float farPlane;

uniform vec3 viewPos0;

varying float counter0;

float ambient = 0.4f;

float specularStrength = 0.5f;

float maxSpecDist = 18f;

uniform samplerCube shadowCube;

float ShadowCalculation(vec3 fragPos)
{
    vec3 fragToLight = fragPos - lightPos0;
    float currentDist = length(fragToLight);

    // sample depth from cubemap
    float closestDepth = texture(shadowCube, fragToLight).r;
    closestDepth *= farPlane;

    float bias = 0.05;

    float shadow = currentDist - bias > closestDepth ? 1.0 : 0.0;
    return shadow;
}

void main()
{

vec3 normalisedNormal = normalize(normal0);

vec3 lightDir = normalize(lightPos0 - fragPos0);


vec3 viewDir = normalize(viewPos0 - fragPos0);

float diff = max(dot(normalisedNormal, lightDir), 0.0f);



vec3 halfwayDir = normalize(lightDir + viewDir);


float spec = pow(max(dot(normalisedNormal, halfwayDir), 0.0),32);

float shadow = ShadowCalculation(fragPos0);

float dist = distance(fragPos0,lightPos0);
float attenuation = 1.0 / (sqrt(dist));
attenuation = clamp(1.0 - dist / maxSpecDist, 0.0, 1.0);
spec *= attenuation;



vec3 specular = specularStrength * spec * lightColour0; 


vec3 litDiffuse = diff * lightColour0;

vec3 ambientColour = ambient * lightColour0;

vec3 result = (ambientColour + (1.0f - shadow) *  (litDiffuse + specular));

vec2 uv = vec2(texCoord0.x, texCoord0.y * -1.0) * UVScale0;

vec4 tex = texture2D(diffuse, uv);



if (wibble0 > 0.5f)
{
	gl_FragColor = vec4(tex.rgb * result, tex.a);
}
else
{

	gl_FragColor = vec4(tex.rgb * result, tex.a);
}


}
