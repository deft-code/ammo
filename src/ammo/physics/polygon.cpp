#include "polygon.hpp"

#include "single_body_impl.hpp"
#include <Box2D.h>

namespace ammo
{
	PhysicPimpl Polygon::Instantiate( b2World& world, GameObject& parent ) const
	{
		b2Body* body = world.CreateBody( &body_blueprint );
		assert( body != NULL );
		PhysicPimpl ptr( new SingleBodyImpl( *body, parent) );

		body->CreateShape( const_cast<b2PolygonDef*>(&polygon_blueprint) );
		body->SetMassFromShapes();

		return ptr;
	}
}
