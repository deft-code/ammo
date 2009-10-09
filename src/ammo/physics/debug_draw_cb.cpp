#include "debug_draw_cb.hpp"
#include "ammo/graphics.hpp"
#include "debug_draw.hpp"

#include <cmath>

namespace ammo
{
	DebugDrawCB::DebugDrawCB( const unsigned& physics_generation ) :
		_polygon(    sf::Render::Polygon,    physics_generation),
		_line_loop(  sf::Render::Line_Loop,  physics_generation),
		_line_strip( sf::Render::Line_Strip, physics_generation),
		_lines(      sf::Render::Lines,      physics_generation),
		_outline_color( 0.f, 0.f, 0.f )
	{ }

	void DebugDrawCB::
	SetGraphicSys( GraphicSys& graphic_sys )
	{
		_graphic_sys = &graphic_sys;
	}

	void DebugDrawCB::
	SetZOrder( float z_order )
	{
		_polygon.z_order =    z_order;
		_line_loop.z_order =  z_order + 0.1f;
		_line_strip.z_order = z_order + 0.1f;
		_lines.z_order =      z_order + 0.1f;
	}

	void DebugDrawCB::
	DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		Graphic prim = _graphic_sys->NewGraphic(_line_loop);

		for( int32 i=vertexCount-1; i>=0; --i )
		{
			prim.Impl().Meta( DebugDraw::Add_Vertex, &vertices[i], &color );
		}
	}
	
	void DebugDrawCB::
	DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		Graphic prim = _graphic_sys->NewGraphic(_polygon);
		Graphic outline = _graphic_sys->NewGraphic(_line_loop);

		for( int32 i=vertexCount-1; i>0; --i )
		{
			prim.Impl().Meta( DebugDraw::Add_Vertex, &vertices[i], &color );
			outline.Impl().Meta( DebugDraw::Add_Vertex, &vertices[i], &_outline_color );
		}
		prim.Impl().Meta( DebugDraw::Add_Vertex, &vertices[0], &color );
		outline.Impl().Meta( DebugDraw::Add_Vertex, &vertices[0], &_outline_color );
	}
	
	void DebugDrawCB::
	DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
	{
		Graphic prim = _graphic_sys->NewGraphic(_line_loop);

		const float angle_step = 2.f * b2_pi * (1.f/11.f);
		for( float angle=2.f * b2_pi; angle>0.f; angle -= angle_step )
		{
			const b2Vec2 vert = center + radius*b2Vec2(std::cos(angle),std::sin(angle));
			prim.Impl().Meta( DebugDraw::Add_Vertex, &vert, &color );
		}
	}
	
	void DebugDrawCB::
	DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
	{
		Graphic prim = _graphic_sys->NewGraphic(_polygon);
		Graphic outline = _graphic_sys->NewGraphic(_line_strip);

		outline.Impl().Meta( DebugDraw::Add_Vertex, &center, &_outline_color );

		float angle = std::atan2(axis.y,axis.x);
		const float angle_step = 2.f * b2_pi * (1.f/11.f);
		for( unsigned i=0; i<11; ++i )
		{
			const b2Vec2 vert = center + radius*b2Vec2(std::cos(angle),std::sin(angle));
			prim.Impl().Meta( DebugDraw::Add_Vertex, &vert, &color );
			outline.Impl().Meta( DebugDraw::Add_Vertex, &vert, &_outline_color );
			angle -= angle_step;
		}

		const b2Vec2 vert = center + radius*axis;
		outline.Impl().Meta( DebugDraw::Add_Vertex, &vert, &_outline_color );
   }
   
	void DebugDrawCB::
	DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
	{
		Graphic prim = _graphic_sys->NewGraphic(_lines);
		prim.Impl().Meta( DebugDraw::Add_Vertex, &p1, &color );
		prim.Impl().Meta( DebugDraw::Add_Vertex, &p2, &color );
	}
	
	void DebugDrawCB::
	DrawXForm(const b2XForm& xf)
	{
		b2Vec2 p1 = xf.position;
		b2Vec2 p2;
		const float32 k_axisScale = 0.4f;
		b2Color color( 1.f, 0.f, 0.f );

		Graphic prim = _graphic_sys->NewGraphic(_lines);

		prim.Impl().Meta( DebugDraw::Add_Vertex, &p1, &color );
		p2 = p1 + k_axisScale * xf.R.col1;
		prim.Impl().Meta( DebugDraw::Add_Vertex, &p2, &color );

		color.r =0.f;
		color.g =1.f;
		color.b =0.f;

		prim.Impl().Meta( DebugDraw::Add_Vertex, &p1, &color );
		p2 = p1 + k_axisScale * xf.R.col2;
		prim.Impl().Meta( DebugDraw::Add_Vertex, &p2, &color );
	}

}
