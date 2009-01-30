#include "circle.hpp"

#include "single_body_impl.hpp"
#include "ammo/game/gameobject.hpp"

namespace ammo
{
	PhysicPimpl Circle::Instantiate( b2World& world, GameObject& parent ) const
	{
		b2Body* body = world.CreateBody( &body_blueprint );
		assert( body != NULL );
		PhysicPimpl ptr( new SingleBodyImpl( *body, parent ) );

		body->CreateShape( const_cast<b2CircleDef*>(&circle_blueprint) );
		body->SetMassFromShapes();

		return ptr;
	}
}
