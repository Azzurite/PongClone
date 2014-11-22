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

#include "graphics/Text.h"
#include "Renderer.h"

namespace pong {
namespace graphics {

// ====== public: ======

Text::Text() noexcept = default;

Text::Text(const Text&) noexcept = default;

Text::Text(Text&&) noexcept = default;

Text::~Text() noexcept = default;

Text& Text::operator=(const Text&) noexcept = default;

Text& Text::operator=(Text&&) noexcept = default;

void Text::render(Renderer &renderer)
{

}

// ====== protected: ======

// ====== private: ======



}} // namespace pong::graphics
