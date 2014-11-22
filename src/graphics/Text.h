/** \file
 *
 * \date 18.11.2014
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

#include "Renderable.h"

namespace pong {
namespace graphics {

class Renderer;

class Text final : public Renderable
{
public:

	/**
	 * \brief Default constructor.
	 */
	Text() noexcept;
	
	/**
	 * \brief Default copy constructor.
	 */
	Text(const Text&) noexcept;
		
	/**
	 * \brief Default move constructor.
	 */
	Text(Text&&) noexcept;
	
	/**
	 * \brief Default destructor.
	 */
	virtual ~Text() noexcept;
	
	
	/**
	 * \brief Default copy assignment operator.
	 */
	Text& operator=(const Text&) noexcept;
	
	/**
	 * \brief Default move assignment operator.
	 */
	Text& operator=(Text&&) noexcept;

	virtual void render(Renderer& renderer) override;
	

protected:

private:

};

}} // namespace pong::graphics
