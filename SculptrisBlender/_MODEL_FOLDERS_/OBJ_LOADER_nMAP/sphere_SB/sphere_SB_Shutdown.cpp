                    if(sphere_SB_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &sphere_SB_NORMALMAP);                                                                  
                            sphere_SB_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(sphere_SB_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &sphere_SB_TEXTUREMAP);                                                                 
                            sphere_SB_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(sphere_SB_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &sphere_SB_VBO);                                                                         
                            sphere_SB_VBO  = 0;                                                                                         
                    }                                                                                                              
