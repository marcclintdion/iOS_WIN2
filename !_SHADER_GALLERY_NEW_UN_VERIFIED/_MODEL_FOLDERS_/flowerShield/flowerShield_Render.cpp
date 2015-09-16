
  
                                                                                                                                                
    glBindBuffer(GL_ARRAY_BUFFER, flowerShield_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
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
    SelectShader(shaderNumber);   
    //======================================================================================================                                                                  
                                                                                                                        
    //---       
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_FRESNELMAP);                                                                                                                          
    //---               
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, flowerShield_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 120);                                                                                                     

