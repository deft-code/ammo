#ifndef AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED

class b2World;
class b2Vec2;

#include "ammo/physics/physic_impl.fwd.hpp"

namespace ammo
{
	class GameObject;

	class PhysicSchema
	{
	public:
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent ) const =0;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position ) const =0;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position, float theta ) const =0;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_BLUE_PRINT_HPP_INCLUDED
