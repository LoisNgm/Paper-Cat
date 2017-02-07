#include "papercat.h"
#include "time.h"

//=============================================================================
// Constructor
//=============================================================================
Papercat::Papercat()
{
	mainFont = new TextDX();
	pausedFont = new TextDX();
}

//=============================================================================
// Destructor
//=============================================================================
Papercat::~Papercat()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Papercat::initialize(HWND hwnd)
{
	srand(time(NULL));
	Game::initialize(hwnd); // throws GameError

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// background stage texture
	if (!backgroundStageTexture.initialize(graphics, BACKGROUND_STAGE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround stage texture"));

	// Highscore texture
	if (!highscoreTexture.initialize(graphics, BACKGROUND_HIGHSCORE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround highscore texture"));

	// Credits texture
	if (!creditTexture.initialize(graphics, BACKGROUND_CREDIT_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround credit texture"));
	//buttons
	if (!buttonsTexture.initialize(graphics, BUTTONS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing button texture"));

	// main textures
	if (!mainTexture.initialize(graphics, ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main texture"));

	// item textures
	if (!itemTexture.initialize(graphics, ITEMS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing item texture"));

	//   // nebula texture
	//   if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

	//   // main game textures
	//   if (!shipTexture.initialize(graphics,SHIP_IMAGE))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship texture"));
	//// main game textures
	//if (!asteroidTexture.initialize(graphics, ASTEROID_IMAGE))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid texture"));

	//   // nebula image
	//   if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
	//       throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

	// menu image
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// background stage image
	if (!backgroundStage.initialize(graphics, 0, 0, 0, &backgroundStageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

	// background highscore image
	if (!backgroundHighscore.initialize(graphics, 0, 0, 0, &highscoreTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));
	// background credit image
	if (!backgroundCredit.initialize(graphics, 0, 0, 0, &creditTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

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
	scissor1.setY(50 * (rand() % (GAME_HEIGHT/scissor1.getHeight()-1)));
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
	blackhole.setX(GAME_WIDTH/2);
	blackhole.setY(GAME_HEIGHT/2);
	//minion
	if (!minion->initialize(this, minionNS::SMALL_MINION_WIDTH, minionNS::SMALL_MINION_HEIGHT, minionNS::SMALL_MINION_TEXTURE_COLS))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing minion"));
	

	//asteroids
	for (int i = 0; i < MAX_ASTEROIDS_NO; i++)
	{
		//if (!asteroidList[i].initialize(this, asteroidNS::WIDTH, asteroidNS::HEIGHT, asteroidNS::TEXTURE_COLS, &asteroidTexture))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid"));
		//asteroidList[i].setFrames(asteroidNS::ASTEROID_START_FRAME, asteroidNS::ASTEROID_END_FRAME);
		//asteroidList[i].setCurrentFrame(asteroidNS::ASTEROID_START_FRAME);
		//asteroidList[i].setX(GAME_WIDTH/4);
		//asteroidList[i].setY(GAME_HEIGHT/4 * (i+1));

	}

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
	for (int i = 0; i < BUFF_NUM-1; i++)
	{
		randLineNum = rand() % 3 + 1;
		arrayNum = rand() % arrayOfNumX + 0;
		
		items[i].setX(arrayOfPosition[arrayNum]);
		temp1 = items[i];
		setYvalue(randLineNum, i);
		for (int j = i + 1; j < BUFF_NUM; j++)
		{
			items[i].setX(arrayOfPosition[arrayNum]);
			setYvalue(randLineNum, i);
			temp2 = items[j];
	     while (collisionWithItem(temp1,temp2))
			{
			 randLineNum = rand() % 3 + 1;
			 arrayNum = rand() % arrayOfNumX + 0;
			 items[i].setX(arrayOfPosition[arrayNum]);
			setYvalue(randLineNum, i);
			temp2 = items[j];
			}
		}
	}
	//coins initialization
	/*for (int i = 0; i < NUMBER_OF_COINS; i++)
	{
		if (!coins[i].initialize(this, itemsNS::WIDTH, itemsNS::HEIGHT, itemsNS::TEXTURE_COLS, &itemTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing coins"));
		items[i].setFrames(BUFF_NUM, BUFF_NUM);
		items[i].setCurrentFrame(BUFF_NUM);
	}
	for (int i = 1; i < 4; i++)//there are 3 total number of platforms
	{
		//check if it collides with other items
		for (int j = 0; j < BUFF_NUM; j++)
		{
			while (collisionWithItem(items[i], temp2))
			{
				arrayOfPosition[arrayNum];
			}
		}
	}*/
	// initialize font
	if (mainFont->initialize(graphics, 30, true, false, "Courier New") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
	if (pausedFont->initialize(graphics, 100, true, false, "Courier New") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font 2"));
	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Papercat::update()
{
	startButton.update(frameTime);
	highscoreButton.update(frameTime);
	creditsButton.update(frameTime);
	//ship.update(frameTime);

	if (gameStart == 1)
	{
		cat.setVelocityY(cat.getVelocityY() + 2.5f);

		cat.update(frameTime);
		
		scissor1.update(frameTime);
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
	//collision with scissors
	if ((cat.getX() + cat.getWidth()) >= (scissor1.getX()) &&
		(cat.getX() <= (scissor1.getX() + scissor1.getWidth()) &&
		(cat.getY() + cat.getHeight()) >= scissor1.getY()) &&
		cat.getY() <= (scissor1.getY() + scissor1.getHeight()))
	{
		//playerScore++;
		//scissor1.setY(50 * rand() % 15 + 1);
		//scissor1.setX(0);
		// damage(scissor1)
	}
}

//=============================================================================
// Render game items
//=============================================================================
void Papercat::render()
{
	const int BUF_SIZE = 50;
	static char buffer[BUF_SIZE];
	if (gameStart == 0)
	{
		graphics->spriteBegin();
		menu.draw();							// add the menu to the scene
		startButton.draw();						// add start button to menu scene
		highscoreButton.draw();					// add highscore button to menu scene
		creditsButton.draw();					// add credits button to menu scene
		//nebula.draw();                          // add the orion nebula to the scene
		//ship.draw();                           // add the spaceship to the scene
		graphics->spriteEnd();

		for (int i = 0; i < MAX_ASTEROIDS_NO; i++)//add the asteroids to the scene
		{
			//asteroidList[i].draw();
		}
		if (startButton.getClickedState())
		{
			gameStart = 1;
		}
     	else if (highscoreButton.getClickedState())
		{
			gameStart = 2;			
		}
		else if (creditsButton.getClickedState())
		{
			gameStart = 3;
		}
	}
	else if (gameStart == 1)
	{
		graphics->spriteBegin();
		backgroundStage.draw();
		scissor1.draw();	
		cat.draw();
		for (int i = 0; i < BUFF_NUM; i++)
		{
			items[i].draw();
			items[i].update(frameTime);
		}

		if (minion != nullptr)
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
		mainFont->setFontColor(graphicsNS::WHITE);
		_snprintf_s(buffer, BUF_SIZE, "Score: %d", (int)playerScore);
		mainFont->print(buffer, GAME_WIDTH - 150, 20);

		if (input->wasKeyPressed(VK_ESCAPE)){
			paused = true;
		}
		if (paused)
		{
			pausedFont->setFontColor(graphicsNS::WHITE);
			pausedFont->print("PAUSED\n", GAME_WIDTH/4, 200);
			pausedFont->print("Hit \"Enter\" \nto resume", GAME_WIDTH / 10, 300);
			if (input->wasKeyPressed(VK_RETURN))
				paused = false;
		}


		graphics->spriteEnd();
		//gravity();
		drawing.GetDevice(graphics->get3Ddevice());
		drawing.Line(0, 10 + 50, 100, 10 + 50, 5, true, graphicsNS::WHITE);//starting platform. (10 for holdoff, 50 for the charcter's height(not created yet))

		drawing.Line(0, 10 + 50 + 10 + cat.getHeight(), 500, 10 + 50 + 10 + 100 + cat.getHeight(), 5, true, graphicsNS::WHITE);//platform 1 (500 for the hortizol distance of the platform)

		drawing.Line(GAME_WIDTH - 500, 10 + 50 + 10 + 100 + 100 + 100 + cat.getHeight(), GAME_WIDTH, 10 + 50 + 10 + 100 + 100 + cat.getHeight(), 5, true, graphicsNS::WHITE);//platform 2(100 for holdoff betwe)

		drawing.Line(0, 10 + 50 + 10 + 100 + 100 + 100 + 100 + cat.getHeight(), 500, 10 + 50 + 10 + 100 + 100 + 100 + 100 + 100 + cat.getHeight(), 5, true, graphicsNS::WHITE);//platform 3


	//	blackhole.draw();
	}
	else if (gameStart == 2)
	{
		graphics->spriteBegin();
		backgroundHighscore.draw();
		graphics->spriteEnd();
	}
	else if (gameStart == 3)
	{
		graphics->spriteBegin();
		backgroundCredit.draw();		
		graphics->spriteEnd();
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
	//nebulaTexture.onLostDevice();
	//shipTexture.onLostDevice();
	//asteroidTexture.onLostDevice();

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
	//nebulaTexture.onResetDevice();
	//shipTexture.onResetDevice();
	//asteroidTexture.onResetDevice();
	mainFont->setFontColor(graphicsNS::WHITE);
	Game::resetAll();
	return;
}

void Papercat::gravity()
{

	
	//dot product to get the distance between the two point between the cat and the planet
	//similar to eq d= sqrt(x*x+y*y) whereby d^2 = x^2 + y2
	FLOAT D3DXVec2Dot(const D3DXVECTOR2 *, const D3DXVECTOR2 *);
	D3DXVECTOR2 vectorOfCat = D3DXVECTOR2(cat.getX(), cat.getY());
	D3DXVECTOR2 vectorOfBlackhole = D3DXVECTOR2(blackhole.getX(), blackhole.getY());
	float distanceBetweenCatAndBlackhole = D3DXVec2Dot(&vectorOfCat, &vectorOfBlackhole);
	float velocity = 1000.0f;
	int i = int(velocity + 0.5);
	int j = int(distanceBetweenCatAndBlackhole + 0.5);
	j-=1;
	if (j<= 0 || j == 1)
	{
		j = 1;
	}	
	if (cat.getX()<blackhole.getCenterX())		
	      cat.setX(cat.getX() + (i*i / j));
	else if (cat.getX()>blackhole.getCenterX())
		cat.setX(cat.getX() - (i*i / j));
	//cat.setX(cat.getX() + (velocity*velocity / distanceBetweenCatAndBlackhole));
		//cat.setX(cat.getX() - (velocity*velocity / distanceBetweenCatAndBlackhole));

	if (cat.getY() < blackhole.getCenterY())
		cat.setY(cat.getY() + (i*i / j));		
	else if (cat.getY() > blackhole.getCenterY())
		cat.setY(cat.getY() - (i*i / j));
	//cat.setY(cat.getY() + (velocity*velocity / distanceBetweenCatAndBlackhole));
	//	cat.setY(cat.getY() - (velocity*velocity / distanceBetweenCatAndBlackhole));

}
void Papercat::setYvalue(int randLineNum, int i)
{
	if (randLineNum == 1)
	{
		items[i].setY(items[i].getX()*0.2 + (10 + 50 + 10 + 100 + 100 + 100 + 100 - items[i].getHeight()));
	}
	else if (randLineNum == 2)
	{
		items[i].setY((items[i].getX()*-0.2) + (406 - items[i].getHeight()));
	}
	else
	{
		items[i].setY(items[i].getX()*0.2 + (10 + 50 + 10 - items[i].getHeight()));
	}

}

bool Papercat::collisionWithItem(Items item1,Items item2)
{
	if ((item1.getX() + item1.getWidth()) >= (item2.getX()) &&
		(item1.getX() <= (item2.getX() + item2.getWidth()) &&
		(item1.getY() + item1.getHeight()) >= item2.getY()) &&
		item1.getY() <= (item2.getY() + item2.getHeight()))
		return true;
		return false;
}
void Papercat::setArray(float arrayOfposition[arrayOfNumX])
{
	for (int i = 0; i < arrayOfNumX; i++)
	{
		arrayOfPosition[i] = items[0].getWidth()*i + 0.2f / 2;
	}
}