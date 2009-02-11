#ifndef AMMO_PHYSICS_DEBUG_DRAW_CB_HPP_INCLUDED
#define AMMO_PHYSICS_DEBUG_DRAW_CB_HPP_INCLUDED

#include <Box2D.h>

namespace ammo
{
	class GraphicSys;
	class DebugDrawCB : public b2DebugDraw
	{
	public:
		void SetGraphicSys( GraphicSys& graphic_sys );

		void SetZOrder( float z_order );

		virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	
		virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	
		virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	
		virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	
		virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	
		virtual void DrawXForm(const b2XForm& xf);

	private:
		GraphicSys* _graphic_sys;
		float _z_order;
	};

}

#endif // AMMO_PHYSICS_DEBUG_DRAW_CB_HPP_INCLUDED
