      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          


                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/horseParts/neck/neck_DOT3.bmp",          neck_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/horseParts/neck/neck.png",               neck_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "neck.cpp"                                                                                                                
      glGenBuffers(1,              &neck_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, neck_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(neck), neck, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
