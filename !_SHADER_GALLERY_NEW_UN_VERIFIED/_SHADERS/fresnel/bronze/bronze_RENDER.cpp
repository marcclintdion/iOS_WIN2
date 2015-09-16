    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUseProgram(bronze_SHADER);            
    //------------------------------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_bronze, bronze_LIGHT_POSITION_01[0], bronze_LIGHT_POSITION_01[1], bronze_LIGHT_POSITION_01[2], bronze_LIGHT_POSITION_01[3]);        
        
    glUniform1f(UNIFORM_SHININESS_01_bronze, bronze_SHININESS_01);                                                                                                                  
 
    glUniform1f(UNIFORM_ATTENUATION_01_bronze, bronze_ATTENUATION_01);                                                                                                                  
    
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_bronze,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_MODELVIEW_bronze,       1,0,  modelView);    
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_bronze,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_FRESNELMAP_bronze, 2);      
    glUniform1i (UNIFORM_TEXTURE_DOT3_bronze, 1);      
    glUniform1i (UNIFORM_TEXTURE_bronze, 0 );    
