#pragma once

#include <stdint.h>

class Agent;

static const uint32_t AGENTS = 10;

class Environment
{
	Agent* m_agents[AGENTS];

public:
	Environment();

	int update();

};