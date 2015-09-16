      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/horseParts/backRightUpperLeg/backRightLeg_DOT3.bmp",          backRightLeg_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/horseParts/backRightUpperLeg/backRightLeg.png",               backRightLeg_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "backRightUpperLeg.cpp"                                                                                                                
      glGenBuffers(1,              &backRightUpperLeg_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, backRightUpperLeg_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(backRightUpperLeg), backRightUpperLeg, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
