/** @file
 *
 * \date 22.11.2014
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

#include "util/Exceptions.h"

#include <stdexcept>
#include <string>

#include "SDL.h"

namespace pong {
namespace util {

std::runtime_error sdlError(std::string message)
{
	return std::runtime_error(message + " | SDL error message: " + SDL_GetError());
}

}} // namespace pong::util
