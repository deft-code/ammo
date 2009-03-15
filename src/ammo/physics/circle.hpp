#ifndef AMMO_PHYSICS_CIRCLE_HPP_INCLUDED
#define AMMO_PHYSICS_CIRCLE_HPP_INCLUDED

#include "ammo/physics/physic_schema.hpp"
#include <Box2D.h>

namespace ammo
{
	class Circle : public PhysicSchema
	{
	public:
		b2BodyDef body;
		b2CircleDef shape;

		virtual PhysicPimpl Instantiate(b2World& world, GameObject& parent) const;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position ) const;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position, float theta ) const;
	};
}
#endif // AMMO_PHYSICS_CIRCLE_HPP_INCLUDED
