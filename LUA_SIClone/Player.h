/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Player class
*/

#pragma once

//includes go here
#include "Ship.h"
#include "Helper.h"

using namespace std;

class Player: public Ship
{
private:
	//members
	int m_lives;
	int m_score;
	lua_State* L;
public:
	//constructor
	Player( float xPos, float yPos, int lives, string filename)
		:Ship(xPos, yPos, filename)//week 3
	{
		m_lives = lives;
		m_score = 0;

		 L = luaL_newstate();

		//open main libraries for scripts
		luaL_openlibs(L);

		//Load and parse the Lua file
		//note - you culd press a key to reload and execute this script file at run time
		//just close the state, then ru nthis dofile line again
		if (!LuaOK(L, luaL_dofile(L, "LuaScript.lua")))
			assert(false);



		
	}
	~Player(void);


	//methods
	void reduceLives();
	void increaseLives();
	void setScore(int score);
	int getLives();
	int getScore();
	void kill();
	void reset_lives();
	void reset_score();
	void left();
	void right();
};