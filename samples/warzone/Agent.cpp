#include "Agent.h"

#include <stdio.h>


	Agent::Agent(uint32_t health, uint32_t damage, float positionX, float positionY, float radius, Factions team, Environment* env) 
	{
		m_killed = false;
		m_type = TURRET;
		reset_scan();

		m_health = health;
		m_damage = damage;
		m_positionX = positionX;
		m_positionY = positionY;
		m_radius = radius;
		m_team = team;

		m_env = env;
	}

	int Agent::damage(uint32_t damage)
	{
		m_health-=damage;
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
		// scan all, attack, move

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
			// control if it's the same Unit (continue)

			//// Euclidian norm
			//if( (m_position.x - m_env[i].m_position.x) * (m_position.x - m_env[i].m_position.x) +
			//	(m_position.y - m_env[i].m_position.y) * (m_position.y - m_env[i].m_position.y) < m_radius)
			//{
			//	// this Unit it's in range
			//	printf("X:%i Y:%i\n", m_env[i].m_position.x, m_env[i].m_position.y);
			//}


			// Euclidian norm
			if( (m_positionX - m_env->m_agents[i]->m_positionX) * (m_positionX - m_env->m_agents[i]->m_positionX) +
				(m_positionY - m_env->m_agents[i]->m_positionY) * (m_positionY - m_env->m_agents[i]->m_positionY) < m_radius * m_radius)
			{
				// this Agent it's in range [i]
				//printf("X: %f Y: %f TEAM: %i\n", m_env->m_agents[i]->m_positionX, m_env->m_agents[i]->m_positionY, m_env->m_agents[i]->m_team);
				if(m_env->m_agents[i]->m_killed == false)
					m_agents_trace[i] = 1;
			}//ciao
		}
		return 0;
	}

	int Agent::attack()
	{
		for(uint32_t i=0; i<AGENTS; i++)
			if( (m_agents_trace[i] == 1) &&
				m_env->m_agents[i]->m_team != m_team)

					m_env->m_agents[i]->damage(m_damage);
		return 0;
	}

	int Agent::destroy()
	{
		m_killed = true;
		return 0;
	}