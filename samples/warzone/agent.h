#pragma once

#include <stdint.h>

class Environment;

class Agent
{
	// Attributes
	uint32_t m_health;
	uint32_t m_damage;
	uint32_t m_speed;

	float m_positionX;
	float m_positionY;
	float m_radius;

	Environment *m_env; 

public: // Constructor

	Agent(uint32_t health, uint32_t damage, uint32_t speed, float positionX, float positionY, float radius, Environment& env);

	
public: // Methods
	
	int update();
	int damage(uint32_t damage);

private:
	int scan();
	int destroy();

};

