#pragma once
#include <stdint.h>
#include "Environment.h"
#include "Vec2.h"

using namespace crown;

class Environment;

enum Faction {RED = 0, BLUE = 1};
enum Type {NONE = 0, HQ, TURRET, UNIT, TANK, MEDIC};
const int32_t MAX_HEALTH = 5000;

class Agent
{
protected:
	const int32_t		m_initial_health;
	int32_t 			m_health;
	uint32_t 			m_damage;

	float 				m_radius;

	Environment* 		m_env;

	Type 				m_type;
	Faction 			m_team;

	float				m_dt_elapsed;
	bool				m_cooldown;

public:

	Vec2				m_pos;

public:
	Agent(const Vec2& pos, Faction team, int32_t health, Environment* env);

	virtual int 		update(float dt) = 0;
	virtual Type 		get_type();

	Faction				get_faction();
	int32_t				get_health();
	int32_t				get_initial_health();
	int					damage(uint32_t damage);
	int 				heal(uint32_t health);
	float 				area_of_effect();
	bool				is_dead() const;


};

