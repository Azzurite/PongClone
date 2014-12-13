/*! @file
 *
 * @date 18.11.2014
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

#include "SDL.h"

#include "graphics/Renderable.h"
#include "graphics/Color.h"
#include "graphics/Rect.h"

namespace pong {
namespace graphics {

class Renderer;

class RenderRect final : public Renderable
{
public:

	/*!
	 * @brief Creates a new rectangle
	 * @param x location from upper left corner in x direction
	 * @param y location from upper left corner in y direction
	 * @param w width of the rectangle
	 * @param h height of the rectangle
	 */
	RenderRect(Rect rect) noexcept;

	/*!
	 * @brief Default copy constructor.
	 */
	RenderRect(const RenderRect&) noexcept;

	/*!
	 * @brief Default move constructor.
	 */
	RenderRect(RenderRect&&) noexcept;

	/*!
	 * @brief Default destructor.
	 */
	virtual ~RenderRect() noexcept;

	/*!
	 * @brief Default copy assignment operator.
	 */
	RenderRect& operator=(const RenderRect&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	RenderRect& operator=(RenderRect&&) noexcept;

	operator const Rect&() const { return rect_; }

	operator Rect&() { return rect_; }

	virtual void render(const Renderer& renderer) const override;

protected:

private:

	Rect rect_;

};


bool operator==(const RenderRect& lhs, const RenderRect& rhs);

bool operator!=(const RenderRect& lhs, const RenderRect& rhs);


} // namespace graphics
} // namespace pong
