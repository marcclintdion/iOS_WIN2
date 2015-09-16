


//==========================================================================================================================   
#ifdef __APPLE__
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#endif
//=================================================================================================================================


bubbles_SHADER = glCreateProgram();
//---------------------------------------------------------------------
const GLchar *vertexSource =

"    #define highp                                                                                                                                               \n"

"    uniform         mat4  modelViewProjectionMatrix;                                                                                                            \n"

"    uniform   highp float counter1;                                                                                                                             \n"

"    attribute highp vec4  positionInitial;                                                                                                                      \n"
"    attribute highp vec4  positionFinal;                                                                                                                        \n"
"    attribute highp vec4  individualCounter;                                                                                                                    \n"
"    attribute highp vec4  Size;                                                                                                                                 \n"

"    varying   highp vec4  position;                                                                                                                             \n"
"    varying   highp vec3  lightDir1;                                                                                                                            \n"
"    varying   highp vec2  texCoords_PASS;                                                                                                                       \n"



"    varying   highp float timeColor;                                                                                                                            \n"



"void main()                                                                                                                                                     \n"
"{                                                                                                                                                               \n"

"       //float angle_rad   =   counter1;                                                                                                                        \n"

"       timeColor           =   individualCounter.x;                                                                                                             \n"

"       position            =  (positionInitial * (1.0 - individualCounter.x) + positionFinal * individualCounter.x);                                            \n"

"       gl_PointSize        =   1.0 + abs(20.0 + Size.x);                                                                                                        \n"

"       position.x          = ( position.x * cos(individualCounter.x * 0.23) +  position.y * sin(individualCounter.x * 0.21));//ORBIT_PIVOT_POINT_EXPANSION      \n"
"       position.y          = (-position.x * sin(individualCounter.x * 0.17) +  position.y * cos(individualCounter.x * 0.19));                                   \n"


"       lightDir1           =   normalize(vec3(0.0, 0.0, 1.76));                                                                                                 \n"



"       gl_Position         =   modelViewProjectionMatrix * position;                                                                                            \n"

"}                                                                                                                                                               \n";
//---------------------------------------------------------------------
bubbles_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(bubbles_SHADER_VERTEX, 1, &vertexSource, NULL);
glCompileShader(bubbles_SHADER_VERTEX);    
//---------------------------------------------------------------------
const GLchar *fragmentSource =     

" #ifdef GL_ES                                                                                                                                          \n"
" #else                                                                                                                                                 \n"
" #define highp                                                                                                                                         \n"
" #endif                                                                                                                                                \n"

"       uniform   sampler2D   Texture1;                                                                                                                 \n"
"       uniform   sampler2D   NormalMap;                                                                                                                \n"

"       varying   highp vec4  position;                                                                                                                 \n"
"       varying   highp vec3  lightDir1;                                                                                                                \n"

"       varying   highp float timeColor;                                                                                                                \n"

"                 highp vec4  finalcolor;                                                                                                               \n"
"                 highp vec3  NormalTex;                                                                                                                \n"

"                 highp vec3  normal;                                                                                                                   \n"

"                 highp float NdotL1;                                                                                                                   \n"
"                 highp float specular;                                                                                                                 \n"

"void main()                                                                                                                                            \n"
"{                                                                                                                                                      \n"

"       NormalTex               =  texture2D(NormalMap,   gl_PointCoord).xyz;                                                                           \n"
"       NormalTex               = (NormalTex - 0.5) * 2.0;                                                                                              \n"
"       normal                  =  normalize(NormalTex);                                                                                                \n"

"       NdotL1                  =  dot(normal,lightDir1);                                                                                               \n"

"       specular                =  pow(NdotL1, 5.0);                                                                                                    \n"

"       finalcolor              =  texture2D(Texture1,    gl_PointCoord) * NdotL1 * 1.3 + specular * 0.3;                                               \n"


"       finalcolor.r            += cos(position.y * 0.1)   * sin(position.x * 0.1) * 1.5;                                                               \n"
"       finalcolor.g            -= clamp(cos(timeColor)    * sin(position.x * 0.1) * 1.5, 0.0, 1.0);                                                    \n"

"       finalcolor.a            =  (finalcolor.r + finalcolor.g + finalcolor.b) * 0.4  - timeColor * 0.001;                                             \n"

"       gl_FragColor            =  finalcolor;                                                                                                          \n"         


"}                                                                                                                                                      \n";

//    vec4(1.0,1.0,1.0,1.0)

//---------------------------------------------------------------------
bubbles_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(bubbles_SHADER_FRAGMENT, 1, &fragmentSource, NULL);
glCompileShader(bubbles_SHADER_FRAGMENT);      
//------------------------------------------------
glAttachShader(bubbles_SHADER, bubbles_SHADER_VERTEX);
glAttachShader(bubbles_SHADER, bubbles_SHADER_FRAGMENT);
//------------------------------------------------    
glBindAttribLocation(bubbles_SHADER, 0, "positionInitial");       
glBindAttribLocation(bubbles_SHADER, 1, "positionFinal");  
glBindAttribLocation(bubbles_SHADER, 2, "individualCounter");  
glBindAttribLocation(bubbles_SHADER, 3, "Size");  
 
//------------------------------------------------    
glLinkProgram(bubbles_SHADER);
//------------------------------------------------
#ifdef __APPLE__    
glDetachShader(bubbles_SHADER, bubbles_SHADER_VERTEX);
glDetachShader(bubbles_SHADER, bubbles_SHADER_FRAGMENT);
#endif     
//------------------------------------------------
glDeleteShader(bubbles_SHADER_VERTEX);
glDeleteShader(bubbles_SHADER_FRAGMENT);

//------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS

UNIFORM_MODELVIEWPROJ                   = glGetUniformLocation(bubbles_SHADER,  "modelViewProjectionMatrix");
UNIFORM_LIGHT_MATRIX                    = glGetUniformLocation(bubbles_SHADER,  "lightMatrix");    

UNIFORM_LIGHT_POSITION_01_bubbles       = glGetUniformLocation(bubbles_SHADER,  "light_POSITION_01");      
UNIFORM_TEXTURE_DOT3_bubbles            = glGetUniformLocation(bubbles_SHADER,  "NormalMap");
UNIFORM_TEXTURE_bubbles                 = glGetUniformLocation(bubbles_SHADER,  "Texture1");

UNIFORM_counter1_bubbles                = glGetUniformLocation(bubbles_SHADER,  "counter1" );

//=================================================================================================================================


glGenBuffers(1, &bubbles_00_VERT_INITIAL_vboID);
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_INITIAL_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(bubbles), bubbles, GL_STREAM_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);

glGenBuffers(1, &bubbles_00_VERT_FINAL_vboID);
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_FINAL_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(bubbles), bubbles, GL_STREAM_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);

glGenBuffers(1, &bubbles_00_CYCLE_COUNTER_vboID);
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_CYCLE_COUNTER_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(bubbles), bubbles, GL_STREAM_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);

glGenBuffers(1, &bubbles_00_BubbleSize_vboID);
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_BubbleSize_vboID);
glBufferData(GL_ARRAY_BUFFER,       sizeof(bubbles), bubbles, GL_STREAM_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0);

//==================================================================================================================================
srand(time(0)); 
//-----------------------------------------------------------------------------------------------        
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_INITIAL_vboID);         
vertexSet_InitialPositions = (GLfloat*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);

for(int i = 0; i < 60; i++)
{
        *vertexSet_InitialPositions  =  0; 
         vertexSet_InitialPositions +=  1;
        *vertexSet_InitialPositions  =  0;       
         vertexSet_InitialPositions +=  1;
        *vertexSet_InitialPositions  =  0;       
         vertexSet_InitialPositions +=  1;        
}

glUnmapBufferOES(GL_ARRAY_BUFFER);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//-----------------------------------------------------------------------------------------------              
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_FINAL_vboID);         
vertexSet_FinalPositions = (GLfloat*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);

for(int i = 0; i < 60; i++)
{
        particlePositonFinal[i][0]   =  (float)((rand() % 100) - 50) * 0.0015;  
        
        particlePositonFinal[i][1]   =  (float)((rand() % 100) - 50) * 0.0015;       
        
        particlePositonFinal[i][2]   =  (float)((rand() % 100) - 50) * 0.0015;   
}  

for(int i = 0; i < 60; i++)
{
        *vertexSet_FinalPositions  =   particlePositonFinal[i][0]; 
         vertexSet_FinalPositions +=   1;
        *vertexSet_FinalPositions  =   particlePositonFinal[i][1]; 
         vertexSet_FinalPositions +=   1;
        *vertexSet_FinalPositions  =   particlePositonFinal[i][2]; 
         vertexSet_FinalPositions +=   1;                                   
        
}
glUnmapBufferOES(GL_ARRAY_BUFFER);
glBindBuffer(GL_ARRAY_BUFFER, 0);
//-----------------------------------------------------------------------------------------------            
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_CYCLE_COUNTER_vboID);         
GLfloat *vertexSet_cycleCounters = (GLfloat*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);

for(int i = 0; i < 60; i++)
{
        *vertexSet_cycleCounters   =   i; 
         vertexSet_cycleCounters  +=   1;
        *vertexSet_cycleCounters   =   bubbles_00_counter1 + i;      
         vertexSet_cycleCounters  +=   1;
        *vertexSet_cycleCounters   =   bubbles_00_counter1 + i;       
         vertexSet_cycleCounters  +=   1;        
}

glUnmapBufferOES(GL_ARRAY_BUFFER);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//-----------------------------------------------------------------------------------------------          
if(resetParticlesCounter_bubbles_00)
{      
        for(int i = 0; i < 60; i++)
        {
                particleCycleCounter[i][0]   =  0.0 + i; 
                if(particleCycleCounter[i][0] >= 60  && particleCycleCounter[i][0] < 120)
                {
                        particleCycleCounter[i][0]   =  -60.0 + i;                  
                }   
                if(particleCycleCounter[i][0] >= 120 && particleCycleCounter[i][0] < 180)
                {
                        particleCycleCounter[i][0]   =  -120.0 + i;                  
                }                 
                if(particleCycleCounter[i][0] >= 180 && particleCycleCounter[i][0] < 240)
                {
                        particleCycleCounter[i][0]   =  -180.0 + i;                  
                }    
                if(particleCycleCounter[i][0] >= 240 && particleCycleCounter[i][0] < 300)
                {
                        particleCycleCounter[i][0]   =  -240.0 + i;                  
                } 
        }
        resetParticlesCounter_bubbles_00 = false; 
}      
//-----------------------------------------------------------------------------------------------  
glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_BubbleSize_vboID);         
vertexSet_bubbleSize = (GLfloat*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);

for(int i = 0; i < 60; i++)
{
        particleBubbleSize[i][0]  =  (float)((rand() % 100) - 50) * 0.1; 
        particleBubbleSize[i][1]  =  (float)((rand() % 100) - 50) * 0.1;
        particleBubbleSize[i][2]  =  (float)((rand() % 100) - 50) * 0.1;                             
        
        *vertexSet_bubbleSize  =   particleBubbleSize[i][0]; 
         vertexSet_bubbleSize +=   1;
        *vertexSet_bubbleSize  =   particleBubbleSize[i][1]; 
         vertexSet_bubbleSize +=   1;
        *vertexSet_bubbleSize  =   particleBubbleSize[i][2]; 
         vertexSet_bubbleSize +=   1;                                   
        
}
glUnmapBufferOES(GL_ARRAY_BUFFER);
glBindBuffer(GL_ARRAY_BUFFER, 0);



//==================================================================================================================================

#ifdef WIN32   
    loadTexture("_MODEL_FOLDERS_/bubbles_00/bubbles_00.jpg",        bubbles_TEXTUREMAP);
    loadTexture("_MODEL_FOLDERS_/bubbles_00/bubbles_00_DOT3.bmp",   bubbles_NORMALMAP);
#endif 


#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"bubbles_00_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &bubbles_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, bubbles_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"bubbles_00" ofType:@"jpg"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &bubbles_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, bubbles_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    





	






