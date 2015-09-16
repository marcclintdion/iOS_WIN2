    glUseProgram(backRightFoot_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, backRightFoot_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, backRightFoot_POSITION[0], backRightFoot_POSITION[1], backRightFoot_POSITION[2]);                                                                                         
    Rotate(modelView, backRightFoot_ROTATE[0], backRightFoot_ROTATE[1], backRightFoot_ROTATE[2], backRightFoot_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                         
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                      
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_backRightFoot, backRightFoot_LIGHT_POSITION_01[0], backRightFoot_LIGHT_POSITION_01[1], backRightFoot_LIGHT_POSITION_01[2], backRightFoot_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_backRightFoot, backRightFoot_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_backRightFoot, backRightFoot_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_backRightFoot,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_backRightFoot,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, backRightFoot_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_backRightFoot, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, backRightFoot_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_backRightFoot, 0 );                                                                                                                                 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 228);                                                                                                     

