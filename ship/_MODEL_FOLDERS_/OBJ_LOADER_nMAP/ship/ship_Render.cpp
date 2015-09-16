    glUseProgram(ship_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, ship_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, ship_POSITION[0], ship_POSITION[1], ship_POSITION[2]);                                                                                               
    Rotate(modelView, ship_ROTATE[0], ship_ROTATE[1], ship_ROTATE[2], ship_ROTATE[3]);                                                                                        
    Scale(modelView, 0.5, 0.5, 0.5);                                                                                                                                          
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_ship, ship_LIGHT_POSITION_01[0], ship_LIGHT_POSITION_01[1], ship_LIGHT_POSITION_01[2], ship_LIGHT_POSITION_01[3]);                  
    glUniform1f(UNIFORM_SHININESS_ship, ship_SHININESS);                                                                                                                      
    glUniform1f(UNIFORM_ATTENUATION_ship, ship_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_ship,   1,0,  mvpMatrix);                                                                                                        
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_ship,    1,0,  lightMatrix);                                                                                                      
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, ship_NORMALMAP);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_DOT3_ship, 1);                                                                                                                               
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, ship_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_ship, 0 );                                                                                                                                   
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 2526);                                                                                                     

