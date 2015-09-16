   
                      
                      plant_01_POSITION[0]   =   movePiece[0];                                                                                                 
                      plant_01_POSITION[1]   =   movePiece[1];                                                                                                 
                      plant_01_POSITION[2]   =   movePiece[2];                      
                      //-----------------------------                      
                      glBindBuffer(GL_ARRAY_BUFFER, plant_01_VBO);   
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TRANSFORMATIONS         
                      //LoadIdentity(LightModelViewMatrix);
                      
                      //Translate(LightModelViewMatrix,     moveShadow_01[0]+moveShadow_plant_01[0]-goldenSunset_LIGHT_POSITION_01[0]*.05,   moveShadow_01[2]+moveShadow_plant_01[2],   moveShadow_01[1]+moveShadow_plant_01[1]+goldenSunset_LIGHT_POSITION_01[2]*.05); 
                      //Translate(LightModelViewMatrix,     moveSet[0]*.88-(moveSet[1]*0.320001),               -(moveSet[2]-moveSet[1])*.88/2.0,            (moveSet[2]-moveSet[1])*.88/2.0);                
                     
                      //Translate(LightModelViewMatrix,     plant_01_POSITION[0],                      plant_01_POSITION[2],                      plant_01_POSITION[1]);                      
                      //Rotate(LightModelViewMatrix,        plant_01_ROTATE[0],                        plant_01_ROTATE[1],                        plant_01_ROTATE[2],                plant_01_ROTATE[3]);                                        
                      //Scale(LightModelViewMatrix, .8, .8, .8);
                      
                      
                      LoadIdentity(LightModelViewMatrix);
                      InvertMatrix(LightModelViewMatrix, ProjectionShadow);
                      //-------------------------------------------------------------------------------------------------------------------------------------------
                      Translate(LightModelViewMatrix,     (moveSet[0] * 0.113) + moveShadow_plant_01[0] - (moveSet[1] * 0.0605),      0.0,   0.0); 
                      Translate(LightModelViewMatrix,     plant_01_POSITION[0] * 0.113 + adjustMoveShadow_plant_01[0],        0.0,   0.0 );                      
                      //------------------------------ 
                      Rotate(LightModelViewMatrix,                   0.0,  0.0,   1.0,  -20); 
                      //------------------------------ 
                      Translate(LightModelViewMatrix,     0.0,   -(moveSet[2] * 0.094) +  moveShadow_plant_01[2] + (moveSet[1] * 0.091),       0.0); 
                      Translate(LightModelViewMatrix,     0.0,   -(plant_01_POSITION[2] * 0.09) + adjustMoveShadow_plant_01[2],  0.0 );     
                      //------------------------------ 
                      Rotate(LightModelViewMatrix,           plant_01_ROTATE[0],        plant_01_ROTATE[1],        plant_01_ROTATE[2],        plant_01_ROTATE[3]);                                        
                      Rotate(LightModelViewMatrix,        plant_01_Shadow_ROTATE[0], plant_01_Shadow_ROTATE[1], plant_01_Shadow_ROTATE[2], plant_01_Shadow_ROTATE[3]); 
                      //------------------------------ 
                      Scale(LightModelViewMatrix,            plant_01_SCALE,         plant_01_SCALE,       plant_01_SCALE);
                      Scale(LightModelViewMatrix,         scaleShadow_plant_01,   scaleShadow_plant_01,  scaleShadow_plant_01);                      
                      //Scale(LightModelViewMatrix, 1+spikyBall_5_POSITION[1] * .5,   1 + spikyBall_5_POSITION[1] * .5,  1 + spikyBall_5_POSITION[1] * .5);                      
                      
                      
                      
                      //--------------------------------------------------------------------------------------------------------------------------------------|__MATRIX_MATH
                      MultiplyMatrix(mvpMatrix, ProjectionShadow, LightModelViewMatrix); 
                      //--------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      #include "../../_SHADERS/SHADOWS/shadows_24B_RENDER.cpp"
                      //--------------------------------------------------------------------------------------------------------------------------------------
                      //--------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
                      glDrawArrays(GL_TRIANGLES, 0, 804);  	 
