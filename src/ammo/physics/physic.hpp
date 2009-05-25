#ifndef AMMO_PHYSICS_PHYSIC_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_HPP_INCLUDED

#include "ammo/physics/physic_impl.fwd.hpp"
#include "ammo/graphics/icameratarget.hpp"
#include "ammo/util/angle.hpp"

#include "Box2D.h"

namespace ammo
{
	class GameObject;

	class Physic : public ICameraTarget
	{
	public:
		Physic( void );
		Physic( const PhysicPimpl& pimpl );

      b2Vec2 GetPosition( void ) const;
      void SetPosition( const b2Vec2& pos );

      b2Vec2 GetVelocity( void ) const;
      void SetVelocity( const b2Vec2& vel );

		Radians GetAngle( void ) const;
		void SetAngle( Radians angle );

		float GetOmega( void ) const;
		void SetOmega( float omega );

		GameObject& GetParent( void ) const;

	private:
		PhysicPimpl m_pimpl;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_HPP_INCLUDED
