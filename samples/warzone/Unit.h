#pragma once

#include <stdint.h>
#include "Agent.h"

class Environment;

class Unit : public Agent
{
	uint32_t m_speed;

public: // Constructor

	Unit(void);
	Unit(uint32_t health, uint32_t damage, uint32_t speed, float positionX, float positionY, float radius, Factions team, Environment* env);

};

