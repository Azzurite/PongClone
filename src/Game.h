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

#pragma once

#include <memory>

namespace pong {


namespace graphics {
class GameWindow;
}


class Game final
{
public:

	/**
	* \brief Default constructor.
	*/
	Game();

	/**
	* \brief Default copy constructor, deleted
	*/
	Game(const Game& toCopy) noexcept;

	/**
	* \brief Default move constructor, deleted
	*/
	Game(Game&& toMove) noexcept;

	/**
	* \brief Default destructor.
	*/
	~Game() noexcept;


	/**
	* \brief Default copy assignment operator, deleted
	*/
	Game& operator=(const Game& toCopy) noexcept;

	/**
	* \brief Default move assignment operator, deleted
	*/
	Game& operator=(Game&& toMove) noexcept;

	/**
	* \brief initialize the game
	*/
	void init();

	/**
	* \brief Runs the game.
	*/
	int loop();


private:
	std::unique_ptr<graphics::GameWindow> mainWindow_;

};

} // namespace pong
