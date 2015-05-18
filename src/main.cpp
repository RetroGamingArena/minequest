#include "engine/Engine.h"

Engine* engine = Engine::getInstance();

int main(int argc, char **argv)
{
    engine->run();
    
    return 0;
}
