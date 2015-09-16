    glBindBuffer(GL_ARRAY_BUFFER, backLeftFoot_VBO);                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL             
    LoadIdentity(modelView);                                                                                                                                                  
    Translate(modelView, backLeftUpperLeg_POSITION[0] + backLeftLowerLeg_POSITION[0] + backLeftFoot_POSITION[0], backLeftUpperLeg_POSITION[1] + backLeftLowerLeg_POSITION[1] + backLeftFoot_POSITION[1], backLeftUpperLeg_POSITION[2] + backLeftLowerLeg_POSITION[2] + backLeftFoot_POSITION[2]);                                                                                         
    Rotate(modelView, backLeftFoot_ROTATE[0], backLeftFoot_ROTATE[1], backLeftFoot_ROTATE[2], backLeftFoot_ROTATE[3]);//--MODEL                                                                       
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
 #include "../horse_LIGHTWAVE_Render.cpp" 
    //======================================================================================================                                                                  
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, backLeftLeg_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, backLeftLeg_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawArrays(GL_TRIANGLES, 0, 318);                                                                                                     

