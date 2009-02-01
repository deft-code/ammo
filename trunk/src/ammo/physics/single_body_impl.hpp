#ifndef AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED
#define AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED

#include "ammo/physics/physic_impl.hpp"

#include <Box2D.h>
#include <vector>

namespace ammo
{
	class GameObject;

	class SingleBodyImpl : public PhysicImpl
	{
	public:
		SingleBodyImpl( b2Body& body, GameObject& parent );

		virtual ~SingleBodyImpl( void );

		virtual b2Vec2 GetPosition( void ) const;

		virtual void SetPosition( const b2Vec2& pos );

		virtual b2Vec2 GetVelocity( void ) const;

		virtual void SetVelocity( const b2Vec2& vel );

		virtual float GetTheta( void ) const;

		virtual void SetTheta( float theta );

		virtual float GetOmega( void ) const;

		virtual void SetOmega( float omega );

		virtual GameObject& GetParent( void ) const;

		virtual void AddContact( const b2ContactResult& point, b2Shape* me );
		virtual std::size_t GetNumContacts( void ) const;
		virtual PhysicPimpl GetContactPhysic( std::size_t index ) const;
		virtual const b2ContactResult& GetContact( std::size_t index ) const;

	private:
		b2Body& _body;
		GameObject& _parent;

		std::vector<b2ContactResult> m_contacts;
		std::vector<PhysicPimpl> m_contact_physics;
	};
}

#endif // AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED
