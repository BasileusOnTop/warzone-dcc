#pragma once

#include <stdint.h>
#include "Agent.h"

class Environment;

class Turret : public Agent
{

public:
	const float 			m_coord_x;
	const float 			m_coord_y;

public:
	Turret(uint32_t health, uint32_t damage, float coord_x, float coord_y, float radius, Factions team, Environment* env);

};

