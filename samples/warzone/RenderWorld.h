#pragma once

#include "Mat4.h"
using namespace crown;

class Environment;
class Agent;

class RenderWorld
{
public:

					RenderWorld(Environment* env);

	void			init();
	void			frame();
	void			shutdown();

	void			render_agents();

private:

	void			render_hq(Agent* agent);
	void			render_turret(Agent* agent);
	void			render_unit(Agent* agent);

	Environment*	m_env;
	Mat4			m_projection;
};
