#include "Device.h"
#include "Renderer.h"
#include "DebugRenderer.h"
#include "RenderWorld.h"
#include "OsWindow.h"

//-----------------------------------------------------------------------------
RenderWorld::RenderWorld()
{

}

//-----------------------------------------------------------------------------
void RenderWorld::init()
{
	// Obtain window size
	uint32_t w, h;
	device()->window()->get_size(w, h);

	m_projection.build_projection_ortho_rh((float)w, (float)h, 0.1f, 100.0f);
}

//-----------------------------------------------------------------------------
void RenderWorld::frame()
{
	device()->renderer()->set_matrix(MT_MODEL, Mat4::IDENTITY);
	device()->renderer()->set_matrix(MT_PROJECTION, m_projection);
	device()->renderer()->set_matrix(MT_VIEW, Mat4::IDENTITY);

	device()->debug_renderer()->add_line(Vec3(0, 0, 0), Vec3(10, 10, 0), Color4::RED, true);
	device()->debug_renderer()->add_line(Vec3(0, 0, 0), Vec3(10, 5, 0), Color4::RED, true);
	device()->debug_renderer()->add_line(Vec3(0, 0, 0), Vec3(10, 0, 0), Color4::RED, true);

	device()->debug_renderer()->add_sphere(Vec3(0, 0, 0), 50.0f, Color4::RED, true);
}

//-----------------------------------------------------------------------------
void RenderWorld::shutdown()
{

}