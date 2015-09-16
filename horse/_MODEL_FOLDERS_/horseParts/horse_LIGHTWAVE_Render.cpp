    glUseProgram(horse_LIGHTWAVE_SHADER );   
    
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_horse_LIGHTWAVE, horse_LIGHTWAVE_LIGHT_POSITION_01[0], horse_LIGHTWAVE_LIGHT_POSITION_01[1], horse_LIGHTWAVE_LIGHT_POSITION_01[2], horse_LIGHTWAVE_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_horse_LIGHTWAVE, horse_LIGHTWAVE_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_horse_LIGHTWAVE, horse_LIGHTWAVE_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_horse_LIGHTWAVE,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_horse_LIGHTWAVE,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_horse_LIGHTWAVE, 1);   
    glUniform1i (UNIFORM_TEXTURE_horse_LIGHTWAVE, 0 ); 
