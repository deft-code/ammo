#include "single_body_impl.hpp"

#include <Box2D.h>

#include "ammo/game/gameobject.hpp"

namespace ammo
{
	SingleBodyImpl::SingleBodyImpl( b2Body& body, GameObject& parent )
	 : _body(body),
		_parent(parent)
	{
		_body.SetUserData(static_cast<PhysicImpl*>(this));
	}

	SingleBodyImpl::~SingleBodyImpl( void )
	{
		b2World* world = _body.GetWorld();
		world->DestroyBody( &_body );
	}
	
	b2Vec2 SingleBodyImpl::GetPosition( void ) const
	{ return _body.GetPosition(); }
   
	void SingleBodyImpl::SetPosition( const b2Vec2& pos )
	{
		_body.SetXForm( pos, _body.GetAngle() );
	}
	
	b2Vec2 SingleBodyImpl::GetVelocity( void ) const
	{
		return _body.GetLinearVelocity();
	}
	
	void SingleBodyImpl::SetVelocity( const b2Vec2& vel )
	{
		_body.SetLinearVelocity( vel );
	}
	
	float SingleBodyImpl::GetTheta( void ) const
	{
		return _body.GetAngle();
	}
	
	void SingleBodyImpl::SetTheta( float theta )
	{
		_body.SetXForm( _body.GetPosition(), theta );
	}
	
	float SingleBodyImpl::GetOmega( void ) const
	{
		return _body.GetAngularVelocity();
	}
	
	void SingleBodyImpl::SetOmega( float omega )
	{
		_body.SetAngularVelocity( omega );
	}

	GameObject& SingleBodyImpl::GetParent( void ) const
	{
		return _parent;
	}
}
