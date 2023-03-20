/*
Space invaders game
Author:		Philip Alassad
Filename:	Ufo.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Ufo class
*/

#pragma once

//includes go here
#include "Ship.h"
//#include "Helper.h"

using namespace std;

class Ufo : public Ship
{
private:	
	lua_State* L;

public:
	//constructor
	Ufo( float xPos, float yPos, string filename)
		:Ship(xPos, yPos, filename)
	{
		L = luaL_newstate();

		//open main libraries for scripts
		luaL_openlibs(L);

		//Load and parse the Lua file
		//note - you culd press a key to reload and execute this script file at run time
		//just close the state, then ru nthis dofile line again
		if (!LuaOK(L, luaL_dofile(L, "LuaScript.lua")))
			assert(false);
	}
	~Ufo(void);
	//methods
	//void left(int counter, int level);
	void left(int counter, int level);
	//void right(int counter, int level);
	void right(int counter, int level);

};