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

	DebugDrawImpl::DebugDrawImpl( const unsigned& physics_generation ) :
		_physics_generation(physics_generation),
		_initial_generation(physics_generation)
	{ }

	bool DebugDrawImpl::done(void) const
	{ return _initial_generation == _physics_generation; }

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
					const sf::Color* color = reinterpret_cast<const sf::Color*>(p);
					_primative.AddVertex( v.x, v.y, *color );
					return true;
				}

			default:
				return false;
		}
	}

	void DebugDrawImpl::draw(sf::RenderWindow& render)
	{
		render.Draw(_primative);
	}
}
