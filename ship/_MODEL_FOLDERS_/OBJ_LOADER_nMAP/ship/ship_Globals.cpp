GLuint      ship_SHADER_VERTEX;                                                                                                      
GLuint      ship_SHADER_FRAGMENT;                                                                                                    
GLuint      ship_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_ship;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_ship;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_ship;                                                                                          
GLuint      UNIFORM_SHININESS_ship;                                                                                                  
GLuint      UNIFORM_ATTENUATION_ship;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_ship;                                                                                               
GLuint      UNIFORM_TEXTURE_ship;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     ship_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     ship_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     ship_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     ship_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     ship_SHININESS             =    80.0;                                                                                    
GLfloat     ship_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      ship_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      ship_NORMALMAP;                                                                                                          
GLuint      ship_TEXTUREMAP;                                                                                                         
