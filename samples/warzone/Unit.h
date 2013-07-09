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

public: 
					Unit(const Vec2& pos, Faction team, int32_t health, Environment* env);

	void			set_dir(const Vec2& dir);

protected:

	virtual int 	move(float dt);
	virtual int		update(float dt);
	
};

