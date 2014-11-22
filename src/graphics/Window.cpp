/** \file
 *
 * \date 21.11.2014
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

#include "graphics/Window.h"

#include <stdexcept>

#include "SDL.h"

namespace pong {
namespace graphics {

// ====== public: ======

Window::Window(std::string name)
{
	window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_HIDDEN | SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (window_ == nullptr) {
		throw std::runtime_error(std::string("Window could not be created: ") + SDL_GetError());
	}
}

Window::Window(const Window&) noexcept = default;

Window::Window(Window&&) noexcept = default;

Window::~Window() noexcept = default;

Window& Window::operator=(const Window&) noexcept = default;

Window& Window::operator=(Window&&) noexcept = default;

// ====== protected: ======

// ====== private: ======


}} // namespace pong::graphics
