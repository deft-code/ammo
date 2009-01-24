#ifndef AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED
#define AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED

#include "ammo/physics/physic_impl.hpp"

class b2Body;

namespace ammo
{
	class SingleBodyImpl : public PhysicImpl
	{
	public:
		SingleBodyImpl( b2Body* body );

		virtual ~SingleBodyImpl( void );

		virtual b2Vec2 GetPosition( void ) const;

		virtual void SetPosition( const b2Vec2& pos );

		virtual b2Vec2 GetVelocity( void ) const;

		virtual void SetVelocity( const b2Vec2& vel );

		virtual float GetTheta( void ) const;

		virtual void SetTheta( float theta );

		virtual float GetOmega( void ) const;

		virtual void SetOmega( float omega );
	private:
		b2Body* m_body;
	};
}

#endif // AMMO_PHYSICS_SINGLE_BODY_IMPL_HPP_INCLUDED
