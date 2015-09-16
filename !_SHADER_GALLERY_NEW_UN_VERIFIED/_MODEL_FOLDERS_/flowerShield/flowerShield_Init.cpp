
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"cornerStone_FRa" ofType:@"png"];                                                  
      image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &flowerShield_FRESNELMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, flowerShield_FRESNELMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------        
      filePathName = [[NSBundle mainBundle] pathForResource:@"flowerShield_DOT3_20p" ofType:@"bmp"];                                                  
      image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &flowerShield_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, flowerShield_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"flowerShield" ofType:@"png"];                                                       
      image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &flowerShield_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, flowerShield_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32  
      loadTexture("_MODEL_FOLDERS_/flowerShield/cornerStone_FRa.png",                flowerShield_FRESNELMAP);       
      loadTexture("_MODEL_FOLDERS_/flowerShield/flowerShield_DOT3_20p.bmp",          flowerShield_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/flowerShield/flowerShield.png",                   flowerShield_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "flowerShield.cpp"                                                                                                                
      glGenBuffers(1,              &flowerShield_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, flowerShield_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(flowerShield), flowerShield, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
