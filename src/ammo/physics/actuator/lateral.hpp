#ifndef AMMO_PHYSIC_ACTUATOR_LATERAL_HPP_INCLUDED
#define AMMO_PHYSIC_ACTUATOR_LATERAL_HPP_INCLUDED

#include "ammo/physics/actuator/single_physic_actuator.hpp"

namespace ammo
{
	class Lateral : public SinglePhysicActuator
	{
	public:
		Lateral( void ) :
			m_max_force(1),
			m_local_lateral(1.f,0.f)
		{ }

		void setMaxForce( float force )
		{ m_max_force = force; }

		void setLocalDirection( const b2Vec2& dir )
		{
			m_local_lateral.Set( -dir.y, dir.x );
			m_local_lateral.Normalize();
		}

	private:
		virtual void do_step( float dt );

		float m_max_force;
		b2Vec2 m_local_lateral;
	};
}

#endif
