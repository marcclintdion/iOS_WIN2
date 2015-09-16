//glPushMatrix();
              glTranslatef(moveSet[0], moveSet[1], moveSet[2]);                                                
              glTranslatef(spikes_00_POSITION[0], spikes_00_POSITION[1], spikes_00_POSITION[2]);
              glRotatef(rotation_AXIS_spikes_00[3]++,rotation_AXIS_spikes_00[0], rotation_AXIS_spikes_00[1], rotation_AXIS_spikes_00[2]);

              glPushMatrix();
                   glLoadIdentity();
                //_ADDITIONAL_ROTATIONS_GO_HERE
                   glRotatef(-look_LEFT_RIGHT, 0, -1, 0);
                   glTranslatef(-eyePosition[0],-eyePosition[1],-eyePosition[2]);
                   glLightfv(GL_LIGHT0,GL_POSITION,lightPos_spikes_00);
                   glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightAttenuation_spikes_00);
              glPopMatrix();

//glPopMatrix();

              glUseProgramObjectARB(spikes_00_SHADER);


              glUniform1fARB( UNIFORM_shininess_spikes_00, shininess_spikes_00);
              glUniform1fARB( UNIFORM_counter1_spikes_00, spikes_00_counter1);
              glUniform1fARB( UNIFORM_counter2_spikes_00, spikes_00_counter2);
              glUniform1fARB( UNIFORM_counter3_spikes_00, spikes_00_counter3);
              glUniform1fARB( UNIFORM_counter4_spikes_00, spikes_00_counter4);


              glBindBufferARB(GL_ARRAY_BUFFER_ARB, spikes_00_vboID);

              glEnableClientState(GL_TEXTURE_COORD_ARRAY );
              glEnableClientState(GL_NORMAL_ARRAY);
              glEnableClientState(GL_VERTEX_ARRAY);
              glTexCoordPointer(3, GL_FLOAT, 0, (void*)(sizeof(spikes_00_VERT) + sizeof(spikes_00_NORM)));
              glNormalPointer(GL_FLOAT, 0, (void*)sizeof(spikes_00_VERT));
              glVertexPointer(3, GL_FLOAT, 0, 0);

            //Texture3_textureID;
            //Texture3_textureID = glGetUniformLocationARB(spikes_00_SHADER,"Texture3");
            //glUniform1iARB(SPECULAR_textureID, 2);
            //glActiveTextureARB(GL_TEXTURE2_ARB);
            //glBindTexture(GL_TEXTURE_2D,  specularMap[16]);

              DOT3_textureID;
              DOT3_textureID     = glGetUniformLocationARB(spikes_00_SHADER,"NormalMap");
              glUniform1iARB(DOT3_textureID, 1);
              glActiveTextureARB(GL_TEXTURE1_ARB);
              glBindTexture(GL_TEXTURE_2D,  normalMap[16]);

              textureID;
              textureID     = glGetUniformLocationARB(spikes_00_SHADER,"Texture1");
              glUniform1iARB(textureID, 0);
              glActiveTextureARB(GL_TEXTURE0_ARB);
              glBindTexture(GL_TEXTURE_2D, textureMap[16]);


              glDrawArrays(GL_TRIANGLES, 0, 228);


              glDisableClientState(GL_VERTEX_ARRAY);
              glDisableClientState(GL_NORMAL_ARRAY);
              glDisableClientState(GL_TEXTURE_COORD_ARRAY);

              glUseProgramObjectARB(0);

