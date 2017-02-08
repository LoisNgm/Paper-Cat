//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "blackhole.h"

//=============================================================================
// default constructor
//=============================================================================
Blackhole::Blackhole() : Entity()
{
	spriteData.width = blackholeNS::WIDTH;           // size of asteroid
	spriteData.height = blackholeNS::HEIGHT;
	spriteData.x = blackholeNS::X;                   // location on screen
	spriteData.y = blackholeNS::Y;
	spriteData.rect.bottom = blackholeNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = blackholeNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	//frameDelay = blackholeNS::BLACKHOLE_ANIMATION_DELAY;
	startFrame = blackholeNS::BLACKHOLE_START_FRAME;     // first frame of asteroid animation
	endFrame = blackholeNS::BLACKHOLE_END_FRAME;     // last frame of asteroid animation
	currentFrame = startFrame;
	radius = blackholeNS::WIDTH / 2.0;
	mass = blackholeNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 1;

}

//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
bool Blackhole::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the asteroid
//=============================================================================
void Blackhole::draw()
{

	Image::draw();              // draw asteroid


}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Blackhole::update(float frameTime)
{
	Entity::update(frameTime);


}

boolean Blackhole::getActive()
{
	return active;
}

void Blackhole::setActive(boolean flag)
{
	active = flag;
}
/*
void Blackhole::withChar()
{
	float distance_squared = ((this->getY())//planet.position - player.position).sqrmagnitude;
	force = gravitational_constant * ((mass1 * mass2) / distance_squared);
	force_direction = (planet.position - player.position).normalized;
	force_vector = force_direction * force;
}*/
