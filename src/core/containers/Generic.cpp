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

#include "Generic.h"
#include "Types.h"

namespace crown
{

//-----------------------------------------------------------------------------
Generic::Generic() : m_type(GT_UNDEFINED)
{
}

//-----------------------------------------------------------------------------
Generic::Generic(const Generic& other)
{
	*this = other;
}

//-----------------------------------------------------------------------------
Generic::~Generic()
{
}

//-----------------------------------------------------------------------------
Generic::Generic(int32_t value) : m_type(GT_INT)
{
	m_data.int32_t_value = value;
}

//-----------------------------------------------------------------------------
Generic::Generic(uint32_t value) : m_type(GT_UINT)
{
	m_data.uint32_t_value = value;
}

//-----------------------------------------------------------------------------
Generic::Generic(uint16_t value) : m_type(GT_USHORT)
{
	m_data.uint16_t_value = value;
}

//-----------------------------------------------------------------------------
Generic::Generic(float value) : m_type(GT_FLOAT)
{
	m_data.float_value = value;
}

//-----------------------------------------------------------------------------
Generic::Generic(bool value) : m_type(GT_BOOL)
{
	m_data.bool_value = value;
}

//-----------------------------------------------------------------------------
bool Generic::as_int32_t(int32_t& out) const
{
	if (m_type == GT_INT)
	{
		out = m_data.int32_t_value;
		return true;
	}

	if (m_type == GT_UINT)
	{
		out = (int32_t)m_data.uint32_t_value;
		return true;
	}

	if (m_type == GT_USHORT)
	{
		out = (int32_t)m_data.uint16_t_value;
		return true;
	}

	if (m_type == GT_FLOAT)
	{
		out = (int32_t)m_data.float_value;
		return true;
	}

	if (m_type == GT_BOOL)
	{
		out = m_data.bool_value ? 1 : 0;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
int32_t Generic::as_int32_t() const
{
	int32_t value = 0;
	as_int32_t(value);
	return value;
}

//-----------------------------------------------------------------------------
bool Generic::as_uint32_t(uint32_t& out) const
{
	if (m_type == GT_INT)
	{
		out = (uint32_t)m_data.int32_t_value;
		return true;
	}

	if (m_type == GT_UINT)
	{
		out = m_data.uint32_t_value;
		return true;
	}

	if (m_type == GT_USHORT)
	{
		out = (uint32_t)m_data.uint16_t_value;
		return true;
	}

	if (m_type == GT_FLOAT)
	{
		out = (uint32_t)m_data.float_value;
		return true;
	}

	if (m_type == GT_BOOL)
	{
		out = m_data.bool_value?1:0;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
uint32_t Generic::as_uint32_t() const
{
	uint32_t value = 0;
	as_uint32_t(value);
	return value;
}

//-----------------------------------------------------------------------------
bool Generic::as_uint16_t(uint16_t& out) const
{
	if (m_type == GT_INT)
	{
		out = (uint16_t)m_data.int32_t_value;
		return true;
	}

	if (m_type == GT_UINT)
	{
		out = (uint16_t)m_data.uint32_t_value;
		return true;
	}

	if (m_type == GT_USHORT)
	{
		out = m_data.uint16_t_value;
		return true;
	}

	if (m_type == GT_FLOAT)
	{
		out = (uint16_t)m_data.float_value;
		return true;
	}

	if (m_type == GT_BOOL)
	{
		out = m_data.bool_value?1:0;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
uint16_t Generic::as_uint16_t() const
{
	uint16_t value = 0;
	as_uint16_t(value);
	return value;
}

//-----------------------------------------------------------------------------
bool Generic::as_float(float& out) const
{
	if (m_type == GT_INT)
	{
		out = (float)m_data.int32_t_value;
		return true;
	}

	if (m_type == GT_UINT)
	{
		out = (float)m_data.uint32_t_value;
		return true;
	}

	if (m_type == GT_USHORT)
	{
		out = (float)m_data.uint16_t_value;
		return true;
	}

	if (m_type == GT_FLOAT)
	{
		out = m_data.float_value;
		return true;
	}

	if (m_type == GT_BOOL)
	{
		out = m_data.bool_value?1.0f:0.0f;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
float Generic::as_float() const
{
	float value = 0.0f;
	as_float(value);
	return value;
}

//-----------------------------------------------------------------------------
bool Generic::as_bool(bool& out) const
{
	if (m_type == GT_INT)
	{
		out = m_data.int32_t_value==0?false:true;
		return true;
	}

	if (m_type == GT_UINT)
	{
		out = m_data.uint32_t_value==0?false:true;
		return true;
	}

	if (m_type == GT_USHORT)
	{
		out = m_data.uint16_t_value==0?false:true;
		return true;
	}

	if (m_type == GT_FLOAT)
	{
		//Does it make sense?
		out = m_data.float_value==0.0f?false:true;
		return true;
	}

	if (m_type == GT_BOOL)
	{
		out = m_data.bool_value;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
bool Generic::as_bool() const
{
	bool value = false;
	as_bool(value);
	return value;
}

//-----------------------------------------------------------------------------
bool Generic::operator==(const Generic& other)
{
	if (m_type != other.m_type)
	{
		return false;
	}

	switch (m_type)
	{
		case GT_INT:
			return m_data.int32_t_value == other.m_data.int32_t_value;
			break;
		case GT_UINT:
			return m_data.uint32_t_value == other.m_data.uint32_t_value;
			break;
		case GT_USHORT:
			return m_data.uint16_t_value == other.m_data.uint16_t_value;
			break;
		case GT_FLOAT:
			return m_data.float_value == other.m_data.float_value;
			break;
		case GT_BOOL:
			return m_data.bool_value == other.m_data.bool_value;
			break;
		case GT_UNDEFINED:
			return true;
			break;
	}

	return false;
}

//-----------------------------------------------------------------------------
const Generic& Generic::operator=(const Generic& other)
{
	m_type = other.m_type;

	switch (m_type)
	{
		case GT_INT:
			m_data.int32_t_value = other.m_data.int32_t_value;
			break;
		case GT_UINT:
			m_data.uint32_t_value = other.m_data.uint32_t_value;
			break;
		case GT_USHORT:
			m_data.uint16_t_value = other.m_data.uint16_t_value;
			break;
		case GT_FLOAT:
			m_data.float_value = other.m_data.float_value;
			break;
		case GT_BOOL:
			m_data.bool_value = other.m_data.bool_value;
			break;
		case GT_UNDEFINED:
			//Copy nothing
			break;
	}

	return other;
}

} // namespace crown

