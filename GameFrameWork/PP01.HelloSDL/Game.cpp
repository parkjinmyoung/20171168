#include "Game.h"
#include <SDL_image.h>



Game* Game::s_pInstance = 0;



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(MenuState::Instance());


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		

		m_gameObjects.push_back
		(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back
		(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));






		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/Tree.png",
			"tree", m_pRenderer))
		{
			return false;
		}

		m_bRunning = true;
	}
	else
	{
		return false;
	}


	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();

	/*
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	*/
	SDL_RenderPresent(m_pRenderer);

}

void Game::update()
{
	/*
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	*/
}


void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->Update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

}

void Game::quit()
{
	m_bRunning = false;
}