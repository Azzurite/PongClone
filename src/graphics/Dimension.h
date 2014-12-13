/*! \file
 *
 * @date 07.12.2014
 * @author Azzurite
 *
 * @copyright GPL v3
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

namespace pong {
namespace graphics {


class Dimension
{
public:

	/*!
	 * @brief Default constructor.
	 */
	constexpr Dimension() noexcept = default;

	/*!
	* @brief Constructs a new dimension
	* @param width
	* @param height
	*/
	constexpr Dimension(int width, int height) noexcept : width_(width), height_(height) { }

	/*!
	 * @brief Default copy constructor.
	 */
	constexpr Dimension(const Dimension&) noexcept = default;

	/*!
	 * @brief Default move constructor.
	 */
	constexpr Dimension(Dimension&&) noexcept = default;

	/*!
	 * @brief Default destructor.
	 */
	~Dimension() noexcept = default;


	/*!
	 * @brief Default copy assignment operator.
	 */
	Dimension& operator=(const Dimension&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	Dimension& operator=(Dimension&&) noexcept;

	constexpr int width() const { return width_; }

	constexpr int height() const { return height_; }

protected:

private:
	int width_ = 0;
	int height_ = 0;

};

constexpr bool operator==(const Dimension& lhs, const Dimension& rhs)
{
	return lhs.width() == rhs.width() && lhs.height() == rhs.height();
}


} // namespace graphics
} // namespace pong
