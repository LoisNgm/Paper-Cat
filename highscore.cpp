
//  Module:             Gameplay Programming
//  Assignment2:		Paper Cat
//  Student Name:       Ngm Hui Min, Lois	| Jessica Tan Hwee Ching	| Pang Jin Xiang
//  Student Number:     S10158786C			| S10156827G				| S10157119D

#include "highscore.h"
//construtor
Highscore::Highscore()
{
	dxFontForScore = new TextDX();
	displaying = true;
	getScores();
}

void Highscore::draw()
{
	backgroundHighscore2.draw();
	dxFontForScore->setFontColor(graphicsNS::WHITE);
	int i = 0;
	dxFontForScore->print("Position", 50, GAME_HEIGHT / 4 + (i * 25));
	dxFontForScore->print("Name", 200, GAME_HEIGHT / 4 + (i * 25));
	dxFontForScore->print("Score", 450, GAME_HEIGHT / 4 + (i * 25));
	while (i<currentNumberOfHighScorers)
	{
		dxFontForScore->print(to_string((i + 1)), 50, GAME_HEIGHT / 4 + ((i + 1) * 25));
		dxFontForScore->print(scoreName[i], 200, GAME_HEIGHT / 4 + ((i + 1) * 25));
		dxFontForScore->print(to_string(highScore[i]), 450, GAME_HEIGHT / 4 + ((i + 1) * 25));
		i++;
	}
}

void Highscore::initialize(Graphics *graphics)
{
	//highscore page when beat highscore
	if (!highscore2Texture.initialize(graphics, BACKGROUND_HIGHSCORE_PAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backround highscore 2 texture"));

	// background highscore 2 image
	if (!backgroundHighscore2.initialize(graphics, 0, 0, 0, &highscore2Texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background stage"));

	//intialize text for highscore page
	if (dxFontForScore->initialize(graphics, 30, true, false, "Calibri") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));
}

void Highscore::getScores()
{
	int lineNum = 0;
	int arrayNum = 0;
	string line = "";
	ifstream myfile("Highscore.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (lineNum % 2 == 0)
			{
				scoreName[lineNum / 2] = line;
				currentNumberOfHighScorers++;
			}
			else
			{
				highScore[arrayNum] = atoi(line.c_str());
				arrayNum++;
			}
			lineNum++;
		}

	}
	myfile.close();
}
void Highscore::setScores(int playerScore,string playerName)
{
	recordingScore(playerScore, playerName);	
	ofstream myfile;
	myfile.open("Highscore.txt");
	int iterate = 0;
	while (iterate<numOfTopScore)
	{
		if (highScore[iterate] != NULL && highScore[iterate] >0)
		{
			myfile << scoreName[iterate] << endl;
			myfile << highScore[iterate] << endl;
		}
		iterate++;
	}
	myfile.close();
}

void Highscore::setDisplayStatus(bool ifDisplaying)
{
	if (ifDisplaying)
	{
		displaying = true;
	}
	else
	{
		displaying = false;
	}
}
bool Highscore::getDisplayStatus()
{
	return displaying;
}

void Highscore::recordingScore(int score, string name)
{

	bool checkHighScore = true;
	int i = 0;
	string n = name;

	while (checkHighScore)
	{
		//if score is not the first one recorded(means text file not empty)
		if (highScore[i] != NULL)
		{
			if (score >= highScore[i])
			{
				for (int j = 10; j < i; j--)
				{
					if (highScore[j - 1] != NULL&& highScore[j - 1] > 0)
					{
						scoreName[j - 1] = scoreName[j];
						highScore[j - 1] = highScore[j];
					}
				}
				scoreName[i] = n;
				highScore[i] = score;
				checkHighScore = false;
			}
		}
		else
		{
			scoreName[i] = n;
			highScore[i] = score;
			checkHighScore = false;
		}
		if (i > 10)
		{
			checkHighScore = false;
		}
		i++;
	}
}
bool Highscore::checkingScore(int score)
{
	for (int i = 0; i < currentNumberOfHighScorers;i++)
	{
		if (highScore[i] != NULL)
		{
			if (score >= highScore[i])
			{
				return true;
			}
		}
		else
		{
			return true;
		}
		if (i > 9)
		{
			return false;
		}
	}
}