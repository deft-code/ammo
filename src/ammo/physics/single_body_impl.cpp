#include "single_body_impl.hpp"

#include <Box2D.h>

namespace ammo
{
	SingleBodyImpl::SingleBodyImpl( b2Body* body )
	 : m_body(body)
	{ }

	SingleBodyImpl::~SingleBodyImpl( void )
	{
		b2World* world = m_body->GetWorld();
		world->DestroyBody( m_body );
	}
	
	b2Vec2 SingleBodyImpl::GetPosition( void ) const
	{ return m_body->GetPosition(); }
   
	void SingleBodyImpl::SetPosition( const b2Vec2& pos )
	{
		m_body->SetXForm( pos, m_body->GetAngle() );
	}
	
	b2Vec2 SingleBodyImpl::GetVelocity( void ) const
	{
		return m_body->GetLinearVelocity();
	}
	
	void SingleBodyImpl::SetVelocity( const b2Vec2& vel )
	{
		m_body->SetLinearVelocity( vel );
	}
	
	float SingleBodyImpl::GetTheta( void ) const
	{
		return m_body->GetAngle();
	}
	
	void SingleBodyImpl::SetTheta( float theta )
	{
		m_body->SetXForm( m_body->GetPosition(), theta );
	}
	
	float SingleBodyImpl::GetOmega( void ) const
	{
		return m_body->GetAngularVelocity();
	}
	
	void SingleBodyImpl::SetOmega( float omega )
	{
		m_body->SetAngularVelocity( omega );
	}
}
