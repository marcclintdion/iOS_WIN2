var     sculptris_LIGHT_POSITION_01[] = {-4, 8, 27.9, 1};
var     sculptris_ATTENUATION_01         =  -0.601998;
var     sculptris_SHININESS_01           =  0.210099;
//------
var     sculptris_LIGHT_POSITION_02[]      =  {    0.0, 0.0, 15.0,  1};   
var     sculptris_ATTENUATION_02           =       7.48008;                                  
var     sculptris_SHININESS_02             =     340.0;
//------
GLuint      sculptris_SHADER_VERTEX;                                                                                                      
GLuint      sculptris_SHADER_FRAGMENT;                                                                                                    
GLuint      sculptris_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_sculptris;                                                                                              
GLuint      UNIFORM_MODELVIEW_sculptris;
GLuint      UNIFORM_LIGHT_MATRIX_sculptris;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_sculptris;     
GLuint      UNIFORM_LIGHT_POSITION_02_sculptris;                                                                                          
GLuint      UNIFORM_SHININESS_01_sculptris;                                                                                                  
GLuint      UNIFORM_SHININESS_02_sculptris; 
GLuint      UNIFORM_ATTENUATION_01_sculptris;   
GLuint      UNIFORM_ATTENUATION_02_sculptris;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_sculptris;                                                                                               
GLuint      UNIFORM_TEXTURE_sculptris;                                                                                                    
GLuint      UNIFORM_CUBEMAP_sculptris;                                                                       
GLuint      UNIFORM_FRESNELMAP_sculptris;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     sculptris_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     sculptris_ROTATE[]              =  {  0.0, 1.0, 0.0, 0.0};                                                                   
GLfloat     sculptris_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
                                                        
//-----------------------------------------------------------------                                                                       
GLuint      sculptris_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       

GLuint      sculptris_NORMALMAP;                                                                                                          
GLuint      sculptris_TEXTUREMAP;                                                                                                         
GLuint      sculptris_FRESNELMAP;
