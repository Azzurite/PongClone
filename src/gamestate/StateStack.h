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

#pragma once

#include <deque>
#include <memory>

#include "graphics/Renderable.h"

namespace pong {

namespace graphics {
class Renderer;
}

namespace gamestate {

class GameState;

class StateStack final : public graphics::Renderable
{
public:

	/*!
	 * @brief Default constructor.
	 */
	StateStack();

	/*!
	 * @brief Default copy constructor.
	 */
	StateStack(const StateStack&) noexcept;

	/*!
	 * @brief Default move constructor.
	 */
	StateStack(StateStack&&);

	/*!
	 * @brief Default destructor.
	 */
	virtual ~StateStack() noexcept;


	/*!
	 * @brief Default copy assignment operator.
	 */
	StateStack& operator=(const StateStack&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	StateStack& operator=(StateStack&&);

	/*!
	 * @brief Pushes the given gamestate onto the stack.
	 *
	 * Will display the gamestate and put all other gamestates into paused mode.
	 *
	 * @param gameState new gamestate to display
	 */
	void push(std::unique_ptr<GameState>&& gameState);

	/*!
	 * @brief Pops the current [GameState](@ref GameState) off the stack
	 */
	void pop();

	virtual void render(const graphics::Renderer& renderer) const override;


protected:

private:

	std::deque<std::unique_ptr<GameState>> stateStack_;

};

} // namespace gamestate
} // namespace pong
