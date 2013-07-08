#pragma once
#include <stdint.h>
#include "Environment.h"
#include "Vec2.h"

using namespace crown;

class Environment;

enum Faction {RED = 0, BLUE = 1};
enum Type {NONE = 0, HQ, TURRET, UNIT, TANK};

class Agent
{
protected:
	int32_t 			m_health;
	uint32_t 			m_damage;

	float 				m_radius;

	Environment* 		m_env;

	Type 				m_type;
	Faction 			m_team;

public:

	Vec2				m_pos;

private:
	int 				search_and_destroy();

public:
	Agent(const Vec2& pos, Faction team, Environment* env);

	virtual int 		update();
	virtual Type 		get_type();
	Faction				get_faction();
	int 				damage(uint32_t damage);
	float 				area_of_effect();
	bool				is_dead() const;


};

