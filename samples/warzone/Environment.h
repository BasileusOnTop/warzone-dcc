#pragma once

#include <stdint.h>
#include "Vec2.h"

using namespace crown;

class Agent;
class Unit;
class Turret;
class Tank;
class Medic;

static const uint32_t AGENTS = 1500;
static const uint32_t MAX_SPAWN_POINTS = 6;

class Environment
{

private:

	uint32_t	m_agent_count;

public:

	Agent* 		m_agents[AGENTS];
	Vec2		m_spawn_points[MAX_SPAWN_POINTS];

public:

				Environment();

	uint32_t	agent_count();

	int 		update(float dt);
	void		update_physics(float dt);
	int 		add_agent(Agent* a);

	void		spawn_units();
	void		spawn_red_units();
	void		spawn_blue_units();

	void 		spawn_red_medic();
	void 		spawn_blue_medic();
};