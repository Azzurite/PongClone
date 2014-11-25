/** @file
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

namespace pong {
namespace util {

/**
 * @brief Joins the strings in the list with the given separator between them
 * @param separator the string to be inserted between the elements
 * @param elements list of the strings to join
 */
std::string join(std::string separator, std::initializer_list<std::string> elements);


/**
 * @brief Converts the elements std::to_string and joins them with the given separator.
 * @param separator the string to be inserted between the elements
 * @param elements the elements to join
 */
template<typename... Elements>
std::string toStringJoin(std::string separator, Elements... elements)
{
	return join(separator, std::initializer_list<std::string>{std::to_string(elements)...});
}

}} // namespace pong::util
