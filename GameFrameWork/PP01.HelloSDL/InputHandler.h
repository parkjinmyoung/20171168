#pragma once
#include <iostream>
#include "SDL.h"
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:


	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

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

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();

};

typedef InputHandler TheInputHandler;
