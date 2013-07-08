#include "Agent.h"
#include "Log.h"
#include <stdio.h>

using namespace crown;

//-----------------------------------------------------------------------------
Agent::Agent(const Vec2& pos, Faction team, Environment* env) 
{
	m_type 		= NONE;

	m_health 	= 0;
	m_damage 	= 0;
	m_radius 	= 0.0f;

	m_pos		= pos;
	m_team 		= team;
	m_env 		= env;
}

//-----------------------------------------------------------------------------
int Agent::damage(uint32_t damage)
{
	m_health -= damage;
	return 0;
}

//-----------------------------------------------------------------------------
float Agent::area_of_effect()
{
	return m_radius;
}

//-----------------------------------------------------------------------------
int Agent::update(float dt)
{
	if (is_dead())
	{
		return -1;
	}

	return search_and_destroy();
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
int Agent::search_and_destroy()
{

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
