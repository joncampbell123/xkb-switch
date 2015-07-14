/*
 * C++ exceptions that wraps X11 errors.
 *
 * Copyright (C) 2008 by Jay Bromley <jbromley@gmail.com>
 *
 * This file is part of Xkb-switch.
 * Xkb-switch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Xkb-switch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xkb-switch. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef X11EXCEPTION
#define X11EXCEPTION

#include <exception>
#include <stdexcept>

#define CHECK_MSG(x,msg) do{ \
		if(!(x)) { \
			std::ostringstream oss; \
			oss << __FILE__ << ":" << __LINE__ << ": Condition " << #x << " failed. " << msg; \
			throw std::runtime_error(oss.str()); \
		} \
	} while(0)

#define CHECK(x) CHECK_MSG(x,"")

class X11Exception : public std::exception
{
public:
    X11Exception() : _reason("unknown") {}
    X11Exception(const std::string& what) : _reason(what) {}
    virtual ~X11Exception() throw () {};
    virtual const char* what() const throw () { return _reason.c_str(); }

private:
    std::string _reason;
};

#endif
