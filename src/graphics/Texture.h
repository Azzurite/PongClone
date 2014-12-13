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

#pragma once

#include <memory>

#include "SDL.h"

#include "graphics/Renderable.h"

namespace pong {
namespace graphics {

class Renderer;

class Surface;

class Texture final : public Renderable
{
public:
	using SDLTextureUPtr = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;

	/*!
	 * @brief Default copy constructor.
	 */
	Texture(const Texture&) noexcept;

	/*!
	 * @brief Default move constructor.
	 */
	Texture(Texture&&) noexcept;


	/*!
	 * @brief Default destructor.
	 */
	virtual ~Texture() noexcept;


	/*!
	 * @brief Default copy assignment operator.
	 */
	Texture& operator=(const Texture&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	Texture& operator=(Texture&&) noexcept;

	virtual void render(const Renderer& renderer) const override;


protected:

private:
	friend class Renderer;

	Texture(SDLTextureUPtr&& texture);

	SDLTextureUPtr texture_;

	SDL_Rect src;

	SDL_Rect dest;

};

Texture::SDLTextureUPtr make_unique_texture(SDL_Texture* texture);

} // namespace graphics
} // namespace pong
