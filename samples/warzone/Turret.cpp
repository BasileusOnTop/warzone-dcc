#include <stdio.h>
#include "Turret.h"
#include "Environment.h"

Turret::Turret(const Vec2& pos, Faction team, Environment* env) 
	:Agent(pos, team, env)
{
	m_health = 1500;
	m_damage = 20;
	m_radius = 150.0f;
	m_type 		= TURRET;
	m_gun_dir	= Vec2(1, 0);
}

//-----------------------------------------------------------------------------
const Vec2& Turret::gun_dir()
{
	return m_gun_dir;
}
