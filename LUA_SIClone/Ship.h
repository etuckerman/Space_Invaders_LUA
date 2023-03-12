/*
Space invaders game
Author:		Philip Alassad
Filename:	Ship.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Ship class
*/

#pragma once

//includes go here
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "Game.h"
#include <vector>

using namespace std;

class Ship 
{
protected:
	//members
	float m_xpos;
	float m_ypos;
	vector<ALLEGRO_BITMAP*> m_ship_images;
	float m_current_frame;
	float m_direction_flag;

public:
	//constructor
	Ship( int xpos, int ypos, string filename);
	~Ship();

	//methods
	void setX(int xVal);
	void setY(int yVal);
	int getX();
	int getY();
	void left();
	void right();
	void down();
	void draw(void);
	void addFrame(string filename);
};