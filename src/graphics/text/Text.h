/** \file
 *
 * \date 08.12.2014
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
namespace text {


class Text
{
public:

	/**
	 * @brief Default constructor.
	 */
	constexpr Text() noexcept;
	
	/**
	 * @brief Default copy constructor.
	 */
	constexpr Text(const Text&) noexcept;
		
	/**
	 * @brief Default move constructor.
	 */
	constexpr Text(Text&&) noexcept;
	
	/**
	 * @brief Default destructor.
	 */
	~Text() noexcept;
	
	
	/**
	 * @brief Default copy assignment operator.
	 */
	Text& operator=(const Text&) noexcept;
	
	/**
	 * @brief Default move assignment operator.
	 */
	Text& operator=(Text&&) noexcept;
	

protected:

private:

};

}}} // namespace pong::graphics::text
