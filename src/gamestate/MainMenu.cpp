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

#include "gamestate/MainMenu.h"

#include "graphics/Color.h"
#include "graphics/Renderer.h"
#include "graphics/RenderRect.h"

using pong::graphics::Renderer;
using pong::graphics::Color;
using pong::graphics::RenderRect;

namespace pong {
namespace gamestate {

// ====== public: ======

MainMenu::MainMenu() noexcept = default;

MainMenu::MainMenu(const MainMenu&) noexcept = delete;

MainMenu::MainMenu(MainMenu&&) noexcept = default;

MainMenu::~MainMenu() noexcept = default;

MainMenu& MainMenu::operator=(const MainMenu&) noexcept = delete;

MainMenu& MainMenu::operator=(MainMenu&&) noexcept = default;

// ====== protected: ======

void MainMenu::renderImpl(const Renderer& renderer) const
{
	auto r = RenderRect({{100, 100},
						 {200, 200},
						 {255, 255, 255}});

	r.render(renderer);
}

// ====== private: ======


} // namespace gamestate
} // namespace pong
