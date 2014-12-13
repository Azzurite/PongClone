/*! @file
 *
 * @date 19.11.2014
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

#include "SDL.h"

namespace pong {
namespace graphics {

class Color final
{
public:

	/*!
	 * @brief Pure black.
	 */
	constexpr Color() noexcept : Color(0, 0, 0) {}

	/*!
	 * @brief Creates the specified color
	 *
	 * @param red 0-255
	 * @param green 0-255
	 * @param blue 0-255
	 * @param alpha 0-255, 0 = transparent, 255 = solid
	 */
	constexpr Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255) noexcept : color_{red, green, blue, alpha} {}

	/*!
	 * @brief Default copy constructor.
	 */
	constexpr Color(const Color&) noexcept = default;

	/*!
	 * @brief Default move constructor.
	 */
	constexpr Color(Color&&) noexcept = default;

	/*!
	 * @brief Default destructor.
	 */
	~Color() noexcept = default;


	/*!
	 * @brief Default copy assignment operator.
	 */
	Color& operator=(const Color&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	Color& operator=(Color&&) noexcept;

	inline operator SDL_Color&() { return color_; }

	constexpr operator const SDL_Color&() const { return color_; }

	constexpr Uint8 red() const { return color_.r; }

	constexpr Uint8 green() const { return color_.g; }

	constexpr Uint8 blue() const { return color_.b; }

	constexpr Uint8 alpha() const { return color_.a; }

protected:

private:

	SDL_Color color_;

};

constexpr bool operator==(const SDL_Color& lhs, const SDL_Color& rhs)
{
	return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a;
}

constexpr bool operator==(const Color& lhs, const Color& rhs)
{
	return static_cast<SDL_Color>(lhs) == static_cast<SDL_Color>(rhs);
}

constexpr bool operator!=(const SDL_Color& lhs, const SDL_Color& rhs)
{
	return !(lhs == rhs);
}

constexpr bool operator!=(const Color& lhs, const Color& rhs)
{
	return !(lhs == rhs);
}


}} // namespace pong::graphics
