#include "single_physic_actuator.hpp"

#include <stdexcept>

using namespace ammo;

void SinglePhysicActuator::attach( Physic p )
{
	if( m_physic.isValid() )
	{
		throw std::runtime_error("over writting previous physic");
	}
	m_physic = p;
}

void SinglePhysicActuator::detach( Physic p )
{
	if( m_physic.isValid() && p != m_physic )
	{
		throw std::runtime_error("removing physic that was never added.");
	}
	m_physic = Physic();
}

void SinglePhysicActuator::step( float dt )
{
	if( m_physic.isValid() )
	{
		do_step(dt);
	}
}
