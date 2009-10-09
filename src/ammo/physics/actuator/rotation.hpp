#ifndef AMMO_PHYSIC_ACTUATOR_ROTATION_HPP_INCLUDED
#define AMMO_PHYSIC_ACTUATOR_ROTATION_HPP_INCLUDED

#include "ammo/physics/actuator/single_physic_actuator.hpp"

namespace ammo
{
	class Rotation : public SinglePhysicActuator
	{
	public:
		Rotation( void ) :
			m_tracking_angle(0.f),
			m_max_torque(1.f),
			m_max_omega(1.f),
			m_active(true)
		{ }

		void setMaxTorque( float torque )
		{
			assert( torque > 0.f );
			m_max_torque = torque;
		}

		void setMaxOmega( Radians omega )
		{
			assert( omega.asRadians() > 0.f );
			m_max_omega = omega.asRadians();
		}

		void setActive( bool active )
		{
			m_active = active;
		}

		void setAngle( Radians angle )
		{
			m_tracking_angle = angle.asRadians();
		}

	private:
		virtual void do_step( float dt );

		float m_tracking_angle;

		float m_max_torque;
		float m_max_omega;
		bool m_active;
	};
}

#endif
