#include "Device.h"
#include "Renderer.h"
#include "DebugRenderer.h"
#include "RenderWorld.h"
#include "OsWindow.h"
#include "Environment.h"
#include "Agent.h"

//-----------------------------------------------------------------------------
RenderWorld::RenderWorld(Environment* env) :
	m_env(env)
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

	device()->renderer()->set_matrix(MT_MODEL, Mat4::IDENTITY);
	device()->renderer()->set_matrix(MT_PROJECTION, m_projection);
	device()->renderer()->set_matrix(MT_VIEW, Mat4::IDENTITY);

	dr->add_line(Vec3(0, 0, 0), Vec3(15, 0, 15), Color4::RED, true);
	dr->add_line(Vec3(0, 0, 0), Vec3(15, 15, 0), Color4::RED, true);
	dr->add_line(Vec3(0, 0, 0), Vec3(0, 15, 15), Color4::RED, true);

	//dr->add_sphere(Vec3(0, 0, -25), 50.0f, Color4::RED, true);

	dr->add_hexagon(Vec3(50, 50, -1.0f), 16.0f, Color4::RED, true);

	for (uint32_t i = 0; i < AGENTS; i++)
	{
		const float& x = m_env->m_agents[i]->m_positionX;
		const float& y = m_env->m_agents[i]->m_positionY;

		dr->add_hexagon(Vec3(x, y, -1.0f), 16.0f, Color4::RED, true);
	}
}

//-----------------------------------------------------------------------------
void RenderWorld::shutdown()
{

}