/*! @file
 *
 * @date 21.11.2014
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

#include <string>
#include <memory>

#include "SDL.h"

namespace pong {
namespace graphics {

class Renderer;

class Window
{
public:

	using SDLWindowUPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

	enum class Fullscreen;

	enum class Border;

	enum class State;

	/*!
	 * @brief Constructs a new window in "Borderless windowed mode" with input grabbed
	 * @param name name and title of the window
	 */
	explicit Window(std::string name);

	/*!
	 * @brief Constructs a new window in fullscreen mode.
	 * @param name name and title of the window
	 * @param fullscreen fullscreen mode
	 * @param state state of the window
	 * @param inputGrabbed if the mouse should not be able to leave the window
	 */
	Window(std::string name, Fullscreen fullscreen, State state, bool inputGrabbed);

	/*!
	 * @brief Constructs a new window in windowed mode.
	 * @param name the name and title of the window
	 * @param x x-position, from the upper left, of the window
	 * @param y y-position, from the upper left, of the window
	 * @param w width of the window
	 * @param h height of the window
	 * @param border border options
	 * @param state state of the window
	 * @param inputGrabbed if the mouse should not be able to leave the window
	 */
	Window(std::string name, int x, int y, int h, int w, Border border, State s, bool inputGrapped);

	/*!
	 * @brief Default copy constructor.
	 */
	Window(const Window&) noexcept;

	/*!
	 * @brief Default move constructor.
	 */
	Window(Window&&) noexcept;

	/*!
	 * @brief Default destructor.
	 */
	~Window() noexcept;


	/*!
	 * @brief Default copy assignment operator.
	 */
	Window& operator=(const Window&) noexcept;

	/*!
	 * @brief Default move assignment operator.
	 */
	Window& operator=(Window&&) noexcept;


	/*!
	 * @brief Creates a new renderer for this window
	 * @param vSync if VSync should be enabled
	 */
	Renderer createRenderer(bool vSync) const;

protected:

private:

	SDLWindowUPtr window_;
};

namespace {
using SDLFlagType =  decltype(SDL_WINDOW_MINIMIZED | SDL_WINDOW_MAXIMIZED);
}

enum class Window::Fullscreen : SDLFlagType
{
	/*!
	* @brief Desktop fullscreen, also called "Borderless windowed"
	*/
			DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,

	/*!
	* @brief "old" fullscreen, changes video mode
	*/
			VIDEOMODE = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_MAXIMIZED
};

std::string toString(const Window::Fullscreen& fullscreen);

std::ostream& operator<<(std::ostream& os, const Window::Fullscreen& fullscreen);

enum class Window::Border : SDLFlagType
{
	/*!
	 * @brief Normal window border
	 */
			NORMAL = 0,

	/*!
	 * Borderless window
	 */
			OFF = SDL_WINDOW_BORDERLESS,

	/*!
	 * @brief makes the window resizable by dragging the border
	 */
			RESIZABLE = SDL_WINDOW_RESIZABLE
};

std::string toString(const Window::Border& border);

std::ostream& operator<<(std::ostream& os, const Window::Border& border);

enum class Window::State : SDLFlagType
{
	/*!
	 * @brief normal window
	 */
			NORMAL = 0,

	/*!
	 * @brief makes the window minimized
	 */
			MINIMIZED = SDL_WINDOW_MINIMIZED,

	/*!
	 * @brief makes the window maximized
	 */
			MAXIMIZED = SDL_WINDOW_MAXIMIZED
};

std::string toString(const Window::State& state);

std::ostream& operator<<(std::ostream& os, const Window::State& state);

Window::SDLWindowUPtr make_unique_window(SDL_Window* window);

} // namespace graphics
} // namespace pong
