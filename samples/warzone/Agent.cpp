#include "Agent.h"
#include "Log.h"
#include <stdio.h>

using namespace crown;

//-----------------------------------------------------------------------------
Agent::Agent(const Vec2& pos, Faction team, int32_t health, Environment* env)
	: m_initial_health(health)
{
	m_type 			= NONE;

	m_health 		= 0;
	m_damage 		= 0;
	m_radius 		= 0.0f;

	m_pos			= pos;
	m_team 			= team;
	m_env 			= env;

	m_cooldown 		= false;
	m_dt_elapsed 	= 0.0f;
}

//-----------------------------------------------------------------------------
int Agent::damage(uint32_t damage)
{
	m_health -= damage;
	Log::i("Id: %p | damage: %i | cur_hp: %i", (void *) this, damage, m_health);
	return 0;
}

//-----------------------------------------------------------------------------
float Agent::area_of_effect()
{
	return m_radius;
}

//-----------------------------------------------------------------------------
Type Agent::get_type()
{
	return m_type;
}

//-----------------------------------------------------------------------------
Faction Agent::get_faction()
{
	return m_team;
}

//-----------------------------------------------------------------------------
bool Agent::is_dead() const
{
	return this->m_health <= 0;
}

//-----------------------------------------------------------------------------
int32_t Agent::get_health()
{
	return m_health;
}

//-----------------------------------------------------------------------------
int32_t Agent::get_initial_health()
{
	return m_initial_health;
}