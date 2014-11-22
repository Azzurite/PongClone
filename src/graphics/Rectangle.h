/** \file
 *
 * \date 18.11.2014
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

#include "graphics/Renderable.h"
#include "graphics/Color.h"

namespace pong {
namespace graphics {

class Renderer;

class Rectangle final : public Renderable
{
public:

	/**
	 * \brief Creates a new rectangle
	 * \param x location from upper left corner in x direction
	 * \param y location from upper left corner in y direction
	 * \param w width of the rectangle
	 * \param h height of the rectangle
	 */
	Rectangle(int x, int y, int w, int h) noexcept;

	/**
	 * \brief Creates a new rectangle
	 * \param x location from upper left corner in x direction
	 * \param y location from upper left corner in y direction
	 * \param w width of the rectangle
	 * \param h height of the rectangle
	 * \param color the color of the rectangle
	 */
	Rectangle(int x, int y, int w, int h, Color color) noexcept;

	/**
	* \brief Creates a new rectangle
	* \param x location from upper left corner in x direction
	* \param y location from upper left corner in y direction
	* \param w width of the rectangle
	* \param h height of the rectangle
	* \param isFilled if the rectangle should be filled with the color or only an outline should be drawn
	*/
	Rectangle(int x, int y, int w, int h, bool isFilled) noexcept;

	/**
	* \brief Creates a new rectangle
	* \param x location from upper left corner in x direction
	* \param y location from upper left corner in y direction
	* \param w width of the rectangle
	* \param h height of the rectangle
	* \param color the color of the rectangle
	* \param isFilled if the rectangle should be filled with the color or only an outline should be drawn
	*/
	Rectangle(int x, int y, int w, int h, Color color, bool isFilled) noexcept;

	/**
	 * \brief Default copy constructor.
	 */
	Rectangle(const Rectangle&) noexcept;
		
	/**
	 * \brief Default move constructor.
	 */
	Rectangle(Rectangle&&) noexcept;
	
	/**
	 * \brief Default destructor.
	 */
	virtual ~Rectangle() noexcept;
	
	
	/**
	 * \brief Default copy assignment operator.
	 */
	Rectangle& operator=(const Rectangle&) noexcept;
	
	/**
	 * \brief Default move assignment operator.
	 */
	Rectangle& operator=(Rectangle&&) noexcept;

	virtual void render(Renderer&) override;

protected:

private:

	SDL_Rect rectangle_;

	Color color_;

	bool isFilled_;

};

}} // namespace pong::graphics
