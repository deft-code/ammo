#ifndef AMMO_PHYSIC_ACTUATOR_ACUATOR_HPP_INCLUDED
#define AMMO_PHYSIC_ACTUATOR_ACUATOR_HPP_INCLUDED

#include <list>
#include "ammo/physics/physic.hpp"
#include "ammo/physics/active_physic_sys.hpp"

namespace ammo
{
	class Actuator
	{
	public:
		virtual ~Actuator( void ) { }

		void engine_register( ammo::ActivePhysicSys& system, std::list<Actuator*>::iterator position );
		void engine_unregister( void );

		virtual void attach( Physic p ) = 0;
		virtual void detach( Physic p ) = 0;
		virtual void step( float dt ) = 0;

	protected:
		ammo::ActivePhysicSys& system( void );

	private:
		std::list<Actuator*>::iterator m_position;
		ammo::ActivePhysicSys* m_system;
	};
}

#endif

