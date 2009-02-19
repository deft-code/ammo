#include "debug_draw.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdarg>

namespace ammo
{
	//
	// --- Debug Draw Schema ---
	//
	DebugDrawSchema::DebugDrawSchema( sf::Render::Mode mode, const unsigned& physics_generation ) :
		_mode(mode),
		_physics_generation(physics_generation)
	{ }

	GraphicPimpl DebugDrawSchema::Instantiate( void ) const
	{
		GraphicPimpl ptr( new DebugDrawImpl(_mode, z_order, _physics_generation) );
		return ptr;
	}

	//
	// --- Debug Draw Impl ---
	//

	inline const sf::Color convert( const b2Color& color, sf::Uint8 alpha=255 )
	{
    
		return sf::Color( floor( (255.f * color.r) + .5f ),
								floor( (255.f * color.g) + .5f ),
								floor( (255.f * color.b) + .5f ),
								alpha );
	}

	DebugDrawImpl::DebugDrawImpl( sf::Render::Mode mode, float z_order, const unsigned& physics_generation ) :
		_physics_generation(physics_generation),
		_initial_generation(physics_generation),
		_visible(true),
		_z_order(z_order),
		_primative( mode )
	{ }

	bool DebugDrawImpl::done(void) const
	{ return _initial_generation != _physics_generation; }

	void DebugDrawImpl::show( void )
	{ _visible = true; }

	void DebugDrawImpl::hide( void )
	{ _visible = false;	}

	float DebugDrawImpl::GetZOrder( void ) const
	{ return _z_order; }

	void DebugDrawImpl::SetZOrder( float z_order )
	{ _z_order = z_order; }

	bool DebugDrawImpl::Meta(int meta, ... )
	{
		if( meta != DebugDraw::Add_Vertex ) return false;

		va_list va;
		va_start(va,meta);

		b2Vec2* v = va_arg(va,b2Vec2*);
		b2Color* c = va_arg(va,b2Color*);
		_primative.AddVertex( v->x, -v->y, convert(*c) );

		va_end(va);

		return true;
	}

	void DebugDrawImpl::draw(sf::RenderWindow& render)
	{
		if( _visible )
		{
			render.Draw(_primative);
		}
	}

	void DebugDrawImpl::update(float dt)
	{
		if( done() )
		{
			hide();
		}
	}
}
