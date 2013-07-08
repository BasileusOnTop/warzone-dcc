#include <stdio.h>
#include "Turret.h"
#include "Environment.h"

Turret::Turret(uint32_t health, uint32_t damage, const Vec2& pos, float radius, Faction team, Environment* env) 
	:Agent(health, damage, pos, radius, team, env)
{
	m_type 		= TURRET; //THIS IS OK
	m_gun_dir	= Vec2(1, 0);
}

//-----------------------------------------------------------------------------
const Vec2& Turret::gun_dir()
{
	return m_gun_dir;
}
