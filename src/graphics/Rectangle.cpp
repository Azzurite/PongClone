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

#include "graphics/Rectangle.h"
#include "Renderer.h"

namespace pong {
namespace graphics {

// ====== public: ======

Rectangle::Rectangle(int x, int y, int w, int h) noexcept : Rectangle(x, y, w, h, Color(), true) {}

Rectangle::Rectangle(int x, int y, int w, int h, Color color) noexcept : Rectangle(x, y, w, h, color, true) {}

Rectangle::Rectangle(int x, int y, int w, int h, bool isFilled) noexcept : Rectangle(x, y, w, h, Color(), isFilled) {}

Rectangle::Rectangle(int x, int y, int w, int h, Color color, bool isFilled) noexcept
		: rectangle_{x, y, w, h}, color_(color), isFilled_(isFilled) {}

Rectangle::Rectangle(const Rectangle&) noexcept = default;

Rectangle::Rectangle(Rectangle&&) noexcept = default;

Rectangle::~Rectangle() noexcept = default;

Rectangle& Rectangle::operator=(const Rectangle&) noexcept = default;

Rectangle& Rectangle::operator=(Rectangle&&) noexcept = default;

void Rectangle::render(Renderer& renderer) {
	renderer.renderRectangle(&rectangle_);
}

// ====== protected: ======

// ====== private: ======




}} // namespace pong::graphics
