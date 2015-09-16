uniform float counter1;
uniform float counter2;
uniform float counter3;
uniform float counter4;

varying vec4 position;

varying float attenuation;

vec3 normal;
vec4 finalcolor = vec4(1.0, 1.0, 1.0, 1.0);

varying vec3 lightDir1;

float NdotL1;

uniform sampler2D Texture1;
uniform sampler2D NormalMap;

varying float pointSizeAdjust;

varying float distanceFromCenter;

void main( void )
{
    
    vec3 NormalTex            =  texture2D(NormalMap,  gl_TexCoord[0].st).xyz*1.2;
    NormalTex                 = (NormalTex - 0.5) * 2.0;
   	normal                    =  normalize(NormalTex);
    
    
    NdotL1                    =  dot(normal,lightDir1);
    
    finalcolor                =  texture2D(Texture1,gl_TexCoord[0].xy)*NdotL1; 

    finalcolor.r              += cos(position.y*.1) * sin(position.x*.1);
    finalcolor.g              -= cos(position.z*.1) * sin(position.x*.1)*.5;    
    
    finalcolor.a              =  finalcolor.b - gl_TexCoord[0].x*.05;                                                  //finalcolor.a =  finalcolor.r - sin(counter1); 
   
    gl_FragColor              =  finalcolor;

}
