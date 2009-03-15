#include "polygon.hpp"

#include "single_body_impl.hpp"
#include <Box2D.h>

namespace ammo
{
	PhysicPimpl Polygon::Instantiate( b2World& world, GameObject& parent ) const
	{
		return Instantiate(world, parent, body.position, body.angle);
	}

	PhysicPimpl Polygon::Instantiate( b2World& world, GameObject& parent, const b2Vec2& position ) const
	{
		return Instantiate(world, parent, position, body.angle );
	}

	PhysicPimpl Polygon::Instantiate( b2World& world, GameObject& parent, const b2Vec2& position, float theta ) const
	{
		b2BodyDef local = body;
		local.userData = &parent;
		local.position = position;
		local.angle = theta;

		b2Body* body_ptr = world.CreateBody( &local );
		assert( body_ptr != NULL );
		body_ptr->CreateShape( const_cast<b2PolygonDef*>(&shape) );
		body_ptr->SetMassFromShapes();

		return PhysicPimpl( new SingleBodyImpl( *body_ptr, parent ) );
	}

	void intrusive_ptr_add_ref( PhysicImpl* ptr )
	{ ptr->inc_ref();	}

	void intrusive_ptr_release( PhysicImpl* ptr )
	{
		if( ptr->dec_ref() )
			delete ptr;
	}
}
