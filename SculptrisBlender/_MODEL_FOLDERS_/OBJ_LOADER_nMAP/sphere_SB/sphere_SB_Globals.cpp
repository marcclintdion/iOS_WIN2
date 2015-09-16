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
GLfloat     sphere_SB_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     sphere_SB_SHININESS             =    80.0;                                                                                    
GLfloat     sphere_SB_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      sphere_SB_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      sphere_SB_NORMALMAP;                                                                                                          
GLuint      sphere_SB_TEXTUREMAP;                                                                                                         
