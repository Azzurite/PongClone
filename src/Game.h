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

#include "graphics/GameWindow.h"

namespace pong {

class Game
{
public:
	// region ===== Aliases =====
	// endregion ===== Aliases =====

	// region ===== Constants =====
	// endregion ===== Constants =====

	// region ===== (De- &) Constructors =====

	/**
	* \brief Default constructor.
	*/
	Game() noexcept;

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

	// endregion ===== (De- &) Constructors =====

	// region ===== Operators =====

	/**
	* \brief Default copy assignment operator, deleted
	*/
	Game& operator=(const Game& toCopy) noexcept;

	/**
	* \brief Default move assignment operator, deleted
	*/
	Game& operator=(Game&& toMove) noexcept;

	// endregion ===== Operators =====

	// region ===== Methods =====

	/**
	* \brief Runs the game.
	*/
	int run();

	// endregion ===== Methods =====

	// region ===== Members =====
	// endregion ===== Members =====

private:
	// region ===== Aliases =====
	// endregion ===== Aliases =====

	// region ===== Constants =====
	// endregion ===== Constants =====

	// region ===== (De- &) Constructors =====
	// endregion ===== (De- &) Constructors =====

	// region ===== Operators =====
	// endregion ===== Operators =====

	// region ===== Methods =====

	/**
	* \brief initialize the game
	*/
	void init();

	// endregion ===== Methods =====

	// region ===== Members =====
	// endregion ===== Members =====

};

} // namespace pong
