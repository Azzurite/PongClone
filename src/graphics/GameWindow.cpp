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
#include "SDL_image.h"
#include "SDL_ttf.h"

namespace pong {
namespace graphics {

namespace {
	const char* const cPONG_WINDOW_NAME = "Pong";
}

std::string renderInfoString(SDL_Renderer* renderer)
{
	SDL_RendererInfo info;
	SDL_GetRendererInfo(renderer, &info);

	std::stringstream result;
	result << info.name << " flags: ";

	if (info.flags & SDL_RENDERER_SOFTWARE)
	{
		result << "SDL_RENDERER_SOFTWARE ";
	}
	if (info.flags & SDL_RENDERER_ACCELERATED)
	{
		result << "SDL_RENDERER_ACCELERATED ";
	}
	if (info.flags & SDL_RENDERER_PRESENTVSYNC)
	{
		result << "SDL_RENDERER_PRESENTVSYNC ";
	}
	if (info.flags & SDL_RENDERER_TARGETTEXTURE)
	{
		result << "SDL_RENDERER_TARGETTEXTURE ";
	}

	return result.str();
}

// ====== public: ======

GameWindow::GameWindow()
{
	mainWindow_ = SDL_CreateWindow(cPONG_WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_HIDDEN | SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (mainWindow_ == nullptr) {
		throw std::runtime_error(std::string("Window could not be created: ") + SDL_GetError());
	}

	renderer_ = SDL_CreateRenderer(mainWindow_, -1, 0);
	if (renderer_ == nullptr) {
		throw std::runtime_error(std::string("Renderer could not be created: ") + SDL_GetError());
	}

	SDL_ShowSimpleMessageBox(0, "Info", renderInfoString(renderer_).c_str(), nullptr);
}

GameWindow::GameWindow(const GameWindow&) noexcept = default;

GameWindow::GameWindow(GameWindow&&) noexcept = default;

GameWindow::~GameWindow() noexcept
{
	SDL_DestroyRenderer(renderer_);

	SDL_DestroyWindow(mainWindow_);
}


GameWindow& GameWindow::operator=(const GameWindow&) noexcept = default;

GameWindow& GameWindow::operator=(GameWindow&&) noexcept = default;


void GameWindow::show()
{
	SDL_ShowWindow(mainWindow_);
}

namespace {

auto x = 0;
auto y = 0;

}
void GameWindow::update() {

	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
	SDL_RenderClear(renderer_);



	SDL_RenderPresent(renderer_);
}

// ====== protected: ======

// ====== private: ======


}} // namespace pong::graphics

