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

#include <memory>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

namespace pong {
namespace graphics {

class Renderer;

class Texture
{
public:

	/**
	 * \brief Default copy constructor.
	 */
	Texture(const Texture&) noexcept;
		
	/**
	 * \brief Default move constructor.
	 */
	Texture(Texture&&) noexcept;

	/**
	 * \brief creates a texture from a surface
	 */
	Texture(SDL_Surface*);
	
	/**
	 * \brief Default destructor.
	 */
	~Texture() noexcept;
	
	
	/**
	 * \brief Default copy assignment operator.
	 */
	Texture& operator=(const Texture&) noexcept;
	
	/**
	 * \brief Default move assignment operator.
	 */
	Texture& operator=(Texture&&) noexcept;

	virtual void render();
	

protected:

private:
	friend class Renderer;

	Texture(SDL_Renderer*, SDL_Surface*);

	SDL_Renderer* renderer_;

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> texture_;

};

}} // namespace pong::graphics
