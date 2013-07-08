#pragma once

#include <stdint.h>
#include "Vec2.h"

using namespace crown;

class Agent;
class Unit;
class Turret;
class Tank;

static const uint32_t AGENTS = 10;
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

	int 		update();
	int 		add_agent(Agent* a);
};