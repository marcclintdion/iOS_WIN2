                    if(ship_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &ship_NORMALMAP);                                                                  
                            ship_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(ship_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &ship_TEXTUREMAP);                                                                 
                            ship_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(ship_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &ship_VBO);                                                                         
                            ship_VBO  = 0;                                                                                         
                    }                                                                                                              
