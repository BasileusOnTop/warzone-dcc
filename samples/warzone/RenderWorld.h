#pragma once

#include "Mat4.h"
using namespace crown;

class RenderWorld
{
public:

	RenderWorld();

	void	init();
	void	frame();
	void	shutdown();

private:

	Mat4	m_projection;
};