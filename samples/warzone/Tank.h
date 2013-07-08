#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Unit.h"
#include "Vec2.h"

class Environment;

class Tank : public Unit
{
private:

	uint32_t 			m_cooldown;
	uint32_t 			m_cooldown_actual;

public: 
	Tank(const Vec2& pos, float radius, Faction team, Environment* env);

private:

	int 				move();
	int 				update();
	bool				on_cooldown();
	
};
