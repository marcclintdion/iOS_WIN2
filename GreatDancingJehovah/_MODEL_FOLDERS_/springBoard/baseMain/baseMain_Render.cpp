                                                                                                                                            
    glBindBuffer(GL_ARRAY_BUFFER, baseMain_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, baseMain_POSITION[0] + moveSet[0], baseMain_POSITION[1] + moveSet[1], baseMain_POSITION[2] + moveSet[2]);                                                                                         
    Rotate(modelView, baseMain_ROTATE[0], baseMain_ROTATE[1], baseMain_ROTATE[2], baseMain_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                        
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT);                                                                                                                      
    //======================================================================================================                                                                  
 
ShaderSelection(); 
 

if(SHADER_SELECTION == 0)
{  
    glUseProgram(baseMain_SHADER);    
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_baseMain, baseMain_LIGHT_POSITION_01[0], baseMain_LIGHT_POSITION_01[1], baseMain_LIGHT_POSITION_01[2], baseMain_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_baseMain, baseMain_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_baseMain, baseMain_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_baseMain,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_baseMain,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_baseMain, 1);  
    glUniform1i (UNIFORM_TEXTURE_baseMain, 0 ); 
}   
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, baseMain_NORMALMAP);                                                                                                                          
                                                                                                                               
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, baseMain_TEXTUREMAP);                                                                                                                            
                                                                                                                                    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 126);                                                                                                     

