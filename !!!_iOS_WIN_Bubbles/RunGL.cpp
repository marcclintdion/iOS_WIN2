
//####################################################################################################################


#ifdef WIN32
        #define glGenerateMipmap    glGenerateMipmapEXT        
        #define glMapBufferOES      glMapBuffer      
        #define glUnmapBufferOES    glUnmapBuffer           
        
        #define GL_WRITE_ONLY_OES   GL_WRITE_ONLY   
        
        
        #define STRICT
        #define WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

        #include <GL/gl.h>

        HDC	   hDC        = NULL;
        HGLRC      hRC        = NULL;
        HWND       hWnd       = NULL;
        HINSTANCE  hInstance  = NULL;
        //-------------------------------
        int        WINAPI       WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
        LRESULT    CALLBACK     WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
        //-------------------------------
        void       ProcessKeyboard();
        int        LoadTexture(char *texture_name, GLuint *texture);
        //-------------------------------
        bool keys[256], keypressed[256];



        #include "headerFiles/glext.h" 
        #include "headerFiles/glext_Init_A.cpp" 
        
        #include "headerFiles/VSync.h"   
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
    

#endif



//####################################################################################################################


#include <math.h>
  

//###############################################################################################################################################

#include "MATRIX_MATH.cpp"

//###############################################################################################################################################


//----------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef WIN32
               GLfloat viewWidth    = 1280;
               GLfloat viewHeight   =  800;
        #endif
        #ifdef __APPLE__
               GLfloat viewWidth;
               GLfloat viewHeight;
               GLuint  viewFramebuffer;        
        #endif        
        //-------------------------------------------------------------------------------

               GLfloat eyePosition[3];
               GLfloat look_LEFT_RIGHT;
               GLfloat look_UP_DOWN;   


//#########################################################################################################|_FREE_IMAGE

void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{
        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif        
}

//===============================================================================================================================                                                   

GLfloat     modelView[16];
GLfloat     projection[16];
GLfloat     mvpMatrix[16];
GLfloat     mvpMatrixInverse[16];
GLfloat     lightMatrix[16];  
GLfloat     moveSetMatrix[16]; 

GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================



                                //===================================================================================================================
                                
                                GLfloat     moveSet[]                        = {   0.0, 0.0, 0.0}; 

                                GLfloat     lightPos_bubbles_00[]            = {   0.209, 0.200301, 10.76};
                                GLfloat     lightAttenuation_bubbles_00      =     0.99702;

                                GLfloat     MaterialShininess_bubbles_00     =   360.816;
                                //----------------------------------------
                                GLfloat     bubbles_00_POSITION[]            = {   0.0, 0.0, 0.0};
                                GLfloat     bubbles_00_VELOCITY[]            = {   0.0, 0.0, 0.0}; 

                                GLfloat     rotation_AXIS_bubbles_00[]       = {   0.0, 0.0, 0.0, 0.0};

                                GLuint      UNIFORM_particlePosition_bubbles_00;
                                GLuint      UNIFORM_particleVelocity_bubbles_00;                             
                                //----------------------------------------
                                GLfloat     bubbles_00_counter1              =     5.0;
                                GLfloat     bubbles_00_counter2              =    -0.0034;
                                GLfloat     bubbles_00_counter3              =     0.0;
                                GLfloat     bubbles_00_counter4              =     0.0;         

                                GLfloat     bubbles_00_counter1_ACCELERATION =     0.05;                   
                                                      
                                GLfloat     bubbles_00_counter1_FORWARD      =     1.0;

                                GLuint      bubbles_00_VERT_INITIAL_vboID;
                                GLuint      bubbles_00_VERT_FINAL_vboID;                             
                                GLuint      bubbles_00_CYCLE_COUNTER_vboID;   
                                GLuint      bubbles_00_BubbleSize_vboID;                             

                                //----------------------------------------------------------------------------------------------------                             
                                #define     POINTSIZE_OF_PARTICLES               10
                                //----------------------------------------------------------------------------------------------------
                                #define     NUMBER_OF_PARTICLES                 100     //This number is 1/3, the render call has three calls rotated about the z-axis
                                //--------------------------------                             
                                GLfloat     particle_VBO_SIZE[NUMBER_OF_PARTICLES][3];  //This initializes the VBO size                                
                                //-------------------------------------------------------
                                GLfloat     particlePositonINITIAL[60][3];             //This initializes the VBO size                             
                                GLfloat    *vertexSet_InitialPositions;
                                //----------------------------------------------------------------------------------------------------
                                GLfloat     particlePositonFinal[60][3];                  
                                GLfloat    *vertexSet_FinalPositions; 
                                //----------------------------------------------------------------------------------------------------
                                GLfloat     particleCycleCounter[60][3];
                                GLfloat    *vertexSet_cycleCounters;
                                //----------------------------------------------------------------------------------------------------
                                GLfloat     particleBubbleSize[60][3];
                                GLfloat    *vertexSet_bubbleSize;                             
                                bool        runOnce                                   =  true;
                                bool        resetParticlesCounter_bubbles_00          =  true;

                                GLfloat     bubbles_ARRAY[]                           = {0.0, 0.0, 0.0};

                                #include   "_MODEL_FOLDERS_/bubbles_00/bubbles.cpp"
                               // #include   "_MODEL_FOLDERS_/bubbles_00/bubbles_TEX.cpp"

                                GLuint      bubbles_TEXTUREMAP;
                                GLuint      bubbles_NORMALMAP;

                                GLuint      UNIFORM_LIGHT_POSITION_01_bubbles;      
                                GLuint      UNIFORM_TEXTURE_DOT3_bubbles;
                                GLuint      UNIFORM_TEXTURE_bubbles;

                                GLuint      UNIFORM_counter1_bubbles;

                                GLuint      bubbles_SHADER;
                                GLuint      bubbles_SHADER_VERTEX;
                                GLuint      bubbles_SHADER_FRAGMENT;
                                
                                #include   "_MODEL_FOLDERS_/bubbles_00/bubbles_00_vboGlobals.cpp" 
                                //====================================================================================================================    





          #ifdef WIN32
             #include "cpp/winInit.cpp"
          #endif  
          
          
          
          
          
//------------------------------------------------------------------------------------------------------------------------                 
  

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__
{

        eyePosition[0]                     =   0.0; 
        eyePosition[1]                     =   0.0; 
        eyePosition[2]                     =   8.0;
        
        look_LEFT_RIGHT                   =    0.0;
        look_UP_DOWN                      =    0.0; 
        
        
        //==========================================================================
        #ifdef WIN32    
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp" 
            //-------------------------------------
            SetVSyncState(true);        
        #endif
            

        
        //==========================================================================
     
   
        #include "_MODEL_FOLDERS_/bubbles_00/bubbles_00_vboInit.cpp"     //vboID = 530        
        
        //==========================================================================


//=================================================================================================================== 


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);  


//=====================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


void RenderGL(void)
{
        //========================================================================================================================================================        
        //---------------------------------------------------SHADOW_FRAMEBUFFER_CODE_GOES_HERE_____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //---------------------------------------------------SHADOW_FRAMEBUFFER_CODE_GOES_HERE_____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
        //========================================================================================================================================================    
        
        
        
        //========================================================================================================================================================    
        //---------------------------------------------------SHADOW_FRAMEBUFFER_CODE_GOES_HERE_____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
        //---------------------------------------------------SHADOW_FRAMEBUFFER_CODE_GOES_HERE_____________!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //========================================================================================================================================================        
        #ifdef __APPLE__    
            glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        #endif    
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================



        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 5.0f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        //========================================================================================================================================================= 
        PerspectiveMatrix(projection, 45,(float)viewWidth / (float)viewHeight, 0.1, 10000);
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        #endif
        //=========================================================================================================================================================

                  
                projection[12] = eyePosition[0];
                projection[13] = eyePosition[1];
                projection[15] = eyePosition[2];
                 
                 
                Rotate(projection, 1.0, 0.0, 0.0, look_UP_DOWN);
                Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);        
        
        
        //=========================================================================================================================================================
        
        glDepthMask(GL_FALSE);
  
        #ifdef WIN32
             glPointSize(POINTSIZE_OF_PARTICLES);
             glEnable(GL_POINT_SPRITE_ARB);
             glTexEnvf(GL_POINT_SPRITE_ARB, GL_COORD_REPLACE_ARB, GL_TRUE);
             glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);  
        #endif
        glEnable(GL_BLEND);
        
        
        //=========================================================================================================================================================       
        bubbles_00_counter1 += bubbles_00_counter1_ACCELERATION;      
        //-----------------------------------
        glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_CYCLE_COUNTER_vboID);         
        vertexSet_cycleCounters = (GLfloat*)glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES );
        
        for(int i = 0; i < 60; i++)
        {
                particleCycleCounter[i][0] += bubbles_00_counter1_ACCELERATION;
                
                if(particleCycleCounter[i][0] >= 60)
                {
                        particleCycleCounter[i][0] = 0.0;
                }
                
                *vertexSet_cycleCounters   =  particleCycleCounter[i][0]; 
                vertexSet_cycleCounters  +=1;
                
                //------------------------------------//_UNUSED_FILLER
                *vertexSet_cycleCounters   =  0.0;      
                vertexSet_cycleCounters  +=1;
                *vertexSet_cycleCounters   =  0.0;       
                vertexSet_cycleCounters  +=1;        
                //------------------------------------
        }
        glUnmapBufferOES(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        
        //=========================================================================================================================================================
        
        glUseProgram(bubbles_SHADER);
        //--------------------------

        bubbles_00_counter1 += bubbles_00_counter1_ACCELERATION;      
        
        //-----------------------------------------------------------------------------------------------------------
        LoadIdentity(modelView);
    
        Translate(modelView, bubbles_00_POSITION[0], bubbles_00_POSITION[1], bubbles_00_POSITION[2]);
        //Rotate(modelView, rotation_AXIS_bubbles_00[0], rotation_AXIS_bubbles_00[1], rotation_AXIS_bubbles_00[2], rotation_AXIS_bubbles_00[3]);
        
        MultiplyMatrix(mvpMatrix, projection, modelView); 


        //===========================================================================================================       
        glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_INITIAL_vboID);        
        glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 12, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);	
        //===========================================================================================================         
        glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_VERT_FINAL_vboID);        
        glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 12, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(1);	
        //===========================================================================================================         
        glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_CYCLE_COUNTER_vboID);        
        glVertexAttribPointer(2,   3, GL_FLOAT, GL_FALSE, 12, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(2);	
        //===========================================================================================================          
        glBindBuffer(GL_ARRAY_BUFFER, bubbles_00_BubbleSize_vboID);        
        glVertexAttribPointer(3,   3, GL_FLOAT, GL_FALSE, 12, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(3);	
        //===========================================================================================================          
   
        
        glUniform1f( UNIFORM_counter1_bubbles, bubbles_00_counter1);
        glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ,   1,0,  mvpMatrix);
        //------------------------------------------------------------------------------------------------------------
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, bubbles_NORMALMAP);
        glUniform1i(UNIFORM_TEXTURE_DOT3_bubbles, 1);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, bubbles_TEXTUREMAP);
        glUniform1i(UNIFORM_TEXTURE_bubbles, 0);
        //-------------------------------------------------------------
        glDrawArrays(GL_POINTS, 0, 60);
        //-------------------------------------------------------------

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        

        glDepthMask(GL_TRUE);   
        
        //=========================================================================================================================================================

        
        
        #ifdef WIN32
             SwapBuffers( hDC );
        #endif
}

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


#ifdef WIN32 
void ProcessKeyboard()					
{
		


}
#endif


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{
        #ifdef WIN32
            #include "cpp/shutDownWin.cpp"
        #endif 	 

        //====================================================================================
        if(bubbles_NORMALMAP != 0)
        {
                glDeleteTextures(1, &bubbles_NORMALMAP);
                bubbles_NORMALMAP = 0;
        }
        if(bubbles_TEXTUREMAP  != 0)
        {    
                glDeleteTextures(1, &bubbles_TEXTUREMAP);
                bubbles_TEXTUREMAP  = 0;
        }
        
        if(bubbles_00_VERT_INITIAL_vboID  != 0)
        {    
                glDeleteBuffers(1, &bubbles_00_VERT_INITIAL_vboID);
                bubbles_00_VERT_INITIAL_vboID  = 0;
        }        
        if(bubbles_00_VERT_FINAL_vboID  != 0)
        {    
                glDeleteBuffers(1, &bubbles_00_VERT_FINAL_vboID);
                bubbles_00_VERT_FINAL_vboID  = 0;
        }       
        
        if(bubbles_00_CYCLE_COUNTER_vboID  != 0)
        {    
                glDeleteBuffers(1, &bubbles_00_CYCLE_COUNTER_vboID);
                bubbles_00_CYCLE_COUNTER_vboID  = 0;
        }        
        if(bubbles_00_BubbleSize_vboID  != 0)
        {    
                glDeleteBuffers(1, &bubbles_00_BubbleSize_vboID);
                bubbles_00_BubbleSize_vboID  = 0;
        }        
        //====================================================================================
        
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




