#ifndef AMMO_PHYSICS_CIRCLE_HPP_INCLUDED
#define AMMO_PHYSICS_CIRCLE_HPP_INCLUDED

#include "ammo/physics/physic_blue_print.hpp"
#include <Box2D.h>

namespace ammo
{
	class Circle : public PhysicBluePrint
	{
	public:
		b2BodyDef body_blueprint;
		b2CircleDef circle_blueprint;

		virtual PhysicPimpl Instantiate(b2World& world, GameObject& parent) const;
	};
}
#endif // AMMO_PHYSICS_CIRCLE_HPP_INCLUDED
