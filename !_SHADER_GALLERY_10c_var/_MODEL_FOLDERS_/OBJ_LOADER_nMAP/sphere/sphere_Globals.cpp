GLuint      sphere_SHADER_VERTEX;                                                                                                      
GLuint      sphere_SHADER_FRAGMENT;                                                                                                    
GLuint      sphere_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_sphere;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_sphere;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_sphere;                                                                                          
GLuint      UNIFORM_SHININESS_sphere;                                                                                                  
GLuint      UNIFORM_ATTENUATION_sphere;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_sphere;                                                                                               
GLuint      UNIFORM_TEXTURE_sphere;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     sphere_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     sphere_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     sphere_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     sphere_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     sphere_SHININESS             =    80.0;                                                                                    
GLfloat     sphere_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      sphere_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      sphere_NORMALMAP;                                                                                                          
GLuint      sphere_TEXTUREMAP;                                                                                                         
