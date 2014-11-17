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
 
#pragma once

struct SDL_Window;
struct SDL_Renderer;

class SDL_Texture;
class SDL_Surface;

namespace pong {
namespace graphics {

class Texture;

class Renderer
{
public:
	/**
	 * \brief Default constructor.
	 */
	Renderer() noexcept;

	/**
	 * \brief Default copy constructor.
	 */
	Renderer(const Renderer&) noexcept;

	/**
	 * \brief Default move constructor.
	 */
	Renderer(Renderer&&) noexcept;

	/**
	 * \brief Default destructor.
	 */
	~Renderer() noexcept;

	/**
	 * \brief Default copy assignment operator.
	 */
	Renderer& operator=(const Renderer&) noexcept;

	/**
	 * \brief Default move assignment operator.
	 */
	Renderer& operator=(Renderer&&) noexcept;


	/**
	 * \brief Creates a texture from a Surface
	 * \return the created texture
	 */
	Texture createTexture(SDL_Surface*) const;

	/**
	 * \return the window associated with the renderer
	 */
	SDL_Window* getWindow() const { return renderWindow_; }

protected:

private:

	SDL_Window* renderWindow_;

	SDL_Renderer* renderer_;

};

}} // namespace pong::graphics
