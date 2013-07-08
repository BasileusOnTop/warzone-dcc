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
	Tank(const Vec2& pos, Faction team, Environment* env);

private:

	int 				move(float dt);
	int 				update(float dt);
	bool				on_cooldown();
	
};
