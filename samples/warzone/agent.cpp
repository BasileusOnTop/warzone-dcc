#include <stdio.h>
#include "agent.h"
#include "environment.h"

	Agent::Agent(uint32_t health, uint32_t damage, uint32_t speed, float positionX, float positionY, float radius, Environment& env) 
	{
		m_health = health;
		m_damage = damage;
		m_speed = speed;
		m_positionX = positionX;
		m_positionY = positionY;
		m_radius = radius;

		*m_env = env;
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
		return 0;
	}

	int Agent::scan()
	{
		for(uint32_t i=0; &m_env[i]; i++)
		{
			// control if it's the same agent (continue)

			//// Euclidian norm
			//if( (m_position.x - m_env[i].m_position.x) * (m_position.x - m_env[i].m_position.x) +
			//	(m_position.y - m_env[i].m_position.y) * (m_position.y - m_env[i].m_position.y) < m_radius)
			//{
			//	// this agent it's in range
			//	printf("X:%i Y:%i\n", m_env[i].m_position.x, m_env[i].m_position.y);
			//}

			//// Euclidian norm
			//if( (m_positionX - m_env[i]->m_positionX) * (m_positionX - m_env[i].m_positionX) +
			//	(m_positionY - m_env[i].m_positionY) * (m_positionY - m_env[i].m_positionY) < m_radius)
			//{
			//	// this agent it's in range
			//	printf("X:%i Y:%i\n", m_env[i].m_positionX, m_env[i].m_positionY);
			//}
		}
		return 0;
	}

	int Agent::destroy()
	{
		//to do
		return 0;
	}