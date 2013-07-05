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

#include "Compiler.h"
#include "TextureFormat.h"

namespace crown
{

struct TGAHeader
{

	char		id_length;			// 00h  Size of Image ID field
	char		color_map_type;		// 01h  Color map type
	char		image_type;			// 02h  Image type code
	char		c_map_spec[5];		// 03h  Color map origin 05h Color map length 07h Depth of color map entries
	uint16_t	x_offset;			// 08h  X origin of image
	uint16_t	y_offset;			// 0Ah  Y origin of image
	uint16_t	width;				// 0Ch  Width of image
	uint16_t	height;				// 0Eh  Height of image
	char		pixel_depth;     	// 10h  Image pixel size
	char		image_descriptor;	// 11h  Image descriptor byte
};

class TGACompiler : public Compiler
{
public:

					TGACompiler();
					~TGACompiler();

	size_t			compile_impl(const char* resource_path);
	void			write_impl(std::fstream& out_file);

private:

	void			load_uncompressed(std::fstream& in_file);
	void			load_compressed(std::fstream& in_file);
	void			swap_red_blue();

private:

	TGAHeader		m_tga_header;
	uint32_t		m_tga_channels;
	uint32_t		m_tga_size;

	TextureHeader	m_texture_header;
	size_t			m_texture_data_size;
	uint8_t*		m_texture_data;
};

} // namespace crown

