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

#include <cstdlib>

#include "HeapAllocator.h"
#include "Assert.h"

namespace crown
{

//-----------------------------------------------------------------------------
HeapAllocator::HeapAllocator() :
	m_allocated_size(0),
	m_allocation_count(0)
{
}

//-----------------------------------------------------------------------------
HeapAllocator::~HeapAllocator()
{
	CE_ASSERT(m_allocation_count == 0 && allocated_size() == 0,
		"Missing %d deallocations causing a leak of %d bytes", m_allocation_count, allocated_size());
}

//-----------------------------------------------------------------------------
void* HeapAllocator::allocate(size_t size, size_t align)
{
	size_t actual_size = actual_allocation_size(size, align);

	Header* h = (Header*)malloc(actual_size);
	h->size = actual_size;

	void* data = memory::align_top(h + 1, align);

	pad(h, data);

	m_allocated_size += actual_size;
	m_allocation_count++;

	return data;
}

//-----------------------------------------------------------------------------
void HeapAllocator::deallocate(void* data)
{
	Header* h = header(data);

	m_allocated_size -= h->size;
	m_allocation_count--;

	free(h);
}

//-----------------------------------------------------------------------------
size_t HeapAllocator::allocated_size()
{
	return m_allocated_size;
}

//-----------------------------------------------------------------------------
size_t HeapAllocator::get_size(void* data)
{
	Header* h = header(data);

	return h->size;
}

//-----------------------------------------------------------------------------
size_t HeapAllocator::actual_allocation_size(size_t size, size_t align)
{
	return size + align + sizeof(Header);
}

//-----------------------------------------------------------------------------
HeapAllocator::Header* HeapAllocator::header(void* data)
{
	uint32_t* ptr = (uint32_t*)data;
	ptr--;

	while (*ptr == memory::PADDING_VALUE)
	{
		ptr--;
	}

	return (Header*)ptr;
}

//-----------------------------------------------------------------------------
void* HeapAllocator::data(Header* header, size_t align)
{
	return memory::align_top(header + 1, align);
}

//-----------------------------------------------------------------------------
void HeapAllocator::pad(Header* header, void* data)
{
	uint32_t* p = (uint32_t*)(header + 1);

	while (p != (uint32_t*)data)
	{
		*p = memory::PADDING_VALUE;
		p++;
	}
}

} // namespace crown

