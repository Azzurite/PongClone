/*! @file
*
* @date 16.11.2014
* @author Azzu
*
* @copyright GPL v3
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

#pragma once

#include "gamestate/GameState.h"

namespace pong {
namespace gamestate {


class MainMenu : public GameState
{
public:
	/*!
	* @brief Default constructor.
	*/
	MainMenu() noexcept;

	/*!
	* @brief Default copy constructor.
	*/
	MainMenu(const MainMenu&) noexcept;

	/*!
	* @brief Default move constructor.
	*/
	MainMenu(MainMenu&&) noexcept;

	/*!
	* @brief Default destructor.
	*/
	virtual ~MainMenu() noexcept;

	/*!
	* @brief Default copy assignment operator.
	*/
	MainMenu& operator=(const MainMenu&) noexcept;

	/*!
	* @brief Default move assignment operator.
	*/
	MainMenu& operator=(MainMenu&&) noexcept;

protected:

	virtual void renderImpl(const pong::graphics::Renderer&) const override;

private:

};

} // namespace gamestate
} // namespace pong
