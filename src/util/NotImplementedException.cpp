/*! @file
 *
 * @date 13.12.2014
 * @author Azzurite
 *
 * @copyright GPL v3
 *   Copyright (C) 2014 Azzurite
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

#include "util/NotImplementedException.h"

namespace pong {
namespace util {


// ====== public: ======

NotImplementedException::NotImplementedException() noexcept : NotImplementedException("Not implemented yet.") { }

NotImplementedException::NotImplementedException(const char* message) noexcept : message_(message) { }

NotImplementedException::NotImplementedException(const NotImplementedException&) noexcept = default;

NotImplementedException::NotImplementedException(NotImplementedException&&) noexcept = default;

NotImplementedException::~NotImplementedException() noexcept = default;

NotImplementedException& NotImplementedException::operator=(const NotImplementedException&) noexcept = default;

NotImplementedException& NotImplementedException::operator=(NotImplementedException&&) noexcept = default;

// ====== protected: ======

// ====== private: ======

// ====== freestanding: ======

} // namespace pong
} // namespace util

