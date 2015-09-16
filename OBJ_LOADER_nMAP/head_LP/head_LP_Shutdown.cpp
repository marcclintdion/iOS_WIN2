                    if(head_LP_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &head_LP_NORMALMAP);                                                                  
                            head_LP_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(head_LP_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &head_LP_TEXTUREMAP);                                                                 
                            head_LP_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(head_LP_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &head_LP_VBO);                                                                         
                            head_LP_VBO  = 0;                                                                                         
                    }                                                                                                              
