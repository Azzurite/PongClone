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
 
#pragma once

namespace pong {
namespace resources {


class ResourceManager
{
public:

	/*!
	 * @brief Default constructor.
	 */
	ResourceManager() noexcept;
	
	/*!
	 * @brief Default copy constructor.
	 */
	ResourceManager(const ResourceManager&) noexcept;
		
	/*!
	 * @brief Default move constructor.
	 */
	ResourceManager(ResourceManager&&) noexcept;
	
	/*!
	 * @brief Default destructor.
	 */
	~ResourceManager() noexcept;
	
	
	/*!
	 * @brief Default copy assignment operator.
	 */
	ResourceManager& operator=(const ResourceManager&) noexcept;
	
	/*!
	 * @brief Default move assignment operator.
	 */
	ResourceManager& operator=(ResourceManager&&) noexcept;
	

protected:

private:

};

} // namespace resources
} // namespace pong

