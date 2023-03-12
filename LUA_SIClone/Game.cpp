/*
Space invaders game
Author:		Philip Alassad
Filename:	Game.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Game class
*/

#include "Game.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include "Input.h"



//Constructor
Game::Game()
{
	if (!al_init())
	{
		cout << "Allegro initialisation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		return;
	}

	// tell allegro program needs keyboard input
	if (!al_install_keyboard())
	{
		cout << "Keyboard initialisation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		return;
	}

	m_display = al_create_display(1000, 700); // create a display window of size 1000 by 700

	if (!m_display)
	{
		cout << "Display initialisation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_display(m_display);
		return;
	}

	al_set_window_position(m_display, 250, 20); // position display window on screen


	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();  // initialize the True Type Font addon

	m_LargeMessage = al_load_ttf_font("assets/DejaVuSans.ttf", 70, 0);
	if (!m_LargeMessage)
	{
		cout << "Large text creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_font(m_LargeMessage);
		return;
	}

	m_SmallMessage = al_load_ttf_font("assets/DejaVuSans.ttf", 20, 0);
	if (!m_SmallMessage)
	{
		cout << "Small text display creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_font(m_SmallMessage);
		return;
	}

	al_init_image_addon(); // initialise allegro image loading 
	Input* Input_manager = new Input();

	// register  display with the event queue, so display change events can be processed
	al_register_event_source(Input_manager->Get_event(), al_get_display_event_source(m_display));
}

Game::~Game()
{
	al_destroy_font(m_LargeMessage);
	al_destroy_font(m_SmallMessage);
}

//Methods
ALLEGRO_FONT* Game::message()
{
	return m_LargeMessage;
}

ALLEGRO_FONT* Game::small_message()
{
	return m_SmallMessage;
}

