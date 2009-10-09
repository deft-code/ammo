#include "thruster.hpp"
#include <cmath>

using namespace ammo;

void Thruster::do_step( float dt )
{
	if( m_strength != 0.f )
	{
		b2Body& body = m_physic.engine_GetBody();

		const b2Vec2 world_position = body.GetWorldPoint( m_local_position );
		const b2Vec2 world_force = body.GetWorldVector( m_local_force );

		body.ApplyForce( world_position, m_strength * world_force);
	}
}
