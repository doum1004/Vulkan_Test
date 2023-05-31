#include "vk_engine.h"

#include <SDL.h>
#include <SDL_vulkan.h>
#include <SDL_keyboard.h>

#include <vk_types.h>
#include <vk_initializers.h>
#include <iostream>

void VulkanEngine::init()
{
	// We initialize SDL and create a window with it. 
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
	
	_window = SDL_CreateWindow(
		"Vulkan Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		_windowExtent.width,
		_windowExtent.height,
		window_flags
	);
	
	//everything went fine
	_isInitialized = true;
}
void VulkanEngine::cleanup()
{	
	if (_isInitialized) {
		
		SDL_DestroyWindow(_window);
	}
}

void VulkanEngine::draw()
{
	//nothing yet
}

void VulkanEngine::run()
{
	SDL_Event e;
	bool bQuit = false;

	//main loop
	while (!bQuit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type) {
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				handleKeyEvent(&e.key);
				break;
			case SDL_QUIT:
				bQuit = true;
				break;
			}
		}

		draw();
	}
}

void VulkanEngine::handleKeyEvent(SDL_KeyboardEvent* key)
{
	/* Is it a release or a press? */
	if (key->type == SDL_KEYUP)
		printf("Release:- ");
	else
		printf("Press:- ");

	/* Print the hardware scancode first */
	printf("Scancode: 0x%02X", key->keysym.scancode);
	/* Print the name of the key */
	printf(", Name: %s", SDL_GetKeyName(key->keysym.sym));
	/* We want to print the unicode info, but we need to make */
	/* sure its a press event first (remember, release events */
	/* don't have unicode info                                */
	if (key->type == SDL_KEYDOWN) {
		/* If the Unicode value is less than 0x80 then the    */
		/* unicode value can be used to get a printable       */
		/* representation of the key, using (char)unicode.    */
		//printf(", Unicode: ");
		//if (key->keysym.unicode < 0x80 && key->keysym.unicode > 0) {
		//	printf("%c (0x%04X)", (char)key->keysym.unicode,
		//		key->keysym.unicode);
		//}
		//else {
		//	printf("? (0x%04X)", key->keysym.unicode);
		//}
	}
	printf("\n");
	/* Print modifier info */
	PrintModifiers(key->keysym.mod);
}

void VulkanEngine::PrintModifiers(Uint16 mod) {
	printf("Modifers: ");

	/* If there are none then say so and return */
	if (mod == KMOD_NONE) {
		printf("None\n");
		return;
	}

	/* Check for the presence of each SDLMod value */
	/* This looks messy, but there really isn't    */
	/* a clearer way.                              */
	if (mod & KMOD_NUM) printf("NUMLOCK ");
	if (mod & KMOD_CAPS) printf("CAPSLOCK ");
	if (mod & KMOD_LCTRL) printf("LCTRL ");
	if (mod & KMOD_RCTRL) printf("RCTRL ");
	if (mod & KMOD_RSHIFT) printf("RSHIFT ");
	if (mod & KMOD_LSHIFT) printf("LSHIFT ");
	if (mod & KMOD_RALT) printf("RALT ");
	if (mod & KMOD_LALT) printf("LALT ");
	if (mod & KMOD_CTRL) printf("CTRL ");
	if (mod & KMOD_SHIFT) printf("SHIFT ");
	if (mod & KMOD_ALT) printf("ALT ");
	printf("\n");
}