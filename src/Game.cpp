/*! @file
 *
 * @date 19.02.2014
 * @author Azzu
 *
 * @copyright GPL v3
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
#include <chrono>
#include <thread>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL2_framerate.h"

#include "graphics/GameWindow.h"
#include "util/Exceptions.h"
using pong::graphics::GameWindow;

namespace pong {


// ====== public: ======

Game::Game()
{
	if (SDL_Init(cUSED_SDL_SUBSYSTEMS) != 0) {
		throw util::sdlError("Error while initializing SDL2.");
	}

	if (TTF_Init() != 0) {
		throw util::sdlError("Error while initializing SDL_TTF.");
	}

	mainWindow_ = std::make_unique<GameWindow>();
}

Game::Game(const Game& toCopy) noexcept = delete;

Game::Game(Game&& toMove) noexcept = delete;

Game::~Game() noexcept
{
	TTF_Quit();
	SDL_Quit();
}


Game& Game::operator=(const Game& toCopy) noexcept = delete;

Game& Game::operator=(Game&& toMove) noexcept = delete;


int Game::loop()
{
	auto fps = FPSmanager{};
	SDL_initFramerate(&fps);
	SDL_setFramerate(&fps, 120);

	auto x = 0;
	auto quit = false;
	while (!quit) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN) {
				std::cout << "Quit called" << std::endl;
				quit = true;
			}
		}

		if (x++ == 1000) {
			SDL_setFramerate(&fps, 60);
		}
		mainWindow_->update();
		SDL_framerateDelay(&fps);
	}

	return 0;
}


// ====== protected: ======

// ====== private: ======



} // namespace pong
