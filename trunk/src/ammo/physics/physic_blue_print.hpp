#ifndef AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED

class b2World;

#include "ammo/physics/physic_impl.fwd.hpp"

namespace ammo
{
	class GameObject;

	class PhysicBluePrint
	{
	public:
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent ) const =0;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
