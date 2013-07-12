#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Vec2.h"

class Environment;

class Unit : public Agent
{

protected:
	float 		m_speed;
	Vec2		m_dir;
	Vec2		m_force_dir;
	bool		m_force_dir_f;

	Vec2		m_last_pos;

public: 
					Unit(const Vec2& pos, Faction team, int32_t health, Environment* env);

	void			set_dir(const Vec2& dir);

protected:

	virtual int 	move(float dt);
	virtual int		update(float dt);
	void 			set_pos(const float dt);
	
};

