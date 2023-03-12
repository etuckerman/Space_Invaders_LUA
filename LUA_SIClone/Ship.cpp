/*
Space invaders game
Author:		Philip Alassad
Filename:	Ship.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Ship class
*/

#include "Ship.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>


//Constructor
Ship::Ship( int xpos, int ypos, string filename)
{
	m_xpos = xpos;
	m_ypos = ypos;
	m_direction_flag = true;
	m_current_frame = 0;

	ALLEGRO_BITMAP* new_bitmap = NULL;
	new_bitmap = al_load_bitmap(filename.c_str());
	al_convert_mask_to_alpha(new_bitmap, al_map_rgb(255, 0, 255));

	if (!new_bitmap)//error check
	{
		cout << filename.c_str() << " bitmap creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_bitmap(new_bitmap);
		exit(-1);
	}
	m_ship_images.push_back(new_bitmap);
}

Ship::~Ship()
{
	for (int i = 0; i < 2; i++)//change the less than bit for more or less images
	{
		if(m_ship_images[i] != NULL)al_destroy_bitmap(m_ship_images[i]);
	}
	m_ship_images.clear();
}

//Methods

void Ship::left(void)
{
	m_direction_flag = false;
	m_current_frame = m_current_frame + 0.1f;
	m_xpos = m_xpos-5;
	if (m_xpos <= -5) m_xpos = -5;
	if (m_current_frame > 1.9)
		m_current_frame = 0;
}

void Ship::right(void)
{
	m_xpos = m_xpos+5;
	if (m_xpos >= 910) m_xpos = 910;
	if (m_current_frame > 1.9)
		m_current_frame = 0;
}

void Ship::down(void)
{
	m_current_frame++;
	m_ypos += 10;
	if (m_current_frame > 1.9)
		m_current_frame = 0;
}

//set and get methods
void Ship::setX(int xVal)
{
 	m_xpos = xVal;
}

void Ship::setY(int yVal)
{
	m_ypos = yVal;
}

int Ship::getX()
{
	return m_xpos;
}

int Ship::getY()
{
	return m_ypos;
}

void Ship::draw(void)
{
	if (m_direction_flag)
	{
		al_draw_bitmap(m_ship_images[m_current_frame], m_xpos, m_ypos, 0);
	}
	else
		al_draw_bitmap(m_ship_images[m_current_frame], m_xpos, m_ypos, 1);

}

void Ship::addFrame(string filename)
{
	ALLEGRO_BITMAP* new_bitmap = NULL;
	new_bitmap = al_load_bitmap(filename.c_str());
	al_convert_mask_to_alpha(new_bitmap, al_map_rgb(255, 0, 255));
	//m_width = al_get_bitmap_width(new_bitmap);
	//m_height = al_get_bitmap_height(new_bitmap);
	if (!new_bitmap)//error check
	{
		cout << filename.c_str() << " bitmap creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		new_bitmap = nullptr;
		//al_destroy_bitmap(m_creature_image);
		exit(-1);
		//return ;
	}
	m_ship_images.push_back(new_bitmap);
}

