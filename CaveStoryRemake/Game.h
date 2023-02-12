#pragma once

#include "Player.h"

class Graphics;

class Game { 
public:
	Game();
	~Game();
	int LAST_UPDATE_TIME;
	int CURRENT_TIME_MS;
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
	
	/// <summary>
	/// Calculates how long the frame took to complete. Clamps by MAX_FRAME_RATE
	/// </summary>
	/// <returns></returns>
	int calculateDeltaTime();
};