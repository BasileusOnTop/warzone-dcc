#include <stdio.h>
#include "Turret.h"
#include "Environment.h"

Turret::Turret(uint32_t health, uint32_t damage, float coord_x, float coord_y, float radius, Factions team, Environment* env) 
	:Agent(health, damage, coord_x, coord_y, radius, team, env)
{
	m_type 		= TURRET; //THIS IS OK
}