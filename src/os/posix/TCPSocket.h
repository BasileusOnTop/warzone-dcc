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

#include "Types.h"

namespace crown
{
namespace os
{

class NetAddress;

/// OS level TCP socket.
class TCPSocket
{
public:

				TCPSocket();
				~TCPSocket();

	// Open connection (server side)
	bool 		open(uint16_t port);

	// Connect (client side)
	bool		connect(const NetAddress& destination);

	// Close connection
	void		close();

	// Send data through socket
	bool 		send(const void* data, size_t size);

	// Receive data through socket
	size_t		receive(void* data, size_t size);

	// Is connection open?
	bool 		is_open();

	// Getter method for socket descriptor
	int 		socket_id();

	// Getter method for active socket descriptor
	int 		active_socket_id();

private:
	
	// Generated by ::socket
	int 		m_socket;

	// Generated by ::accept
	int 		m_active_socket;
};

} // namespace os
} // namespace crown
