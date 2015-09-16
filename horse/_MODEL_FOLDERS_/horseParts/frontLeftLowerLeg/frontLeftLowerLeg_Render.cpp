                                                                                                                                            
    glBindBuffer(GL_ARRAY_BUFFER, frontLeftLowerLeg_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, frontLeftUpperLeg_POSITION[0] + frontLeftLowerLeg_POSITION[0],  frontLeftUpperLeg_POSITION[1] + frontLeftLowerLeg_POSITION[1],  frontLeftUpperLeg_POSITION[2] + frontLeftLowerLeg_POSITION[2]);                                                                                         
    Rotate(modelView, frontLeftLowerLeg_ROTATE[0], frontLeftLowerLeg_ROTATE[1], frontLeftLowerLeg_ROTATE[2], frontLeftLowerLeg_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
 #include "../horse_LIGHTWAVE_Render.cpp" 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, frontLeftLeg_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, frontLeftLeg_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 204);                                                                                                     

