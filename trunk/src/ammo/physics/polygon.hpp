#ifndef AMMO_PHYSICS_POLYGON_HPP_INCLUDED
#define AMMO_PHYSICS_POLYGON_HPP_INCLUDED

class b2World;

namespace ammo
{
	class Polygon : public PhysicBluePrint
	{
	public:
		b2BodyDef body_blueprint;
		b2PolygonDef polygon_blueprint;

		virtual PhysicPimpl Instantiate(b2World& world) const;
	};
}

#endif // AMMO_PHYSICS_POLYGON_HPP_INCLUDED
