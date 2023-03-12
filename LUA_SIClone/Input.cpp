/*
Space invaders game
Author:		Philip Alassad
Filename:	Input.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Input class
*/

#include "Input.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
//Constructor
Input::Input()
{
	//initialise keypress array
	for (int i = 0; i < SIZE_OF_KEYS_PRESSED_ENUM; i++)
	{
		m_keysPressed[i] = false;
	}

	// need to create an event queue so allegro can respond to events, such as keypresses
	m_event = al_create_event_queue();

	if (!m_event)
	{
		cout << "Event queue creation failed" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
		al_destroy_event_queue(m_event);
		return;
	}
	

	// register keyboard with the event queue, so keypress events can be processed
	al_register_event_source(m_event, al_get_keyboard_event_source());
}

Input::~Input()
{
	al_destroy_event_queue(m_event);
}

//Methods
void Input::update()
{
//Body of method
	ALLEGRO_EVENT allegro_event;

	// get the next event from the event queue
	bool got_event = al_get_next_event(m_event, &allegro_event);

	if (got_event == false) return; // no event waiting

	// test if a key is pressed down, update global keypress array
	if (allegro_event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (allegro_event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = true;
			break;
		case ALLEGRO_KEY_A:
			m_keysPressed[KEY_A] = true;
			break;

		case ALLEGRO_KEY_D:
			m_keysPressed[KEY_D] = true;
			break;
		case ALLEGRO_KEY_SPACE:
			m_keysPressed[KEY_SPACE] = true;
			break;
		case ALLEGRO_KEY_ENTER:
			m_keysPressed[KEY_ENTER] = true;
			break;
		}
	}
	// Test if a key is let go, update global keypress array
	else if (allegro_event.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (allegro_event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = false;
			break;
		case ALLEGRO_KEY_A:
			m_keysPressed[KEY_A] = false;
			break;
		case ALLEGRO_KEY_D:
			m_keysPressed[KEY_D] = false;
			break;
		case ALLEGRO_KEY_SPACE:
			m_keysPressed[KEY_SPACE] = false;
			break;
		/*case ALLEGRO_KEY_ENTER:
			m_keysPressed[KEY_ENTER] = false;
			break;*/
		}
	}
}

bool Input::key_is_pressed(KEYS_PRESSED_LIST key)
{
	if (!KEY_ESCAPE)
	{
		return m_keysPressed[key];
	}
	else
		return false;

}

void Input::set_key_to_false(KEYS_PRESSED_LIST key)
{
	if (m_keysPressed[key] == true)
	{
		m_keysPressed[key] = false;
	}
}

void Input::set_key_to_true(KEYS_PRESSED_LIST key)
{
		m_keysPressed[key] = true;
}
ALLEGRO_EVENT_QUEUE* Input::Get_event()
{
	return m_event;
}