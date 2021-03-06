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

#include "Types.h"
#include "VertexFormat.h"

namespace crown
{

//-----------------------------------------------------------------------------
size_t Vertex::bits_per_vertex(VertexFormat format)
{
	return bytes_per_vertex(format) * 8;
}

//-----------------------------------------------------------------------------
size_t Vertex::bytes_per_vertex(VertexFormat format)
{
	switch (format)
	{
		case VF_XY_FLOAT_32:
		case VF_UV_FLOAT_32:
		{
			return 8;
		}
		case VF_XYZ_FLOAT_32:
		case VF_UVT_FLOAT_32:
		case VF_XYZ_NORMAL_FLOAT_32:
		{
			return 12;
		}
		case VF_XYZ_UV_XYZ_NORMAL_FLOAT_32:
		{
			return 32;
		}
		case VF_UNKNOWN:
		default:
		{
			return 0;
		}
	}
}

} // namespace crown

