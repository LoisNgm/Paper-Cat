//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "mainChar.h"

//=============================================================================
// default constructor
//=============================================================================
MainChar::MainChar() : Entity()
{
	
	spriteData.width = mainCharNS::WIDTH;           // size of asteroid
	spriteData.height = mainCharNS::HEIGHT;
	spriteData.x = mainCharNS::X;                   // location on screen
	spriteData.y = mainCharNS::Y;
	spriteData.rect.bottom = mainCharNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = mainCharNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = mainCharNS::CAT_ANIMATION_DELAY;
	startFrame = mainCharNS::CAT_START_FRAME;     // first frame of asteroid animation
	endFrame = mainCharNS::CAT_END_FRAME;     // last frame of asteroid animation
	currentFrame = startFrame;
	mass = mainCharNS::MASS;
	spriteData.scale = 1;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool MainChar::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	for (int i = 0; i < BUFF_NUM; i++)
	{
		buff[i].initialize(gamePtr->getGraphics(), width, height, ncols, textureM);
		buff[i].setFrames(44 + i, 44 + i);
		buff[i].setCurrentFrame(44 + i);
	}

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the cat
//=============================================================================
void MainChar::draw()
{
	Image::draw();              // draw cat
	for (int i = 0; i < BUFF_NUM; i++)
	{
		buff[i].draw();
		buff[i].setVisible(false);
	}
	
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void MainChar::update(float frameTime)
{
	Entity::update(frameTime);
	if (getState() != -1)
	{
  		buff[getState()].setVisible(true);
		buff[getState()].setX(this->getX());
		buff[getState()].setY(this->getY() - this->getHeight());
		buff[getState()].update(frameTime);
	}	
	//condition for removing buff state
	//set state to false;
	setX(getX() + frameTime*velocity.x);
	setY(getY() + frameTime*velocity.y);
	checkDirection();
	characterOutOfScreen();
	checkStunned(state);
}

//=============================================================================
//Movement
//=============================================================================
void MainChar::characterMovementStage(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right, UCHAR jump)
{
	if (input->isKeyDown(right))
	{
		velocity.x += CHARACTER_S_ACCLERATION;
		flipHorizontal(true);
	}
	if (input->isKeyDown(left))
	{
		velocity.x -= CHARACTER_S_ACCLERATION;
		flipHorizontal(false);
	}

	if (input->wasKeyPressed(jump))
	{
		input->clearKeyPress(jump);

		velocity.y = -CHARACTER_JUMPING_FORCE;
	}

	if (velocity.x > 0)
	{
		velocity.x -= FRICTION;
	}
	else
	{
		velocity.x += FRICTION;
	}
}


void MainChar::characterOutOfScreen()
{
	if (getX() <= 0)//increase the responsiveness of the game 
	{
		velocity.x = 0;
		setX(getX() + 1);
	}
	if (getX() >= GAME_WIDTH - getWidth())
	{
		velocity.x = 0;
		setX(getX() - 1);
	}
	if (getY() <= 0)//increase the responsiveness of the game 
	{
		velocity.y = 0;
		setY(getY() + 1);
	}
	if (getY() >= GAME_HEIGHT - getHeight())
	{
		velocity.y = 0;
		setY(getY() - 1);
	}
}
void MainChar::checkDirection()
{
	if (round(velocity.x) == 0)
	{
		if (velocity.x >= 0)
		{
			flipHorizontal(true);
		}
		else
		{
			flipHorizontal(false);
		}
	}
}
void MainChar::checkStunned(int state)
{
	if (state == 0){
		Timer += 0.03;
		stunState = true;
		if (Timer >= STUNNEDTIME)
		{
			setState(-1);
			Timer = 0;
			stunState = false;
		}
	}
	else
		stunState = false;
}


void MainChar::checkBuff(float frameTime)
{
	if (getState() != -1)
	{
		buff[getState()].setVisible(true);
		buff[getState()].setX(this->getX());
		buff[getState()].setY(this->getY() - this->getHeight());
		buff[getState()].update(frameTime);
	}
}
void MainChar::characterMovementFinal(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right)
{
	if (input->isKeyDown(right))
	{
		velocity.x += CHARACTER_S_ACCLERATION;
		flipHorizontal(true);
	}
	if (input->isKeyDown(left))
	{
		velocity.x -= CHARACTER_S_ACCLERATION;
		flipHorizontal(false);
	}
	if (input->isKeyDown(up))
	{
		velocity.y -= CHARACTER_S_ACCLERATION;
	}
	if (input->isKeyDown(down))
	{
		velocity.y += CHARACTER_S_ACCLERATION;

	}

	if (velocity.x > 0)
	{
		velocity.x -= FRICTION;
	}
	else
	{
		velocity.x += FRICTION;
	}
	if (velocity.y > 0)
	{
		velocity.y -= FRICTION;
	}
	else
	{
		velocity.y += FRICTION;
	}
}