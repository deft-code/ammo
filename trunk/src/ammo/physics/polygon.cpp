#include "circle.hpp"

#include "physic_impl.hpp"
#include <Box2D.h>

namespace ammo
{
	PhysicPimpl Polygon::Instantiate( b2World& world ) const
	{
		b2Body* body = world.CreateBody( &body_blueprint );
		PhysicPimpl ptr( new SingleBodyImpl(body) );

		body->CreateShape( &polygon_blueprint );
		body->SetMassFromShapes();

		return ptr;
	}
}
