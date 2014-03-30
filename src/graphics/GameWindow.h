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

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "SDL.h"

namespace pong {
namespace graphics {

class GameWindow {
public:
	/**
	 * \brief Default constructor.
	 */
	GameWindow();

	/**
	 * \brief Default copy constructor.
	 */
	GameWindow(const GameWindow&) noexcept;

	/**
	 * \brief Default move constructor.
	 */
	GameWindow(GameWindow&&) noexcept;

	/**
	 * \brief Default destructor.
	 */
	~GameWindow() noexcept;

	/**
	 * \brief Default copy assignment operator.
	 */
	GameWindow& operator=(const GameWindow&) noexcept;

	/**
	 * \brief Default move assignment operator.
	 */
	GameWindow& operator=(GameWindow&&) noexcept;

private:
	SDL_Window* mainWindow = nullptr;

	SDL_Renderer* renderer = nullptr;
};

} /* namespace graphics */
} /* namespace pong */
#endif /* GAMEWINDOW_H_ */
