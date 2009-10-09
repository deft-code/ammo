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

		virtual Radians GetAngle( void ) const;

		virtual void SetAngle( Radians angle );

		virtual float GetOmega( void ) const;

		virtual void SetOmega( float omega );

		virtual GameObject& GetParent( void ) const;

		virtual b2Body& engine_GetBody( void );
	private:
		b2Body& _body;
		GameObject& _parent;
	};
}

#endif // AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED
