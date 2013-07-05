#pragma once

#include <stdint.h>

class Agent;

static const uint32_t AGENTS = 10;

class Environment
{
public:
	Agent* m_agents[AGENTS];

	Environment();

	int update();

};