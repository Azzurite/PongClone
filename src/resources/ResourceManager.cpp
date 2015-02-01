/*! @file
 *
 * @date 12.12.2014
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
 
#include "resources/ResourceManager.h"

namespace pong {
namespace resources {


// ====== public: ======

ResourceManager::ResourceManager() noexcept = default;

ResourceManager::ResourceManager(const ResourceManager&) noexcept = default;

ResourceManager::ResourceManager(ResourceManager&&) noexcept = default;

ResourceManager::~ResourceManager() noexcept = default;

ResourceManager& ResourceManager::operator=(const ResourceManager&) noexcept = default;

ResourceManager& ResourceManager::operator=(ResourceManager&&) noexcept = default;

// ====== protected: ======

// ====== private: ======

// ====== freestanding: ======

} // namespace resources
} // namespace pong

