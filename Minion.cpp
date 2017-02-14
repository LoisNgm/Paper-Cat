///  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "Minion.h"

//=============================================================================
// default constructor
//=============================================================================
Minion::Minion() : Entity()
{
	spriteData.width = minionNS::LARGE_MINION_WIDTH;		        // size of minion
	spriteData.height = minionNS::LARGE_MINION_HEIGHT;
	spriteData.x = minionNS::X;						// location on screen
	spriteData.y = minionNS::Y;
	spriteData.rect.bottom = minionNS::LARGE_MINION_HEIGHT;			// rectangle to select parts of an image
	spriteData.rect.right = minionNS::LARGE_MINION_WIDTH;
	currentFrame = minionNS::LARGE_MINION_FRAME;
	spriteData.scale = 1;
}

//=============================================================================
// Initialize the minion
// Post: returns true if successful, false if failed
//=============================================================================
bool Minion::initialize(Game *gamePtr, int width, int height, int ncols)
{
	if (!minionTexture.initialize(gamePtr->getGraphics(), ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minion textures"));

	if (!minionBossTexture.initialize(gamePtr->getGraphics(), ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minionBoss textures"));

	minionBoss.initialize(gamePtr->getGraphics(), minionNS::LARGE_MINION_WIDTH, minionNS::LARGE_MINION_HEIGHT, minionNS::LARGE_MINION_TEXTURE_COLS, &minionBossTexture);
	minions[0].setX(500);
	minions[0].setY(C_FOR_PLATFORM_3 + minionNS::SMALL_MINION_HEIGHT - 5);
	minions[1].setX(GAME_WIDTH - 500);
	minions[1].setY(C_FOR_PLATFORM_1 + PLATFORM_DISTANCEY + PLATFORM_DISTANCEY + minionNS::SMALL_MINION_HEIGHT - 5);
	minions[2].setX(500);
	minions[2].setY(C_FOR_PLATFORM_1 + minionNS::SMALL_MINION_HEIGHT - 5);
	for (int i = 0; i < NUM_OF_SMALL_MINION; i++)
	{
		minions[i].initialize(gamePtr->getGraphics(), width, height, ncols, &minionTexture);
		minions[i].setCurrentFrame(minionNS::SMALL_MINION_START_FRAME);
		minions[i].setFrames(minionNS::SMALL_MINION_START_FRAME, minionNS::SMALL_MINION_END_FRAME);
	}


	velocity.x = -100;
	velocity.y = -20;


	return(Entity::initialize(gamePtr, minionNS::LARGE_MINION_WIDTH, minionNS::LARGE_MINION_HEIGHT, minionNS::LARGE_MINION_TEXTURE_COLS, &minionBossTexture));
}
//=============================================================================
// draw the minion
//=============================================================================
void Minion::draw()
{
	/*minion.draw();
	minion2.draw();
	minion3.draw();*/
	for (int i = 0; i < NUM_OF_SMALL_MINION; i++)
	{

		minions[i].draw();
	}
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

	for (int i = 0; i < NUM_OF_SMALL_MINION; i++)
	{

		minions[i].update(frameTime);
		if (i % 2 == 0)
		{
			minions[i].setX(minions[i].getX() + frameTime * velocity.x);
			minions[i].setY(minions[i].getY() + frameTime * velocity.y);
		}
		else
		{
			minions[i].setX(minions[i].getX() - frameTime * velocity.x);
			minions[i].setY(minions[i].getY() + frameTime * velocity.y);
		}

		if (minions[i].getX() < 0 || minions[i].getX() > GAME_WIDTH - minions[i].getWidth())
		{
			velocity.x *= -1;
			velocity.y *= -1;
			minions[i].setVisible(true);
		}
	}

}
bool Minion::collisionDetectionWithCharacter(Entity cat)
{
	for (int i = 0; i < NUM_OF_SMALL_MINION; i++)
	{

		if ((cat.getX() + cat.getWidth()) >= (minions[i].getX()) &&
			(cat.getX() <= (minions[i].getX() + minions[i].getWidth()) &&
			(cat.getY() + cat.getHeight()) >= minions[i].getY()) &&
			cat.getY() <= (minions[i].getY() + minions[i].getHeight()) && minions[i].getVisible())
		{
			minions[i].setVisible(false);
			return true;
		}
	}
	return false;
}
