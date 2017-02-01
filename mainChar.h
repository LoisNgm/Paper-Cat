
#ifndef _MAINCHAR_H                 // Prevent multiple definitions if this 
#define _MAINCHAR_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace mainCharNS
{
	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height
	const int X = 0;   // location on screen
	const int Y = 0;
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
	const int   TEXTURE_COLS = 4;
	const int   CAT_START_FRAME = 0;
	const int   CAT_END_FRAME = 3;
	const float CAT_ANIMATION_DELAY = 1.0f;    // time between frames
}

// inherits from Entity class
class MainChar : public Entity
{
private:
	bool    shieldOn;
	Image   shield;
	bool states[BUFF_NUM];
	Image buff[BUFF_NUM];
	boolean isJumping;
public:
	// constructor
	MainChar();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void damage(WEAPON);
	void movement(UCHAR jump, UCHAR left, UCHAR right, float frameTime);

	void characterMovement(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right);
	void characterGravity();
	boolean getActive();
	void setActive(boolean flag);
	void setJumping(boolean flag) { isJumping = flag; };
	void checkCharacterOnGround();
	void checkDirection();
};
#endif

