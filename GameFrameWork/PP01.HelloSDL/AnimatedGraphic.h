#pragma once

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
	
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	void update();
private:
	int m_animSpeed;
	int m_numFrames =2;
};
