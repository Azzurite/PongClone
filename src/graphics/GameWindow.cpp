/** \file
 *
 * \date 19.02.2014
 * \author Azzu
 *
 * \copyright GPL v3
 *   Copyright (C) 2014 Azzu
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "graphics/GameWindow.h"

#include <windows.h>
#include <string>
#include <stdexcept>
#include "SDL.h"

namespace pong {
namespace graphics {

namespace {
	const char* const cPONG_WINDOW_NAME = "Pong";
}

GameWindow::GameWindow() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		throw std::runtime_error("SDL_INIT_ERROR");
	}

	mainWindow = SDL_CreateWindow(cPONG_WINDOW_NAME, 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	if (mainWindow == nullptr) {
		throw std::runtime_error("Window could not be created.");
	}

	renderer = SDL_CreateRenderer(mainWindow, -1, 0);
	if (renderer == nullptr) {
		throw std::runtime_error{"Renderer could not be created."};
	}

	SDL_Surface* momoSurf = SDL_LoadBMP("E:\\programming\\test\\files\\momo.bmp");
	if (momoSurf == nullptr) {
		throw std::runtime_error(std::string("Error loading BMP with RWops: ") + std::string(SDL_GetError()));
	}

	SDL_Texture *momoTex = SDL_CreateTextureFromSurface(renderer, momoSurf);
	if (momoTex == nullptr) {
		throw std::runtime_error(std::string("Error creating texture from surface: ") + std::string(SDL_GetError()));
	}

	SDL_Rect srcRec;
	srcRec.x = 0;
	srcRec.y = 0;
	srcRec.w = momoSurf->w;
	srcRec.h = momoSurf->h;

	SDL_Rect destRec;
	destRec.x = 1024 / 2 - momoSurf->w / 2;
	destRec.y = 768 / 2 - momoSurf->h / 2;
	destRec.w = momoSurf->w;
	destRec.h = momoSurf->h;


	SDL_RenderCopy(renderer, momoTex, &srcRec, &destRec);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(momoSurf);
}

GameWindow::GameWindow(const GameWindow&) noexcept = default;

GameWindow::GameWindow(GameWindow&&) noexcept = default;

GameWindow::~GameWindow() noexcept = default;

GameWindow& GameWindow::operator=(const GameWindow&) noexcept = default;

GameWindow& GameWindow::operator=(GameWindow&&) noexcept = default;

} /* namespace graphics */
} /* namespace pong */
