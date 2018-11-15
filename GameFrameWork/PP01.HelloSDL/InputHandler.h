#pragma once
#include <iostream>
#include "SDL.h"



class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void Update();
	void clean();
	bool isKeyDown(SDL_Scancode key);



private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

};

typedef InputHandler TheInputHandler;
