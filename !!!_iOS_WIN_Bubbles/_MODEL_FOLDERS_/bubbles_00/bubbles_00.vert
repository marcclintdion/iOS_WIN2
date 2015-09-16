uniform float counter1;
uniform float counter2;
uniform float counter3;
uniform float counter4;

varying vec4 position;

uniform vec4 particlePosition;
uniform vec4 particleVelocity;

varying vec3 lightDir1;

varying float attenuation;

//varying vec3 normal;

varying float pointSizeAdjust;

varying float distanceFromCenter;

vec4 positionRaw;

void main( void )
{
    gl_TexCoord[0]    =   gl_MultiTexCoord0;
    gl_TexCoord[1]    =   gl_MultiTexCoord1;
   
    
    float angle_rad   =   counter1;  

    position          =  (gl_Vertex * (1.0 - gl_TexCoord[0].x) + vec4(gl_Normal, 1.0) * gl_TexCoord[0].x);

    gl_PointSize      =  gl_TexCoord[1].x+50.0;

    position.x = ( position.x * cos(gl_TexCoord[0].x*.2) + position.y * sin(gl_TexCoord[0].x*.2));//ORBIT_PIVOT_POINT_EXPANSION
    position.y = (-position.x * sin(gl_TexCoord[0].x*.2) + position.y * cos(gl_TexCoord[0].x*.2));      
    
    gl_Position       =  gl_ModelViewProjectionMatrix *  position;

    lightDir1         =  normalize(gl_LightSource[0].position.xyz);
   // attenuation       =  1.00 / (gl_LightSource[0].quadraticAttenuation);
}





    //position.x = ( position.x * cos(gl_TexCoord[0].x) + position.y * sin(gl_TexCoord[0].x));//ORBIT_PIVOT_POINT_EXPANSION
    //position.y = (-position.x * sin(gl_TexCoord[0].x) + position.y * cos(gl_TexCoord[0].x));  








