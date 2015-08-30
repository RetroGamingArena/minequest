#include <cstdlib>

#include "Label.h"
// Start of user code includes
// End of user code

Label::Label(char* _caption)
{
	caption = _caption;
}

Label::Label()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    caption = NULL;
	// End of user code
}

Label::~Label()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
int Label::size = 25;

Label::Label(char* _caption, int _x, int _y)
{
    this->caption = new char[strlen(_caption)];
    strcpy(this->caption, _caption);
    //Label(caption);
    x = _x;
    y = _y;
}
// End of user code

void Label::render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs)
{
	// Start of user code render
    unsigned int length = strlen(caption);
    
    // Fill buffers
    for ( unsigned int i=0 ; i<length ; i++ )
    {
        glm::vec2 vertex_up_left    = glm::vec2( x+i*size     , -4+y+size );
        glm::vec2 vertex_up_right   = glm::vec2( x+i*size+size, -4+y+size );
        glm::vec2 vertex_down_right = glm::vec2( x+i*size+size, -12+y      );
        glm::vec2 vertex_down_left  = glm::vec2( x+i*size     , -12+y      );
        
        vertices.push_back(vertex_up_left   );
        vertices.push_back(vertex_down_left );
        vertices.push_back(vertex_up_right  );
        
        vertices.push_back(vertex_down_right);
        vertices.push_back(vertex_up_right);
        vertices.push_back(vertex_down_left);
        
        char character = caption[i]-32;
        float uv_x = (character%16)/16.0f;
        float uv_y = (character/16)/8.0f;
        
        glm::vec2 uv_up_left    = glm::vec2( uv_x           , -1*uv_y );
        glm::vec2 uv_up_right   = glm::vec2( uv_x+1.0f/16.0f, -1*uv_y );
        glm::vec2 uv_down_right = glm::vec2( uv_x+1.0f/16.0f, -1*(uv_y + 1.0f/8.0f) );
        glm::vec2 uv_down_left  = glm::vec2( uv_x           , -1*(uv_y + 1.0f/8.0f) );
        
        UVs.push_back(uv_up_left   );
        UVs.push_back(uv_down_left );
        UVs.push_back(uv_up_right  );
        
        UVs.push_back(uv_down_right);
        UVs.push_back(uv_up_right);
        UVs.push_back(uv_down_left);
    }
	// End of user code
}
void Label::refresh()
{
	// Start of user code refresh
	// End of user code
}



char* Label::getCaption()
{
	// Start of user code getCaption
	// End of user code
	return caption;
}

void Label::setCaption(char* _caption)
{
    if(caption != NULL)
        delete caption;
	caption = _caption;
}



