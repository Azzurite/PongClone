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

#include "util/Strings.h"

#include <string>
#include <initializer_list>
using std::string;

namespace pong {
namespace util {

string join(string separator, std::initializer_list<string> elements)
{
	auto cur = elements.begin();
	if (cur == elements.end()) return string{};

	auto joined = *cur++;
	while (cur != elements.end())
	{
		joined += separator + *cur++;
	}
	return joined;
}

}} // namespace pong::util
