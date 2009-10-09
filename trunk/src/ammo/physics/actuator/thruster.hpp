#ifndef AMMO_PHYSIC_ACTUATOR_THRUSTER_HPP_INCLUDED
#define AMMO_PHYSIC_ACTUATOR_THRUSTER_HPP_INCLUDED

#include "ammo/physics/actuator/single_physic_actuator.hpp"
#include "Box2D.h"

namespace ammo
{
	class Thruster : public SinglePhysicActuator
	{
	public:
		Thruster( void ) :
			m_local_position( b2Vec2_zero ),
			m_local_force( 0.f, 1.f )
		{ }

		void setMaxForce( float force )
		{
			const float old_max = m_local_force.Length();
		
			m_local_force *= force/old_max;
		}

		void setStrength( float strength )
		{ m_strength = strength; }

	private:
		virtual void do_step( float dt );

		float m_strength;
		b2Vec2 m_local_position;
		b2Vec2 m_local_force;
	};
}

#endif
