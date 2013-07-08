#pragma once
#include <stdint.h>
#include "Environment.h"

class Environment;

enum Factions {RED = 0, BLUE = 1};
enum Type {NONE = 0, HQ, TURRET, UNIT, TANK};

class Agent
{

private:
	int 				m_agents_trace[AGENTS];
	

protected:
	uint32_t 			m_health;
	uint32_t 			m_damage;

	float 				m_radius;

	Environment* 		m_env;

	bool 				m_killed : 1;
	Type 				m_type;

public:
	float 				m_coord_x;
	float 				m_coord_y;
	Factions 			m_team;

private:
	int 				scan();
	int 				attack();
	int 				destroy();
	int 				reset_scan();

public:
	Agent(uint32_t health, uint32_t damage, float coord_x, float coord_y, float radius, Factions team, Environment* env);

	virtual int 		update();
	virtual Type 		get_type();
	int 				damage(uint32_t damage);
	float 				area_of_effect();


};

