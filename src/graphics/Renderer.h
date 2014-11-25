/** @file
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

#pragma once

#include "SDL.h"

#include <memory>

#include "Dimension.h"

namespace pong {
namespace graphics {

class Color;
class Rect;
class Surface;
class Texture;
class Window;

class Renderer final
{
public:

	using SDLRendererUPtr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

	/**
	 * @brief Default copy constructor.
	 */
	Renderer(const Renderer&) noexcept;

	/**
	 * @brief Default move constructor.
	 */
	Renderer(Renderer&&) noexcept;

	/**
	 * @brief Default destructor.
	 */
	~Renderer() noexcept;

	/**
	 * @brief Default copy assignment operator.
	 */
	Renderer& operator=(const Renderer&) noexcept;

	/**
	 * @brief Default move assignment operator.
	 */
	Renderer& operator=(Renderer&&) noexcept;


	/**
	 * @brief Creates a texture from a surface
	 * @return the created texture
	 */
	Texture createTexture(const Surface& surface) const;

	void renderPresent() const;

	void render(const Rect& rectangle) const;

	void render(SDL_Texture* texture, const SDL_Rect* const src, const SDL_Rect* const dest) const;

	void setLogicalSize(Dimension dim);

	Dimension getLogicalSize();

protected:

private:
	friend class Window;

	Renderer(SDLRendererUPtr&& renderer);

	void setRenderColor(const Color& color) const;

	SDLRendererUPtr renderer_;

};

}} // namespace pong::graphics
