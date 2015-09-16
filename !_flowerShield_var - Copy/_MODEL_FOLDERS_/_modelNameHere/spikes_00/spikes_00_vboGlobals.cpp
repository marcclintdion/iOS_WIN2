GLuint spikes_00_vboID   =  16 ;

GLuint spikes_00_SHADER;
GLuint spikes_00_SHADER_Vertex;
GLuint spikes_00_SHADER_Fragment;

#include "spikes_00_VERT.cpp"
#include "spikes_00_NORM.cpp"
#include "spikes_00_TEX.cpp"
GLfloat     spikes_00_POSITION[]           =  {0.0, 0.0, 0.0};

GLfloat     lightPos_spikes_00[]           =  {-1.56117, 11.9431, 10.7077};
GLfloat     lightAttenuation_spikes_00     =   1.283;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GLfloat    shininess_spikes_00               = 199.733f;
GLuint     UNIFORM_shininess_spikes_00;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
GLfloat     rotation_AXIS_spikes_00[]      =  {1.0, 1.0, 1.0, 0.0};
GLfloat     spikes_00_counter1             =   0.0;
GLfloat     spikes_00_counter2             =   0.0;
GLfloat     spikes_00_counter3             =   0.0;
GLfloat     spikes_00_counter4             =   0.0;
GLuint      UNIFORM_counter1_spikes_00;

GLuint      UNIFORM_counter2_spikes_00;

GLuint      UNIFORM_counter3_spikes_00;

GLuint      UNIFORM_counter4_spikes_00;

GLfloat     LightAmbient_spikes_00[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightDiffuse_spikes_00[]        = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     LightSpecular_spikes_00[]       = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialAmbient_spikes_00[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialDiffuse_spikes_00[]     = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialEmission_spikes_00[]    = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat     MaterialSpecular_spikes_00[]    = { 0.0, 0, 0};
GLfloat     scalespikes_00ShadowY[]         = {1.26801, 0.0, 1.26801};
