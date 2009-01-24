#ifndef AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED

class b2World;

#include "ammo/physics/physic_impl.fwd.hpp"

namespace ammo
{
	class PhysicBluePrint
	{
	public:
		virtual PhysicPimpl Instantiate( b2World& world ) const =0;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
