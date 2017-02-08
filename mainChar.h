//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D


#ifndef _MAINCHAR_H                 // Prevent multiple definitions if this 
#define _MAINCHAR_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace mainCharNS
{
	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height
	const int X = 1;   // location on screen
	const int Y = 1;
	const float SPEED = 10.0f;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
	const int   TEXTURE_COLS = 8;
	const int   CAT_START_FRAME = 32;
	const int   CAT_END_FRAME = 35;
	const float CAT_ANIMATION_DELAY = 1.0f;    // time between frames
}

// inherits from Entity class
class MainChar : public Entity
{
private:
	Image buff[BUFF_NUM];
	int state=-1;
	int health = 3;
	bool shield = false;
public:
	// constructor
	MainChar();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void damage(WEAPON);
	void characterMovement(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right);
	boolean getActive();
	void checkDirection();
	void characterOutOfScreen();
	float getVelocityX() { return velocity.x; };
	void setVelocityX(float velx) { velocity.x = velx; };
	float getVelocityY() { return velocity.y; };
	void setVelocityY(float vely) { velocity.y = vely; };
	void setState(int a){ state = a; };
	int getState(){ return state; };
	void setHealth(int a){ health = a; };
	int getHealth(){ return health; };
	void setShield(bool a){ shield = a; };
	int getShield(){ return shield; };
};
#endif

