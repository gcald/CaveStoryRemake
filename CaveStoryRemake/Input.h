#pragma once

#include <SDL.h>
#include <map>
using std::map;

class Input {
public:
	
	/// <summary>
	/// This function gets called at the beginning of each new frame
	/// to reset the keys that are no longer relevant
	/// </summary>
	void beginNewFrame();
	
	/// <summary>
	/// This gets called when a key has been pressed
	/// </summary>
	/// <param name="event"></param>
	void keyUpEvent(const SDL_Event& event);

	/// <summary>
	/// This gets called when a key gets released
	/// </summary>
	/// <param name="event"></param>
	void keyDownEvent(const SDL_Event& event);

	/// <summary>
	/// Checks if a certain key was pressed during the current frame
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool wasKeyPressed(SDL_Scancode key);
	
	/// <summary>
	/// Checks if a certain key was released during the current frame
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool wasKeyReleased(SDL_Scancode key);

	/// <summary>
	/// Checks if a certain key is being held during the current frame
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool isKeyHeld(SDL_Scancode key);
private:
	map<SDL_Scancode, bool> _heldKeys;
	map<SDL_Scancode, bool> _pressedKeys;
	map<SDL_Scancode, bool> _releasedKeys;
};

