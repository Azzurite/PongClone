/** \file
 *
 * \date 16.11.2014
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

#include "graphics/Renderer.h"

#include "SDL.h"
#include "Texture.h"

namespace pong {
namespace graphics {

// ====== public: ======

Renderer::Renderer() noexcept = default;

Renderer::Renderer(const Renderer&) noexcept = default;

Renderer::Renderer(Renderer&&) noexcept = default;

Renderer::~Renderer() noexcept = default;

Renderer& Renderer::operator=(const Renderer&) noexcept = default;

Renderer& Renderer::operator=(Renderer&&) noexcept = default;


// ====== protected: ======

// ====== private: ======

Texture Renderer::createTexture(SDL_Surface *surface) const {
	return graphics::Texture(renderer_, surface);
}
}} // namespace pong::graphics
