                    if(backRightUpperLeg_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &backRightUpperLeg_NORMALMAP);                                                                  
                            backRightUpperLeg_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(backRightUpperLeg_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &backRightUpperLeg_TEXTUREMAP);                                                                 
                            backRightUpperLeg_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(backRightUpperLeg_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &backRightUpperLeg_VBO);                                                                         
                            backRightUpperLeg_VBO  = 0;                                                                                         
                    }                                                                                                              
