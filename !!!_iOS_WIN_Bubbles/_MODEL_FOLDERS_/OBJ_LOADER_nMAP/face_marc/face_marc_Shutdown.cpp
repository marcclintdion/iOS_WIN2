                    if(face_marc_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &face_marc_NORMALMAP);                                                                  
                            face_marc_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(face_marc_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &face_marc_TEXTUREMAP);                                                                 
                            face_marc_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(face_marc_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &face_marc_VBO);                                                                         
                            face_marc_VBO  = 0;                                                                                         
                    }                                                                                                              
