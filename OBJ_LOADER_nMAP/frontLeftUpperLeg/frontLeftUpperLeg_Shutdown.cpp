                    if(frontLeftUpperLeg_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &frontLeftUpperLeg_NORMALMAP);                                                                  
                            frontLeftUpperLeg_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(frontLeftUpperLeg_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &frontLeftUpperLeg_TEXTUREMAP);                                                                 
                            frontLeftUpperLeg_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(frontLeftUpperLeg_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &frontLeftUpperLeg_VBO);                                                                         
                            frontLeftUpperLeg_VBO  = 0;                                                                                         
                    }                                                                                                              
