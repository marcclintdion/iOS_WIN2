
                                                                                                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "backLeftFoot.cpp"                                                                                                                
      glGenBuffers(1,              &backLeftFoot_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, backLeftFoot_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(backLeftFoot), backLeftFoot, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //=================================================================================================================================       
