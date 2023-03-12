/*
Space invaders game
Author:		Philip Alassad
Filename:	laser.cpp
Date:		23/10/2015
Last Updated:	__/__/____

Description: Source file for laser class
*/

#include "laser.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>


laser::laser(int xpos, int ypos, string filename)
{
	m_xpos = xpos;
	m_ypos = ypos;

	m_laser = al_load_bitmap(filename.c_str());
	al_convert_mask_to_alpha(m_laser, al_map_rgb(255, 0, 255));

	if (!m_laser)//error check
	{
		cout << filename.c_str() << " bitmap creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_bitmap(m_laser);
		exit(-1);
	}
}

laser::~laser()
{
	al_destroy_bitmap(m_laser);
}


//methods
void laser::up(void)
{
	m_ypos -= 10;
}

void laser::down(void)
{
	m_ypos += 4;
}

//set and get methods
void laser::setX(int xVal)
{
	m_xpos = xVal;
}

void laser::setY(int yVal)
{
	m_ypos = yVal;
}

int laser::getX()
{
  	return m_xpos;
}

int laser::getY()
{
	return m_ypos;
}

void laser::draw(void)
{
	al_draw_bitmap(m_laser, m_xpos, m_ypos, 0);
}