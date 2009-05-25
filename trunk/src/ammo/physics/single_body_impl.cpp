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
	
	Radians SingleBodyImpl::GetAngle( void ) const
	{
		return Radians(_body.GetAngle());
	}
	
	void SingleBodyImpl::SetAngle( Radians angle )
	{
		_body.SetXForm( _body.GetPosition(), angle.asRadians() );
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

	void SingleBodyImpl::AddContact( const b2ContactResult& point, b2Shape* me )
	{
		m_contacts.push_back( point );
		if( m_contacts.back().shape1 != me )
		{
			b2ContactResult& contact = m_contacts.back();
			std::swap( contact.shape1, contact.shape2 );
			contact.normal = -contact.normal;
			assert( m_contacts.back().shape1 == me );
		}
		PhysicPimpl ptr( reinterpret_cast<PhysicImpl*>( m_contacts.back().shape2->GetBody()->GetUserData() ) );
		m_contact_physics.push_back( ptr );
	}

	std::size_t SingleBodyImpl::GetNumContacts( void ) const
	{
		assert( m_contacts.size() == m_contact_physics.size() );
		return m_contacts.size();
	}

	PhysicPimpl SingleBodyImpl::GetContactPhysic( std::size_t index ) const
	{
		return m_contact_physics.at(index);
	}

	const b2ContactResult& SingleBodyImpl::GetContact( std::size_t index ) const
	{
		return m_contacts.at(index);
	}
}
