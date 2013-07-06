#include "Agent.h"

#include <stdio.h>


	Agent::Agent(uint32_t health, uint32_t damage, float coord_x, float coord_y, float radius, Factions team, Environment* env) 
	{
		m_killed 	= false;
		m_type 		= TURRET; //TODO, MAYBE NOT

		reset_scan();

		m_health 	= health;
		m_damage 	= damage;

		m_coord_x 	= coord_x;
		m_coord_y 	= coord_y;
		m_radius 	= radius;

		m_team 		= team;

		m_env 		= env;
	}

	int Agent::damage(uint32_t damage)
	{
		m_health -= damage;

		if (m_health <= 0)
			destroy();

		return 0;
	}

	float Agent::area_of_effect()
	{
		return m_radius;
	}


	int Agent::update()
	{
		scan();
		attack();
		reset_scan();

		return 0;
	}

	Type Agent::get_type()
	{
		return m_type;
	}

	int Agent::reset_scan()
	{
		for( uint32_t i=0; i<AGENTS; i++)
			m_agents_trace[i] = 0;

		return 0;
	}

	int Agent::scan()
	{
		for(uint32_t i=0; i<AGENTS; i++)
		{
			// Euclidian norm
			if( (m_coord_x - m_env->m_agents[i]->m_coord_x) * (m_coord_x - m_env->m_agents[i]->m_coord_x) +
				(m_coord_y - m_env->m_agents[i]->m_coord_y) * (m_coord_y - m_env->m_agents[i]->m_coord_y) < m_radius * m_radius)
			{
				if(m_env->m_agents[i]->m_killed == false)
					m_agents_trace[i] = 1;
			}
		}
		return 0;
	}

	int Agent::attack()
	{
		for(uint32_t i=0; i<AGENTS; i++)
		{
			if( (m_agents_trace[i] == 1) && (m_env->m_agents[i]->m_team != m_team))

					m_env->m_agents[i]->damage(m_damage);
		}

		return 0;
	}

	int Agent::destroy()
	{
		m_killed = true;

		return 0;
	}