                                                                                                                                           
    glBindBuffer(GL_ARRAY_BUFFER, backRightFoot_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, backRightUpperLeg_POSITION[0] + backRightLowerLeg_POSITION[0] + backRightFoot_POSITION[0],  backRightUpperLeg_POSITION[1] + backRightLowerLeg_POSITION[1] + backRightFoot_POSITION[1],  backRightUpperLeg_POSITION[2] + backRightLowerLeg_POSITION[2] + backRightFoot_POSITION[2]);                                                                                          
    Rotate(modelView, backRightFoot_ROTATE[0], backRightFoot_ROTATE[1], backRightFoot_ROTATE[2], backRightFoot_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
 #include "../horse_LIGHTWAVE_Render.cpp" 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, backRightLeg_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, backRightLeg_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 318);                                                                                                     

