      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      backWall_2x2_SHADER = glCreateProgram();                                                                                                  
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource =                                                                                                              
      "    #define highp                                                                                            
"                       
      "    uniform highp vec4 light_POSITION_01;                                                                    
"                       
      "    uniform         mat4 modelViewProjectionMatrix;                                                          
"                       
      "    uniform         mat4 lightMatrix;                                                                        
"                       
      "    attribute       vec4 position;                                                                           
"                       
      "    attribute       vec2 texture;                                                                            
"                       
      "    varying highp vec4 lightPosition_PASS;                                                                   
"                       
      "    varying highp vec2 varTexcoord;                                                                          
"                       
      "    void main()                                                                                              
"                       
      "    {                                                                                                        
"                       
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                     
"                       
      "        varTexcoord        = texture;                                                                        
"                       
      "        gl_Position        = modelViewProjectionMatrix * position;                                           
"                       
      "    }                                                                                                        
";                      
      //---------------------------------------------------------------------                                                                   
      backWall_2x2_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                            
      glShaderSource(backWall_2x2_SHADER_VERTEX, 1, &vertexSource, NULL);                                                                       
      glCompileShader(backWall_2x2_SHADER_VERTEX);                                                                                              
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource =                                                                                                            
      " #ifdef GL_ES                                                                                                
"                       
      " #else                                                                                                       
"                       
      " #define highp                                                                                               
"                       
      " #endif                                                                                                      
"                       
      "    uniform sampler2D  Texture1;                                                                             
"                       
      "    uniform sampler2D  NormalMap;                                                                            
"                       
      "    varying highp vec4  lightPosition_PASS;                                                                  
"                       
      "    varying highp vec2  varTexcoord;                                                                         
"                       
      "     highp float NdotL1;                                                                                     
"                       
      "     highp vec3  normal;                                                                                     
"                       
      "     void main()                                                                                             
"                       
      "     {                                                                                                       
"                       
      "         highp vec3 NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                   
"                       
      "         NormalTex             = (NormalTex - 0.5);                                                          
"                       
      "         normal                =  normalize(NormalTex);                                                      
"                       
      "         normal                =  normal.rgb;                                                                
"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                       
"                       
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                             
"                       
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1         
"                       
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, 80.0)*.6 ;          
"                       
      "     }                                                                                                       
";                      
      //---------------------------------------------------------------------                                                                   
      backWall_2x2_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                        
      glShaderSource(backWall_2x2_SHADER_FRAGMENT, 1, &fragmentSource, NULL);                                                                   
      glCompileShader(backWall_2x2_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                        
      glAttachShader(backWall_2x2_SHADER, backWall_2x2_SHADER_VERTEX);                                                                          
      glAttachShader(backWall_2x2_SHADER, backWall_2x2_SHADER_FRAGMENT);                                                                        
      //------------------------------------------------                                                                                        
      glBindAttribLocation(backWall_2x2_SHADER, 0, "position");                                                                               
      glBindAttribLocation(backWall_2x2_SHADER, 1, "texture");                                                                                
      //glBindAttribLocation(backWall_2x2 _SHADER, 2, "normal");                                                                              
      //------------------------------------------------                                                                                        
      glLinkProgram(backWall_2x2_SHADER);                                                                                                       
      //------------------------------------------------                                                                                        
      #ifdef __APPLE__                                                                                                                          
      glDetachShader(backWall_2x2_SHADER, backWall_2x2_SHADER_VERTEX);                                                                          
      glDetachShader(backWall_2x2_SHADER, backWall_2x2_SHADER_FRAGMENT);                                                                        
      #endif                                                                                                                                    
      //------------------------------------------------                                                                                        
      glDeleteShader(backWall_2x2_SHADER_VERTEX);                                                                                               
      glDeleteShader(backWall_2x2_SHADER_FRAGMENT);                                                                                             
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS          
      UNIFORM_MODELVIEWPROJ                   = glGetUniformLocation(backWall_2x2_SHADER, "modelViewProjectionMatrix");                       
      UNIFORM_LIGHT_MATRIX                    = glGetUniformLocation(backWall_2x2_SHADER, "lightMatrix");                                     
      //UNIFORM_NORMAL_backWall_2x2LeftUpperArm       = glGetUniformLocation(backWall_2x2 _SHADER, "normalMatrix");                           
      UNIFORM_backWall_2x2_LIGHT_POSITION_01          = glGetUniformLocation(backWall_2x2_SHADER, "light_POSITION_01");                       
      UNIFORM_TEXTURE                         = glGetUniformLocation(backWall_2x2_SHADER, "Texture1");                                        
      UNIFORM_TEXTURE_DOT3                    = glGetUniformLocation(backWall_2x2_SHADER, "NormalMap");                                       
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES          
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"backWall_2x2_DOT3" ofType:@"bmp"];                                            
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &backWall_2x2_NORMAL_TEX);                                                                                                
      glBindTexture(GL_TEXTURE_2D, backWall_2x2_NORMAL_TEX);                                                                                     
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"backWall_2x2" ofType:@"png"];                                                 
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &backWall_2x2_TEXTURE1);                                                                                               
      glBindTexture(GL_TEXTURE_2D, backWall_2x2_TEXTURE1);                                                                                    
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef _WIN32_                                                                                                                            
      loadTexture("backWall_2x2/backWall_2x2_DOT3.bmp",          backWall_2x2_NORMAL_TEX);                                                     
      loadTexture("backWall_2x2/backWall_2x2.png",               backWall_2x2_TEXTURE1);                                                    
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "backWall_2x2/backWall_2x2.cpp"                                                                                             
      glGenBuffers(1,              &backWall_2x2_VBO);                                                                                          
      glBindBuffer(GL_ARRAY_BUFFER, backWall_2x2_VBO);                                                                                          
      glBufferData(GL_ARRAY_BUFFER, sizeof(backWall_2x2), backWall_2x2, GL_STATIC_DRAW);                                                        
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
