#include "Agent.h"

#include <stdio.h>


	Agent::Agent()
	{
	}

	Agent::Agent(uint32_t health, uint32_t damage, float positionX, float positionY, float radius, Factions team, Environment* env) 
	{
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
		if (m_damage <= 0)
			destroy();
		return 0;
	}

	int Agent::update()
	{
		// scan all, attack, move

		scan();
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
				// this Agent it's in range
				printf("X: %f Y: %f TEAM: %i\n", m_env->m_agents[i]->m_positionX, m_env->m_agents[i]->m_positionY, m_env->m_agents[i]->m_team);
			}
		}
		return 0;
	}

	int Agent::attack(Agent* agents)
	{

	}

	int Agent::destroy()
	{
		//to do
		return 0;
	}