      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      sphere_SB_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_sphere_SB =                                                                                                        

      "    #define highp                                                                                     \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                          \n"                           
      "    varying highp vec2   varTexcoord;                                                                 \n"                           


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      sphere_SB_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(sphere_SB_SHADER_VERTEX, 1, &vertexSource_sphere_SB, NULL);                                                                        
      glCompileShader(sphere_SB_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_sphere_SB =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  float         NdotL1;                                                                               \n"                       
      "     highp  vec3          normal;                                                                               \n"                       
      "     highp vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .1                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0)*0.5;              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      sphere_SB_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(sphere_SB_SHADER_FRAGMENT, 1, &fragmentSource_sphere_SB, NULL);                                                                          
      glCompileShader(sphere_SB_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(sphere_SB_SHADER, sphere_SB_SHADER_VERTEX);                                                                                              
      glAttachShader(sphere_SB_SHADER, sphere_SB_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(sphere_SB_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(sphere_SB_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(sphere_SB _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(sphere_SB_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(sphere_SB_SHADER, sphere_SB_SHADER_VERTEX);                                                                                              
      glDetachShader(sphere_SB_SHADER, sphere_SB_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(sphere_SB_SHADER_VERTEX);                                                                                                            
      glDeleteShader(sphere_SB_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_sphere_SB                   = glGetUniformLocation(sphere_SB_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_sphere_SB                    = glGetUniformLocation(sphere_SB_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_sphere_SB               = glGetUniformLocation(sphere_SB_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_sphere_SB                       = glGetUniformLocation(sphere_SB_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_sphere_SB                     = glGetUniformLocation(sphere_SB_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_sphere_SB                    = glGetUniformLocation(sphere_SB_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_sphere_SB                         = glGetUniformLocation(sphere_SB_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"sphere_SB_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &sphere_SB_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, sphere_SB_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"sphere_SB" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &sphere_SB_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, sphere_SB_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/sphere_SB/sphere_SB_DOT3.bmp",          sphere_SB_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/sphere_SB/sphere_SB.png",               sphere_SB_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "sphere_SB.cpp"                                                                                                                
      glGenBuffers(1,              &sphere_SB_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, sphere_SB_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_SB), sphere_SB, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
