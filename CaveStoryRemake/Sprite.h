#pragma once

#include <string>
#include <SDL_image.h>
#include "Graphics.h"
#include "Globals.h"

/* Holds all information for individual sprites */
class Sprite {
public:
	Sprite();
	Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics& graphics, int x, int y);
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
private:

	float _x, _y;
};

