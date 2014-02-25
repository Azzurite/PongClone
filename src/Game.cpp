/** \file
 *
 * \date 19.02.2014
 * \author Azzu
 *
 * \copyright GPL v3
 * Copyright (C) 2014 Azzu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Game.h>

#include <SDL2/SDL.h>

namespace pong {

Game::Game() noexcept = default;

Game::Game(const Game& toCopy) noexcept = delete;

Game::Game(Game&& toMove) noexcept = delete;

Game::~Game() noexcept = default;

Game& Game::operator=(const Game& toCopy) noexcept = delete;

Game& Game::operator=(Game&& toMove) noexcept = delete;

int Game::run() {
	SDL_Delay(5000);
	return 0;
}

void Game::init() {

}

} /* namespace pong */
