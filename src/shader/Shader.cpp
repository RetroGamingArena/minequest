#include <cstdlib>

#include "Shader.h"
// Start of user code includes
#include "ShaderLoader.h"
// End of user code

Shader::Shader(const char * _vertex_file_path, const char * _fragment_file_path, const char * _geometry_file_path, GLuint _programID, GLuint _mMatrixID, GLuint _vMatrixID, GLuint _pMatrixID)
{
	vertex_file_path = _vertex_file_path;
	fragment_file_path = _fragment_file_path;
	geometry_file_path = _geometry_file_path;
	programID = _programID;
	mMatrixID = _mMatrixID;
	vMatrixID = _vMatrixID;
	pMatrixID = _pMatrixID;
}

Shader::Shader()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
Shader::Shader(const char * _vertex_file_path, const char * _fragment_file_path, const char * _geometry_file_path) : Shader(_vertex_file_path, _fragment_file_path, _geometry_file_path,0,0,0,0)
{
    //Shader(_vertex_file_path, _fragment_file_path, _geometry_file_path,0,0,0,0);
    programID = ShaderLoader::load( _vertex_file_path, _fragment_file_path, _geometry_file_path);//"shaders/geometryShader.glsl");
    
    mMatrixID = glGetUniformLocation(programID, "M");
    vMatrixID = glGetUniformLocation(programID, "V");
    pMatrixID = glGetUniformLocation(programID, "P");
    
    cameraID = glGetUniformLocation(programID, "camera");
    rayLengthID = glGetUniformLocation(programID, "rayLength");
    
    glUniform1i(rayLengthID, 128);
}

GLuint Shader::getCameraID()
{
    // Start of user code getPMatrixID
    // End of user code
    return cameraID;
}
GLuint Shader::getRayLengthID()
{
    // Start of user code getPMatrixID
    // End of user code
    return rayLengthID;
}
// End of user code




const char * Shader::getVertex_file_path()
{
	// Start of user code getVertex_file_path
	// End of user code
	return vertex_file_path;
}

void Shader::setVertex_file_path(const char * _vertex_file_path)
{
	vertex_file_path = _vertex_file_path;
}

const char * Shader::getFragment_file_path()
{
	// Start of user code getFragment_file_path
	// End of user code
	return fragment_file_path;
}

void Shader::setFragment_file_path(const char * _fragment_file_path)
{
	fragment_file_path = _fragment_file_path;
}

const char * Shader::getGeometry_file_path()
{
	// Start of user code getGeometry_file_path
	// End of user code
	return geometry_file_path;
}

void Shader::setGeometry_file_path(const char * _geometry_file_path)
{
	geometry_file_path = _geometry_file_path;
}

GLuint Shader::getProgramID()
{
	// Start of user code getProgramID
	// End of user code
	return programID;
}

void Shader::setProgramID(GLuint _programID)
{
	programID = _programID;
}

GLuint Shader::getMMatrixID()
{
	// Start of user code getMMatrixID
	// End of user code
	return mMatrixID;
}

void Shader::setMMatrixID(GLuint _mMatrixID)
{
	mMatrixID = _mMatrixID;
}

GLuint Shader::getVMatrixID()
{
	// Start of user code getVMatrixID
	// End of user code
	return vMatrixID;
}

void Shader::setVMatrixID(GLuint _vMatrixID)
{
	vMatrixID = _vMatrixID;
}

GLuint Shader::getPMatrixID()
{
	// Start of user code getPMatrixID
	// End of user code
	return pMatrixID;
}

void Shader::setPMatrixID(GLuint _pMatrixID)
{
	pMatrixID = _pMatrixID;
}



