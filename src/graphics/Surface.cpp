/*! @file
 *
 * @date 16.11.2014
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

#include "graphics/Surface.h"

#include <string>

#include "SDL.h"

#include "graphics/Texture.h"
#include "util/Exceptions.h"

namespace pong {
namespace graphics {

// ====== public: ======

Surface::Surface(std::string fileName) noexcept : surface_(SDL_LoadBMP(fileName.c_str()), SDL_FreeSurface)
{
	if (!surface_) {
		throw util::sdlError("Could not load BMP to Surface.");
	}
}

Surface::Surface(const Surface&) noexcept = delete;

Surface::Surface(Surface&&) noexcept = default;

Surface::~Surface() noexcept = default;

Surface& Surface::operator=(const Surface&) noexcept = delete;

Surface& Surface::operator=(Surface&&) noexcept = default;




// ====== protected: ======

// ====== private: ======


} // namespace graphics
} // namespace pong
