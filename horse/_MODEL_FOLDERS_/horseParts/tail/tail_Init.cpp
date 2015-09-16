     //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          


                                                                                                                 
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/horseParts/tail/tail_DOT3.bmp",          tail_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/horseParts/tail/tail.png",               tail_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "tail.cpp"                                                                                                                
      glGenBuffers(1,              &tail_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, tail_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(tail), tail, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
