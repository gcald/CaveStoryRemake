#include "Input.h"

/* Input Class
* Keeps track of keyboard state
*/

/// <summary>
/// This function gets called at the beginning of each new frame
/// to reset the keys that are no longer relevant
/// </summary>
void Input::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

/// <summary>
/// This gets called when a key has been pressed
/// </summary>
/// <param name="event"></param>
void Input::keyDownEvent(const SDL_Event& event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

/// <summary>
/// This gets called when a key gets released
/// </summary>
/// <param name="event"></param>
void Input::keyUpEvent(const SDL_Event& event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    //this->_pressedKeys[event.key.keysym.scancode] = false;
    this->_heldKeys[event.key.keysym.scancode] = false;
}
/// <summary>
/// Checks if a certain key was pressed during the current frame
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

/// <summary>
/// Checks if a certain key was released during the current frame
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

/// <summary>
/// Checks if a certain key is being held during the current frame
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool Input::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}
