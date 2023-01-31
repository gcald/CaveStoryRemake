#pragma once

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	/* Loads an image into the _spriteSheets map if it doesn't exist already
	As a result, each image will only ever be loaded once
	Returns the image from the mpa regardless of whether or not it was just loaded
	*/
	SDL_Surface* loadImage(const std::string& filePath);

	/* Draws a texture to a certain part of the screen */
	void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* Renders everything to the screen */
	void flip();

	/* Clears the screen */
	void clear();

	/* Returns the renderer */
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};