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

namespace pong {
namespace graphics {


class Point
{
public:

	/**
	* @brief Default constructor.
	*/
	constexpr Point() noexcept = default;

	/**
	* @brief Construct a new point
	* @param x the x coordinate, 0 is at the left, positive values extending right
	* @param y the y coordinate, 0 is at the top, positive values extending down
	*/
	constexpr Point(int x, int y) noexcept : x_(x), y_(y) {}
	
	/**
	 * @brief Default copy constructor.
	 */
	constexpr Point(const Point&) noexcept = default;
		
	/**
	 * @brief Default move constructor.
	 */
	constexpr Point(Point&&) noexcept = default;
	
	/**
	 * @brief Default destructor.
	 */
	~Point() noexcept = default;
	
	
	/**
	 * @brief Default copy assignment operator.
	 */
	Point& operator=(const Point&) noexcept;
	
	/**
	 * @brief Default move assignment operator.
	 */
	Point& operator=(Point&&) noexcept;

	constexpr int x() const { return x_; }
	constexpr int y() const { return y_; }

protected:

private:
	int x_ = 0;
	int y_ = 0;

};

}} // namespace pong::graphics
