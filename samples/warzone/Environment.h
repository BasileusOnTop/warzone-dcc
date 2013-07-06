#pragma once

#include <stdint.h>

class Agent;
class Unit;

static const uint32_t AGENTS = 10;

class Environment
{

private:
	uint32_t 	m_items; // number of agents

public:
	Agent* 		m_agents[AGENTS];

	Environment();

	int 		update();
	int 		add_agent(Agent* a);
	int 		add_agent(Unit* a);

};