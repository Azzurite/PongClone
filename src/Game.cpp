/** \file
 *
 * \date 19.02.2014
 * \author Azzu
 *
 * \copyright GPL v3
 * Copyright (C) 2014 Azzu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Game.h"

#include <stdexcept>
#include <iostream>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "graphics/GameWindow.h"
using pong::graphics::GameWindow;

namespace pong {

namespace {
constexpr unsigned cUSED_SDL_SUBSYSTEMS = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS;
}

// ====== public: ======

Game::Game() = default;

Game::Game(const Game& toCopy) noexcept = delete;

Game::Game(Game&& toMove) noexcept = delete;

Game::~Game() noexcept = default;


Game& Game::operator=(const Game& toCopy) noexcept = delete;

Game& Game::operator=(Game&& toMove) noexcept = delete;


void printEvent(const SDL_Event * event)
{
	if (event->type == SDL_WINDOWEVENT) {
		switch (event->window.event) {
			case SDL_WINDOWEVENT_SHOWN:
				SDL_Log("Window %d shown", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				SDL_Log("Window %d hidden", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_EXPOSED:
				SDL_Log("Window %d exposed", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_MOVED:
				SDL_Log("Window %d moved to %d,%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_Log("Window %d resized to %dx%d",
						event->window.windowID, event->window.data1,
						event->window.data2);
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				SDL_Log("Window %d minimized", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				SDL_Log("Window %d maximized", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_RESTORED:
				SDL_Log("Window %d restored", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_ENTER:
				SDL_Log("Mouse entered window %d",
						event->window.windowID);
				break;
			case SDL_WINDOWEVENT_LEAVE:
				SDL_Log("Mouse left window %d", event->window.windowID);
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				SDL_Log("Window %d gained keyboard focus",
						event->window.windowID);
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				SDL_Log("Window %d lost keyboard focus",
						event->window.windowID);
				break;
			case SDL_WINDOWEVENT_CLOSE:
				SDL_Log("Window %d closed", event->window.windowID);
				break;
			default:
				SDL_Log("Window %d got unknown event %d",
						event->window.windowID, event->window.event);
				break;
		}
	}
}

void Game::init() {
	if (SDL_Init(cUSED_SDL_SUBSYSTEMS) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}

	if (TTF_Init() != 0)
	{
		throw std::runtime_error(TTF_GetError());
	}

	mainWindow_ = std::make_unique<GameWindow>();
	mainWindow_->show();
}

int Game::loop()
{
	auto i = 0;
	auto quit = false;
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				std::cout << "Quit called" << std::endl;
				quit = true;
			}
			printEvent(&e);
		}


		mainWindow_->update();
//		SDL_Delay(10);
		std::cout << i << '\n';
		if ((i % 1000) == 0) {
			std::cout << std::endl;
		}
		if (++i == 20000) quit = true;
	}


	std::cout << std::endl;
	SDL_Quit();
	return 0;
}


// ====== protected: ======

// ====== private: ======



} // namespace pong
