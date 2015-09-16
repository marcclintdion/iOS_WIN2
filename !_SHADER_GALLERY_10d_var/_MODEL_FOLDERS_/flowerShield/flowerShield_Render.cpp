spinModel += 1.0;
  
    glUseProgram(flowerShield_SHADER);                                                                                                                                              
    glBindBuffer(GL_ARRAY_BUFFER, flowerShield_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, flowerShield_POSITION[0], flowerShield_POSITION[1], flowerShield_POSITION[2]);                                                                                         
    Rotate(modelView, flowerShield_ROTATE[0], flowerShield_ROTATE[1], flowerShield_ROTATE[2], flowerShield_ROTATE[3]+spinModel);//--MODEL                                                                       
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_flowerShield, flowerShield_LIGHT_POSITION_01[0], flowerShield_LIGHT_POSITION_01[1], flowerShield_LIGHT_POSITION_01[2], flowerShield_LIGHT_POSITION_01[3]);        
    glUniform4f(UNIFORM_LIGHT_POSITION_02_flowerShield, flowerShield_LIGHT_POSITION_02[0], flowerShield_LIGHT_POSITION_02[1], flowerShield_LIGHT_POSITION_02[2], flowerShield_LIGHT_POSITION_02[3]);       
    glUniform1f(UNIFORM_SHININESS_01_flowerShield, flowerShield_SHININESS_01);                                                                                                                  
    glUniform1f(UNIFORM_SHININESS_02_flowerShield, flowerShield_SHININESS_02);     
    glUniform1f(UNIFORM_ATTENUATION_01_flowerShield, flowerShield_ATTENUATION_01);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_02_flowerShield, flowerShield_ATTENUATION_02);     
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_flowerShield,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_MODELVIEW_flowerShield,       1,0,  modelView);    
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_flowerShield,    1,0,  lightMatrix);                                                                                                    
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_FRESNELMAP);                                                                                                                          
    glUniform1i (UNIFORM_FRESNELMAP_flowerShield, 2);                                                                                                                             
    //---               
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_NORMALMAP);                                                                                                                          
    glUniform1i (UNIFORM_TEXTURE_DOT3_flowerShield, 1);                                                                                                                             
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, flowerShield_TEXTUREMAP);                                                                                                                            
    glUniform1i (UNIFORM_TEXTURE_flowerShield, 0 ); 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 120);                                                                                                     

