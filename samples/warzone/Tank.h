#pragma once

#include <stdint.h>
#include "Agent.h"
#include "Unit.h"
#include "Vec2.h"

class Environment;

class Tank : public Unit
{
private:

	float 			m_cooldown;

public: 
	Tank(const Vec2& pos, Faction team, int32_t health, Environment* env);

private:

	int 			update(float dt);
	bool			on_cooldown();
	
};
