GLuint      head_LP_SHADER_VERTEX;                                                                                                      
GLuint      head_LP_SHADER_FRAGMENT;                                                                                                    
GLuint      head_LP_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_head_LP;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_head_LP;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_head_LP;                                                                                          
GLuint      UNIFORM_SHININESS_head_LP;                                                                                                  
GLuint      UNIFORM_ATTENUATION_head_LP;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_head_LP;                                                                                               
GLuint      UNIFORM_TEXTURE_head_LP;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     head_LP_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     head_LP_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     head_LP_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     head_LP_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     head_LP_SHININESS             =    80.0;                                                                                    
GLfloat     head_LP_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      head_LP_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      head_LP_NORMALMAP;                                                                                                          
GLuint      head_LP_TEXTUREMAP;                                                                                                         
