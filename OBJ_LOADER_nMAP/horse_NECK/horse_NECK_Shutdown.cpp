                    if(horse_NECK_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &horse_NECK_NORMALMAP);                                                                  
                            horse_NECK_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(horse_NECK_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &horse_NECK_TEXTUREMAP);                                                                 
                            horse_NECK_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(horse_NECK_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &horse_NECK_VBO);                                                                         
                            horse_NECK_VBO  = 0;                                                                                         
                    }                                                                                                              
