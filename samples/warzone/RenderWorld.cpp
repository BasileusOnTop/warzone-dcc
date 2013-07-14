#include "Device.h"
#include "Renderer.h"
#include "DebugRenderer.h"
#include "RenderWorld.h"
#include "OsWindow.h"
#include "Environment.h"
#include "Agent.h"
#include "Turret.h"
#include "Unit.h"
#include "Vec2.h"
#include "Tank.h"
#include "Hq.h"
#include "Medic.h"

//-----------------------------------------------------------------------------
RenderWorld::RenderWorld(Environment* env) :
	m_env(env),
	m_debug(true)
{
}

//-----------------------------------------------------------------------------
void RenderWorld::init()
{
	// Obtain window size
	uint32_t w, h;
	device()->window()->get_size(w, h);

	m_projection.build_projection_ortho_rh((float)w, (float)h, 0.0001f, 100.0f);
}

//-----------------------------------------------------------------------------
void RenderWorld::frame()
{
	DebugRenderer* dr = device()->debug_renderer();

	// Reset matrices to default
	device()->renderer()->set_matrix(MT_MODEL, Mat4::IDENTITY);
	device()->renderer()->set_matrix(MT_PROJECTION, m_projection);
	device()->renderer()->set_matrix(MT_VIEW, Mat4::IDENTITY);
	device()->renderer()->set_clear_color(Color4::BLACK);

	render_bounds();

	// Render all the agents, dynamically selecting the shape of each
	render_agents();
}

//-----------------------------------------------------------------------------
void RenderWorld::shutdown()
{

}

//-----------------------------------------------------------------------------
void RenderWorld::render_agents()
{
	for (uint32_t i = 0; i < m_env->agent_count(); i++)
	{
		Agent* ith = m_env->m_agents[i];

		if (ith->is_dead())
		{
			continue;
		}

		switch (ith->get_type())
		{
			case HQ:
			{
				render_hq((Hq*)ith);
				break;
			}
			case TURRET:
			{
				render_turret((Turret*)ith);
				break;
			}
			case UNIT:
			{
				render_unit((Unit*)ith);
				break;
			}
			case TANK:
			{
				render_tank((Tank*)ith);
				break;
			}
			case MEDIC:
			{
				render_medic((Medic*)ith);
				break;
			}
			// Never
			case NONE:
			{
				break;
			}
		}

		render_health(ith);
	}
}

//-----------------------------------------------------------------------------
bool RenderWorld::debug()
{
	return m_debug;
}

//-----------------------------------------------------------------------------
void RenderWorld::enable_debug(bool enable)
{
	m_debug = enable;
}

//-----------------------------------------------------------------------------
void RenderWorld::render_hq(Hq* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	dr->add_hexagon(Vec3(x, y - 34.64f, -1.0f), 40.0f, team_color(agent->get_faction()), true);
	dr->add_hexagon(Vec3(x, y + 34.64f, -1.0f), 40.0f, team_color(agent->get_faction()), true);

	if (agent->get_faction() == RED)
	{
		dr->add_hexagon(Vec3(x - 60.0f, y, -1.0f), 40.0f, team_color(agent->get_faction()), true);	
	}
	else
	{
		dr->add_hexagon(Vec3(x + 60.0f, y, -1.0f), 40.0f, team_color(agent->get_faction()), true);	
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_turret(Turret* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	// Base shape
	dr->add_hexagon(Vec3(x, y, -1.0f), 25.0f, team_color(agent->get_faction()), true);
	dr->add_hexagon(Vec3(x, y, -1.0f), 10.0f, team_color(agent->get_faction()), true);

	// Gun shape
	Vec2 gun_dir = agent->gun_dir();
	gun_dir *= 50.0f;

	dr->add_line(Vec3(x, y, -1.0f), Vec3(x, y, -1.0f) + Vec3(gun_dir.x, gun_dir.y, -1.0f), team_color(agent->get_faction()), true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_unit(Unit* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	dr->add_circle(Vec3(x, y, -1.0f), 16.0f, team_color(agent->get_faction()), true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_tank(Tank* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	dr->add_rectangle(Vec3(x, y, -1.0f), 16.0f, team_color(agent->get_faction()), true);

	// Gun shape
	Vec2 gun_dir = agent->gun_dir();
	gun_dir *= 30.0f;

	dr->add_line(Vec3(x, y, -1.0f), Vec3(x, y, -1.0f) + Vec3(gun_dir.x, gun_dir.y, -1.0f), team_color(agent->get_faction()), true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_medic(Medic* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	dr->add_circle(Vec3(x, y, -1.0f), 16.0f, team_color(agent->get_faction()), true);
	dr->add_line(Vec3(x - 5.0f, y, -1.0f), Vec3(x + 5.0f, y, -1.0f), team_color(agent-get_faction()), Color::LIMEGREEN, true);
	dr->add_line(Vec3(x, y - 5.0f, -1.0f), Vec3(x, y + 5.0f, -1.0f), team_color(agent-get_faction()), Color::LIMEGREEN, true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_bounds()
{
	DebugRenderer* dr = device()->debug_renderer();

	dr->add_line(Vec3(0.0f, -625.0f/2.0f, -1.0f), Vec3(0.0f, 625.0f/2.0f, -1.0f), Color4::YELLOW, true);
}

//-----------------------------------------------------------------------------
void RenderWorld::render_health(Agent* agent)
{
	DebugRenderer* dr = device()->debug_renderer();
	const float& x = agent->m_pos.x;
	const float& y = agent->m_pos.y;

	// [0.0f..1.0f]
	float health_percent = (float)agent->get_health() / (float)agent->get_initial_health();

	dr->add_line(Vec3(x - 20.0f, y + 35.0f, -1.0f), Vec3(x - 20.0f + (40.0f * health_percent), y + 35.0f, -1.0f), Color4::LIME, true);	

}

//-----------------------------------------------------------------------------
Color4 RenderWorld::team_color(Faction team)
{
	switch (team)
	{
		case RED: return Color4::RED; break;
		case BLUE: return Color4::BLUE; break;
		default: return Color4::YELLOW; break;
	}
}
