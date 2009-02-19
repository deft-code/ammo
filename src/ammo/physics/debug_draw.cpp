#include "debug_draw.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace ammo
{
	//
	// --- Debug Draw Schema ---
	//
	DebugDrawSchema::DebugDrawSchema( unsigned& physics_generation ) :
		_physics_generation(physics_generation)
	{ }

	GraphicPimpl DebugDrawSchema::load( void ) const
	{
		GraphicPimpl ptr( new DebugDrawImpl(_physics_generation) );
		return ptr;
	}

	//
	// --- Debug Draw Impl ---
	//

	inline const sf::Color convert( const b2Color& color, sf::Uint8 alpha=255 )
	{
		return sf::Color( roundf( 255.f * color.r),
								roundf( 255.f * color.g),
								roundf( 255.f * color.b),
								alpha );
	}

	DebugDrawImpl::DebugDrawImpl( const unsigned& physics_generation ) :
		_physics_generation(physics_generation),
		_initial_generation(physics_generation),
		_visible(true)
	{ }

	bool DebugDrawImpl::done(void) const
	{ return _initial_generation != _physics_generation; }

	void DebugDrawImpl::show( void )
	{ _visible = true; }

	void DebugDrawImpl::hide( void )
	{ _visible = false;	}


	bool DebugDrawImpl::Meta_N(int meta, double& n)
	{
		DebugDraw::Meta meta_enum = (DebugDraw::Meta)meta;

		switch( meta_enum )
		{
			case DebugDraw::Set_Render_Mode:
				_primative.SetRenderMode( (sf::Render::Mode) n );
				return true;

			default:
				return false;
		}
	}

	bool DebugDrawImpl::Meta_VP(int meta, b2Vec2& v, void* p)
	{
		DebugDraw::Meta meta_enum = (DebugDraw::Meta)meta;

		switch( meta_enum )
		{
			case DebugDraw::Add_Vertex:
				{
					const b2Color* color = reinterpret_cast<const b2Color*>(p);
					_primative.AddVertex( v.x, -v.y, convert(*color) );
					return true;
				}

			default:
				return false;
		}
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
