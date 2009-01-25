#ifndef AMMO_PHYSICS_PHYSIC_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_HPP_INCLUDED

#include "ammo/physics/physic_impl.fwd.hpp"
#include "ammo/graphics/icameratarget.hpp"

#include "Box2D.h"

namespace ammo
{
  class Physic : public ICameraTarget
	{
	public:
		Physic( void );
		Physic( const PhysicPimpl& pimpl );

      b2Vec2 GetPosition( void ) const;
      void SetPosition( const b2Vec2& pos );

      b2Vec2 GetVelocity( void ) const;
      void SetVelocity( const b2Vec2& vel );

		float GetTheta( void ) const;
		void SetTheta( float theta );

		float GetOmega( void ) const;
		void SetOmega( float omega );

	private:
		PhysicPimpl m_pimpl;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_HPP_INCLUDED
