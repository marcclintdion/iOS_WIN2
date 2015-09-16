    glUseProgram(horse_NECK_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, horse_NECK_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, horse_NECK_POSITION[0], horse_NECK_POSITION[1], horse_NECK_POSITION[2]);                                                                                         
    Rotate(modelView, horse_NECK_ROTATE[0], horse_NECK_ROTATE[1], horse_NECK_ROTATE[2], horse_NECK_ROTATE[3]);//--MODEL                                                                       
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_horse_NECK, horse_NECK_LIGHT_POSITION_01[0], horse_NECK_LIGHT_POSITION_01[1], horse_NECK_LIGHT_POSITION_01[2], horse_NECK_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_horse_NECK, horse_NECK_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_horse_NECK, horse_NECK_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_horse_NECK,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_horse_NECK,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, horse_NECK_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_horse_NECK, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, horse_NECK_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_horse_NECK, 0 );                                                                                                                                 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 144);                                                                                                     

