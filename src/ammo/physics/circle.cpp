#include "circle.hpp"

#include "single_body_impl.hpp"

namespace ammo
{
	PhysicPimpl Circle::Instantiate( b2World& world ) const
	{
		b2Body* body = world.CreateBody( &body_blueprint );
		PhysicPimpl ptr( new SingleBodyImpl( body ) );

		body->CreateShape( const_cast<b2CircleDef*>(&circle_blueprint) );
		body->SetMassFromShapes();

		return ptr;
	}
}
