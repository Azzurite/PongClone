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

#include <string>
#include <sstream>
#include <stdexcept>
#include "SDL.h"

namespace pong {
namespace graphics {

// public:

// region ===== Aliases =====
// endregion ===== Aliases =====

// region ===== Constants =====
namespace {
	const char* const cPONG_WINDOW_NAME = "Pong";
}
// endregion ===== Constants =====

// region ===== (De- &) Constructors =====

GameWindow::GameWindow()
{
	mainWindow = SDL_CreateWindow(cPONG_WINDOW_NAME, 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	if (mainWindow == nullptr) {
		throw std::runtime_error(std::string{"Window could not be created:"} + SDL_GetError());
	}

	renderer = SDL_CreateRenderer(mainWindow, -1, 0);
	if (renderer == nullptr) {
		throw std::runtime_error(std::string{"Renderer could not be created: "} + SDL_GetError());
	}

	SDL_Surface* momoSurf = SDL_LoadBMP("C:\\programming\\data\\test\\momo.bmp");
	if (momoSurf == nullptr) {
		throw std::runtime_error(std::string{"Error loading BMP with RWops: "} + SDL_GetError());
	}

	SDL_Texture *momoTex = SDL_CreateTextureFromSurface(renderer, momoSurf);
	if (momoTex == nullptr) {
		throw std::runtime_error(std::string{"Error creating texture from surface: "} + SDL_GetError());
	}

	SDL_Rect srcRec{0,
			0,
			momoSurf->w,
			momoSurf->h};

	SDL_Rect destRec{1024 / 2 - momoSurf->w / 2,
			768 / 2 - momoSurf->h / 2,
			momoSurf->w,
			momoSurf->h};

	SDL_RenderCopy(renderer, momoTex, &srcRec, &destRec);
	SDL_RenderPresent(renderer);

	int w;
	int h;

	SDL_GetRendererOutputSize(renderer, &w, &h);

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
			"target correct?",
			(std::to_string(w) + " " + std::to_string(h)).c_str(),
			nullptr);

	SDL_FreeSurface(momoSurf);
}

GameWindow::GameWindow(const GameWindow&) noexcept = default;

GameWindow::GameWindow(GameWindow&&) noexcept = default;

GameWindow::~GameWindow() noexcept
{
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(mainWindow);
}

// endregion ===== (De- &) Constructors =====

// region ===== Operators =====

GameWindow& GameWindow::operator=(const GameWindow&) noexcept = default;

GameWindow& GameWindow::operator=(GameWindow&&) noexcept = default;

// endregion ===== Operators =====

// region ===== Methods =====
// endregion ===== Methods =====

// region ===== Members =====
// endregion ===== Members =====


}} // namespace pong::graphics

