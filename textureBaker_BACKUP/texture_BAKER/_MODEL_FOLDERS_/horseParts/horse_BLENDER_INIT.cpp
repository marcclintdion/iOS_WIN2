      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      horse_BLENDER_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_horse_BLENDER =                                                                                                        

      "    #define highp                                                                                     \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           
     
      "    uniform highp  float   scale_UV_MAP;                                                                 \n"   
      "    uniform highp  float   UV_WINDOW;                                                                 \n"        
      
      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                          \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    highp vec4   tempPos;                                                                              \n"
     
     
      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "         tempPos =  position;                                                                           \n"  
      "         //-----------------------------------------                                                    \n"         
      
      "         if(UV_WINDOW == 1.0)                                                                             \n"   
      "         {                                                                                              \n"   
      "             tempPos.xy = (texture.xy - 0.5);                                                           \n" 
      "             tempPos.z = 0.0;                                                                           \n"  
      "             tempPos.xy *= vec2(scale_UV_MAP,scale_UV_MAP) ;                                            \n"        
      "         }                                                                                              \n"      
      
      "         //-----------------------------------------                                                    \n"      
      "         varTexcoord        = texture;                                                                  \n"                           
      "         gl_Position        = mvpMatrix *tempPos;                                                       \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      horse_BLENDER_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(horse_BLENDER_SHADER_VERTEX, 1, &vertexSource_horse_BLENDER, NULL);                                                                        
      glCompileShader(horse_BLENDER_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_horse_BLENDER =                                                                                                            

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
    //  "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
    //  "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
    //  "         normal                =  normalize(NormalTex);                                                           \n"                       

    //  "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0);                                    \n"                             

                    

    
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      horse_BLENDER_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(horse_BLENDER_SHADER_FRAGMENT, 1, &fragmentSource_horse_BLENDER, NULL);                                                                          
      glCompileShader(horse_BLENDER_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(horse_BLENDER_SHADER, horse_BLENDER_SHADER_VERTEX);                                                                                              
      glAttachShader(horse_BLENDER_SHADER, horse_BLENDER_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(horse_BLENDER_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(horse_BLENDER_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(horse_BLENDER _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(horse_BLENDER_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(horse_BLENDER_SHADER, horse_BLENDER_SHADER_VERTEX);                                                                                              
      glDetachShader(horse_BLENDER_SHADER, horse_BLENDER_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(horse_BLENDER_SHADER_VERTEX);                                                                                                            
      glDeleteShader(horse_BLENDER_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_horse_BLENDER                   = glGetUniformLocation(horse_BLENDER_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_horse_BLENDER                    = glGetUniformLocation(horse_BLENDER_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_horse_BLENDER               = glGetUniformLocation(horse_BLENDER_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_horse_BLENDER                       = glGetUniformLocation(horse_BLENDER_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_horse_BLENDER                     = glGetUniformLocation(horse_BLENDER_SHADER,   "attenuation");                                              
      UNIFORM_scale_UV_MAP_horse_BLENDER                    = glGetUniformLocation(horse_BLENDER_SHADER,   "scale_UV_MAP");        
      UNIFORM_UV_WINDOW_horse_BLENDER                       = glGetUniformLocation(horse_BLENDER_SHADER,   "UV_WINDOW");        
      
      UNIFORM_TEXTURE_DOT3_horse_BLENDER                    = glGetUniformLocation(horse_BLENDER_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_horse_BLENDER                         = glGetUniformLocation(horse_BLENDER_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
