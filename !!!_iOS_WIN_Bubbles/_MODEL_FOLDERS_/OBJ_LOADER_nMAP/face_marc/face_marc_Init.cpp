      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      face_marc_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_face_marc =                                                                                                        

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
      face_marc_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(face_marc_SHADER_VERTEX, 1, &vertexSource_face_marc, NULL);                                                                        
      glCompileShader(face_marc_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_face_marc =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define mediump                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform mediump float   shininess;                                                                            \n"                       
      "    uniform mediump float   attenuation;                                                                          \n"                       

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

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      face_marc_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(face_marc_SHADER_FRAGMENT, 1, &fragmentSource_face_marc, NULL);                                                                          
      glCompileShader(face_marc_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(face_marc_SHADER, face_marc_SHADER_VERTEX);                                                                                              
      glAttachShader(face_marc_SHADER, face_marc_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(face_marc_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(face_marc_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(face_marc _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(face_marc_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(face_marc_SHADER, face_marc_SHADER_VERTEX);                                                                                              
      glDetachShader(face_marc_SHADER, face_marc_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(face_marc_SHADER_VERTEX);                                                                                                            
      glDeleteShader(face_marc_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_face_marc                   = glGetUniformLocation(face_marc_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_face_marc                    = glGetUniformLocation(face_marc_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_face_marc               = glGetUniformLocation(face_marc_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_face_marc                       = glGetUniformLocation(face_marc_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_face_marc                     = glGetUniformLocation(face_marc_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_face_marc                    = glGetUniformLocation(face_marc_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_face_marc                         = glGetUniformLocation(face_marc_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"face_marc_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &face_marc_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, face_marc_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"face_marc" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding], false);                                                   
      glGenTextures(1, &face_marc_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, face_marc_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/face_marc/face_marc_DOT3.bmp",          face_marc_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/face_marc/face_marc.png",               face_marc_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "face_marc.cpp"                                                                                                                
      glGenBuffers(1,              &face_marc_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, face_marc_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(face_marc), face_marc, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
