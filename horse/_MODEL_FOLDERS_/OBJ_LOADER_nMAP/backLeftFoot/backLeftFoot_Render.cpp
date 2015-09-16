    glUseProgram(backLeftFoot_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, backLeftFoot_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, backLeftFoot_POSITION[0], backLeftFoot_POSITION[1], backLeftFoot_POSITION[2]);                                                                                         
    Rotate(modelView, backLeftFoot_ROTATE[0], backLeftFoot_ROTATE[1], backLeftFoot_ROTATE[2], backLeftFoot_ROTATE[3]);//--MODEL                                                                       
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_backLeftFoot, backLeftFoot_LIGHT_POSITION_01[0], backLeftFoot_LIGHT_POSITION_01[1], backLeftFoot_LIGHT_POSITION_01[2], backLeftFoot_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_backLeftFoot, backLeftFoot_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_backLeftFoot, backLeftFoot_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_backLeftFoot,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_backLeftFoot,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_backLeftFoot, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_backLeftFoot, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, backLeftFoot_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, backLeftFoot_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 318);                                                                                                     

