#include "polygon.hpp"

#include "single_body_impl.hpp"
#include <Box2D.h>

namespace ammo
{
	PhysicPimpl Polygon::Instantiate( b2World& world ) const
	{
		b2Body* body = world.CreateBody( &body_blueprint );
		PhysicPimpl ptr( new SingleBodyImpl(body) );

		body->CreateShape( const_cast<b2PolygonDef*>(&polygon_blueprint) );
		body->SetMassFromShapes();

		return ptr;
	}
}
