#pragma once

#include <iostream>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "GameState.h"
#include "PlayState.h"

class Game
{
public:

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	int m_currentFrame;

	//std::vector<GameObject*> m_gameObjects;

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:

	

	GameStateMachine* m_pGameStateMachine;


	static Game* s_pInstance;


	Game() {}
	
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	

};

typedef Game TheGame;