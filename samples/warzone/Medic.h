#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Vec2.h"

class Environment;

class Medic: public Agent
{

protected:
	float 		m_speed;
	Vec2		m_dir;;
	uint32_t 	m_heal;

	Vec2		m_last_pos;

public: 
					Medic(const Vec2& pos, Faction team, int32_t health, Environment* env);

	void			set_dir(const Vec2& dir);

protected:

	virtual int 	move(float dt);
	virtual int		update(float dt);
	void 			set_pos(const float dt);
	uint32_t		heal(const uint32_t health);
	
};

