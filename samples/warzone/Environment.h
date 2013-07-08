#pragma once

#include <stdint.h>

class Agent;
class Unit;
class Turret;

static const uint32_t AGENTS = 10;

class Environment
{

private:

	uint32_t	m_agent_count;

public:

	Agent* 		m_agents[AGENTS];

public:

				Environment();

	uint32_t	agent_count();

	int 		update();
	int 		add_agent(Agent* a);
};