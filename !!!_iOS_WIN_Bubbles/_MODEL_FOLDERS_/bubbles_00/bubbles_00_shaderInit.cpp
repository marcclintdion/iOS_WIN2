    const char *bubbles_00_SHADER_VertexStrings[1];
    const char *bubbles_00_SHADER_FragmentStrings[1];

    bubbles_00_SHADER_Vertex = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );

	 unsigned char *bubbles_00_SHADER_VertexAssembly = readShaderFile( "_MODEL_FOLDERS_/bubbles_00/bubbles_00.vert" );
    bubbles_00_SHADER_VertexStrings[0] = (char*)bubbles_00_SHADER_VertexAssembly;
    glShaderSourceARB( bubbles_00_SHADER_Vertex, 1, bubbles_00_SHADER_VertexStrings, NULL );
    glCompileShaderARB( bubbles_00_SHADER_Vertex);
    delete bubbles_00_SHADER_VertexAssembly;

    bubbles_00_SHADER_Fragment = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );

    unsigned char *bubbles_00_SHADER_FragmentAssembly = readShaderFile( "_MODEL_FOLDERS_/bubbles_00/bubbles_00.frag" );
    bubbles_00_SHADER_FragmentStrings[0] = (char*)bubbles_00_SHADER_FragmentAssembly;
    glShaderSourceARB( bubbles_00_SHADER_Fragment, 1, bubbles_00_SHADER_FragmentStrings, NULL );
    glCompileShaderARB(bubbles_00_SHADER_Fragment );

    delete bubbles_00_SHADER_FragmentAssembly;

	 bubbles_00_SHADER = glCreateProgramObjectARB();

    glAttachObjectARB( bubbles_00_SHADER, bubbles_00_SHADER_Vertex );
    glAttachObjectARB( bubbles_00_SHADER, bubbles_00_SHADER_Fragment );

    glLinkProgramARB(bubbles_00_SHADER); 
    
    //----------------------------------------------------------------------------    
    UNIFORM_particlePosition_bubbles_00 = glGetUniformLocationARB( bubbles_00_SHADER, "particlePosition" );
    UNIFORM_particleVelocity_bubbles_00 = glGetUniformLocationARB( bubbles_00_SHADER, "particleVelocity" );    
    //----------------------------------------------------------------------------    
    UNIFORM_counter1_bubbles_00         = glGetUniformLocationARB( bubbles_00_SHADER, "counter1" );

    UNIFORM_counter2_bubbles_00         = glGetUniformLocationARB( bubbles_00_SHADER, "counter2" );

    UNIFORM_counter3_bubbles_00         = glGetUniformLocationARB( bubbles_00_SHADER, "counter3" );

    UNIFORM_counter4_bubbles_00         = glGetUniformLocationARB( bubbles_00_SHADER, "counter4" );

