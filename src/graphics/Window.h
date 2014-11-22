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
 
#pragma once

#include <string>
#include <SDL2/SDL_video.h>

namespace pong {
namespace graphics {

class Window
{
public:

	/**
	 * \brief Default constructor.
	 */
	Window(std::string name);
	
	/**
	 * \brief Default copy constructor.
	 */
	Window(const Window&) noexcept;
		
	/**
	 * \brief Default move constructor.
	 */
	Window(Window&&) noexcept;
	
	/**
	 * \brief Default destructor.
	 */
	~Window() noexcept;
	
	
	/**
	 * \brief Default copy assignment operator.
	 */
	Window& operator=(const Window&) noexcept;
	
	/**
	 * \brief Default move assignment operator.
	 */
	Window& operator=(Window&&) noexcept;
	

protected:

private:

	SDL_Window* window_;
};

}} // namespace pong::graphics
