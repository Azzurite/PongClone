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

#include "RenderRect.h"

#include <iostream>

#include "graphics/Renderer.h"

namespace pong {
namespace graphics {

// ====== public: ======

RenderRect::RenderRect(Rect rect) noexcept : rect_(rect) { }

RenderRect::RenderRect(const RenderRect&) noexcept = default;

RenderRect::RenderRect(RenderRect&&) noexcept = default;

RenderRect::~RenderRect() noexcept = default;

RenderRect& RenderRect::operator=(const RenderRect&) noexcept = default;

RenderRect& RenderRect::operator=(RenderRect&&) noexcept = default;

void RenderRect::render(const Renderer& renderer) const
{
	renderer.render(rect_);
}

// ====== protected: ======

// ====== private: ======

// ====== freestanding: =====

bool operator==(const RenderRect& lhs, const RenderRect& rhs)
{
	return static_cast<Rect>(lhs) == static_cast<Rect>(rhs);
}

bool operator!=(const RenderRect& lhs, const RenderRect& rhs)
{
	return !(lhs == rhs);
}


} // namespace graphics
} // namespace pong
