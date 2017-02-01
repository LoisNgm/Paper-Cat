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
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void MainChar::draw()
{
	Image::draw();              // draw ship
	int stateNum = -1;
	//check if collision between buff is true and draw states	
	for (int i = 0; i++; i < BUFF_NUM - 1)
	{
		if (states[i])
		{  // draw buffs using colorFilter 50% alpha
			buff[i].draw(spriteData, graphicsNS::ALPHA50 & colorFilter);
			//reset buff timing
			stateNum = i;
		}	
	}
	for (int i = 0; i++; i < BUFF_NUM - 1)
	{
		if (i != stateNum)
		{
			states[i] = false;
		}
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
	movement(VK_SPACE, VK_LEFT, VK_RIGHT , frameTime);
	if (isJumping)
	{
		velocity.y = -10;
		//do
		//{
			this->setY(spriteData.y + velocity.y);
			velocity.y += 0.1f;// velocity.y *0.9 + frameTime;
			if (velocity.y > 8)
				velocity.y = 8;
		//} while (frameTime<100);//on collision with platform
		//if (this->getY() > 50) if collide with platform
			//isJumping = false;
	}
	//condition for removing buff state
	//set state to false;
	characterMovement(input, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT);
	setX(getX() + frameTime*velocity.x);
	setY(getY() + frameTime*velocity.y);
	Entity::update(frameTime);

	characterGravity();
	checkCharacterOnGround();
	checkDirection();

}

//=============================================================================
// damage
//=============================================================================
void MainChar::damage(WEAPON weapon)
{
	//if damage with collision type 
	states[0] = true;// to be change ltr
}
//=============================================================================
//Movement
//=============================================================================
void MainChar::movement(UCHAR jump, UCHAR left, UCHAR right,float frameTime)
{
	//jump
	if (input->wasKeyPressed(jump))
	{
		isJumping = true;
		//put jumping method here for cat character to keep jumping
	}
	if (input->wasKeyPressed(right))
	{
	}

}
void MainChar::characterMovement(Input *input, UCHAR up, UCHAR down, UCHAR left, UCHAR right)
{
	if (input->isKeyDown(right))
	{
		velocity.x += 2.0f;
	}
	if (input->isKeyDown(left))
	{
		velocity.x -= 2.0f;
	}

	if (input->wasKeyPressed(VK_SPACE))
	{
		input->clearKeyPress(VK_SPACE);
		if (isJumping == false)
		{
			velocity.y = -150;
			isJumping = true;
		}

	}

	if (velocity.x > 0)
	{
		velocity.x -= 1.0f;
	}
	else
	{
		velocity.x += 1.0f;
	}
}
void MainChar::characterGravity()
{
	velocity.y += 1.5;
}
void MainChar::checkCharacterOnGround()
{
	if (getY() > (10 + 50 - getHeight()) && getX() < (100) && getY() < (10 + 50))
	{
		isJumping = false;
		velocity.y = 0;
	}
	else
	{
		if (getY() > (10 + 50 + 10 + 100 - getHeight()) || getX()>500)
		{
			isJumping = true;
			if (getX() < GAME_WIDTH - 500 - getWidth() || getY() > (10 + 50 + 10 + 100 + 100 + 100))
			{
				isJumping = true;
				if (getX()>500 || getY() > (10 + 50 + 10 + 100 + 100 + 100 + 100 + 100 + 100))
				{
					isJumping = true;
					if (getY() > (GAME_HEIGHT - getHeight()))
					{
						isJumping = false;
						velocity.y = 0;
					}
				}
				else
				{
					if (getY() > (getX()*0.2 + (10 + 50 + 10 + 100 + 100 + 100 + 100 - getHeight())))
					{
						isJumping = false;
						velocity.y = 0;
						setY(getX()*0.2 + (10 + 50 + 10 + 100 + 100 + 100 + 100 - getHeight()));
					}
				}

			}
			else
			{
				if (getY() > ((getX()*-0.2) + (406 - getHeight())))
				{
					isJumping = false;
					velocity.y = 0;
					setY((getX()*-0.2) + (406 - getHeight()));
				}
			}



		}
		else
		{
			if (getY() > (getX()*0.2 + (10 + 50 + 10 - getHeight())))
			{
				isJumping = false;
				velocity.y = 0;
				setY(getX()*0.2 + (10 + 50 + 10 - getHeight()));
			}
		}


	}

}

void MainChar::checkDirection()
{
	if (round(velocity.x) == 0)
	{
		if (velocity.x > 0)
		{
			flipHorizontal(true);
		}
		else
		{
			flipHorizontal(false);
		}
	}
}