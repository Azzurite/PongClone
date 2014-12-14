/*! @file
 *
 * @date 21.11.2014
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

#include "util/Strings.h"

#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <string>
using std::string;


namespace pong {
namespace util {

string join(string separator, std::initializer_list<string> elements)
{
	return join(separator, elements.begin(), elements.end());
}

std::vector<string> getParams(int argc, char** argv)
{
	std::vector<string> args;
	args.reserve(argc - 1); // without path
	std::copy(&argv[1], &argv[argc], std::back_inserter(args)); // skip path (argv[0])
	return args;
}
} // namespace util
} // namespace pong
