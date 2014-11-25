/** @file
 *
 * \date 16.11.2014
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

#include <memory>
#include <string>

#include "SDL.h"

namespace pong {
namespace graphics {

class Surface final
{
public:

	using SDLSurfaceUPtr = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;

	/**
	 * @brief Default constructor.
	 */
	Surface(std::string fileName) noexcept;
	
	/**
	 * @brief Default copy constructor.
	 */
	Surface(const Surface&) noexcept;
		
	/**
	 * @brief Default move constructor.
	 */
	Surface(Surface&&) noexcept;
	
	/**
	 * @brief Default destructor.
	 */
	~Surface() noexcept;
	
	
	/**
	 * @brief Default copy assignment operator.
	 */
	Surface& operator=(const Surface&) noexcept;
	
	/**
	 * @brief Default move assignment operator.
	 */
	Surface& operator=(Surface&&) noexcept;

	operator SDL_Surface&() { return *surface_; }

	operator SDL_Surface&() const { return *surface_; }




protected:

private:

	SDLSurfaceUPtr surface_;

};

}} // namespace pong::graphics
