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
#include "Vec2.h"
#include "Vec3.h"
#include "Mat4.h"
#include "Quat.h"

namespace crown
{

Vec2* next_vec2();
Vec3* next_vec3();

Mat4* next_mat4();
Quat* next_quat();

class LuaStack
{
public:

							LuaStack(lua_State* L);

	void					push_bool(bool value);

	void					push_int32(int32_t value);

	void					push_uint32(uint32_t value);

	void					push_int64(int64_t value);

	void					push_uint64(uint64_t value);

	void 					push_float(float value);

	void 					push_string(const char* str, size_t len);

	void					push_vec2(Vec2* v);

	void					push_vec3(Vec3* v);

	void					push_mat4(Mat4* m);

	void					push_quat(Quat* q);

	bool 					get_bool(int32_t index);

	int32_t					get_int(int32_t index);

	float 					get_float(int32_t index);

	const char*				get_string(int32_t index);

	Vec2*					get_vec2(int32_t index);

	Vec3*					get_vec3(int32_t index);

	Mat4*					get_mat4(int32_t index);

	Quat*					get_quat(int32_t index);

private:

	lua_State* 				m_state;
};

} // namespace crown