#include <cstdlib>

#include "ShaderLoader.h"
// Start of user code includes
#include <string>
#include <fstream>

//#include "../depends/lodepng/lodepng.h"
// End of user code


ShaderLoader::ShaderLoader()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

ShaderLoader::~ShaderLoader()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code





int ShaderLoader::load(const char * vertex_file_path, const char * fragment_file_path, const char * geometry_file_path)
{
	// Start of user code load
    // Crée les shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    GLuint GeometryShaderID;
    if(geometry_file_path != NULL)
        GeometryShaderID = glCreateShader(GL_GEOMETRY_SHADER_EXT);
    
    // Lit le code du vertex shader à partir du fichier
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }
    
    // Lit le code du fragment shader à partir du fichier
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }
    
    // Lit le code du geomtry shader à partir du fichier
    std::string GeometryShaderCode;
    if(geometry_file_path != NULL)
    {
        std::ifstream GeometryShaderStream(geometry_file_path, std::ios::in);
        if(GeometryShaderStream.is_open())
        {
            std::string Line = "";
            while(getline(GeometryShaderStream, Line))
                GeometryShaderCode += "\n" + Line;
            GeometryShaderStream.close();
        }
    }
    
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    // Compile le vertex shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);
    
    // Vérifie le vertex shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
    
    // Compile le fragment shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);
    
    // Vérifie le fragment shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    
    if(geometry_file_path != NULL)
    {
        // Compile le geometry shader
        printf("Compiling shader : %s\n", geometry_file_path);
        char const * GeometrySourcePointer = GeometryShaderCode.c_str();
        glShaderSource(GeometryShaderID, 1, &GeometrySourcePointer , NULL);
        glCompileShader(GeometryShaderID);
        
        // Vérifie le geometry shader
        glGetShaderiv(GeometryShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(GeometryShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        std::vector<char> GeometryShaderErrorMessage(InfoLogLength);
        glGetShaderInfoLog(GeometryShaderID, InfoLogLength, NULL, &GeometryShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &GeometryShaderErrorMessage[0]);
    }
    
    // Lit le programme
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    if(geometry_file_path != NULL)
        glAttachShader(ProgramID, GeometryShaderID);
    glLinkProgram(ProgramID);
    
    // Vérifie le programme
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
    if(geometry_file_path != NULL)
        glDeleteShader(GeometryShaderID);
    
    return ProgramID;
	// End of user code
}

