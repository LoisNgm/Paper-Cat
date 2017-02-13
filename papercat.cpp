//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D


#include "papercat.h"
#include "time.h"
#include <thread>

//=============================================================================
// Constructor
//=============================================================================
Papercat::Papercat()
{
	mainFont = new TextDX();
	pausedFont = new TextDX();
	highscoreLogging= new Highscore();
}

//=============================================================================
// Destructor
//=============================================================================
Papercat::~Papercat()
{
	releaseAll();           // call onLostDevice() for every graphics item
}
void Papercat::characterPlatformCheckingForStage1()
{

	if (cat.getX() <= (STARTINGPLATFORM_HEIGHT) && cat.getY() + cat.getHeight() >= (STARTINGPLATFORM_HEIGHT) && cat.getY() <= (STARTINGPLATFORM_HEIGHT))//starting platform
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}

		if ((cat.getY() + cat.getHeight() / 2) >= STARTINGPLATFORM_HEIGHT)
		{
			cat.setY(cat.getY() + STARTINGPLATFORM_HEIGHT - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY(STARTINGPLATFORM_HEIGHT - cat.getHeight());
		}

		cat.setVelocityY(0);
		return;
	}

	if (cat.getY() + cat.getHeight() >= (cat.getX()*0.2 + C_FOR_PLATFORM_1) && cat.getY() <= (cat.getX()*0.2 + C_FOR_PLATFORM_1) && cat.getX()<PLATFORM_DISTANCEX)
	{
		if (cat.getVelocityY() < 0)
		{
			cat.setY(cat.getY() + (cat.getHeight() / 2));
		}

		if ((cat.getY() + cat.getHeight() / 2) >= cat.getX()*0.2 + C_FOR_PLATFORM_1)
		{
			cat.setY(cat.getY() + cat.getX()*0.2 + C_FOR_PLATFORM_1 - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY(cat.getX()*0.2 + C_FOR_PLATFORM_1 - cat.getHeight());
		}
		cat.setVelocityY(0);
		return;
	}
	if (cat.getX() >= GAME_WIDTH - PLATFORM_DISTANCEX - cat.getWidth() && cat.getY() + cat.getHeight() >= ((cat.getX()*-0.2) + (C_FOR_PLATFORM_2 + cat.getHeight())) && cat.getY() <= ((cat.getX()*-0.2) + (C_FOR_PLATFORM_2 + cat.getHeight())))
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}
		if ((cat.getY() + cat.getHeight() / 2) >= ((cat.getX()*-0.2) + (C_FOR_PLATFORM_2 + cat.getHeight())))
		{
			cat.setY(cat.getY() + ((cat.getX()*-0.2) + (C_FOR_PLATFORM_2 + cat.getHeight())) - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY(((cat.getX()*-0.2) + (C_FOR_PLATFORM_2 + cat.getHeight())) - cat.getHeight());
		}
		cat.setVelocityY(0);
		return;
	}
	if (cat.getX() < PLATFORM_DISTANCEX && cat.getY() + cat.getHeight() >= (cat.getX()*0.2 + (C_FOR_PLATFORM_3)) && cat.getY() <= (cat.getX()*0.2 + (C_FOR_PLATFORM_3)))
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}
		if ((cat.getY() + cat.getHeight() / 2) >= (cat.getX()*0.2 + (C_FOR_PLATFORM_3)))
		{
			cat.setY(cat.getY() + (cat.getX()*0.2 + (C_FOR_PLATFORM_3)) - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY((cat.getX()*0.2 + (C_FOR_PLATFORM_3)) - cat.getHeight());
		}
		cat.setVelocityY(0);
		return;
	}
}
void Papercat::characterPlatformCheckingForBonusStage()
{
	if (cat.getX() <= (STARTINGPLATFORM_WIDTH) && cat.getY() + cat.getHeight() >= (STARTINGPLATFORM_HEIGHT) && cat.getY() <= (STARTINGPLATFORM_HEIGHT))//starting platform
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}

		if ((cat.getY() + cat.getHeight() / 2) >= STARTINGPLATFORM_HEIGHT)
		{
			cat.setY(cat.getY() + STARTINGPLATFORM_HEIGHT - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY(STARTINGPLATFORM_HEIGHT - cat.getHeight());
		}

		cat.setVelocityY(0);
		return;
	}

	if (cat.getX() <= (PLATFORM_DISTANCEX) && cat.getY() + cat.getHeight() >= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3) && cat.getY() <= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3))//starting platform
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}

		if ((cat.getY() + cat.getHeight() / 2) >= (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3)
		{
			cat.setY(cat.getY() + (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 - cat.getHeight());
		}
		cat.setVelocityY(0);
		return;
	}
	if (cat.getX() <= (PLATFORM_DISTANCEX) && cat.getY() + cat.getHeight() >= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2) && cat.getY() <= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2))//starting platform
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}

		if ((cat.getY() + cat.getHeight() / 2) >= (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2)
		{
			cat.setY(cat.getY() + (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2 - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2 - cat.getHeight());
		}

		cat.setVelocityY(0);
		return;
	}
	if (cat.getX() <= (PLATFORM_DISTANCEX) && cat.getY() + cat.getHeight() >= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT)) && cat.getY() <= ((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT)))//starting platform
	{
		if (cat.getVelocityY()<0)
		{
			cat.setY(cat.getY() + 1);
		}

		if ((cat.getY() + cat.getHeight() / 2) >= (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT))
		{
			cat.setY(cat.getY() + (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) - cat.getY() + (cat.getHeight() / 2));
		}
		else
		{
			cat.setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) - cat.getHeight());
		}

		cat.setVelocityY(0);
		return;
	}
}
//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Papercat::initialize(HWND hwnd)
{
	srand(time(NULL));
	Game::initialize(hwnd); // throws GameError

	//Pages for the games 
	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// background stage texture
	if (!backgroundStageTexture.initialize(graphics, BACKGROUND_STAGE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround stage texture"));

	// background stage 2 texture
	if (!backgroundStage2Texture.initialize(graphics, BACKGROUND_STAGE2_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround stage texture"));

	// Highscore texture
	if (!highscoreTexture.initialize(graphics, BACKGROUND_HIGHSCORE_PAGE2_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround highscore texture"));
	highscoreLogging->initialize(graphics);

	// Credits texture
	if (!creditTexture.initialize(graphics, BACKGROUND_CREDIT_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround credit texture"));

	//tutorial texture
	if (!tutorialTexture.initialize(graphics, BACKGROUND_TUTORIAL_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround tutorial texture"));

	// rainbow texture
	if (!rainbowTexture.initialize(graphics, RAINBOW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround rainbow texture"));
	//buttons
	if (!buttonsTexture.initialize(graphics, BUTTONS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing button texture"));

	//for characters and items
	// main textures
	if (!mainTexture.initialize(graphics, ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main texture"));

	// item textures
	if (!itemTexture.initialize(graphics, ITEMS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing item texture"));
	
	//Images
	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// background stage image
	if (!backgroundStage.initialize(graphics, 0, 0, 0, &backgroundStageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

	// background stage 2 image
	if (!backgroundStage2.initialize(graphics, 0, 0, 0, &backgroundStage2Texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));
	
	// background highscore image
	if (!backgroundHighscore.initialize(graphics, 0, 0, 0, &highscoreTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

	// background credit image
	if (!backgroundCredit.initialize(graphics, 0, 0, 0, &creditTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));
	// background tutorial image
	if (!backgroundTutorial.initialize(graphics, 0, 0, 0, &tutorialTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tutorial page"));
	// rainbow flashing image
	if (!rainbow.initialize(graphics, 0, 0, 0, &rainbowTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing rainbow flashing"));

	// buttons
	// start
	if (!startButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	startButton.setFrames(buttonsNS::START_FRAME, buttonsNS::START_FRAME);
	startButton.setCurrentFrame(buttonsNS::START_FRAME);
	startButton.setX(GAME_WIDTH / 3.0);
	startButton.setY(GAME_HEIGHT / 2.5);

	// highscore
	if (!highscoreButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	highscoreButton.setFrames(buttonsNS::HIGHSCORE_FRAME, buttonsNS::HIGHSCORE_FRAME);
	highscoreButton.setCurrentFrame(buttonsNS::HIGHSCORE_FRAME);
	highscoreButton.setX(GAME_WIDTH / 3);
	highscoreButton.setY(GAME_HEIGHT / 2.5 + BUTTON_SPACING);

	// credits
	if (!creditsButton.initialize(this, buttonsNS::WIDTH, buttonsNS::HEIGHT, buttonsNS::TEXTURE_COLS, &buttonsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buttons"));
	creditsButton.setFrames(buttonsNS::CREDITS_FRAME, buttonsNS::CREDITS_FRAME);
	creditsButton.setCurrentFrame(buttonsNS::CREDITS_FRAME);
	creditsButton.setX(GAME_WIDTH / 3);
	creditsButton.setY(GAME_HEIGHT / 2.5 + BUTTON_SPACING * 2);

	// elements
	// scissors
	if (!scissor1.initialize(this, scissorsNS::WIDTH, scissorsNS::HEIGHT, scissorsNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing scissors"));
	scissor1.setFrames(scissorsNS::SCISSORS_START_FRAME, scissorsNS::SCISSORS_END_FRAME);
	scissor1.setCurrentFrame(scissorsNS::SCISSORS_START_FRAME);

	scissor1.setX(0);
	scissor1.setY(50 * (rand() % (GAME_HEIGHT / scissor1.getHeight() - 1)));
	//scissor1.setVisible(0);

	// cat
	if (!cat.initialize(this, mainCharNS::WIDTH, mainCharNS::HEIGHT, mainCharNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cat"));
	cat.setFrames(mainCharNS::CAT_START_FRAME, mainCharNS::CAT_END_FRAME);
	cat.setCurrentFrame(mainCharNS::CAT_START_FRAME);
	/*cat.setX(50);
	cat.setY(100);*/

	//blackhole
	if (!blackhole.initialize(this, blackholeNS::WIDTH, blackholeNS::HEIGHT, blackholeNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing blackhole"));
	blackhole.setFrames(blackholeNS::BLACKHOLE_START_FRAME, blackholeNS::BLACKHOLE_END_FRAME);
	blackhole.setCurrentFrame(blackholeNS::BLACKHOLE_START_FRAME);
	blackhole.setX(GAME_WIDTH / 3);
	blackhole.setY(GAME_HEIGHT / 3);
	//minion
	if (!minion->initialize(this, minionNS::SMALL_MINION_WIDTH, minionNS::SMALL_MINION_HEIGHT, minionNS::SMALL_MINION_TEXTURE_COLS))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minion"));
	// items
	for (int i = 0; i < BUFF_NUM; i++)
	{
		if (!items[i].initialize(this, itemsNS::WIDTH, itemsNS::HEIGHT, itemsNS::TEXTURE_COLS, &itemTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing items"));
		items[i].setFrames(i, i);
		items[i].setCurrentFrame(i);
	}

	srand(time(0));//To truely randomized random number
	int randLineNum;//randomize the platform whereby items are placed
	int arrayNum;
	Items temp1;
	Items temp2;
	setArray(arrayOfPosition);
	for (int i = 0; i < BUFF_NUM; i++)
	{
		randLineNum = rand() % 3 + 1;
		arrayNum =SetRandomNum(randLineNum);
		items[i].setX(arrayOfPosition[arrayNum]);
		temp1 = items[i];
		setYvalue(randLineNum, i, 1);
		for (int j = 0; j < BUFF_NUM; j++)
		{
			temp2 = items[j];
			if (collisionWithItem(temp1, temp2))
			{
				randLineNum = rand() % 3 + 1;
				arrayNum = SetRandomNum(randLineNum);
				items[i].setX(arrayOfPosition[arrayNum]);
				setYvalue(randLineNum, i,1);
				temp1 = items[i];				
			}
		}
	}
	
	//coins initialization	
	for (int i = 0; i < NUMBER_OF_COINS; i++)
	{
		if (!coins[i].initialize(this, itemsNS::WIDTH, itemsNS::HEIGHT, itemsNS::TEXTURE_COLS, &itemTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing coins"));
		coins[i].setFrames(BUFF_NUM, BUFF_NUM);
		coins[i].setCurrentFrame(BUFF_NUM);
	}


	int currentLine = 1;
	arrayNum = 0;
	int cutOff = (3 * arrayOfNumX / 4) - 1;
	for (int i = 0; i < NUMBER_OF_COINS; i++)
	{
		if (arrayNum == cutOff)
		{
			arrayNum = 0;
			currentLine++;
			if (currentLine == 2)
			{
				arrayNum = arrayOfNumX / 3;
				cutOff = arrayOfNumX - 1;
			}
			else
			{
				arrayNum = 0;
				cutOff = (3 * arrayOfNumX / 4) - 1;
			}
		}
		coins[i].setX(arrayOfPosition[arrayNum]);
		setYvalue(currentLine, i,2);
		for (int j = 0; j < BUFF_NUM; j++)
		{
			if (collisionWithItem(coins[i], items[j]))
			{
				if (arrayNum == cutOff)
				{
					arrayNum = 0;
					currentLine++;
					if (currentLine == 2)
					{
						arrayNum = arrayOfNumX / 3;
						cutOff = arrayOfNumX - 1;
					}
					else
					{
						arrayNum = 0;
						cutOff = (3*arrayOfNumX / 4)-1;						
					}
				}
				else
				{
					arrayNum++;
				}								
				coins[i].setX(arrayOfPosition[arrayNum]);
				setYvalue(currentLine, i, 2);
				j = 0;
			}
		}
		arrayNum++;	
		if (currentLine == 3 && arrayNum == cutOff)
			i = NUMBER_OF_COINS;
	}
	// star initialization
	for (int i = 0; i < NUMBER_OF_STARS; i++)
	{
		if (!stars[i].initialize(this, starNS::WIDTH, starNS::HEIGHT, starNS::TEXTURE_COLS, &mainTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid"));
		stars[i].setFrames(starNS::STAR_FRAME, starNS::STAR_FRAME);
		stars[i].setCurrentFrame(starNS::STAR_FRAME);
		stars[i].setX(rand() % GAME_WIDTH);
		stars[i].setY(rand() % GAME_HEIGHT);
		stars[i].setVelocity(VECTOR2((rand() % 250 + 50), -(rand() % 250 + 50))); // VECTOR2(X, Y)

	}


	// initialize font
	if (mainFont->initialize(graphics, 30, true, false, "Courier New") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
	if (pausedFont->initialize(graphics, 100, true, false, "Courier New") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font 2"));
	// menu texture
	if (!doorTexture.initialize(graphics, ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing door texture"));
	// menu image
	if (!doorFinal.initialize(graphics, 48, 48, 8, &doorTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing door"));
	doorFinal.setCurrentFrame(39);
	doorFinal.setX(200);
	doorFinal.setY((doorFinal.getX() * -0.2) + (C_FOR_PLATFORM_2 + cat.getHeight() - doorFinal.getHeight() - 10));
	// menu image
	if (!doorBonus.initialize(graphics, 48, 48, 8, &doorTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing door"));
	doorBonus.setCurrentFrame(39);

	doorBonus.setX(doorBonus.getWidth());
	doorBonus.setY(GAME_HEIGHT - doorBonus.getHeight() * 2);

	return;

	// play sound
	thread t(&Papercat::playBGM, this);
	t.join();
}

//=============================================================================
// Update all game items
//=============================================================================
void Papercat::update()
{
	startButton.update(frameTime);
	highscoreButton.update(frameTime);
	creditsButton.update(frameTime);
	mciSendString("play sounds\\theme_song.wav", NULL, 0, NULL);
	switch (gameStart)
	{
	case 1:
	{
			  cat.checkStunned(cat.getState());
			  cat.checkBuff(frameTime);
			  cat.setVelocityY(cat.getVelocityY() + 2.5f);
			  characterPlatformCheckingForStage1();
			  cat.characterMovementStage(input, CHARACTER_UP, CHARACTER_DOWN, CHARACTER_LEFT, CHARACTER_RIGHT, CHARACTER_JUMP);
			  bool collision = minion->collisionDetectionWithCharacter(cat);
			  if (collision)
			  {
				  if (cat.getState() != 2)
				  {
					  PlaySound(TEXT("sounds\\meow.wav"), NULL, SND_ASYNC);
					  cat.setHealth(cat.getHealth() - 1);
				  }		
				  else
				  {
					  cat.setState(-1);
				  }
			  }
			  if (cat.getHealth() <= 0)
			  {
				  gameStart = 7;
			  }
			  if (cat.stunned() == false){
				  cat.update(frameTime);
				  cat.checkStunned(cat.getState());
			  }
			  if (minion != nullptr && !paused)
			  {
				  minion->update(frameTime);
			  }
			  scissor1.update(frameTime);
	}
		break;
	case 4:
		gravity();
		cat.characterMovementFinal(input, CHARACTER_UP, CHARACTER_DOWN, CHARACTER_LEFT, CHARACTER_RIGHT);
		cat.update(frameTime); 
		for (int i = 0; i < NUMBER_OF_STARS; i++)
		{
			stars[i].update(frameTime);
		}
		if (numberOfStarsCollected == NUMBER_OF_STARS)
			gameStart = 7;
		break;
	case 8:
	{
			  cat.setVelocityY(cat.getVelocityY() + 2.5f);
			  characterPlatformCheckingForBonusStage();
			  cat.characterMovementStage(input, CHARACTER_UP, CHARACTER_DOWN, CHARACTER_LEFT, CHARACTER_RIGHT, CHARACTER_JUMP);
			  cat.update(frameTime);
	}
		break;
	default:
		break;
	}
	
	
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Papercat::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Papercat::collisions()
{
	VECTOR2 collisionVector;
	switch (gameStart)
	{
	case 1:
		//collision with enemy boss

		if ((cat.getX() + cat.getWidth()) >= (minion->getX()) &&
			(cat.getX() <= (minion->getX() + minion->getWidth()) &&
			(cat.getY() + cat.getHeight()) >= minion->getY()) &&
			cat.getY() <= (minion->getY() + minion->getHeight()))
		{
			if (cat.getState() != 2)
			{
				minion->setVisible(false);
				cat.setHealth(cat.getHealth() - 1);
			}
		}

		//collision with scissors
		checkScissorCollision();

		//collision with coins
		checkCoinCollision();

		//collision with buff
		checkBuffCollision();

		checkFinalDoor();
		checkBonusDoor();
		break;
	case 4:
		checkCoinCollision();
		for (int i = 0; i < NUMBER_OF_STARS; i++){
			if (stars[i].collidesWith(blackhole, collisionVector))
				stars[i].bounce(collisionVector, blackhole);
			if ((cat.getX() + cat.getWidth()) >= (stars[i].getX()) &&
				(cat.getX() <= (stars[i].getX() + stars[i].getWidth()) &&
				(cat.getY() + cat.getHeight()) >= stars[i].getY()) &&
				cat.getY() <= (stars[i].getY() + stars[i].getHeight()))
			{
				stars[i].setVisible(false);
				stars[i].setX(-50);
				stars[i].setY(-50);
				numberOfStarsCollected++;
			}
		}
		break;
	case 8:
		checkCoinCollision();
		checkFinalDoor();
		break;
	}
}



//=============================================================================
// Render game items
//=============================================================================
void Papercat::render()
{
	const int BUF_SIZE = 50;
	static char buffer[BUF_SIZE];
	switch (gameStart)
	{
	case 0:
		graphics->spriteBegin();
		menu.draw();							// add the menu to the scene
		startButton.draw();						// add start button to menu scene
		highscoreButton.draw();					// add highscore button to menu scene
		creditsButton.draw();					// add credits button to menu scene
		graphics->spriteEnd();
		if (input->wasKeyPressed(VK_F10))
		{
			if (highscoreLogging->checkingScore(playerScore));
			gameStart = 5;
		}
		if (startButton.getClickedState())
		{
			gameStart = 6;
		}
		else if (highscoreButton.getClickedState())
		{
			gameStart = 2;
		}
		else if (creditsButton.getClickedState())
		{
			gameStart = 3;
		}
		break;
	case 1:
		graphics->spriteBegin();
		backgroundStage.draw();
		scissor1.draw();
		doorFinal.draw();
		doorBonus.draw();
		for (int i = 0; i < BUFF_NUM; i++)
		{
			items[i].draw();
			items[i].update(frameTime);
		}

		for (int i = 0; i < NUMBER_OF_COINS; i++)
		{
			coins[i].draw();
			coins[i].update(frameTime);
		}
		
		if (minion != nullptr && !paused)
		{
			if (minion->getY()<0)
			{
				SAFE_DELETE(minion);
			}
			else
			{
				minion->update(frameTime);
				minion->draw();
			}
		}
		cat.draw();
		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Score: %d", (int)playerScore);
		mainFont->print(buffer, GAME_WIDTH - 150, 20);
		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Health: %d", (int)cat.getHealth());
		mainFont->print(buffer, GAME_WIDTH - 150 - 200, 20);
		rainbow.draw();
		if (input->wasKeyPressed(VK_ESCAPE)){
			paused = true;
		}
		if (paused)
		{
			pausedFont->setFontColor(graphicsNS::WHITE);
			pausedFont->print("PAUSED\n", GAME_WIDTH / 4, 200);
			pausedFont->print("Hit \"Enter\" \nto resume", GAME_WIDTH / 10, 300);
			if (input->wasKeyPressed(VK_RETURN))
				paused = false;
		}
		if ((cat.getX() + cat.getWidth()) >= (doorFinal.getX()) &&
			(cat.getX() <= (doorFinal.getX() + doorFinal.getWidth()) &&
			(cat.getY() + cat.getHeight()) >= doorFinal.getY()) &&
			cat.getY() <= (doorFinal.getY() + doorFinal.getHeight()) || input->wasKeyPressed(VK_UP))
		{
			for (int i = 0; i < NUMBER_OF_COINS; i++)
			{
				coins[i].setX(rand() % GAME_WIDTH + 0);
				coins[i].setY(rand() % GAME_HEIGHT + 0);
				while (checkCollisionforStage2())
				{
					coins[i].setX(rand() % GAME_WIDTH + 0);
					coins[i].setY(rand() % GAME_HEIGHT + 0);
				}
			}
			gameStart = 4;
		}
		if (cat.getState() == 3){
			flashTimer += 0.05;
			if ((int)flashTimer % 10 == 0)
				rainbow.setVisible(true);
			else
				rainbow.setVisible(false);
			if (flashTimer >= FLASHTIME)
			{
				cat.setState(-1);
				flashTimer = 0;
			}
		}
		else
			rainbow.setVisible(false);
		graphics->spriteEnd();
		drawing.GetDevice(graphics->get3Ddevice());
		drawing.Line(0, STARTINGPLATFORM_HEIGHT, STARTINGPLATFORM_WIDTH, STARTINGPLATFORM_HEIGHT, 5, true, graphicsNS::WHITE);//starting platform. (10 for holdoff, 50 for the charcter's height(not created yet))

		drawing.Line(0, C_FOR_PLATFORM_1, 0 + PLATFORM_DISTANCEX, C_FOR_PLATFORM_1 + PLATFORM_DISTANCEY, 5, true, graphicsNS::WHITE);//platform 1 (500 for the hortizol distance of the platform)

		drawing.Line(GAME_WIDTH - PLATFORM_DISTANCEX, C_FOR_PLATFORM_1 + PLATFORM_DISTANCEY + PLATFORM_DISTANCEY + PLATFORM_DISTANCEY, GAME_WIDTH, C_FOR_PLATFORM_1 + PLATFORM_DISTANCEY + PLATFORM_DISTANCEY, 5, true, graphicsNS::WHITE);//platform 2(100 for holdoff betwe)

		drawing.Line(0, C_FOR_PLATFORM_3, 0 + PLATFORM_DISTANCEX, C_FOR_PLATFORM_3 + PLATFORM_DISTANCEY, 5, true, graphicsNS::WHITE);//platform 3
		break;
	case 2:
		graphics->spriteBegin();
		highscoreLogging->draw();
		graphics->spriteEnd();
		if (input->anyKeyPressed())
		{
			gameStart = 0;
		}
		break;
	case 3:
		graphics->spriteBegin();
		backgroundCredit.draw();
		graphics->spriteEnd();
		if (input->anyKeyPressed())
		{
			gameStart = 0;
		}
		break;
	case 4:
		graphics->spriteBegin();
		backgroundStage2.draw();
		for (int i = 0; i < NUMBER_OF_STARS; i++)
		{
			stars[i].draw();
		}
		blackhole.draw();
		for (int i = 0; i < NUMBER_OF_COINS; i++)
		{
			coins[i].setVisible(true);
			coins[i].draw();
			coins[i].setVisible(true);
		}
		cat.draw();
		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Score: %d", (int)playerScore);
		mainFont->print(buffer, GAME_WIDTH - 150, 20);
		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Health: %d", (int)cat.getHealth());
		mainFont->print(buffer, GAME_WIDTH - 150 - 200, 20);
		graphics->spriteEnd();
		break;
	case 5:
		graphics->spriteBegin();
		backgroundHighscore.draw();
		if (playerName.size() < 8)
		{
			playerName = input->getTextIn();
		}
		if (playerName.size() > 7)
		{

			if (input->wasKeyPressed(VK_BACK))
				playerName = input->getTextIn();
			else
				input->setTextIn(playerName);
		}

		pausedFont->print(playerName, GAME_WIDTH / 4, GAME_HEIGHT / 2);
		if (input->isKeyDown(VK_RETURN) && playerName != "")
		{
			highscoreLogging->setScores(playerScore, playerName);
			gameStart = 2;
		}

		graphics->spriteEnd();
		break;
	case 6:
		graphics->spriteBegin();
		backgroundTutorial.draw();
		graphics->spriteEnd();
		if (input->wasKeyPressed(VK_RETURN))
		{
			gameStart = 1;
		}
		break;
	case 7:
		mciSendString("play sounds\\game_over.wav", NULL, 0, NULL);
		graphics->spriteBegin();
		backgroundStage.draw();

		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Score: %d", (int)playerScore);
		mainFont->print(buffer, GAME_WIDTH / 2 - 60, GAME_HEIGHT / 2 + 30);
		graphics->spriteEnd();
		break;
	case 8:
		graphics->spriteBegin();
		backgroundStage.draw();
		cat.draw();
		
		doorFinal.draw();
		for (int i = 0; i < NUMBER_OF_COINS; i++)
		{
			coins[i].draw();
			coins[i].update(frameTime);
		}
		graphics->spriteEnd();
		drawing.GetDevice(graphics->get3Ddevice());
		drawing.Line(0, STARTINGPLATFORM_HEIGHT, STARTINGPLATFORM_WIDTH, STARTINGPLATFORM_HEIGHT, 5, true, graphicsNS::WHITE);

		drawing.Line(0, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3, PLATFORM_DISTANCEX, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3, 5, true, graphicsNS::WHITE);

		drawing.Line(0, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2, PLATFORM_DISTANCEX, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2, 5, true, graphicsNS::WHITE);

		drawing.Line(0, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT), PLATFORM_DISTANCEX, (GAME_HEIGHT - STARTINGPLATFORM_HEIGHT), 5, true, graphicsNS::WHITE);
 
		break;
	default:
		break;
	}
	// exit at any point
	if (GetKeyState(VK_LMENU) && input->wasKeyPressed(VK_F4))
	{
		exitGame();
	}
	
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Papercat::releaseAll()
{
	menuTexture.onLostDevice();
	buttonsTexture.onLostDevice();
	backgroundStageTexture.onLostDevice();
	mainTexture.onLostDevice();
	creditTexture.onLostDevice();
	highscoreTexture.onLostDevice();
	tutorialTexture.onLostDevice();
	rainbowTexture.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Papercat::resetAll()
{
	menuTexture.onResetDevice();
	buttonsTexture.onResetDevice();
	backgroundStageTexture.onResetDevice();
	mainTexture.onResetDevice();
	creditTexture.onResetDevice();
	highscoreTexture.onResetDevice();
	tutorialTexture.onResetDevice();
	rainbowTexture.onResetDevice();
	mainFont->setFontColor(graphicsNS::WHITE);
	Game::resetAll();
	return;
}

void Papercat::gravity()
{

	float testX = 0;
	float testY = 0;


	////update y value of cat			
	if (cat.getY() < blackhole.getCenterY())
	{
		testY = cat.getVelocityY() + GRAVITY;
		cat.setVelocityY(testY);
	}
	else if (cat.getY() > blackhole.getCenterY())
	{
		testY = cat.getVelocityY() - GRAVITY;
		cat.setVelocityY(testY);
	}
	if (cat.getX() < blackhole.getCenterX())
	{
		testX = cat.getVelocityX() + GRAVITY;
		cat.setVelocityX(testX);
	}
	else if (cat.getX() > blackhole.getCenterX())
	{
		testX = cat.getVelocityX() - GRAVITY;
		cat.setVelocityX(testX);
	}

}

void Papercat::setYvalue(int randLineNum, int i, int type)
{
	Items *obj = new Items;
	if (type == 1)
	{
		obj = items;
	}
	else if (type == 2)
	{
		obj = coins;
	}
	if (randLineNum == 1)
	{		
		obj[i].setY(obj[i].getX()*0.2 + (10 + 50 + 10));	
	}
	else if (randLineNum == 2)
	{
		 obj[i].setY((obj[i].getX()*-0.2) + (454 - obj[i].getHeight()));

	}
	else
	{		
		obj[i].setY(obj[i].getX()*0.2 + (10 + 50 + 10 + 100 + 100 + 100 + 100));
	}
	
}

bool Papercat::collisionWithItem(Items item1,Items item2)
{
	//to prevent items from getting detected even when they are not touching each other,
	//0.2f is set to reduce the range whereby the coins are being detected
	if ((item1.getX() + item1.getWidth()-0.2f) >= (item2.getX()) &&
		(item1.getX() <= (item2.getX() + item2.getWidth() - 0.2f) &&
		(item1.getY() + item1.getHeight()) >= item2.getY()) &&
		item1.getY() <= (item2.getY() + item2.getHeight()))
	{
		return true;
	}
		return false;
}
void Papercat::setArray(float arrayOfposition[arrayOfNumX])
{
	for (int i = 0; i < arrayOfNumX; i++)
	{
		arrayOfPosition[i] =  items[0].getWidth()*i + 0.2f / 2;
	}
}
int Papercat::SetRandomNum(int lineNum)
{
	int randNum;
	if (lineNum == 1 || lineNum ==3)
	{
		randNum = rand() % (arrayOfNumX / 2);
	}
	else if (lineNum == 2)
	{
		randNum = rand() % (arrayOfNumX - (arrayOfNumX / 2) )+ (arrayOfNumX / 2);
	}
	return randNum;
}
void Papercat::playBGM()
{
	PlaySound(TEXT("sounds\\theme_song.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
} 
bool Papercat::checkCollisionforStage2(){
	// coin and blackhole

	for (int i = 0; i < NUMBER_OF_COINS; i++)
	{
		if ((coins[i].getX() + coins[i].getWidth()) >= (blackhole.getX()) &&
			(coins[i].getX() <= (blackhole.getX() + blackhole.getWidth()) &&
			(coins[i].getY() + coins[i].getHeight()) >= blackhole.getY()) &&
			coins[i].getY() <= (blackhole.getY() + blackhole.getHeight()))
		{
			i--;
			return true;
		}
		else
			return false;
	}
	// items and items
	for (int i = 0; i <NUMBER_OF_COINS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COINS; i++)
		{
			if ((coins[i].getX() + coins[i].getWidth()) >= (coins[j].getX()) &&
				(coins[i].getX() <= (coins[j].getX() + coins[j].getWidth()) &&
				(coins[i].getY() + coins[i].getHeight()) >= coins[j].getY()) &&
				coins[i].getY() <= (coins[j].getY() + coins[j].getHeight()))
			{
				i--;
				return true;
			}		
			else
			{
				return false;
			}
		}
	}
}
void Papercat::checkScissorCollision()
{
	if ((cat.getX() + cat.getWidth()) >= (scissor1.getX()) &&
		(cat.getX() <= (scissor1.getX() + scissor1.getWidth()) &&
		(cat.getY() + cat.getHeight()) >= scissor1.getY()) &&
		cat.getY() <= (scissor1.getY() + scissor1.getHeight()) && scissor1.getVisible())
	{
		PlaySound(TEXT("sounds\\meow.wav"), NULL, SND_ASYNC);
		if (cat.getState() != 2)
		{//playerScore++;
			scissor1.setY(50 * rand() % 15 + 1);
			scissor1.setX(0);
			scissor1.setVisible(false);
			cat.setHealth(cat.getHealth() - 1);

			if (cat.getHealth() <= 0)
			{
				gameStart = 7;
			}
		}
		else
		{
			cat.setState(-1);
		}
	}
}
void Papercat::checkCoinCollision()
{
	for (int i = 0; i < NUMBER_OF_COINS; i++)
	{
		if ((cat.getX() + cat.getWidth()) >= (coins[i].getX()) &&
			(cat.getX() <= (coins[i].getX() + coins[i].getWidth()) &&
			(cat.getY() + cat.getHeight()) >= coins[i].getY()) &&
			cat.getY() <= (coins[i].getY() + coins[i].getHeight()))
		{
			PlaySound(TEXT("sounds\\coin.wav"), NULL, SND_ASYNC);
			if (cat.getState() == 1)
			{
				playerScore++;
				numberOfCoinsCollected++;
			}
			playerScore++;
			coins[i].setVisible(false);
			coins[i].setX(-100.0f);
			coins[i].setY(-100.0f);
			if (numberOfCoinsCollected > 10)
			{
				cat.setState(-1);
			}
		}
	}
}
void Papercat::checkBuffCollision()
{
	for (int i = 0; i < BUFF_NUM; i++)
	{
		if ((cat.getX() + cat.getWidth()) >= (items[i].getX()) &&
			(cat.getX() <= (items[i].getX() + items[i].getWidth()) &&
			(cat.getY() + cat.getHeight()) >= items[i].getY()) &&
			cat.getY() <= (items[i].getY() + items[i].getHeight()))
		{
			PlaySound(TEXT("sounds\\rune.wav"), NULL, SND_ASYNC);
			items[i].setVisible(false);
			items[i].setX(-100.0f);
			items[i].setY(-100.0f);
			cat.setState(i);
		}
	}
}
void Papercat::checkFinalDoor()
{
	if ((cat.getX() + cat.getWidth()) >= (doorFinal.getX()) &&
		(cat.getX() <= (doorFinal.getX() + doorFinal.getWidth()) &&
		(cat.getY() + cat.getHeight()) >= doorFinal.getY()) &&
		cat.getY() <= (doorFinal.getY() + doorFinal.getHeight()) && doorFinal.getVisible())
	{
		if (input->wasKeyPressed(VK_UP))
		{
			gameStart = 4;
			for (int i = 0; i < NUMBER_OF_COINS; i++)
			{
				coins[i].setCurrentFrame(itemsNS::COIN_FRAME);
				coins[i].setVisible(true);
				coins[i].setX(rand() % GAME_WIDTH + 0);
				coins[i].setY(rand() % GAME_HEIGHT + 0);
				coins[i].update(frameTime);
			}
			cat.setX(mainCharNS::X);
			cat.setY(mainCharNS::Y);
		}
		
	}
}
void Papercat::checkBonusDoor()
{
	if ((cat.getX() + cat.getWidth()) >= (doorBonus.getX()) &&
		(cat.getX() <= (doorBonus.getX() + doorBonus.getWidth()) &&
		(cat.getY() + cat.getHeight()) >= doorBonus.getY()) &&
		cat.getY() <= (doorBonus.getY() + doorBonus.getHeight()) && doorBonus.getVisible())
	{
		if (input->wasKeyPressed(VK_UP))
		{
			gameStart = 8;
			srand(time(0));
			for (int i = 0; i < NUMBER_OF_COINS; i++)
			{
				if (!coins[i].initialize(this, itemsNS::WIDTH, itemsNS::HEIGHT, itemsNS::TEXTURE_COLS, &itemTexture))
					throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing items"));
				coins[i].setCurrentFrame(itemsNS::COIN_FRAME);
				Items* currentItem = &coins[i];
				setItemsInPosition(currentItem);
				bool reCheckForRepeats = false;
				do
				{
					for (int j = 0; j < i - 1; j++)
					{
						if ((currentItem->getX() == coins[j].getX() && currentItem->getY() == coins[j].getY()))
						{
							setItemsInPosition(currentItem);
							reCheckForRepeats = true;
							break;
						}
						reCheckForRepeats = false;
					}

				} while (reCheckForRepeats);
			}
			doorFinal.setY(GAME_HEIGHT - doorFinal.getHeight());
			doorFinal.setX(0);
			cat.setX(mainCharNS::X);
			cat.setY(mainCharNS::Y);
		}
	}
}
void Papercat::setItemsInPosition(Entity* item)
{
	int spawnColumns = floor(GAME_WIDTH / itemsNS::WIDTH);
	int spawnLine = rand() % 3 + 1;
	int spawnColumn = rand() % spawnColumns + 1;
	item->setX(spawnColumn*itemsNS::WIDTH);
	switch (gameStart)
	{
	case 8:
		switch (spawnLine)
		{
		case 1:
			if (item->getX() < PLATFORM_DISTANCEX)
			{
				item->setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 - item->getHeight() - 10);
			}
			else
			{
				setItemsInPosition(item);
			}
			break;
		case 2:
			if (item->getX() < (PLATFORM_DISTANCEX))
			{
				item->setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) / 3 * 2 - item->getHeight() - 10);
			}
			else
			{
				setItemsInPosition(item);
			}
			break;
		case 3:
			if (item->getX() < PLATFORM_DISTANCEX)
			{
				item->setY((GAME_HEIGHT - STARTINGPLATFORM_HEIGHT) - item->getHeight() - 10);
			}
			else
			{
				setItemsInPosition(item);
			}
			break;

		default:
			break;
		}
		break;
	case 1:
		switch (spawnLine)
		{
		case 1:
			if (item->getX() < PLATFORM_DISTANCEX)
			{
				item->setY(item->getX()*0.2 + (C_FOR_PLATFORM_1 - item->getHeight() - 10)); //7 is item holdoff
			}
			else
			{
				setItemsInPosition(item);
			}

			break;
		case 2:
			if (item->getX() > (GAME_WIDTH - PLATFORM_DISTANCEX))
			{
				item->setY((item->getX() * -0.2) + (C_FOR_PLATFORM_2 + cat.getHeight() - item->getHeight() - 10));
			}
			else
			{
				setItemsInPosition(item);
			}
			break;
		case 3:
			if (item->getX() < PLATFORM_DISTANCEX)
			{
				item->setY(item->getX() * 0.2 + (C_FOR_PLATFORM_3 - item->getHeight() - 10));
			}
			else
			{
				setItemsInPosition(item);
			}
			break;

		default:
			break;
		}
		break;
	default:
		break;
	}

}