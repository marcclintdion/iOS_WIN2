                    if(bubbles_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &bubbles_NORMALMAP);                                                                  
                            bubbles_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(bubbles_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &bubbles_TEXTUREMAP);                                                                 
                            bubbles_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(bubbles_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &bubbles_VBO);                                                                         
                            bubbles_VBO  = 0;                                                                                         
                    }                                                                                                              
