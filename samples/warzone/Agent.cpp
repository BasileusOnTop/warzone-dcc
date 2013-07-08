#include "Agent.h"
#include "Log.h"
#include <stdio.h>

using namespace crown;

Agent::Agent(uint32_t health, uint32_t damage, const Vec2& pos, float radius, Faction team, Environment* env) 
{
	m_type 		= TURRET; //TODO, MAYBE NOT

	m_health 	= health;
	m_damage 	= damage;

	m_pos		= pos;
	m_radius 	= radius;

	m_team 		= team;

	m_env 		= env;
}

int Agent::damage(uint32_t damage)
{
	m_health -= damage;
	return 0;
}

float Agent::area_of_effect()
{
	return m_radius;
}


int Agent::update()
{
	if (is_dead())
	{
		return -1;
	}

	scan();

	return 0;
}

Type Agent::get_type()
{
	return m_type;
}

Faction Agent::get_faction()
{
	return m_team;
}

int Agent::scan()
{
	for(uint32_t i=0; i<m_env->agent_count(); i++)
	{
		Agent* ith = m_env->m_agents[i];

		// If it's me
		if (ith == this)
		{
			continue;
		}

		// Euclidian norm
		if( (m_pos.x - ith->m_pos.x) * (m_pos.x - ith->m_pos.x) +
			(m_pos.y - ith->m_pos.y) * (m_pos.y - ith->m_pos.y) <= m_radius * m_radius)
		{
			if((!ith->is_dead()) && (ith->m_team != m_team))
			{
				ith->damage(m_damage);
				Log::i("ciao");
			}
		}
	}
	return 0;
}


bool Agent::is_dead() const
{
	bool dead = (m_health <= 0);

	Log::i("is_dead() says: %d", m_health);
	return dead;
}
