#pragma once

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
	int calculateDeltaTime();
};