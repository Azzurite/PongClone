/** @file
 *
 * \date 21.11.2014
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

#include "graphics/Window.h"

#include <ostream>
#include <stdexcept>
#include <string>
using std::string;

#include "SDL.h"

#include "graphics/Renderer.h"
#include "util/Exceptions.h"

namespace pong {
namespace graphics {

namespace {

SDLFlagType getInputGrabbedFlag(bool inputGrabbed)
{
	return static_cast<SDLFlagType>(inputGrabbed ? SDL_WINDOW_INPUT_GRABBED : 0);
}

SDLFlagType createFlag()
{
	return static_cast<SDLFlagType>(0);
}

template <typename First, typename... Flags>
SDLFlagType createFlag(First firstFlag, Flags... rest)
{
	return static_cast<SDLFlagType>(firstFlag) | createFlag(rest...);
}

template <typename... Flags>
Window::SDLWindowUPtr createWindow(string name, int x, int y, int h, int w, bool inputGrabbed, Flags... flags)
{
	auto grabbedFlag = getInputGrabbedFlag(inputGrabbed);
	auto windowPtr = SDL_CreateWindow(name.c_str(), x, y, w, h, createFlag(grabbedFlag, flags...));
	return make_unique_window(windowPtr);
}

}

// ====== public: ======

Window::Window(string name) : Window(name, Fullscreen::DESKTOP, State::NORMAL, true) {}

Window::Window(string name, Fullscreen fullscreen, State state, bool inputGrabbed)
		: window_(std::move(createWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, inputGrabbed, fullscreen, state)))
{
	if (window_ == nullptr) {
		throw util::sdlError("Window could not be created.");
	}
}

Window::Window(string name, int x, int y, int h, int w, Border border, State state, bool inputGrabbed)
		: window_(std::move(createWindow(name, x, y, h, w, inputGrabbed, border, state)))
{
	if (!window_) {
		throw util::sdlError("Window could not be created.");
	}
}

Window::Window(const Window&) noexcept = delete;

Window::Window(Window&&) noexcept = default;

Window::~Window() noexcept = default;

Window& Window::operator=(const Window&) noexcept = delete;

Window& Window::operator=(Window&&) noexcept = default;

Renderer Window::createRenderer(bool vSync) const
{
	auto* rendererPtr = SDL_CreateRenderer(window_.get(), -1, vSync ? SDL_RENDERER_PRESENTVSYNC : 0);
	if (rendererPtr == nullptr)
	{
		throw util::sdlError("Error while creating the renderer.");
	}
	Renderer::SDLRendererUPtr renderer(rendererPtr, SDL_DestroyRenderer);
	return Renderer(std::move(renderer));
}

// ====== protected: ======

// ====== private: ======

// ====== freestanding: ======

std::string toString(const Window::Fullscreen& fullscreen)
{
	switch (fullscreen)
	{
	case Window::Fullscreen::DESKTOP:
		return "Window::Fullscreen::DESKTOP";
		break;
	case Window::Fullscreen::VIDEOMODE:
		return "Window::Fullscreen::VIDEOMODE";
		break;
	default:
		throw std::runtime_error("Unhandled switch case");
	}
}

std::ostream& operator<<(std::ostream& os, const Window::Fullscreen& fullscreen)
{
	return os << toString(fullscreen);
}

std::string toString(const Window::Border& border)
{
	switch (border)
	{
	case Window::Border::NORMAL:
		return "Window::Border::NORMAL";
		break;
	case Window::Border::RESIZABLE:
		return "Window::Border::RESIZABLE";
		break;
	case Window::Border::OFF:
		return "Window::Border::OFF";
		break;
	default:
		throw std::runtime_error("Unhandled switch case");
	}
}

std::ostream& operator<<(std::ostream& os, const Window::Border& border)
{
	return os << toString(border);
}

std::string toString(const Window::State& state)
{
	switch (state)
	{
	case Window::State::NORMAL:
		return "Window::State::NORMAL";
		break;
	case Window::State::MINIMIZED:
		return "Window::State::MINIMIZED";
		break;
	case Window::State::MAXIMIZED:
		return "Window::State::MAXIMIZED";
		break;
	default:
		throw std::runtime_error("Unhandled switch case");
	}
}

std::ostream& operator<<(std::ostream& os, const Window::State& state)
{
	return os << toString(state);
}

Window::SDLWindowUPtr make_unique_window(SDL_Window* window)
{
	return Window::SDLWindowUPtr(window, SDL_DestroyWindow);
}

}} // namespace pong::graphics
