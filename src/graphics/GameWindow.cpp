/*! @file
 *
 * @date 19.02.2014
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

#include "graphics/GameWindow.h"

#include <string>
#include <sstream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "gamestate/StateStack.h"
#include "gamestate/GameState.h"
#include "gamestate/MainMenu.h"
#include "util/Strings.h"
#include "util/Exceptions.h"

using pong::gamestate::GameState;
using pong::gamestate::MainMenu;

namespace pong {
namespace graphics {

namespace {
const char* const cPONG_WINDOW_NAME = "Pong";
}


// ====== public: ======

GameWindow::GameWindow() : mainWindow_(cPONG_WINDOW_NAME), renderer_(mainWindow_.createRenderer(false))
{
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
	renderer_.setLogicalSize({cRENDER_WIDTH, cRENDER_HEIGHT});

	stateStack_.push(std::make_unique<MainMenu>());
}

GameWindow::GameWindow(const GameWindow&) noexcept = delete;

GameWindow::GameWindow(GameWindow&&) = default;

GameWindow::~GameWindow() noexcept = default;

GameWindow& GameWindow::operator=(const GameWindow&) noexcept = delete;

GameWindow& GameWindow::operator=(GameWindow&&) = default;


void GameWindow::update()
{
	stateStack_.render(renderer_);

	renderer_.renderPresent();
}

// ====== protected: ======

// ====== private: ======


} // namespace graphics
} // namespace pong

