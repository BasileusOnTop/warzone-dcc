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

#include "Vec3.h"
#include "LuaStack.h"
#include "LuaEnvironment.h"

namespace crown
{

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3(lua_State* L)
{
	LuaStack stack(L);

	float x = stack.get_float(1);
	float y = stack.get_float(2);
	float z = stack.get_float(3);

	Vec3* vec = next_vec3();

	vec->x = x;
	vec->y = y;
	vec->z = z;

	stack.push_vec3(vec);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_values(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	float x = a->x;
	float y = a->y;
	float z = a->z;

	stack.push_float(x);
	stack.push_float(y);
	stack.push_float(z);

	return 3;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_add(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	*a += *b;

	stack.push_vec3(a);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_subtract(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	*a -= *b;

	stack.push_vec3(a);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_multiply(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	float b = stack.get_float(2);

	*a *= b;

	stack.push_vec3(a);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_divide(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	float b = stack.get_float(2);

	*a /= b;

	stack.push_vec3(a);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_dot(lua_State* L)
{
	LuaStack stack(L);
	
	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_float(a->dot(*b));

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_cross(lua_State* L)
{
	LuaStack stack(L);
	
	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	/// CHECK CHECK CHECK
	*a = a->cross(*b);

	stack.push_vec3(a);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_equals(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_bool(*a == *b);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_lower(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_bool(*a < *b);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_greater(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_bool(*a > *b);

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_length(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	stack.push_float(a->length());

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_squared_length(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	stack.push_float(a->squared_length());

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_set_length(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	float len = stack.get_float(2);

	a->set_length(len);

	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_normalize(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	a->normalize();

	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_negate(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	a->negate();

	return 0;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_get_distance_to(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_float(a->get_distance_to(*b));

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_get_angle_between(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);
	Vec3* b = stack.get_vec3(2);

	stack.push_float(a->get_angle_between(*b));

	return 1;
}

//-----------------------------------------------------------------------------
CE_EXPORT int32_t vec3_zero(lua_State* L)
{
	LuaStack stack(L);

	Vec3* a = stack.get_vec3(1);

	a->zero();

	return 0;
}	

//-----------------------------------------------------------------------------
void load_vec3(LuaEnvironment& env)
{
	env.load_module_function("Vec3", "new", 				vec3);
	env.load_module_function("Vec3", "val", 				vec3_values);
	env.load_module_function("Vec3", "add", 				vec3_add);
	env.load_module_function("Vec3", "sub", 				vec3_subtract);
	env.load_module_function("Vec3", "mul", 				vec3_multiply);
	env.load_module_function("Vec3", "div", 				vec3_divide);
	env.load_module_function("Vec3", "dot", 				vec3_dot);
	env.load_module_function("Vec3", "cross", 				vec3_cross);
	env.load_module_function("Vec3", "equals", 				vec3_equals);
	env.load_module_function("Vec3", "lower", 				vec3_lower);
	env.load_module_function("Vec3", "greater", 			vec3_greater);
	env.load_module_function("Vec3", "length", 				vec3_length);
	env.load_module_function("Vec3", "squared_length", 		vec3_squared_length);
	env.load_module_function("Vec3", "set_length", 			vec3_set_length);
	env.load_module_function("Vec3", "normalize", 			vec3_normalize);
	env.load_module_function("Vec3", "negate", 				vec3_negate);
	env.load_module_function("Vec3", "get_distance_to", 	vec3_get_distance_to);
	env.load_module_function("Vec3", "get_angle_between", 	vec3_get_angle_between);
	env.load_module_function("Vec3", "zero", 				vec3_zero);	
}

} // namespace crown