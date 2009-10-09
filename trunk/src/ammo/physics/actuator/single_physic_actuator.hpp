#ifndef AMMO_PHYSIC_ACTUATOR_SINGLE_PHYSIC_ACTUATOR_HPP_INCLUDED
#define AMMO_PHYSIC_ACTUATOR_SINGLE_PHYSIC_ACTUATOR_HPP_INCLUDED

#include "ammo/physics/actuator/actuator.hpp"
#include "ammo/physics/physic.hpp"

namespace ammo
{
	class SinglePhysicActuator : public Actuator
	{
	public:
		virtual void attach( Physic p );
		virtual void detach( Physic p );
		virtual void step( float dt );

	protected:

		virtual void do_step( float dt ) = 0;

		Physic m_physic;
	};
}

#endif
