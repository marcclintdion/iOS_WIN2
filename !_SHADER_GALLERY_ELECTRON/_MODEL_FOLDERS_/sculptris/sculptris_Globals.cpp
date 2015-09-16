GLuint      sculptris_SHADER_VERTEX;                                                                                                      
GLuint      sculptris_SHADER_FRAGMENT;                                                                                                    
GLuint      sculptris_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_sculptris;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_sculptris;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_sculptris;                                                                                          
GLuint      UNIFORM_SHININESS_sculptris;                                                                                                  
GLuint      UNIFORM_ATTENUATION_sculptris;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_sculptris;                                                                                               
GLuint      UNIFORM_TEXTURE_sculptris;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     sculptris_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     sculptris_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     sculptris_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
  GLfloat     sculptris_LIGHT_POSITION_01[] = {0, 0.920018, 30, 1};
  GLfloat     sculptris_ATTENUATION         =  1.05;
  GLfloat     sculptris_SHININESS           =  800;                                                                        
//-----------------------------------------------------------------                                                                       
GLuint      sculptris_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      sculptris_NORMALMAP;                                                                                                          
GLuint      sculptris_TEXTUREMAP;                                                                                                         
