#pragma once

#include "Mat4.h"
#include "Agent.h"
using namespace crown;

class Environment;
class Agent;
class Turret;
class Unit;
class Tank;
class Hq;

class RenderWorld
{
public:

					RenderWorld(Environment* env);

	void			init();
	void			frame();
	void			shutdown();

	void			render_agents();

	bool			debug();
	void			enable_debug(bool enable);

private:

	void			render_hq(Hq* agent);
	void			render_turret(Turret* agent);
	void			render_unit(Unit* agent);
	void			render_tank(Tank* agent);
	void			render_bounds();

	Color4			team_color(Faction team);

private:

	bool			m_debug;

	Environment*	m_env;
	Mat4			m_projection;
};
