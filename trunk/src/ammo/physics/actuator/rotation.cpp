#include "rotation.hpp"

using namespace ammo;

void Rotation::do_step( float dt )
{
	if( m_active )
	{
		b2Body& body = m_physic.engine_GetBody();

		const float current_angle = body.GetAngle();
		// normalize the angle so that the actuator wont twist the long
		//  way around the circle
		const float delta_angle = Radians(m_tracking_angle - current_angle).normalize().asRadians();

		const float needed_omega = b2Clamp( delta_angle / dt, -m_max_omega, m_max_omega );
		const float delta_omega = needed_omega - body.GetAngularVelocity();

		// T = Iw' : F = ma
		// delta_omega : theta/sec : w => delta_omega/dt : theta/sec/sec : w/sec : w'
		const float needed_torque = body.GetInertia() * delta_omega / dt;

		body.ApplyTorque( b2Clamp( needed_torque, -m_max_torque, m_max_torque ) );
	}
}

