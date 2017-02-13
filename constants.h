// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 constants.h v1.0

//  Module:             Gameplay Programming
//  Assignment2:		Paper cat the hero
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }

#define TRANSCOLOR  SETCOLOR_ARGB(0,255,170,255)  // transparent color (light magenta)


//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Paper Cat The Hero";
const char GAME_TITLE[] = "Paper Cat The Hero";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 680;               // width of game in pixels
const UINT GAME_HEIGHT = 768;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 6.67428e-11f;             // gravitational constant
const float MASS_PLANET = 1.0e14f;
const float MASS_SHIP = 5.0f;

// graphic images
const char ELEMENTS_IMAGE[] = "pictures\\paper_cat_textures.png";	//cat, enemy, coin, scissors, state, slime pricness/king, black hole
const char MENU_IMAGE[] = "pictures\\menu.png";
const char BACKGROUND_STAGE_PAGE_IMAGE[] = "pictures\\background1.png";
const char BACKGROUND_STAGE2_PAGE_IMAGE[] = "pictures\\background2.png";
const char BACKGROUND_HIGHSCORE_PAGE_IMAGE[] = "pictures\\Highscore_Page.png";
const char BACKGROUND_HIGHSCORE_PAGE2_IMAGE[] = "pictures\\HighscoreLog.png";
const char BACKGROUND_CREDIT_PAGE_IMAGE[] = "pictures\\Credit_Page.png";
const char BACKGROUND_TUTORIAL_PAGE_IMAGE[] = "pictures\\tutorial.png";
const char BUTTONS_IMAGE[] = "pictures\\buttons.png";
const char ITEMS_IMAGE[] = "pictures\\runes.png";
const char RAINBOW_IMAGE[] = "pictures\\rainbow.png";
const UINT NUMBER_OF_COINS = 37;
const UINT NUMBER_OF_STARS = 4;
const UINT arrayOfNumX = 21;
const UINT numOfTopScore = 10;
const UINT STUNNEDTIME = 10;
const UINT FLASHTIME = 70;


// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY = VK_MENU;         // Alt key
const UCHAR ENTER_KEY = VK_RETURN;       // Enter key
const UINT BUFF_NUM = 4;

#endif
