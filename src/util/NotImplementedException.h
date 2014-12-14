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
 
#pragma once

#include <exception>

namespace pong {
namespace util {


class NotImplementedException final : public std::exception
{
public:

	/*!
	 * @brief Default constructor.
	 */
	NotImplementedException() noexcept;

	/*!
	 * @brief Message constructor.
	 * @param message the message to be shown by what()
	 */
	explicit NotImplementedException(const char* message) noexcept;
	
	/*!
	 * @brief Default copy constructor.
	 */
	NotImplementedException(const NotImplementedException&) noexcept;
		
	/*!
	 * @brief Default move constructor.
	 */
	NotImplementedException(NotImplementedException&&) noexcept;
	
	/*!
	 * @brief Default destructor.
	 */
	~NotImplementedException() noexcept;
	
	
	/*!
	 * @brief Default copy assignment operator.
	 */
	NotImplementedException& operator=(const NotImplementedException&) noexcept;
	
	/*!
	 * @brief Default move assignment operator.
	 */
	NotImplementedException& operator=(NotImplementedException&&) noexcept;

	virtual const char* what() const noexcept override { return message_; }

protected:

private:

	const char* message_;

};

} // namespace pong
} // namespace util

