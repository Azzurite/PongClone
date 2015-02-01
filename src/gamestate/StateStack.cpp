/*! @file
 *
 * @date 19.11.2014
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

#include "gamestate/StateStack.h"

#include "SDL2Wrap.h"
using sdl2wrap::video::Renderer;

#include "GameState.h"

namespace pong {
namespace gamestate {

// ====== public: ======

StateStack::StateStack() = default;

StateStack::StateStack(const StateStack&) noexcept = delete;

StateStack::StateStack(StateStack&&) = default;

StateStack::~StateStack() noexcept = default;

StateStack& StateStack::operator=(const StateStack&) noexcept = delete;

StateStack& StateStack::operator=(StateStack&&) = default;

void StateStack::push(std::unique_ptr<GameState>&& gameState)
{
	if (!stateStack_.empty()) stateStack_.front()->pause();

	stateStack_.push_front(std::move(gameState));
}

void StateStack::pop()
{
	stateStack_.pop_front();

	if (!stateStack_.empty()) stateStack_.front()->resume();
}

void StateStack::render(const Renderer& renderer) const
{
	for (auto cur = stateStack_.crbegin(); cur != stateStack_.crend(); ++cur) {
		(*cur)->render(renderer);
	}
}

// ====== protected: ======

// ====== private: ======



} // namespace gamestate
} // namespace pong
