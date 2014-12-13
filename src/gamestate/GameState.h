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

#pragma once

#include <memory>
#include "graphics/Renderable.h"

namespace pong {
namespace graphics {
class Renderer;
class Texture;
}
}

struct SDL_Surface;

namespace pong {
namespace gamestate {


class GameState : public pong::graphics::Renderable
{
public:

	/*!
	 * @brief Default constructor.
	 */
	GameState() noexcept;

	/*!
	 * @brief Default copy constructor.
	 */
	GameState(const GameState&) noexcept;

	/*!
	 * @brief Default move constructor.
	 */
	GameState(GameState&&) noexcept;

	/*!
	 * @brief Default destructor.
	 */
	~GameState() noexcept;


	/*!
	 * @brief Default copy assignment operator.
	 */
	GameState& operator=(const GameState&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	GameState& operator=(GameState&&) noexcept;


	void pause();

	void resume();

	void render(const pong::graphics::Renderer&) const override;

protected:

	void renderPaused(const pong::graphics::Renderer&) const;

	virtual void renderImpl(const pong::graphics::Renderer&) const = 0;

private:

	bool isPaused_ = false;

	mutable std::unique_ptr<pong::graphics::Texture> cachedRender_;

};

} // namespace gamestate
} // namespace pong
