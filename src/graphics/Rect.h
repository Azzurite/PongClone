/** \file
 *
 * \date 07.12.2014
 * \author Azzurite
 *
 * \copyright GPL v3
 *   Copyright (C) 2014 Azzurite
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

#include "graphics/Point.h"
#include "graphics/Dimension.h"
#include "graphics/Color.h"

namespace pong {
namespace graphics {


class Rect
{
public:

	constexpr Rect() noexcept : Rect(Point{}, Dimension{}) {}

	/**
	* @brief Creates a new filled rectangle with color black
	* @param topLeft the top left point of the rectangle
	* @param dim the dimensions of the rectangle
	*/
	constexpr Rect(Point topLeft, Dimension dim) noexcept : Rect(topLeft, dim, Color{}) {}

	/**
	* @brief Creates a new filled rectangle
	* @param topLeft the top left point of the rectangle
	* @param dim the dimensions of the rectangle
	* @param color the color of the rectangle
	*/
	constexpr Rect(Point topLeft, Dimension dim, Color color) noexcept
			: Rect(topLeft, dim, color, true) {}

	/**
	* @brief Creates a new rectangle with color black
	* @param topLeft the top left point of the rectangle
	* @param dim the dimensions of the rectangle
	* @param isFilled if the rectangle should be filled with the color or only an outline should be drawn
	*/
	constexpr Rect(Point topLeft, Dimension dim, bool isFilled) noexcept
			: Rect(topLeft, dim, Color{}, isFilled) {}

	/**
	* @brief Creates a new rectangle
	* @param topLeft the top left point of the rectangle
	* @param dim the dimensions of the rectangle
	* @param color the color of the rectangle
	* @param isFilled if the rectangle should be filled with the color or only an outline should be drawn
	*/
	constexpr Rect(Point topLeft, Dimension dim, Color color, bool isFilled) noexcept
			: Rect(SDL_Rect{topLeft.x(), topLeft.y(), dim.width(), dim.height()}, color, isFilled) {}

	/**
	* @brief Construct a filled Rect from SDL_Rect with color black
	* @param sdlRect an SDL_Rect
	*/
	constexpr explicit Rect(SDL_Rect sdlRect) noexcept : Rect(sdlRect, Color{}, true) {}

	/**
	* @brief Default constructor.
	*/
	constexpr explicit Rect(SDL_Rect sdlRect, Color color, bool isFilled) noexcept
			: sdlRect_(sdlRect), color_(color), isFilled_(isFilled) {}
	
	/**
	 * @brief Default copy constructor.
	 */
	constexpr Rect(const Rect&) noexcept = default;
		
	/**
	 * @brief Default move constructor.
	 */
	constexpr Rect(Rect&&) noexcept = default;
	
	/**
	 * @brief Default destructor.
	 */
	~Rect() noexcept = default;
	
	
	/**
	 * @brief Default copy assignment operator.
	 */
	Rect& operator=(const Rect&) noexcept;
	
	/**
	 * @brief Default move assignment operator.
	 */
	Rect& operator=(Rect&&) noexcept;

	constexpr operator SDL_Rect() const { return sdlRect_; }

	constexpr Color color() const { return color_; }

	constexpr const SDL_Rect& getSDLRectangle() const { return sdlRect_; }

	constexpr bool isFilled() const { return isFilled_; }

protected:

private:

	SDL_Rect sdlRect_;
	Color color_;
	bool isFilled_;
};

constexpr bool operator==(const SDL_Rect& lhs, const SDL_Rect& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.w == rhs.w && lhs.h == rhs.h;
}

constexpr bool operator==(const Rect& lhs, const Rect& rhs)
{
	return static_cast<SDL_Rect>(lhs) == static_cast<SDL_Rect>(rhs) && lhs.color() == rhs.color() && lhs.isFilled() == rhs.isFilled();
}

constexpr bool operator!=(const SDL_Rect& lhs, const SDL_Rect& rhs)
{
	return !(lhs == rhs);
}

constexpr bool operator!=(const Rect& lhs, const Rect& rhs)
{
	return !(lhs == rhs);
}

}} // namespace pong::graphics
