#include "ammo/physics/actuator/actuator.hpp"

using namespace ammo;

void Actuator::engine_register( ActivePhysicSys& system, std::list<Actuator*>::iterator position )
{
	m_system = &system;
	m_position = position;
}

void Actuator::engine_unregister( void )
{
	m_system = NULL;
	m_position = std::list<Actuator*>::iterator();
}

ActivePhysicSys& Actuator::system( void )
{
	return *m_system;
}
