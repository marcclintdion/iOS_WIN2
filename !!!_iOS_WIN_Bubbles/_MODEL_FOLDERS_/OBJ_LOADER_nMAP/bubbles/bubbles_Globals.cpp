GLuint      bubbles_SHADER_VERTEX;                                                                                                      
GLuint      bubbles_SHADER_FRAGMENT;                                                                                                    
GLuint      bubbles_SHADER;                                                                                                             
//--------------------------------------                                                                                              
GLuint      UNIFORM_MODELVIEWPROJ_bubbles;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_bubbles;                                                                                               
//--------------------------------------                                                                                              
GLuint      UNIFORM_LIGHT_POSITION_01_bubbles;                                                                                          
GLuint      UNIFORM_SHININESS_bubbles;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_bubbles;                                                                                               
GLuint      UNIFORM_TEXTURE_bubbles;                                                                                                    
//--------------------------------------                                                                                              
GLfloat     bubbles_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     bubbles_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     bubbles_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                   
GLfloat     bubbles_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     bubbles_SHININESS             =    80.0;                                                                                    
//-----------------------------------------------------------------                                                                   
GLuint      bubbles_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                   
GLuint      bubbles_NORMALMAP;                                                                                                         
GLuint      bubbles_TEXTUREMAP;                                                                                                           
