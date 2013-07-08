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

public: 
	Unit(const Vec2& pos, Faction team, Environment* env);

private:

	int 			move();
	virtual int		update();
	
};

