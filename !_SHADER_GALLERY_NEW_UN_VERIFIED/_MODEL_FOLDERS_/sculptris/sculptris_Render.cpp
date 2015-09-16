
      
                                                                                                                                             
    glBindBuffer(GL_ARRAY_BUFFER, sculptris_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
                                                                                                                                                
    Translate(modelView, sculptris_POSITION[0], sculptris_POSITION[1], sculptris_POSITION[2]);                                                                                         
    Rotate(modelView, sculptris_ROTATE[0], sculptris_ROTATE[1], sculptris_ROTATE[2], sculptris_ROTATE[3]+spinModel);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //Translate(lightMatrix, 1.0, -10.0, 2.0);                                                                                                                                
                                                                                                                    
    Rotate(lightMatrix,0.0, 1.0, 0.0,  look_LEFT_RIGHT); 
    Rotate(lightMatrix,1.0, 0.0, 0.0,  -look_UP_DOWN);                                                                                                                             
    //======================================================================================================                                                                  
    SelectShader(shaderNumber);     
    //======================================================================================================                                                                  
        
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, sculptris_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, sculptris_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 1584);                                                                                                     

