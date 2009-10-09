#include "lateral.hpp"

using namespace ammo;

void Lateral::do_step( float dt )
{
	b2Body& body = m_physic.engine_GetBody();

	const b2Vec2 world_lateral = body.GetWorldVector( m_local_lateral );

	const float lateral_velocity = b2Dot( body.GetLinearVelocity(), world_lateral );

	const float force = body.GetMass() * lateral_velocity / dt;

	const b2Vec2 corrective_force = b2Clamp( -force, -m_max_force, m_max_force ) * world_lateral;

	body.ApplyForce( corrective_force, body.GetWorldCenter() );
}
