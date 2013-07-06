#pragma once

#include <stdint.h>

class Agent;

static const uint32_t AGENTS = 10;

class Environment
{

private:
	uint32_t m_items;
public:
	Agent* m_agents[AGENTS];

	Environment();

	int update();
	int add_agent(Agent a);

};