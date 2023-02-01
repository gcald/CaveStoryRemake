#pragma once

#include <map>
#include <string>
#include <vector>

#include "Sprite.h"

class Graphics;

/* Holds logic for animating sprites */
class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);
	
	/* Plays the animation provided if it's not already playing */
	void playAnimation(std::string animation, bool once = false);
	
	/* Updates the animated sprite (timer) */
	void update(int elapsedTime);

	/* Draws the sprite to the screen */
	void draw(Graphics& graphics, int x, int y);

	/* A required function that sets up all animations for a sprite */
	virtual void setupAnimations();
protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* Adds an animations to the map of animations for the sprite */
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/* Resets all animations associated with this sprite */
	void resetAnimations();

	/* Stops the current animation */
	void stopAnimation();

	/* Changes the visibility of the animated sprite */
	void setVisible(bool visible);

	/* Logic that happens when an animation ends */
	virtual void animationDone(std::string currentAnimation);
private:
	/* Holds all the SDL_Rects for our animations */
	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

