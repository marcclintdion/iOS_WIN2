/*
 * ---------------- www.spacesimulator.net --------------
 *   ---- Space simulators and 3d engine tutorials ----
 *
 * Author: Damiano Vitulli <info@spacesimulator.net>
 *
 * ALL RIGHTS RESERVED
 *
 *
 * Tutorial 5: Vectors and OpenGL lighting
 * 
 * 
 *
 * To compile this project you must include the following libraries:
 * opengl32.lib,glu32.lib,glut32.lib
 * You need also the header file glut.h in your compiler directory.
 *  
 */

/*
 * Spaceships credits:
 * fighter1.3ds - created by: Dario Vitulli 
 */

#ifdef WIN32
#include <windows.h>
#endif

#include "glut.h"
#include "load_bmp.h"
#include "load_3ds.h"
#include "object.h"

#include "fstream.h"

/**********************************************************
 *
 * VARIABLES DECLARATION
 *
 *********************************************************/

// The width and height of your window, change them as you like
int screen_width=800;
int screen_height=600;

// Absolute rotation values (0-359 degrees) and rotation increments for each frame
double rotation_x=0, rotation_x_increment=0.7;
double rotation_y=0, rotation_y_increment=0.8;
double rotation_z=0, rotation_z_increment=0.9;
 
// Flag for rendering as lines or filled polygons
int filling=1; //0=OFF 1=ON

//Lights settings
GLfloat light_ambient[]= { 0.1f, 0.1f, 0.1f, 0.1f };
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat light_position[]= { 100.0f, 0.0f, -10.0f, 1.0f };

//Materials settings
GLfloat mat_ambient[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_diffuse[]= { 0.2f, 0.2f, 0.2f, 0.0f };
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f };
GLfloat mat_shininess[]= { 1.0f };



/**********************************************************
 *
 * SUBROUTINE init(void)
 *
 * Used to initialize OpenGL and to setup our world
 *
 *********************************************************/

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Clear background color to black

    // Viewport transformation
    glViewport(0,0,screen_width,screen_height);  

    // Projection transformation
    glMatrixMode(GL_PROJECTION); // Specifies which matrix stack is the target for matrix operations 
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,5.0f,10000.0f); // We define the "viewing volume"
   
	//Lights initialization and activation
    glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
    glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);

    //Materials initialization and activation
	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
    glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);    

	//Other initializations
    glShadeModel(GL_SMOOTH); // Type of shading for the polygons
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Texture mapping perspective correction (OpenGL... thank you so much!)
    glEnable(GL_TEXTURE_2D); // Texture mapping ON
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
	glEnable(GL_CULL_FACE); // Enable the back face culling
    glEnable(GL_DEPTH_TEST); // Enable the depth test (also called z buffer)

	//Objects loading
	ObjLoad ("sphere.3ds","skull.bmp");
//====================================================================================================

system("MKDIR sphere");

ofstream out_Globals("sphere/sphere_Globals.cpp");
         
         
    
         out_Globals << "GLuint      sphere_SHADER_VERTEX;                                                                                                      "        << "\n";
         out_Globals << "GLuint      sphere_SHADER_FRAGMENT;                                                                                                    "        << "\n";
         out_Globals << "GLuint      sphere_SHADER;                                                                                                             "        << "\n";
         out_Globals << "//--------------------------------------                                                                                               "        << "\n";
         out_Globals << "GLuint      UNIFORM_MODELVIEWPROJ_sphere;                                                                                              "        << "\n";
         out_Globals << "GLuint      UNIFORM_LIGHT_MATRIX_sphere;                                                                                               "        << "\n";
         out_Globals << "//--------------------------------------                                                                                               "        << "\n";
         out_Globals << "GLuint      UNIFORM_LIGHT_POSITION_01_sphere;                                                                                          "        << "\n";
         out_Globals << "GLuint      UNIFORM_SHININESS_sphere;                                                                                                  "        << "\n";         
         out_Globals << "GLuint      UNIFORM_TEXTURE_DOT3_sphere;                                                                                               "        << "\n";
         out_Globals << "GLuint      UNIFORM_TEXTURE_sphere;                                                                                                    "        << "\n";
         out_Globals << "//--------------------------------------                                                                                               "        << "\n";

         out_Globals << "GLfloat     sphere_POSITION[]        = {  0.0, 0.0, 0.0, 1.0};                                                                         "        << "\n";
         out_Globals << "GLfloat     sphere_ROTATE[]          = {  0.0, 1.0,  0.0, 0.0};                                                                        "        << "\n";  
         out_Globals << "GLfloat     sphere_SCALE[]           = {  1.0, 1.0,  1.0, 1.0};                                                                        "        << "\n";          
         out_Globals << "//-----------------------------------------------------------------                                                                    "        << "\n";         
         out_Globals << "GLfloat     sphere_LIGHT_POSITION_01[]  =  {  2.0, 15.0, 30.0, 1.0};                                                                        "        << "\n";           
         out_Globals << "GLfloat     sphere_SHININESS         =   80.0;                                                                                         "        << "\n";   
         
         out_Globals << "//-----------------------------------------------------------------                                                                    "        << "\n";
         out_Globals << "GLuint      sphere_VBO;                                                                                                                "        << "\n";             
         out_Globals << "//-----------------------------------------------------------------                                                                    "        << "\n";         
         out_Globals << "GLuint      sphere_NORMAL_TEX;                                                                                                         "        << "\n";
         out_Globals << "GLuint      sphere_TEXTURE1;                                                                                                           "        << "\n";

//====================================================================================================

ofstream out_Init("sphere/sphere_Init.cpp");

         
         out_Init << "      #ifdef __APPLE__                                                                                                                          "        << "\n";
         out_Init << "      #import <OpenGLES/ES2/gl.h>                                                                                                               "        << "\n";
         out_Init << "      #import <OpenGLES/ES2/glext.h>                                                                                                            "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //===============================================================================================                                         "        << "\n";
         out_Init << "      sphere_SHADER = glCreateProgram();                                                                                                        "        << "\n";
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      const GLchar *vertexSource_sphere =                                                                                                              "        << "\n\n";

         out_Init << "      \"    #define mediump                                                                                     \\n\"                           "        << "\n\n";

         out_Init << "      \"    uniform mediump vec4   light_POSITION_01;                                                           \\n\"                           "        << "\n";
         out_Init << "      \"    uniform         mat4   mvpMatrix;                                                                   \\n\"                           "        << "\n";
         out_Init << "      \"    uniform         mat4   lightMatrix;                                                                 \\n\"                           "        << "\n\n";

         out_Init << "      \"    attribute       vec4   position;                                                                    \\n\"                           "        << "\n";
         out_Init << "      \"    attribute       vec2   texture;                                                                     \\n\"                           "        << "\n\n";

         out_Init << "      \"    varying mediump vec4   lightPosition_PASS;                                                          \\n\"                           "        << "\n";
         out_Init << "      \"    varying mediump vec2   varTexcoord;                                                                 \\n\"                           "        << "\n\n\n";


         out_Init << "      \"    void main()                                                                                         \\n\"                           "        << "\n";
         out_Init << "      \"    {                                                                                                   \\n\"                           "        << "\n";
         out_Init << "      \"        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \\n\"                           "        << "\n\n";
    
         out_Init << "      \"        varTexcoord        = texture;                                                                   \\n\"                           "        << "\n\n";

         out_Init << "      \"        gl_Position        = mvpMatrix * position;                                                      \\n\"                           "        << "\n\n";
         out_Init << "      \"    }\\n\";                                                                                                                             "        << "\n";
         
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      sphere_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                  "        << "\n";
         out_Init << "      glShaderSource(sphere_SHADER_VERTEX, 1, &vertexSource_sphere, NULL);                                                                             "        << "\n";
         out_Init << "      glCompileShader(sphere_SHADER_VERTEX);                                                                                                    "        << "\n";
         
         out_Init << "      //---------------------------------------------------------------------                                                                   "        << "\n";
         out_Init << "      const GLchar *fragmentSource_sphere =                                                                                                            "        << "\n\n";
  
         out_Init << "      \" #ifdef GL_ES                                                                                                     \\n\"                       "        << "\n";
         out_Init << "      \" #else                                                                                                            \\n\"                       "        << "\n";
         out_Init << "      \" #define mediump                                                                                                  \\n\"                       "        << "\n";
         out_Init << "      \" #endif                                                                                                           \\n\"                       "        << "\n\n";


         out_Init << "      \"    uniform sampler2D       Texture1;                                                                             \\n\"                       "        << "\n";
         out_Init << "      \"    uniform sampler2D       NormalMap;                                                                            \\n\"                       "        << "\n";
         out_Init << "      \"    uniform mediump float   shininess;                                                                            \\n\"                       "        << "\n\n";
         

         out_Init << "      \"    varying mediump vec4    lightPosition_PASS;                                                                   \\n\"                       "        << "\n";
         out_Init << "      \"    varying mediump vec2    varTexcoord;                                                                          \\n\"                       "        << "\n\n";

         out_Init << "      \"     mediump  float         NdotL1;                                                                               \\n\"                       "        << "\n";
         out_Init << "      \"     mediump  vec3          normal;                                                                               \\n\"                       "        << "\n";
         out_Init << "      \"     mediump vec3           NormalTex;                                                                            \\n\"                       "        << "\n\n";

         out_Init << "      \"     void main()                                                                                                  \\n\"                       "        << "\n";
         out_Init << "      \"     {                                                                                                            \\n\"                       "        << "\n";
         out_Init << "      \"         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \\n\"                       "        << "\n";
         out_Init << "      \"         NormalTex             = (NormalTex - 0.5);                                                               \\n\"                       "        << "\n";
         out_Init << "      \"         normal                =  normalize(NormalTex);                                                           \\n\"                       "        << "\n\n";

         out_Init << "      \"         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \\n\"                       "        << "\n\n";

         out_Init << "      \"         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                                  \\n\"                       "        << "\n\n";        

         out_Init << "      \"                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1              \\n\"                       "        << "\n\n";

         out_Init << "      \"                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \\n\"                       "        << "\n\n";

         out_Init << "      \"    }\\n\";                                                                                                                                   "        << "\n\n";
         out_Init << "      //---------------------------------------------------------------------                                                                 "        << "\n";
         out_Init << "      sphere_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                            "        << "\n";
         out_Init << "      glShaderSource(sphere_SHADER_FRAGMENT, 1, &fragmentSource_sphere, NULL);                                                                       "        << "\n";
         out_Init << "      glCompileShader(sphere_SHADER_FRAGMENT);                                                                                                "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                      "        << "\n";
         out_Init << "      glAttachShader(sphere_SHADER, sphere_SHADER_VERTEX);                                                                                    "        << "\n";
         out_Init << "      glAttachShader(sphere_SHADER, sphere_SHADER_FRAGMENT);                                                                                  "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                      "        << "\n";
         out_Init << "      glBindAttribLocation(sphere_SHADER, 0, \"position\");                                                                                   "        << "\n";
         out_Init << "      glBindAttribLocation(sphere_SHADER, 1, \"texture\");                                                                                    "        << "\n";
         out_Init << "      //glBindAttribLocation(sphere _SHADER, 2, \"normal\");                                                                                  "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                      "        << "\n";
         out_Init << "      glLinkProgram(sphere_SHADER);                                                                                                           "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                         "        << "\n";
         out_Init << "      #ifdef __APPLE__                                                                                                                           "        << "\n";
         out_Init << "      glDetachShader(sphere_SHADER, sphere_SHADER_VERTEX);                                                                                       "        << "\n";
         out_Init << "      glDetachShader(sphere_SHADER, sphere_SHADER_FRAGMENT);                                                                                     "        << "\n";
         out_Init << "      #endif                                                                                                                                     "        << "\n";
         out_Init << "      //------------------------------------------------                                                                                         "        << "\n";
         out_Init << "      glDeleteShader(sphere_SHADER_VERTEX);                                                                                                      "        << "\n";
         out_Init << "      glDeleteShader(sphere_SHADER_FRAGMENT);                                                                                                    "        << "\n";


         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS           "        << "\n";
         out_Init << "      UNIFORM_MODELVIEWPROJ_sphere                   = glGetUniformLocation(sphere_SHADER, \"mvpMatrix\");                       "        << "\n";
         out_Init << "      UNIFORM_LIGHT_MATRIX_sphere                    = glGetUniformLocation(sphere_SHADER, \"lightMatrix\");                                     "        << "\n";
         out_Init << "      UNIFORM_LIGHT_POSITION_01_sphere               = glGetUniformLocation(sphere_SHADER, \"light_POSITION_01\");                               "        << "\n"; 
         out_Init << "      UNIFORM_SHININESS_sphere                       = glGetUniformLocation(sphere_SHADER, \"shininess\");                                       "        << "\n";         
         out_Init << "      UNIFORM_TEXTURE_DOT3_sphere                    = glGetUniformLocation(sphere_SHADER, \"NormalMap\");                                       "        << "\n";        
         out_Init << "      UNIFORM_TEXTURE_sphere                         = glGetUniformLocation(sphere_SHADER, \"Texture1\");                                        "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES           "        << "\n";


         out_Init << "      //------------------------------------------------------------------------------------------                                              "        << "\n";
         out_Init << "      #ifdef __APPLE__                                                                                                                          "        << "\n";
         out_Init << "      filePathName = [[NSBundle mainBundle] pathForResource:@\"sphere_DOT3\" ofType:@\"bmp\"];                                                  "        << "\n";
         out_Init << "      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   "        << "\n";
         out_Init << "      glGenTextures(1, &sphere_NORMAL_TEX);                                                                                                     "        << "\n";
         out_Init << "      glBindTexture(GL_TEXTURE_2D, sphere_NORMAL_TEX);                                                                                          "        << "\n";
         out_Init << "      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      "        << "\n";
         out_Init << "      imgDestroyImage(image);                                                                                                                   "        << "\n";
         out_Init << "      //---------------------                                                                                                                   "        << "\n";
         out_Init << "      filePathName = [[NSBundle mainBundle] pathForResource:@\"sphere\" ofType:@\"png\"];                                                       "        << "\n";
         out_Init << "      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   "        << "\n";
         out_Init << "      glGenTextures(1, &sphere_TEXTURE1);                                                                                                       "        << "\n";
         out_Init << "      glBindTexture(GL_TEXTURE_2D, sphere_TEXTURE1);                                                                                            "        << "\n";
         out_Init << "      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      "        << "\n";
         out_Init << "      imgDestroyImage(image);                                                                                                                   "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------                                              "        << "\n";
         out_Init << "      #ifdef WIN32                                                                                                                            "        << "\n";
         out_Init << "      loadTexture(\"_MODEL_FOLDERS_/sphere/sphere_DOT3.bmp\",          sphere_NORMAL_TEX);                                                      "        << "\n";
         out_Init << "      loadTexture(\"_MODEL_FOLDERS_/sphere/sphere.png\",               sphere_TEXTURE1);                                                        "        << "\n";
         out_Init << "      #endif                                                                                                                                    "        << "\n";
         out_Init << "      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               "        << "\n";
         out_Init << "      #include    \"sphere.cpp\"                                                                                                                "        << "\n";
         out_Init << "      glGenBuffers(1,              &sphere_VBO);                                                                                                "        << "\n";
         out_Init << "      glBindBuffer(GL_ARRAY_BUFFER, sphere_VBO);                                                                                                "        << "\n";
         out_Init << "      glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);                                                                    "        << "\n";
         out_Init << "      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         "        << "\n";
         out_Init << "      //=================================================================================================================================       "        << "\n";       
         

//====================================================================================================

ofstream out_Render("sphere/sphere_Render.cpp");

       

         out_Render << "    glUseProgram(sphere_SHADER);                                                                                                                                              "        << "\n";
         out_Render << "    glBindBuffer(GL_ARRAY_BUFFER, sphere_VBO);                                                                                                                                "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             "        << "\n";
         out_Render << "    LoadIdentity(modelView);                                                                                                                                                  "        << "\n";
         out_Render << "    Translate(modelView, sphere_POSITION[0], sphere_POSITION[1], sphere_POSITION[2]);                                                                                         "        << "\n";
         out_Render << "    Rotate(modelView, sphere_ROTATE[0], sphere_ROTATE[1], sphere_ROTATE[2], sphere_ROTATE[3]);//--MODEL                                                                       "        << "\n";
         out_Render << "    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             "        << "\n";
         out_Render << "    LoadIdentity(lightMatrix);                                                                                                                                                "        << "\n";
         out_Render << "    InvertMatrix(lightMatrix, modelView);                                                                                                                                     "        << "\n";
         out_Render << "    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                "        << "\n";
         out_Render << "    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      "        << "\n";
         out_Render << "    Rotate(lightMatrix,1.0, 0.0, 0.0,  look_UP_DOWN);                                                                                                                       "        << "\n";       
         out_Render << "    //======================================================================================================                                                                  "        << "\n";         
         out_Render << "    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  "        << "\n";
         out_Render << "    glEnableVertexAttribArray(0);	                                                                                                                                          "        << "\n";
         out_Render << "    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 "        << "\n";
         out_Render << "    glEnableVertexAttribArray(1);                                                                                                                                             "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          "        << "\n";    
         out_Render << "    glUniform4f(UNIFORM_LIGHT_POSITION_01_sphere, sphere_LIGHT_POSITION_01[0], sphere_LIGHT_POSITION_01[1], sphere_LIGHT_POSITION_01[2], sphere_LIGHT_POSITION_01[3]);        "        << "\n";
         out_Render << "    glUniform1f(UNIFORM_SHININESS_sphere, sphere_SHININESS);                                                                                                                  "        << "\n";         
         out_Render << "    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_sphere,   1,0,  mvpMatrix);                                                                                                      "        << "\n";
         out_Render << "    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_sphere,    1,0,  lightMatrix);                                                                                                    "        << "\n";
         out_Render << "    //======================================================================================================                                                                  "        << "\n";         
         out_Render << "    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          "        << "\n";
         out_Render << "    glBindTexture(GL_TEXTURE_2D, sphere_NORMAL_TEX);                                                                                                                          "        << "\n";
         out_Render << "    glUniform1i (UNIFORM_TEXTURE_DOT3_sphere, 1);                                                                                                                             "        << "\n";
         out_Render << "    //---                                                                                                                                                                     "        << "\n";
         out_Render << "    glActiveTexture (GL_TEXTURE0);                                                                                                                                            "        << "\n";
         out_Render << "    glBindTexture(GL_TEXTURE_2D, sphere_TEXTURE1);                                                                                                                            "        << "\n";  
         out_Render << "    glUniform1i (UNIFORM_TEXTURE_sphere, 0 );                                                                                                                                 "        << "\n";
         out_Render << "    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              "        << "\n";
         out_Render << "    glDrawArrays(GL_TRIANGLES, 0,  " << object.polygons_qty * 3 << ");                                                                                                                                       "        << "\n";

//====================================================================================================


ofstream out_Keyboard("sphere/sphere_Keyboard.cpp");

         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    if (keys['J'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {                                                                                                                                   "        << "\n";
         out_Keyboard << "             sphere_POSITION[0]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['L'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_POSITION[0]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['I'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_POSITION[1]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['K'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_POSITION[1]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['O'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_POSITION[2]         +=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['U'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_POSITION[2]         -=  .01;                                                                                  "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";
         out_Keyboard << "    /* if (keys['J'])                                                                                                                   "        << "\n";
         out_Keyboard << "    {                                                                                                                                   "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[0]         -=  .01;                                                                         "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['L'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[0]         +=  .01;                                                                         "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['I'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[1]         +=  .01;                                                                         "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['K'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[1]         -=  .01;                                                                         "        << "\n";
         out_Keyboard << "    }                                                                                                                                   "        << "\n";
         out_Keyboard << "    if (keys['O'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[2]         +=  .01;                                                                         "        << "\n";
         out_Keyboard << "    }	                                                                                                                                  "        << "\n";
         out_Keyboard << "    if (keys['U'])                                                                                                                      "        << "\n";
         out_Keyboard << "    {	                                                                                                                                  "        << "\n";
         out_Keyboard << "             sphere_LIGHT_POSITION_01[2]         -=  .01;                                                                         "        << "\n";
         out_Keyboard << "    } */                                                                                                                                "        << "\n";
         out_Keyboard << "    //=======================================================================================                                           "        << "\n";




//====================================================================================================


ofstream out_ShutDown("sphere/sphere_Shutdown.cpp");
//--------------------------------------------------------


         out_ShutDown << "                    if(sphere_NORMALMAP != 0)                                                                                        "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteTextures(1, &sphere_NORMALMAP);                                                                  "        << "\n"; 
         out_ShutDown << "                            sphere_NORMALMAP = 0;                                                                                    "        << "\n"; 
         out_ShutDown << "                    }                                                                                                              "        << "\n"; 
         out_ShutDown << "                    if(sphere_TEXTUREMAP  != 0)                                                                                      "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteTextures(1, &sphere_TEXTUREMAP);                                                                 "        << "\n"; 
         out_ShutDown << "                            sphere_TEXTUREMAP  = 0;                                                                                  "        << "\n"; 
         out_ShutDown << "                    }                                                                                                              "        << "\n"; 
         out_ShutDown << "                    if(sphere_VBO  != 0)                                                                                             "        << "\n"; 
         out_ShutDown << "                    {                                                                                                              "        << "\n"; 
         out_ShutDown << "                            glDeleteBuffers(1, &sphere_VBO);                                                                         "        << "\n"; 
         out_ShutDown << "                            sphere_VBO  = 0;                                                                                         "        << "\n"; 
         out_ShutDown << "                    }                                                                                                              "        << "\n"; 


//====================================================================================================

ofstream out_LOCATION_STRINGS("sphere/_LOCATION_STRINGS.cpp");
         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Globals.cpp\"                                                                "        <<"\n";                                              
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Init.cpp\"                                                                   "        <<"\n";          
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";           
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Shadow_01.cpp\"                                                              "        <<"\n";         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                  
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Shadow_00.cpp\"                                                              "        <<"\n";           
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                    
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Render.cpp\"                                                                 "        <<"\n";
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                    
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Keyboard.cpp\"                                                               "        <<"\n";         
         out_LOCATION_STRINGS << "//====================================================================================                                          "        <<"\n";                  
         out_LOCATION_STRINGS << "#include \"_MODEL_FOLDERS_/sphere/sphere_Shutdown.cpp\"                                                               "        <<"\n";    


}
void resize (int p_width, int p_height)
{
	if (screen_width == 0 && screen_height==0) exit(0);
    screen_width=p_width; // We obtain the new screen width values and store it
    screen_height=p_height; // Height value
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // We clear both the color and the depth buffer so to draw the next frame
    glViewport(0,0,screen_width,screen_height); // Viewport transformation
    glMatrixMode(GL_PROJECTION); // Projection transformation
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0,(GLfloat)screen_width/(GLfloat)screen_height, 0.1, 10000.0);
    glutPostRedisplay (); // This command redraw the scene (it calls the same routine of glutDisplayFunc)
}
using std::ios;
void display(void)
{
   glDisable(GL_LIGHTING);
   ofstream out("sphere/sphere.cpp", ios::binary);
   int j;
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
   //glMatrixMode(GL_PROJECTION);
    glTranslatef(0.0,0.0,-2);
    glMatrixMode(GL_MODELVIEW); // Modeling transformation
    glLoadIdentity(); // Initialize the model matrix as identity
    glTranslatef(0.0,0.0,-1); // We move the object forward (the model matrix is multiplied by the translation matrix)
    rotation_x = rotation_x + rotation_x_increment;
    rotation_y = rotation_y + rotation_y_increment;
    rotation_z = rotation_z + rotation_z_increment;
    if (rotation_x > 359) rotation_x = 0;
    if (rotation_y > 359) rotation_y = 0;
    if (rotation_z > 359) rotation_z = 0;
    glRotatef(rotation_x,1.0,0.0,0.0); // Rotations of the object (the model matrix is multiplied by the rotation matrices)
    glRotatef(rotation_y,0.0,1.0,0.0);
    glRotatef(rotation_z,0.0,0.0,1.0);
    if (object.id_texture!=-1) 
	{
		glBindTexture(GL_TEXTURE_2D, object.id_texture); // We set the active texture 
	    glEnable(GL_TEXTURE_2D); // Texture mapping ON
	}
	else
	    glDisable(GL_TEXTURE_2D); // Texture mapping OFF
    out << "GLfloat sphere[] = \n" << "{\n"  << "     //number of vertices = " << object.polygons_qty*3 << "\n\n";    
    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
	for (j=0;j<object.polygons_qty;j++)
	{
		//----------------- FIRST VERTEX -----------------
		
        
		// Coordinates of the first vertex
		glVertex3f( object.vertex[ object.polygon[j].a ].x,
					object.vertex[ object.polygon[j].a ].y,
					object.vertex[ object.polygon[j].a ].z);

  out << object.vertex[ object.polygon[j].a ].x << ", ";
  out << object.vertex[ object.polygon[j].a ].y << ", ";
  out << object.vertex[ object.polygon[j].a ].z << ",";        
        

        
        //Normal coordinates of the first vertex
		glNormal3f( object.normal[ object.polygon[j].a ].x,
					object.normal[ object.polygon[j].a ].y,
					object.normal[ object.polygon[j].a ].z);
  
 // out << object.normal[ object.polygon[j].a ].x << ", ";
 // out << object.normal[ object.polygon[j].a ].y << ", ";
  //out << object.normal[ object.polygon[j].a ].z << ", ";
		

        // Texture coordinates of the first vertex
		glTexCoord2f( object.mapcoord[ object.polygon[j].a ].u,
					  object.mapcoord[ object.polygon[j].a ].v);
  
  out << "" << object.mapcoord[ object.polygon[j].a ].u << ", ";
  out << object.mapcoord[ object.polygon[j].a ].v << ", \n";	
    
    
    	//----------------- SECOND VERTEX -----------------
		// Texture coordinates of the second vertex
			

		// Coordinates of the second vertex
		glVertex3f( object.vertex[ object.polygon[j].b ].x,
					object.vertex[ object.polygon[j].b ].y,
					object.vertex[ object.polygon[j].b ].z);
					
  out << object.vertex[ object.polygon[j].b ].x << ", ";
  out << object.vertex[ object.polygon[j].b ].y << ", ";
  out << object.vertex[ object.polygon[j].b ].z << ",";					
        

        
        //Normal coordinates of the second vertex
		glNormal3f( object.normal[ object.polygon[j].b ].x,
					object.normal[ object.polygon[j].b ].y,
					object.normal[ object.polygon[j].b ].z);

 // out << object.normal[ object.polygon[j].b ].x << ", ";
 // out << object.normal[ object.polygon[j].b ].y << ", ";
  //out << object.normal[ object.polygon[j].b ].z << ", ";		        
        
        
        
		glTexCoord2f( object.mapcoord[ object.polygon[j].b ].u,
					  object.mapcoord[ object.polygon[j].b ].v);
					  
  out << "" << object.mapcoord[ object.polygon[j].b ].u << ", ";
  out << object.mapcoord[ object.polygon[j].b ].v << ", \n";        
        
		//----------------- THIRD VERTEX -----------------


		// Coordinates of the Third vertex
		glVertex3f( object.vertex[ object.polygon[j].c ].x,
					object.vertex[ object.polygon[j].c ].y,
					object.vertex[ object.polygon[j].c ].z);
					
  out << object.vertex[ object.polygon[j].c ].x << ", ";
  out << object.vertex[ object.polygon[j].c ].y << ", ";
  out << object.vertex[ object.polygon[j].c ].z << ",";
  					
  					

    	
        //Normal coordinates of the third vertex
		glNormal3f( object.normal[ object.polygon[j].c ].x,
					object.normal[ object.polygon[j].c ].y,
					object.normal[ object.polygon[j].c ].z);
  
  //out << object.normal[ object.polygon[j].c ].x << ", ";
  //out << object.normal[ object.polygon[j].c ].y << ", ";
  //out << object.normal[ object.polygon[j].c ].z << ", ";  					
  					
  				
                  
		// Texture coordinates of the third vertex
		glTexCoord2f( object.mapcoord[ object.polygon[j].c ].u,
					  object.mapcoord[ object.polygon[j].c ].v);
					  
  out << "" << object.mapcoord[ object.polygon[j].c ].u << ", ";
  out << object.mapcoord[ object.polygon[j].c ].v << ",\n\n ";                  	
  					
  					
	}
out << "};\n";	
	glEnd();
    glFlush(); // This force the execution of OpenGL commands
    glutSwapBuffers(); // In double buffered mode we invert the positions of the visible buffer and the writing buffer
}


void keyboard(unsigned char p_key, int p_x, int p_y)
{  
    switch (p_key)
    {
        case ' ':
            rotation_x_increment=0;
            rotation_y_increment=0;
            rotation_z_increment=0;
        break;
		case 'r': case 'R':
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 27:
			exit(0);
		break;
    }
}
void keyboard_s (int p_key, int p_x, int py)
{
    switch (p_key)
    {
        case GLUT_KEY_UP:
            rotation_x_increment = rotation_x_increment +0.005;
        break;
        case GLUT_KEY_DOWN:
            rotation_x_increment = rotation_x_increment -0.005;
        break;
        case GLUT_KEY_LEFT:
            rotation_y_increment = rotation_y_increment +0.005;
        break;
        case GLUT_KEY_RIGHT:
            rotation_y_increment = rotation_y_increment -0.005;
        break;
    }
}
/**********************************************************
 *
 * The main routine
 * 
 *********************************************************/

int main(int argc, char **argv)
{
    // We use the GLUT utility to initialize the window, to handle the input and to interact with the windows system
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("www.spacesimulator.net - 3d engine tutorials - To exit press ESC");    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc (resize);
    glutKeyboardFunc (keyboard);
    glutSpecialFunc (keyboard_s);
    init();
    glutMainLoop();

    return(0);    
}
