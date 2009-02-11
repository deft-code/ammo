#include "debug_draw_cb.hpp"
#include "ammo/graphics.hpp"
#include "debug_draw.hpp"

namespace ammo
{
	void DebugDrawCB::
	SetGraphicSys( GraphicSys& graphic_sys )
	{
		_graphic_sys = &graphic_sys;
	}

	void DebugDrawCB::
	SetZOrder( float z_order )
	{
		_z_order = z_order;
	}

	void DebugDrawCB::
	DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Line_Loop );

		for( int32 i=vertexCount-1; i>=0; --i )
		{
			prim.Meta_VP( DebugDraw::Add_Vertex, vertices[i], &color );
		}
	}
	
	void DebugDrawCB::
	DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Polygon );

		Graphic outline = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order + 0.1f );
		outline.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Line_Loop );

		const b2Color outline_color(0.f, 0.f, 0.f);
		for( int32 i=vertexCount-1; i>0; --i )
		{
			prim.Meta_VP( DebugDraw::Add_Vertex, vertices[i], &color );
			outline.Meta_VP( DebugDraw::Add_Vertex, vertices[i], &outline_color );
		}
		prim.Meta_VP( DebugDraw::Add_Vertex, vertices[0], &color );
		outline.Meta_VP( DebugDraw::Add_Vertex, vertices[0], &outline_color );
	}
	
	void DebugDrawCB::
	DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
	{
		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Line_Loop );

		const float angle_step = 2.f * b2_pi * (1.f/11.f);
		for( float angle=2.f * b2_pi; angle>0.f; angle -= angle_step )
		{
			const b2Vec2 vert = center + radius*b2Vec2(std::cos(angle),std::sin(angle));
			prim.Meta_VP( DebugDraw::Add_Vertex, vert, &color );
		}
	}
	
	void DebugDrawCB::
	DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
	{
		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Polygon );

		Graphic outline = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order + 0.1f );
		outline.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Line_Strip );

		const b2Color outline_color(0.f, 0.f, 0.f);

		outline.Meta_VP( DebugDraw::Add_Vertex, center, &outline_color );

		float angle = std::atan2(axis.y,axis.x);
		const float angle_step = 2.f * b2_pi * (1.f/11.f);
		for( unsigned i=0; i<11; ++i )
		{
			const b2Vec2 vert = center + radius*b2Vec2(std::cos(angle),std::sin(angle));
			prim.Meta_VP( DebugDraw::Add_Vertex, vert, &color );
			outline.Meta_VP( DebugDraw::Add_Vertex, vert, &outline_color );
			angle -= angle_step;
		}

		const b2Vec2 vert = center + radius*axis;
		outline.Meta_VP( DebugDraw::Add_Vertex, vert, &outline_color );
   }
   
	void DebugDrawCB::
	DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
	{
		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Lines );
		prim.Meta_VP( DebugDraw::Add_Vertex, p1, &color );
		prim.Meta_VP( DebugDraw::Add_Vertex, p2, &color );
	}
	
	void DebugDrawCB::
	DrawXForm(const b2XForm& xf)
	{
		b2Vec2 p1 = xf.position;
		b2Vec2 p2;
		const float32 k_axisScale = 0.4f;
		b2Color color( 1.f, 0.f, 0.f );

		Graphic prim = _graphic_sys->getGraphic("debug_draw");
		prim.SetZOrder( _z_order );
		prim.Meta_N( DebugDraw::Set_Render_Mode, sf::Render::Lines );

		prim.Meta_VP( DebugDraw::Add_Vertex, p1, &color );
		p2 = p1 + k_axisScale * xf.R.col1;
		prim.Meta_VP( DebugDraw::Add_Vertex, p2, &color );

		color.r =0.f;
		color.g =1.f;
		color.b =0.f;

		prim.Meta_VP( DebugDraw::Add_Vertex, p1, &color );
		p2 = p1 + k_axisScale * xf.R.col2;
		prim.Meta_VP( DebugDraw::Add_Vertex, p2, &color );
	}

}
