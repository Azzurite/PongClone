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

#include "graphics/Renderer.h"

#include <memory>

#include "SDL.h"

#include "graphics/Dimension.h"
#include "graphics/Surface.h"
#include "graphics/Texture.h"
#include "graphics/Rect.h"
#include "util/Exceptions.h"

namespace pong {
namespace graphics {

// ====== public: ======


Renderer::Renderer(const Renderer&) noexcept = delete;

Renderer::Renderer(Renderer&&) noexcept = default;

Renderer::~Renderer() noexcept = default;

Renderer& Renderer::operator=(const Renderer&) noexcept = delete;

Renderer& Renderer::operator=(Renderer&&) noexcept = default;

Texture Renderer::createTexture(const Surface& surface) const
{
	auto sdlSurface = (static_cast<SDL_Surface&>(surface));
	auto texture = make_unique_texture(SDL_CreateTextureFromSurface(renderer_.get(), &sdlSurface));
	if (!texture) {
		throw util::sdlError("Failed to create texture from surface.");
	}

	return Texture(std::move(texture));
}

void Renderer::renderPresent() const
{
	SDL_RenderPresent(renderer_.get());
	SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
	SDL_RenderClear(renderer_.get());
}

void Renderer::render(const Rect& rectangle) const
{
	setRenderColor(rectangle.color());
	const SDL_Rect r = static_cast<SDL_Rect>(rectangle);
	SDL_RenderDrawRect(renderer_.get(), &r);
}

void Renderer::render(SDL_Texture* texture, const SDL_Rect* const src, const SDL_Rect* const dest) const
{
	SDL_RenderCopy(renderer_.get(), texture, src, dest);
}

void Renderer::setLogicalSize(Dimension dim)
{
	SDL_RenderSetLogicalSize(renderer_.get(), dim.width(), dim.height());
}

Dimension Renderer::getLogicalSize()
{
	int width;
	int height;
	SDL_RenderGetLogicalSize(renderer_.get(), &width, &height);
	return {width, height};
}

// ====== protected: ======

// ====== private: ======

Renderer::Renderer(SDLRendererUPtr&& renderer) : renderer_(std::move(renderer))
{
}


void Renderer::setRenderColor(const Color& color) const
{
	SDL_SetRenderDrawColor(renderer_.get(), color.red(), color.green(), color.blue(), color.alpha());
}


} // namespace graphics
} // namespace pong
