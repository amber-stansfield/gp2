#version 330


in data
{
 vec3 position;
 vec3 normal;
 float wibble;
 vec3 fragPos;
 vec2 texCoord;
 float counter;
 float UVScale;
} frag;

float fog_maxdist = 100.0f;
float fog_mindist = 3.0f;
vec4  fog_colour = vec4(0.13f, 0.6f, 0.71f, 0.0f);

uniform float texMult;
uniform sampler2D diffuse;
uniform vec3 lightPos0;
uniform vec3 lightColour0;
uniform float farPlane;
uniform vec3 viewPos0;
uniform samplerCube shadowCube;

//varying float counter0;

float ambient = 0.4f;

float specularStrength = 0.5f;

float maxSpecDist = 18.0f;


float ShadowCalculation(vec3 fragPos)
{
    vec3 fragToLight = fragPos - lightPos0;
    float currentDist = length(fragToLight);

    // sample depth from cubemap
    float closestDepth = texture(shadowCube, fragToLight).r;
    closestDepth *= farPlane;

    vec3 pointdir = lightPos0 - frag.position;

    float bias = 0.05;

    float shadow = currentDist - bias > closestDepth ? 1.0 : 0.0;
    return shadow;
}

float fogFactor()
{
    float  dist = distance(viewPos0,frag.fragPos);
    float fogAmount = (fog_maxdist - dist) / (fog_maxdist - fog_mindist);
    fogAmount = clamp(fogAmount, 0.0f,1.0f);

    return fogAmount;
}



void main()
{

vec3 normalisedNormal = normalize(frag.normal);

vec3 lightDir = normalize(lightPos0 - frag.fragPos);


vec3 viewDir = normalize(viewPos0 - frag.fragPos);

float diff = max(dot(normalisedNormal, lightDir), 0.0f);


vec3 halfwayDir = normalize(lightDir + viewDir);


float spec = pow(max(dot(normalisedNormal, halfwayDir), 0.0),32);

float shadow = ShadowCalculation(frag.fragPos);

float dist = distance(frag.fragPos,lightPos0);
float attenuation = 1.0 / (sqrt(dist));
attenuation = clamp(1.0 - dist / maxSpecDist, 0.0, 1.0);
spec *= attenuation;


vec3 specular = specularStrength * spec * lightColour0; 

vec3 litDiffuse = diff * lightColour0;

vec3 ambientColour = ambient * lightColour0;

vec3 result = (ambientColour + (1.0f - shadow) *  (litDiffuse + specular));

vec2 uv = vec2(frag.texCoord.x, frag.texCoord.y * -1.0) * frag.UVScale;

vec4 tex = texture2D(diffuse, uv);

float fogamount = fogFactor();

// fogamount *= -1* (sqrt(distance(frag.fragPos,lightPos0)));
//
//fogamount = clamp(fogamount, 0.0f,1.0f);





if (frag.wibble > 0.5f)
{
    //gl_FragColor = vec4(1-shadow);
    
    //gl_FragColor = vec4(gl_FragDepth);
	gl_FragColor = vec4(mix(fog_colour.xyz, tex.rgb * result * texMult,fogamount), tex.a);
}
else
{
    //gl_FragColor = vec4(1-shadow);
	gl_FragColor = vec4(mix(fog_colour.xyz, tex.rgb * result * texMult,fogamount), tex.a);
}


}
