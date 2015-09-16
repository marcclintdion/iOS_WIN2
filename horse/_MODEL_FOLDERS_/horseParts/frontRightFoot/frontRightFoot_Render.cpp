                                                                                                                                             
    glBindBuffer(GL_ARRAY_BUFFER, frontRightFoot_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, frontRightUpperLeg_POSITION[0] + frontRightLowerLeg_POSITION[0] + frontRightFoot_POSITION[0],  frontRightUpperLeg_POSITION[1] + frontRightLowerLeg_POSITION[1] + frontRightFoot_POSITION[1],  frontRightUpperLeg_POSITION[2] + frontRightLowerLeg_POSITION[2] + frontRightFoot_POSITION[2]);                                                                                         
    Rotate(modelView, frontRightFoot_ROTATE[0], frontRightFoot_ROTATE[1], frontRightFoot_ROTATE[2], frontRightFoot_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
 #include "../horse_LIGHTWAVE_Render.cpp" 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, frontRightLeg_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, frontRightLeg_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 318);                                                                                                     

