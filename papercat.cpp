
#include "papercat.h"

//=============================================================================
// Constructor
//=============================================================================
Papercat::Papercat()
{}

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
	Game::initialize(hwnd); // throws GameError

	// menu texture
	if (!menuTexture.initialize(graphics, MENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// background stage texture
	if (!backgroundStageTexture.initialize(graphics, BACKGROUND_STAGE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround stage texture"));
	//buttons
	if (!buttonsTexture.initialize(graphics, BUTTONS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing button texture"));

	// main textures
	if (!mainTexture.initialize(graphics, ELEMENTS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main texture"));

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
	scissor1.setX(50);
	scissor1.setY(100);
	scissor1.setVisible(0);

	// cat
	if (!cat.initialize(this, mainCharNS::WIDTH, mainCharNS::HEIGHT, mainCharNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing cat"));
	cat.setFrames(mainCharNS::CAT_START_FRAME, mainCharNS::CAT_END_FRAME);
	cat.setCurrentFrame(mainCharNS::CAT_START_FRAME);
	cat.setX(50);
	cat.setY(100);
	
	//blackhole
	if (!blackhole.initialize(this, blackholeNS::WIDTH, blackholeNS::HEIGHT, blackholeNS::TEXTURE_COLS, &mainTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing blackhole"));
	blackhole.setFrames(blackholeNS::BLACKHOLE_START_FRAME, blackholeNS::BLACKHOLE_END_FRAME);
	blackhole.setCurrentFrame(blackholeNS::BLACKHOLE_START_FRAME);
	blackhole.setX(GAME_WIDTH/2);
	blackhole.setY(GAME_HEIGHT/2);
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

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Papercat::update()
{
	startButton.update(frameTime);
	//ship.update(frameTime);
	if (gameStart == 1)
	{
		cat.update(frameTime);
		cat.setVelocityY(cat.getVelocityY() + 2.5f);
	}
	
	for (int i = 0; i < MAX_ASTEROIDS_NO; i++)
	{
		//asteroidList[i].update(frameTime);
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
		// damage(scissor1)
	}
}

//=============================================================================
// Render game items
//=============================================================================
void Papercat::render()
{
	
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
	//	if (input->wasKeyPressed(VK_RETURN))
		if (startButton.getClickedState())
		{
			gameStart = 1;
		}
	}
	else if (gameStart == 1)
	{
		graphics->spriteBegin();
		backgroundStage.draw();
		scissor1.draw();	
		cat.draw();
		graphics->spriteEnd();
		//gravity();
		drawing.GetDevice(graphics->get3Ddevice());
		drawing.Line(0, 10 + 50, 100, 10 + 50, 5, true, graphicsNS::WHITE);//starting platform. (10 for holdoff, 50 for the charcter's height(not created yet))

		drawing.Line(0, 10 + 50 + 10, 500, 10 + 50 + 10 + 100, 5, true, graphicsNS::WHITE);//platform 1 (500 for the hortizol distance of the platform)

		drawing.Line(GAME_WIDTH - 500, 10 + 50 + 10 + 100 + 100 + 100, GAME_WIDTH, 10 + 50 + 10 + 100 + 100, 5, true, graphicsNS::WHITE);//platform 2(100 for holdoff betwe)

		drawing.Line(0, 10 + 50 + 10 + 100 + 100 + 100 + 100, 500, 10 + 50 + 10 + 100 + 100 + 100 + 100 + 100, 5, true, graphicsNS::WHITE);//platform 3


	//	blackhole.draw();
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