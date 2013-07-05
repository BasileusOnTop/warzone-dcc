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

#include <cstdio>
#include <cstring>

#include "Assert.h"
#include "Types.h"

namespace crown
{
namespace string
{

const char* const	EMPTY = "";

bool				is_alpha(char c);
bool				is_digit(char c);
bool				is_upper(char c);
bool				is_lower(char c);
bool				is_whitespace(char c);

size_t				strlen(const char* str);
const char*			strstr(const char* str1, const char* str2);
int32_t				strcmp(const char* str1, const char* str2);
char*				strcpy(char* dest, const char* src);
char*				strncpy(char* dest, const char* src, size_t len);
char* 				strcat(char* dest, const char* src);
char*				strncat(char* dest, const char* src, size_t len);

const char*			begin(const char* str);
const char*			end(const char* str);

const char*			find_first(const char* str, char c);
const char*			find_last(const char* str, char c);
void				substring(const char* begin, const char* end, char* out, size_t len);

//-----------------------------------------------------------------------------
inline bool is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

//-----------------------------------------------------------------------------
inline bool is_digit(char c)
{
	return !(c < '0' || c > '9');
}

//-----------------------------------------------------------------------------
inline bool is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

//-----------------------------------------------------------------------------
inline bool is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

//-----------------------------------------------------------------------------
inline bool is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

//-----------------------------------------------------------------------------
inline size_t strlen(const char* str)
{
	size_t chars = 0;

	while(*str)
	{
		if ((*str & 0xC0) != 0x80)
		{
			chars++;
		}
		str++;
	}

	return chars;
}

//-----------------------------------------------------------------------------
inline const char* strstr(const char* str1, const char* str2)
{
	return ::strstr(str1, str2);
}

//-----------------------------------------------------------------------------
inline int32_t strcmp(const char* str1, const char* str2)
{
	return ::strcmp(str1, str2);
}

//-----------------------------------------------------------------------------
inline char* strcpy(char* dest, const char* src)
{
	return ::strcpy(dest, src);
}

//-----------------------------------------------------------------------------
inline char* strncpy(char* dest, const char* src, size_t len)
{
	return ::strncpy(dest, src, len);
}

//-----------------------------------------------------------------------------
inline char* strcat(char* dest, const char* src)
{
	return ::strcat(dest, src);
}

//-----------------------------------------------------------------------------
inline char* strncat(char* dest, const char* src, size_t len)
{
	return ::strncat(dest, src, len);
}

//-----------------------------------------------------------------------------
inline const char* begin(const char* str)
{
	CE_ASSERT(str != NULL, "Str must be != NULL");
	
	return str;
}

//-----------------------------------------------------------------------------
inline const char* end(const char* str)
{
	CE_ASSERT(str != NULL, "Str must be != NULL");
	
	return str + string::strlen(str) + 1;
}

//-----------------------------------------------------------------------------
inline const char* find_first(const char* str, char c)
{
	CE_ASSERT(str != NULL, "Str must be != NULL");

	const char* str_begin = string::begin(str);
	
	while (str_begin != string::end(str))
	{
		if ((*str_begin) == c)
		{
			return str_begin;
		}
		
		str_begin++;
	}
	
	return string::end(str);
}

//-----------------------------------------------------------------------------
inline const char* find_last(const char* str, char c)
{
	CE_ASSERT(str != NULL, "Str must be != NULL");
	
	const char* str_end = string::end(str) - 1;
	
	while (str_end != string::begin(str) - 1)
	{
		if ((*str_end) == c)
		{
			return str_end;
		}
		
		str_end--;
	}
	
	return string::end(str);
}

//-----------------------------------------------------------------------------
inline void substring(const char* begin, const char* end, char* out, size_t len)
{
	CE_ASSERT(begin != NULL, "Begin must be != NULL");
	CE_ASSERT(end != NULL, "End must be != NULL");
	CE_ASSERT(out != NULL, "Out must be != NULL");
	
	size_t i = 0;
	
	char* out_iterator = out;

	while (begin != end && i < len)
	{
		(*out_iterator) = (*begin);
		
		begin++;
		out_iterator++;
		i++;
	}

	out[i] = '\0';
}

} // namespace string
} // namespace crown

