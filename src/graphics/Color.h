/** \file
 *
 * \date 19.11.2014
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
 
#pragma once

#include "SDL.h"

namespace pong {
namespace graphics {

class Color final
{
public:

	/**
	 * \brief Pure black.
	 */
	Color() noexcept;

	/**
	 * \brief Creates the specified color
	 * \param red 0-255
	 * \param green 0-255
	 * \param blue 0-255
	 * \param alpha 0-255, 0 = transparent, 255 = solid
	 */
	Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255) noexcept;

	/**
	 * \brief Default copy constructor.
	 */
	Color(const Color&) noexcept;
		
	/**
	 * \brief Default move constructor.
	 */
	Color(Color&&) noexcept;
	
	/**
	 * \brief Default destructor.
	 */
	~Color() noexcept;
	
	
	/**
	 * \brief Default copy assignment operator.
	 */
	Color& operator=(const Color&) noexcept;
	
	/**
	 * \brief Default move assignment operator.
	 */
	Color& operator=(Color&&) noexcept;
	

protected:

private:

	SDL_Color color_;

};

}} // namespace pong::graphics
