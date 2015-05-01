#ifndef __Engine__
#define __Engine__

class Engine
{
	static Engine* instance;

	public:
		void run();
		static Engine* getInstance();
};

#endif
