#ifndef __Shader__
#define __Shader__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"



using namespace std;

class Shader
{
	const char * vertex_file_path;
	const char * fragment_file_path;
	const char * geometry_file_path;
	GLuint programID;
	GLuint mMatrixID;
	GLuint vMatrixID;
	GLuint pMatrixID;

	protected:

	public:
		// Start of user code public
        Shader(const char * _vertex_file_path, const char * _fragment_file_path, const char * _geometry_file_path);
		// End of user code
		Shader(const char * _vertex_file_path, const char * _fragment_file_path, const char * _geometry_file_path, GLuint _programID, GLuint _mMatrixID, GLuint _vMatrixID, GLuint _pMatrixID);
		Shader();
		const char * getVertex_file_path();
		void setVertex_file_path(const char * _vertex_file_path);
		const char * getFragment_file_path();
		void setFragment_file_path(const char * _fragment_file_path);
		const char * getGeometry_file_path();
		void setGeometry_file_path(const char * _geometry_file_path);
		GLuint getProgramID();
		void setProgramID(GLuint _programID);
		GLuint getMMatrixID();
		void setMMatrixID(GLuint _mMatrixID);
		GLuint getVMatrixID();
		void setVMatrixID(GLuint _vMatrixID);
		GLuint getPMatrixID();
		void setPMatrixID(GLuint _pMatrixID);
		static void load_png_texture(char* file_name);
		static void flip_image_vertical(unsigned char* data, unsigned int width, unsigned int height);
};

#endif
