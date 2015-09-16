                    if(frontRightUpperLeg_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &frontRightUpperLeg_NORMALMAP);                                                                  
                            frontRightUpperLeg_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(frontRightUpperLeg_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &frontRightUpperLeg_TEXTUREMAP);                                                                 
                            frontRightUpperLeg_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(frontRightUpperLeg_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &frontRightUpperLeg_VBO);                                                                         
                            frontRightUpperLeg_VBO  = 0;                                                                                         
                    }                                                                                                              
