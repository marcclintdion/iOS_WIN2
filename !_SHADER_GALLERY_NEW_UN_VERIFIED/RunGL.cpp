#define var GLfloat
//####################################################################################################################


#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT        
        #define   glGenFramebuffers      glGenFramebuffersEXT    
        #define   glBindFramebuffer      glBindFramebufferEXT          
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT            
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

        #include <GL/gl.h>

        HDC	       hDC        = NULL;
        HGLRC      hRC        = NULL;
        HWND       hWnd       = NULL;
        HINSTANCE  hInstance  = NULL;
        //-------------------------------
        int        WINAPI       WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
        LRESULT    CALLBACK     WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
        //-------------------------------
        void       ProcessKeyboard();
        //-------------------------------
        var keys[256], keypressed[256];



        #include "headerFiles/glext.h" 
        #include "headerFiles/glext_Init_A.cpp" 
        
        #include "headerFiles/VSync.h"   
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"        
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------
        //#include "headerFiles/WGL_ARB_multisample.h"    
        //#include "headerFiles/arb_multisample.h"
        //bool domulti = true;
        //bool doangle = true;    
    
#endif

//####################################################################################################################


#include <math.h>
  

//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################


//-------------------------------------------------------------------------------------------------------------------- 

int TEXTURE_WIDTH  = 1024;
int TEXTURE_HEIGHT = 1024;
//------------------------------------
GLuint      depth;
GLuint      fboId_2D; 
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
               var viewWidth    = 1920;
               var viewHeight   = 1080;
               #include "cpp/WGL_ARB_multisample.cpp"  
        #endif
        #ifdef __APPLE__
               var viewWidth;
               var viewHeight;
               GLuint  viewFramebuffer;        
        #endif        
        //-------------------------------------------------------------------------------

               var eyePosition[3];
               var look_LEFT_RIGHT;
               var look_UP_DOWN;   


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

var     modelView[16];
var     projection[16];
var     mvpMatrix[16];
var     mvpMatrixInverse[16];
var     lightMatrix[16];  
var     moveSetMatrix[16]; 
var     textureMatrix[16];
var     ProjectionShadow[16];
var     LightModelViewMatrix[16];


GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================
                               

//######################################################################################################################
                                                           
                                
                                var spinModel = 0.0;
                                //---------------------------------------------------- 
                                #include  "_SHADERS/SHADOWS/shadows_24B_GLOBALS.cpp"                              
                                var       adjustShadowMove[]                                        =  {  0.11, 0.0, 0.0, 1.0}; 
                                //=========================================================================================== 
                                var       shadows_POSITION[]                                        =  {  0.0, 0.0, 0.0, 1.0}; 
                                var       shadows_ROTATE[]                                          =  {  1.0, 0.0, 0.0, 0.0};
                                //-------------------------
                                var       moveShadow_A[]                                            =  { -5.93004, -7.35991, -12.7902,   1.0};
                                var       rotateShadow_A[]                                          =  {  0, 1,     0.66,     30.0};
                                var       adjustModelShadow_A_ROTATION                              =    33;
                                //-------------------------
                                var       moveShadow_B[]                                            =  {  0.71,    -0.27,      0.0,      1.0};
                                var       rotateShadow_02[]                                         =  {  0.12,    -4.7,       2.42,   -32.456};
                                var       adjustModelShadow_02_ROTATION                             =    25.0;
                                //-------------------------
                                var       moveShadow_03[]                                           =  { -0.515,  -12.6952,   -0.4400,   1.0};
                                var       rotateShadow_03[]                                         =  {  0.0,      1.0,       1.0,     29.28};                           
                                var       darkness_shadow[]                                         =  {  0.0,      0.0,       0.0,      1.0};                                                      
                                //########################################################################################################################
                                var SET_01_POSITION[] = { -5.0,  1.5, 0.0, 0.0};                                                                                                                                                                                                
                                var SET_02_POSITION[] = { -2.5,  1.5, 0.0, 0.0};                                   
                                var SET_03_POSITION[] = {  0.0,  1.5, 0.0, 0.0};                                 
                                var SET_04_POSITION[] = {  5.0,  1.5, 0.0, 0.0};                                                                                                                                                                                                
                                var SET_05_POSITION[] = {  2.5,  1.5, 0.0, 0.0};                                   
                                var SET_06_POSITION[] = { -5.0, -1.75, 0.0, 0.0};                                 
                                var SET_07_POSITION[] = { -2.5, -1.75, 0.0, 0.0};                                  
                                var SET_08_POSITION[] = {  0.0, -1.75, 0.0, 0.0};                                 
                                var SET_09_POSITION[] = {  2.5, -1.75, 0.0, 0.0};                                 
                                var SET_10_POSITION[] = {  5.0, -1.75, 0.0, 0.0};                                   
                                
                                //######################################################################################################________SHADERS  
                                //######################################################################################################________SHADERS                                  
                                #include "_SHADERS/electron/blue/blueElectron_GLOBALS.cpp"                                
                                //=========================================================================================== 
                                #include "_SHADERS/fresnel/DelylaShield/DelylaShield_GLOBALS.cpp"                                 
                                //=========================================================================================== 
                                #include "_SHADERS/fresnel/copper/copper_GLOBALS.cpp"                                 
                                //=========================================================================================== 
                                #include "_SHADERS/fresnel/carbonFiber/carbonFiber_GLOBALS.cpp"                                 
                                //===========================================================================================                                 
                                #include "_SHADERS/electron/grey/greyElectron_GLOBALS.cpp"                                  
                                //===========================================================================================                                  
                                #include "_SHADERS/fresnel/bronze/bronze_GLOBALS.cpp"                                 
                                //===========================================================================================                                 
                                #include "_SHADERS/electron/brightOrange/brightOrange_GLOBALS.cpp"                                  
                                //===========================================================================================                                 
                                #include "_SHADERS/squishy/squishy_01/squishy_01_GLOBALS.cpp"                                
                                //===========================================================================================                                 
                                #include "_SHADERS/electron/darkOrange/darkOrange_GLOBALS.cpp"                                   
                                //===========================================================================================                                 
                                #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_GLOBALS.cpp"                                 
                                
                                
                                
                                
                                //######################################################################################################________MODELS   
                                //######################################################################################################________MODELS                                                                                                
                                //------------------------------------------------------------------------------------   
                                #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/sculptris/sculptris_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/sphere/sphere_Globals.cpp"                                                                
  


//======================================================================================================================================================================================



          #ifdef WIN32
             #include "cpp/winInit.cpp"
          #endif  
          
          
//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{    
     //------------------------------------------------------------------------------------------------------------
     if(shaderNumber == 1)
     {
            #include "_SHADERS/fresnel/DelylaShield/DelylaShield_RENDER.cpp"        
     }
     //------------------------------------------------------------------------------------------------------------
     if(shaderNumber == 2)
     {    
            #include "_SHADERS/fresnel/copper/copper_RENDER.cpp"  
     }
     //------------------------------------------------------------------------------------------------------------   
     if(shaderNumber == 3)
     {    
            #include "_SHADERS/electron/blue/blueElectron_RENDER.cpp"     
     }
     //------------------------------------------------------------------------------------------------------------      
     if(shaderNumber == 4)
     {    
            #include "_SHADERS/fresnel/carbonFiber/carbonFiber_RENDER.cpp"     
     }
     //------------------------------------------------------------------------------------------------------------      
     if(shaderNumber == 5)
     {    
            #include "_SHADERS/electron/grey/greyElectron_RENDER.cpp"       
     }
     //------------------------------------------------------------------------------------------------------------      
     if(shaderNumber == 6)
     {    
            #include "_SHADERS/fresnel/bronze/bronze_RENDER.cpp"                                 
     }
     //------------------------------------------------------------------------------------------------------------          
     if(shaderNumber == 7)
     {    
            #include "_SHADERS/electron/brightOrange/brightOrange_RENDER.cpp"                                  
     }
     //------------------------------------------------------------------------------------------------------------          
     if(shaderNumber == 8)
     {    
            #include "_SHADERS/squishy/squishy_01/squishy_01_RENDER.cpp"                                  
     }
     //------------------------------------------------------------------------------------------------------------           
     if(shaderNumber == 9)
     {    
            #include "_SHADERS/electron/darkOrange/darkOrange_RENDER.cpp"                                  
     }
     //------------------------------------------------------------------------------------------------------------      
     if(shaderNumber == 10)
     {    
            #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_RENDER.cpp"                                  
     }
     //------------------------------------------------------------------------------------------------------------        
              
     
     
}

//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___BEGIN_INIT__
{
        eyePosition[0]                     =   0.0; 
        eyePosition[1]                     =   0.0; 
        eyePosition[2]                     =   8.70001;

        look_LEFT_RIGHT                    =   0.0;
        look_UP_DOWN                       =   0.0;
        
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
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //######################################################################################################________SHADERS  
        //######################################################################################################________SHADERS                                        
        #include "_SHADERS/electron/blue/blueElectron_INIT.cpp"
        //====================================================================================         
        #include "_SHADERS/fresnel/DelylaShield/DelylaShield_INIT.cpp"          
        //====================================================================================          
        #include "_SHADERS/fresnel/copper/copper_INIT.cpp"          
        //====================================================================================         
        #include "_SHADERS/fresnel/carbonFiber/carbonFiber_INIT.cpp"   
        //====================================================================================           
        #include "_SHADERS/electron/grey/greyElectron_INIT.cpp"          
        //====================================================================================            
        #include "_SHADERS/fresnel/bronze/bronze_INIT.cpp"         
        //=========================================================================================== 
        #include "_SHADERS/electron/brightOrange/brightOrange_INIT.cpp"                                  
        //=========================================================================================== 
        #include "_SHADERS/squishy/squishy_01/squishy_01_INIT.cpp"                                             
        //=========================================================================================== 
        #include "_SHADERS/electron/darkOrange/darkOrange_INIT.cpp"          
        //=========================================================================================== 
        #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_INIT.cpp"          
        
        
        
        //######################################################################################################________MODELS   
        //######################################################################################################________MODELS            
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/sphere/sphere_Init.cpp"                                                                   
   
        
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
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];        
        #endif        
        //=========================================================================================================================================================        
        #ifdef WIN32        
        projection[12] = eyePosition[0];
        projection[13] = eyePosition[1];
        projection[15] = eyePosition[2];
        #endif
        
        Rotate(projection, 1.0, 0.0, 0.0,  look_UP_DOWN);
        Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);        
        
//#################################################################################################################################################################        
spinModel += 1.0;
//==============================================================================================================
shaderNumber = 1;      
        //------------------------------------------------------------------------------------
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_01_POSITION[0], SET_01_POSITION[1], SET_01_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_01_POSITION[0], SET_01_POSITION[1], SET_01_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_01_POSITION[0], SET_01_POSITION[1], SET_01_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
//==============================================================================================================
shaderNumber = 2;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_02_POSITION[0], SET_02_POSITION[1], SET_02_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_02_POSITION[0], SET_02_POSITION[1], SET_02_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_02_POSITION[0], SET_02_POSITION[1], SET_02_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------    
//==============================================================================================================
shaderNumber = 3;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_03_POSITION[0], SET_03_POSITION[1], SET_03_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_03_POSITION[0], SET_03_POSITION[1], SET_03_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_03_POSITION[0], SET_03_POSITION[1], SET_03_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                         
    //==============================================================================================================
shaderNumber = 4;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_04_POSITION[0], SET_04_POSITION[1], SET_04_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_04_POSITION[0], SET_04_POSITION[1], SET_04_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_04_POSITION[0], SET_04_POSITION[1], SET_04_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                         
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%         
 //==============================================================================================================
shaderNumber = 5;      
        //------------------------------------------------------------------------------------
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_05_POSITION[0], SET_05_POSITION[1], SET_05_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_05_POSITION[0], SET_05_POSITION[1], SET_05_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_05_POSITION[0], SET_05_POSITION[1], SET_05_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
//==============================================================================================================
shaderNumber = 6;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_06_POSITION[0], SET_06_POSITION[1], SET_06_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_06_POSITION[0], SET_06_POSITION[1], SET_06_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_06_POSITION[0], SET_06_POSITION[1], SET_06_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------    
//==============================================================================================================
shaderNumber = 7;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_07_POSITION[0], SET_07_POSITION[1], SET_07_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_07_POSITION[0], SET_07_POSITION[1], SET_07_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_07_POSITION[0], SET_07_POSITION[1], SET_07_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                         
//==============================================================================================================
shaderNumber = 8;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_08_POSITION[0], SET_08_POSITION[1], SET_08_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_08_POSITION[0], SET_08_POSITION[1], SET_08_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_08_POSITION[0], SET_08_POSITION[1], SET_08_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------        
//==============================================================================================================
shaderNumber = 9;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_09_POSITION[0], SET_09_POSITION[1], SET_09_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_09_POSITION[0], SET_09_POSITION[1], SET_09_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_09_POSITION[0], SET_09_POSITION[1], SET_09_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------           
//==============================================================================================================
shaderNumber = 10;      
        //------------------------------------------------------------------------------------  
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_10_POSITION[0], SET_10_POSITION[1], SET_10_POSITION[2]);    
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_10_POSITION[0], SET_10_POSITION[1], SET_10_POSITION[2]);         
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------                                           
        LoadIdentity(modelView);                                                                                                                                                  
        Translate(modelView, SET_10_POSITION[0], SET_10_POSITION[1], SET_10_POSITION[2]);           
        #include "_MODEL_FOLDERS_/sphere/sphere_Render.cpp"                                                                 
        //------------------------------------------------------------------------------------           
        
        
        
        
        
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
        //#include "_SHADERS/fresnel/DelylaShield/DelylaShield_Keyboard.cpp"                                                               
        //====================================================================================                                          
        //#include "_SHADERS/fresnel/copper/copper_Keyboard.cpp"                                                               
        //====================================================================================                                          
        //#include "_SHADERS/electron/blue/blueElectron_Keyboard.cpp"                                                               
  


        //¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
        #include "EYE_VIEW.cpp"
        //¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬

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
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Shutdown.cpp"                                                               
        //====================================================================================               
        #include "_MODEL_FOLDERS_/sphere/sphere_Shutdown.cpp"                                                               
              
              
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




