#include "engine/Engine.h"

Engine* engine = Engine::getInstance();

int main(int argc, char **argv)
{
    srand (time(NULL));
    engine->run();
    
    return 0;
}
