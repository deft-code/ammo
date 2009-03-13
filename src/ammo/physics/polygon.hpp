#ifndef AMMO_PHYSICS_POLYGON_HPP_INCLUDED
#define AMMO_PHYSICS_POLYGON_HPP_INCLUDED


#include <Box2D.h>
#include "ammo/physics/physic_blue_print.hpp"

namespace ammo
{
	class GameObject;

	class Polygon : public PhysicSchema
	{
	public:
		b2BodyDef body;
		b2PolygonDef shape;

		virtual PhysicPimpl Instantiate(b2World& world, GameObject& parent) const;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position ) const;
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position, float theta ) const;
	};
}

#endif // AMMO_PHYSICS_POLYGON_HPP_INCLUDED
