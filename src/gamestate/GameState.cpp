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

#include "gamestate/GameState.h"

#include <stdexcept>
#include <string>
#include <memory>

#include "SDL.h"

#include "graphics/Renderer.h"
#include "graphics/Texture.h"
#include "util/NotImplementedException.h"

using pong::graphics::Renderer;
using pong::graphics::Texture;

namespace pong {
namespace gamestate {

// ====== public: ======

GameState::GameState() noexcept = default;

GameState::GameState(const GameState&) noexcept = delete;

GameState::GameState(GameState&&) noexcept = default;

GameState::~GameState() noexcept = default;

GameState& GameState::operator=(const GameState&) noexcept = delete;

GameState& GameState::operator=(GameState&&) noexcept = default;

void GameState::pause()
{
	isPaused_ = true;
}

void GameState::resume()
{
	cachedRender_.reset(nullptr);
	isPaused_ = false;
}

void GameState::render(const Renderer& r) const
{
	if (isPaused_) renderPaused(r);
	else renderImpl(r);
}


// ====== protected: ======


void GameState::renderPaused(const Renderer& r) const
{
	if (!cachedRender_) {
		// TODO impl
//		renderImpl(r);
//		SDL_Window* w = r.getWindow();
//		SDL_Surface* windowSurface = SDL_GetWindowSurface(w);
//		SDL_Surface* cacheSurface = SDL_ConvertSurface(windowSurface, windowSurface->format, 0);
//		if (cacheSurface == nullptr)
//		{
//			throw std::runtime_error(std::string("Could not copy surface: ") + SDL_GetError());
//		}
//		Texture t = r.createTexture(cacheSurface);
//		cachedRender_ = std::make_unique<Texture>(std::move(t));
	} else {
		cachedRender_->render(r);
	}
}

// ====== private: ======


} // namespace gamestate
} // namespace pong
