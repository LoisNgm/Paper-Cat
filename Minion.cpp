// Gameplay Programming Common Test Oct 2016
// Student Name: Ngm Hui Min, Lois
// Student Number: S10158786C
// Class: P02

// GPP Common Test
#include "Minion.h"

//=============================================================================
// default constructor
//=============================================================================
Minion::Minion() : Entity()
{
	spriteData.width = minionNS::SMALL_MINION_WIDTH;		        // size of comet
	spriteData.height = minionNS::SMALL_MINION_HEIGHT;
	spriteData.x = minionNS::X;						// location on screen
	spriteData.y = minionNS::Y;
	spriteData.rect.bottom = minionNS::SMALL_MINION_HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = minionNS::SMALL_MINION_WIDTH;
	startFrame = minionNS::SMALL_MINION_START_FRAME;				// start button for menu
	endFrame = minionNS::SMALL_MINION_END_FRAME;
	currentFrame = minionNS::SMALL_MINION_START_FRAME;
	spriteData.scale = 1;
}

//=============================================================================
// Initialize the Comet.
// Post: returns true if successful, false if failed
//=============================================================================
bool Minion::initialize(Game *gamePtr, int width, int height, int ncols)
{
	//character textures
	if (!minionTexture.initialize(gamePtr->getGraphics(), ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minion textures"));
	if (!minionBossTexture.initialize(gamePtr->getGraphics(), ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minionBoss textures"));
	minionBoss.initialize(gamePtr->getGraphics(), minionNS::LARGE_MINION_WIDTH, minionNS::LARGE_MINION_HEIGHT, 0, &minionTexture);
	minion.initialize(gamePtr->getGraphics(), width, height, ncols, &minionTexture);
	minion2.initialize(gamePtr->getGraphics(), width, height, ncols, &minionTexture);
	minion3.initialize(gamePtr->getGraphics(), width, height, ncols, &minionTexture);
	velocity.x = -100;
	velocity.y = -20;
	minion.setX(500);
	minion.setY(10 + 50 + 10 + 100 + 100 + 100 + 100 + 100);
	minion2.setX(GAME_WIDTH - 500);
	minion2.setY(10 + 50 + 10 + 100 + 100 + 100);
	minion3.setX(500);
	minion3.setY(10 + 50 + 10 + 100);
	minion.setCurrentFrame(minionNS::SMALL_MINION_START_FRAME);
	minion.setFrames(minionNS::SMALL_MINION_START_FRAME, minionNS::SMALL_MINION_END_FRAME);
	minion2.setCurrentFrame(minionNS::SMALL_MINION_START_FRAME);
	minion2.setFrames(minionNS::SMALL_MINION_START_FRAME, minionNS::SMALL_MINION_END_FRAME);
	minion3.setCurrentFrame(minionNS::SMALL_MINION_START_FRAME);
	minion3.setFrames(minionNS::SMALL_MINION_START_FRAME, minionNS::SMALL_MINION_END_FRAME);
	return(Entity::initialize(gamePtr, width, height, ncols, &minionBossTexture));
}

//=============================================================================
// draw the comet
//=============================================================================
void Minion::draw()
{
	minion.draw();
	minion2.draw();
	minion3.draw();
	Image::draw();              // draw comet
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Minion::update(float frameTime)
{
	Entity::update(frameTime);

	
	if (spriteData.y > GAME_HEIGHT - minionNS::SMALL_MINION_HEIGHT*getScale())
	{
		this->setX(0);
		this->setY(0);
	}
	if (getX() < 0 || getX() > GAME_WIDTH-getWidth())
	{
		velocity.x *= -1;
	}
	minion.setX(minion.getX() + frameTime * velocity.x);
	minion.setY(minion.getY() + frameTime * velocity.y);
	minion2.setX(minion2.getX() - frameTime * velocity.x);
	minion2.setY(minion2.getY() + frameTime * velocity.y);
	minion3.setX(minion3.getX() + frameTime * velocity.x);
	minion3.setY(minion3.getY() + frameTime * velocity.y);

}

// End of GPP Common Test