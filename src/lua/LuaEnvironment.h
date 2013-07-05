/*
Copyright (c) 2013 Daniele Bartolini, Michele Rossi
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "lua.hpp"
#include "Types.h"
#include "Config.h"

#ifdef WINDOWS
	#define CE_EXPORT extern "C" __declspec(dllexport)
#else
	#define CE_EXPORT
#endif


namespace crown
{

class LuaEnvironment
{

public:
	/// Constructor
					LuaEnvironment(lua_State* L);
	/// Load a function to proper module
	void			load_module_function(const char* module, const char* name, const lua_CFunction func);
	/// Create library based on each module which will be opened by luaopen_*
	void			create_module_library();

private:

	lua_State*		m_state;
};

void load_vec2(LuaEnvironment& env);
void load_vec3(LuaEnvironment& env);
void load_mat4(LuaEnvironment& env);
void load_quat(LuaEnvironment& env);
void load_math(LuaEnvironment& env);

void load_mouse(LuaEnvironment& env);
void load_keyboard(LuaEnvironment& env);
void load_touch(LuaEnvironment& env);
void load_accelerometer(LuaEnvironment& env);

void load_camera(LuaEnvironment& env);

void load_device(LuaEnvironment& env);

void load_window(LuaEnvironment& env);

CE_EXPORT int32_t luaopen_libcrown(lua_State* L);

} // namespace crown