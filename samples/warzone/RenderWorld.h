#pragma once

#include "Mat4.h"
using namespace crown;

class Environment;

class RenderWorld
{
public:

	RenderWorld(Environment* env);

	void	init();
	void	frame();
	void	shutdown();

private:

	Environment*	m_env;
	Mat4			m_projection;
};