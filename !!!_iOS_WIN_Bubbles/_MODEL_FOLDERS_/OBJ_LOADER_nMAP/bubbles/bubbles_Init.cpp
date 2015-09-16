      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      bubbles_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_bubbles =                                                                                                        

      "    #define mediump                                                                                     \n"                           

      "    uniform mediump vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying mediump vec4   lightPosition_PASS;                                                          \n"                           
      "    varying mediump vec2   varTexcoord;                                                                 \n"                           


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      bubbles_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(bubbles_SHADER_VERTEX, 1, &vertexSource_bubbles, NULL);                                                                        
      glCompileShader(bubbles_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_bubbles =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define mediump                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform mediump float   shininess;                                                                            \n"                       

      "    varying mediump vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying mediump vec2    varTexcoord;                                                                          \n"                       

      "     mediump  float         NdotL1;                                                                               \n"                       
      "     mediump  vec3          normal;                                                                               \n"                       
      "     mediump vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1              \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      bubbles_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(bubbles_SHADER_FRAGMENT, 1, &fragmentSource_bubbles, NULL);                                                                          
      glCompileShader(bubbles_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(bubbles_SHADER, bubbles_SHADER_VERTEX);                                                                                              
      glAttachShader(bubbles_SHADER, bubbles_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(bubbles_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(bubbles_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(bubbles _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(bubbles_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(bubbles_SHADER, bubbles_SHADER_VERTEX);                                                                                              
      glDetachShader(bubbles_SHADER, bubbles_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(bubbles_SHADER_VERTEX);                                                                                                            
      glDeleteShader(bubbles_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_bubbles                   = glGetUniformLocation(bubbles_SHADER, "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_bubbles                    = glGetUniformLocation(bubbles_SHADER, "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_bubbles               = glGetUniformLocation(bubbles_SHADER, "light_POSITION_01");                                      
      UNIFORM_SHININESS_bubbles                       = glGetUniformLocation(bubbles_SHADER, "shininess");                                              
      UNIFORM_TEXTURE_DOT3_bubbles                    = glGetUniformLocation(bubbles_SHADER, "NormalMap");                                              
      UNIFORM_TEXTURE_bubbles                         = glGetUniformLocation(bubbles_SHADER, "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"bubbles_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &bubbles_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, bubbles_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"bubbles" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &bubbles_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, bubbles_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/bubbles/bubbles_DOT3.bmp",          bubbles_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/bubbles/bubbles.png",               bubbles_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "bubbles.cpp"                                                                                                                
      glGenBuffers(1,              &bubbles_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, bubbles_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(bubbles), bubbles, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
