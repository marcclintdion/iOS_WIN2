GLuint      sphere_SB_SHADER_VERTEX;                                                                                                      
GLuint      sphere_SB_SHADER_FRAGMENT;                                                                                                    
GLuint      sphere_SB_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_sphere_SB;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_sphere_SB;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_sphere_SB;                                                                                          
GLuint      UNIFORM_SHININESS_sphere_SB;                                                                                                  
GLuint      UNIFORM_ATTENUATION_sphere_SB;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_sphere_SB;                                                                                               
GLuint      UNIFORM_TEXTURE_sphere_SB;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     sphere_SB_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     sphere_SB_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     sphere_SB_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
  GLfloat     sphere_SB_LIGHT_POSITION_01[] = {0, 3.34002, 74.1102, 1};
  GLfloat     sphere_SB_ATTENUATION         =  0.63;
  GLfloat     sphere_SB_SHININESS           =  50.71;                                                                              
//-----------------------------------------------------------------                                                                       
GLuint      sphere_SB_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      sphere_SB_NORMALMAP;                                                                                                          
GLuint      sphere_SB_TEXTUREMAP;                                                                                                         
