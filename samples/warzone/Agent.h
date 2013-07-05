#pragma once
#include <stdint.h>
#include "Environment.h"

class Environment;

enum Factions {RED = 0, BLUE = 1};

class Agent
{

private:
	int m_agents_trace[AGENTS];

protected:
	// Attributes
	uint32_t m_health;
	uint32_t m_damage;

	float m_radius;

	Environment *m_env;

	bool m_killed : 1;

public: // test
	float m_positionX;
	float m_positionY;
	Factions m_team;

public: // Constructor

	Agent(uint32_t health, uint32_t damage, float positionX, float positionY, float radius, Factions team, Environment* env);

	
public: // Methods
	
	int update();
	int damage(uint32_t damage);

private:
	int scan();
	int attack();
	int destroy();
	int reset_scan();
};

