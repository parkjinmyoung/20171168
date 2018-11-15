#include "Game.h"
#include "InputHandler.h"
#include <iostream>
#include <typeinfo>


InputHandler* InputHandler::s_pInstance = 0;
const Uint8* m_keystates;

InputHandler::InputHandler()
{
	// »ý¼ºÀÚ 
}

void InputHandler::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
		if (event.type == SDL_KEYUP)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}


	}


}

void InputHandler::clean()
{
	/*
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(TheGame::Instance()->getWinodw());
	SDL_DestroyRenderer(TheGame::Instance()->getRenderer());
	SDL_Quit();
	*/
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}