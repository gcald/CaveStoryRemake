#include <SDL.h>

#include "Game.h"
#include "Graphics.h";
#include "Input.h";

/* Game Class
*  This class holds all information for our main game loop
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = AnimatedSprite(graphics, "MyChar.png", 0, 0, 16, 16, 100, 100, 100);
	this->_player.setupAnimations();
	this->_player.playAnimation("RunRight");

	LAST_UPDATE_TIME = SDL_GetTicks();

	// Start the game loop
	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			// If the event is an exit event
			else if (event.type == SDL_QUIT) {
				return;
			}

			if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
				return;
			}

		}

		this->update(this->calculateDeltaTime());
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics& graphics) {
	graphics.clear();
	this->_player.draw(graphics, 100, 100);
	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}

int Game::calculateDeltaTime() {
	this->CURRENT_TIME_MS = SDL_GetTicks();
	return std::min(this->CURRENT_TIME_MS - LAST_UPDATE_TIME, MAX_FRAME_TIME);
}