#include "Device.h"
#include "Renderer.h"
#include "DebugRenderer.h"
#include "RenderWorld.h"
#include "OsWindow.h"
#include "Environment.h"
#include "Agent.h"

//-----------------------------------------------------------------------------
RenderWorld::RenderWorld(Environment* env) :
	m_env(env),
	m_debug(false)
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
	for (uint32_t i = 0; i < AGENTS; i++)
	{
		Agent* ith = m_env->m_agents[i];

		// FIXME FIXME FIXME
		// if (ith->is_dead())
		// {
		// 	continue;
		// }

		switch (ith->get_type())
		{
			case HQ:
			{
				render_hq(ith);
				break;
			}
			case TURRET:
			{
				render_turret(ith);
				break;
			}
			case UNIT:
			{
				render_unit(ith);
				break;
			}
			case NONE:
			default:
			{
				break;
			}
		}
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
void RenderWorld::render_hq(Agent* agent)
{
}

//-----------------------------------------------------------------------------
void RenderWorld::render_turret(Agent* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_positionX;
	const float& y = agent->m_positionY;

	dr->add_hexagon(Vec3(x, y, -1.0f), 25.0f, Color4::RED, true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::render_unit(Agent* agent)
{
	DebugRenderer* dr = device()->debug_renderer();

	const float& x = agent->m_positionX;
	const float& y = agent->m_positionY;

	dr->add_circle(Vec3(x, y, -1.0f), 16.0f, Color4::RED, true);

	if (m_debug)
	{
		dr->add_circle(Vec3(x, y, -1.0f), agent->area_of_effect(), Color4::GREEN, true);
	}
}
