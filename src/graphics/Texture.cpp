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

#include "graphics/Texture.h"

#include <stdexcept>
#include <string>

#include "SDL.h"
#include "graphics/Renderer.h"

namespace pong {
namespace graphics {

// ====== public: ======

Texture::Texture(const Texture&) noexcept = delete;

Texture::Texture(Texture&&) noexcept = default;

Texture::~Texture() noexcept = default;

Texture& Texture::operator=(const Texture&) noexcept = delete;

Texture& Texture::operator=(Texture&&) noexcept = default;

void Texture::render() {
	SDL_RenderCopy(renderer_, &*texture_, nullptr, nullptr);
}

// ====== protected: ======

// ====== private: ======

Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface) : renderer_(renderer), texture_(nullptr, SDL_DestroyTexture)
{
	SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, surface);
	if (t == nullptr)
	{
		throw std::runtime_error(std::string("Failed to create texture from surface: ") + SDL_GetError());
	}

	texture_ = std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)>(t, SDL_DestroyTexture);
}

}} // namespace pong::graphics
