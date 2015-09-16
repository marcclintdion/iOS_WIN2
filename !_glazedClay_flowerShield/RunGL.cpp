
//####################################################################################################################


#ifdef WIN32
        #define glGenerateMipmap       glGenerateMipmapEXT        
        #define glGenFramebuffers      glGenFramebuffersEXT    
        #define glBindFramebuffer      glBindFramebufferEXT          
        #define glFramebufferTexture2D glFramebufferTexture2DEXT            
         
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
        
        #include "headerFiles/WGL_ARB_multisample.h"
     
         
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"        
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
    
        #include "headerFiles/arb_multisample.h"
        bool domulti = true;
        bool doangle = true;    
    
#endif

//===============================================================================


//===============================================================================
//####################################################################################################################


#include <math.h>
  

//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################


//-------------------------------------------------------------------------------------------------------------------- 

const       int TEXTURE_WIDTH  = 1024;
const       int TEXTURE_HEIGHT = 1024;
//------------------------------------
GLuint      depth;

GLuint      fboId_2D; 
//GLuint    fboId_3D; 
//-----------------------
GLuint      shadowMap_2D;
//GLuint    shadowMap_3D;

//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef WIN32
               GLfloat viewWidth    = 1920;
               GLfloat viewHeight   = 1080;
               #include "cpp/WGL_ARB_multisample.cpp"  
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
GLfloat     textureMatrix[16];
GLfloat     ProjectionShadow[16];
GLfloat     LightModelViewMatrix[16];


GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================
                               

//######################################################################################################################
                                                           
                                GLuint  Env_Map;
                                GLuint  loc; 
                             
                                GLfloat spinModel = 0.0;
                                //---------------------------------------------------- 
                                #include    "_SHADERS/SHADOWS/shadows_24B_GLOBALS.cpp"                              
                                GLfloat       adjustShadowMove[]                                        =  {  0.11, 0.0, 0.0, 1.0}; 
                                //=========================================================================================== 
                                GLfloat       shadows_POSITION[]                                        =  {  0.0, 0.0, 0.0, 1.0}; 
                                GLfloat       shadows_ROTATE[]                                          =  {  1.0, 0.0, 0.0, 0.0};
                                //-------------------------
                                GLfloat       moveShadow_A[]                                            =  { -5.93004, -7.35991, -12.7902,   1.0};
                                GLfloat       rotateShadow_A[]                                          =  {  0, 1,     0.66,     30.0};
                                GLfloat       adjustModelShadow_A_ROTATION                              =    33;
                                //-------------------------
                                GLfloat       moveShadow_B[]                                            =  {  0.71,    -0.27,      0.0,      1.0};
                                GLfloat       rotateShadow_02[]                                         =  {  0.12,    -4.7,       2.42,   -32.456};
                                GLfloat       adjustModelShadow_02_ROTATION                             =    25.0;
                                //-------------------------
                                GLfloat       moveShadow_03[]                                           =  { -0.515,  -12.6952,   -0.4400,   1.0};
                                GLfloat       rotateShadow_03[]                                         =  {  0.0,      1.0,       1.0,     29.28};                           
                                GLfloat       darkness_shadow[]                                         =  {  0.0,      0.0,       0.0,      1.0};                                                      
                                //===========================================================================================                                  
                                

                                //===========================================================================================                                          
                                #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Globals.cpp"                                                                
                                //------------------------------------------------------------------------------------                                                                                                  
                                GLfloat     flowerShield_POSITION[]               =  {  0.0, 0.0, 0.0, 1.0};                                                                    
                                GLfloat     flowerShield_ROTATE[]                 =  {  0.0, 1.0,  0.0, 0.0};                                                                   
                                GLfloat     flowerShield_SCALE[]                  =  {  1.0, 1.0,  1.0, 1.0};                                                                   
                                //------------------------------------------------------------------------------------                                   
                                GLfloat     flowerShield_LIGHT_POSITION_01[]      =  {   -4.0, 8.0, 27.9, 1};                                                                  
                                GLfloat     flowerShield_LIGHT_POSITION_02[]      =  {    0.0, 0.0, 15.0,  1};                                      
                                GLfloat     flowerShield_SHININESS_01             =      65.86;                                                                                    
                                GLfloat     flowerShield_SHININESS_02             =     340.0; 
                                GLfloat     flowerShield_ATTENUATION_01           =       1.298;                                  
                                GLfloat     flowerShield_ATTENUATION_02           =       7.48008;    
                                //====================================================================================                                          



//======================================================================================================================================================================================



          #ifdef WIN32
             #include "cpp/winInit.cpp"
          #endif  
          
          
          
          
          
//------------------------------------------------------------------------------------------------------------------------                 
  

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
GLuint  snowy_CUBEMAP;
GLuint	cubemapTexture[1];

char *g_cCubemaps[6] = 
{

	"CG_ENVIRO_MAPPING/snowy/snowy_POSX.png",
	"CG_ENVIRO_MAPPING/snowy/snowy_NEGX.png",
	"CG_ENVIRO_MAPPING/snowy/snowy_POSY.png",
	"CG_ENVIRO_MAPPING/snowy/snowy_NEGY.png",
	"CG_ENVIRO_MAPPING/snowy/snowy_POSZ.png",
	"CG_ENVIRO_MAPPING/snowy/snowy_NEGZ.png"
};
//####################################################################################################################################################

void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__
{
        eyePosition[0]                     =   0.0; 
        eyePosition[1]                     =   0.0; 
        eyePosition[2]                     =   5.5;
        
        look_LEFT_RIGHT                    =    0.0;
        look_UP_DOWN                       =    0.0;   
        
        //==========================================================================
        #ifdef WIN32 
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp" 
            //-------------------------------------
            SetVSyncState(true);        
        #endif
        
//==========================================================================================================================================================================



        
        //====================================================================================================================    
        glGenTextures(1, &shadowMap_2D);
        glBindTexture(GL_TEXTURE_2D, shadowMap_2D);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_BGRA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);   
        //--------------------------------------------------------------------------------------------------------------------
        glGenFramebuffers(1, &fboId_2D);
        glBindFramebuffer(GL_FRAMEBUFFER, fboId_2D);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, shadowMap_2D, 0);
        //glGenRenderbuffersEXT(1, &depth);
        //glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth); 
        //glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT16, TEXTURE_WIDTH, TEXTURE_HEIGHT);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //====================================================================================================================                                         
        /*     
        glGenTextures(1, &shadowMap_3D);
	    glBindTexture(GL_TEXTURE_2D, shadowMap_3D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
	    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	    //glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_INTENSITY);
 	    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
 	    glBindTexture(GL_TEXTURE_2D, 0);
        //--------------------------------------------------------------------------------------------------------------------
        glGenFramebuffersEXT(1, &fboId_3D);
 	    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fboId_3D);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
	    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, shadowMap_3D, 0);
	    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        */     
        //====================================================================================================================
        
                                          
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Init.cpp"                                                                   
        //====================================================================================                                          

        
//=================================================================================================================== 


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
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
        
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        
        
        
        //=============================================================================================================================  
        
        glBindFramebuffer(GL_FRAMEBUFFER, fboId_2D);//-----------------------F.B.O.     
        //----------------------------------------------------------------
        //glColor4f(color is changed using fragment program)
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear (GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
        //----------------------------------------------------------------
        
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        
        
        PerspectiveMatrix(ProjectionShadow, 45, 1.0, 0.001, 10000.0);
        
        
        Rotate(ProjectionShadow, 0.0, 1.0, 0.0, 20.0);
        Rotate(ProjectionShadow, 1.0, 0.0, 0.0, 45.0);
        
        
        glUseProgram(SHADER_shadow);//---------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  
        
        //############################################################################################################################################################|__SHADOW_01
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===================================================== 
        darkness_shadow[0] = 0.5;
        darkness_shadow[1] = 0.5;
        darkness_shadow[2] = 0.5;
        
        
                                    
        //#include "_MODEL_FOLDERS_/flowerShield/flowerShield_Shadow_01.cpp"                                                              
        //====================================================================================                                          
        //#include "_MODEL_FOLDERS_/flowerShield/flowerShield_Shadow_00.cpp"                                                              

        
        
        //============================================================================================================================================================|__LAYER__02       
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================                     
        

        //---------------------------------------------------------                                  
       
        
        //############################################################################################################################################################|__SHADOW_02
        
        
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===========================================================                       
        darkness_shadow[0] = 0.3;
        darkness_shadow[1] = 0.3;
        darkness_shadow[2] = 0.3;
        
        
        //============================================================================================================================================================|__LAYER__02     
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================
        
        
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
        LoadIdentity(textureMatrix);
        AssignMatrix(textureMatrix, ProjectionShadow); 
        //===========================================================
        glEnable(GL_DEPTH_TEST);                                 
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 	                       
        glBindFramebuffer(GL_FRAMEBUFFER, 0);	                       

        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	 

//##################################################################################################################################################################################################        
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################          
        
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
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, viewWidth, viewHeight);
        PerspectiveMatrix(projection, 45,(float)viewWidth / (float)viewHeight, 0.1, 10000);
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        #endif        
        //=========================================================================================================================================================        
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];
        Rotate(projection, 1.0, 0.0, 0.0,  look_UP_DOWN);
        Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);        
        
//#################################################################################################################################################################        
        


        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //====================================================================================                                          

  
  
                        
    
        
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

        //====================================================================================  
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Keyboard.cpp"                                                               
        //====================================================================================                                          

/*  
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
         ofstream outKeys("lightPosition.cpp");                                                                                     
        
         outKeys << "  GLfloat     spring_LIGHT_POSITION_01[] = {" << spring_LIGHT_POSITION_01[0] << ", "  << spring_LIGHT_POSITION_01[1] << ", " << spring_LIGHT_POSITION_01[2] << ", " << 1.0 << "};\n";          
         outKeys << "  GLfloat     spring_SHININESS           =  " << spring_SHININESS  << ";\n";  
         outKeys << "  GLfloat     spring_ATTENUATION         =  " << spring_ATTENUATION   << ";\n";                                    
    }             
*/       

//--------------------------------------------------------------------    
    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }
//-----------------------------------
    if (keys['S'])
	{
          eyePosition[2] += .05;
    }
          if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += 0.5;
          
          }    
//-----------------------------------	
    if (keys['W'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= 0.5;      
          }	
//-----------------------------------    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	      if (keys['E'] && keys[VK_SHIFT])
	      {
                eyePosition[1] -= 0.5;      
          }		
    
    if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }
	      if (keys['Q'] && keys[VK_SHIFT])
	      {
                eyePosition[1] += 0.5;      
          }    
        
//--------------------------------------------------------------------

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
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Shutdown.cpp"                                                               
        //====================================================================================            
              
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




