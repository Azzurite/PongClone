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

#include <graphics/GameWindow.h>

#include <windows.h>
#include <SDL2/SDL.h>

namespace pong {
namespace graphics {

namespace {
	const char* const cPONG_WINDOW_NAME = "Pong";
}

GameWindow::GameWindow() {
	LoadLibrary("SDL2.dll");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		throw "SDL_INIT_ERROR";
	}

	mainWindow = SDL_CreateWindow(cPONG_WINDOW_NAME, 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	if (mainWindow == nullptr) {
		throw "Window could not be created.";
	}
}

GameWindow::GameWindow(const GameWindow&) noexcept = default;

GameWindow::GameWindow(GameWindow&&) noexcept = default;

GameWindow::~GameWindow() noexcept = default;

GameWindow& GameWindow::operator=(const GameWindow&) noexcept = default;

GameWindow& GameWindow::operator=(GameWindow&&) noexcept = default;

} /* namespace graphics */
} /* namespace pong */
