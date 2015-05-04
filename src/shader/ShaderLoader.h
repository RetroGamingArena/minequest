#ifndef __ShaderLoader__
#define __ShaderLoader__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>



using namespace std;

class ShaderLoader
{

	public:
		// Start of user code public
		// End of user code
		ShaderLoader();
		static int load(const char * vertex_file_path, const char * fragment_file_path, const char * geometry_file_path);
};

#endif
