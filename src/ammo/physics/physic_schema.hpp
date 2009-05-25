/// @file ammo/physic/physic_schema.hpp

#ifndef AMMO_PHYSICS_PHYSIC_SCHEMA_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_SCHEMA_HPP_INCLUDED

class b2World;
class b2Vec2;

#include "ammo/physics/physic_impl.fwd.hpp"
#include "ammo/util/angle.hpp"

namespace ammo
{
	class GameObject;

	/// abstract base class for all schemas
	class PhysicSchema
	{
	public:

		/// PhysicSchema is a base class
		virtual ~PhysicSchema(void)	{ }

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @see PhysicSys::NewPhysic
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent ) const =0;

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @param position initial position of physic
		/// @return pointer to new physic
		/// @see PhysicSys::NewPhysic
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position ) const =0;

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @param position initial position of physic
		/// @param angle initial orientation of physic
		/// @return pointer to new physic
		/// @see PhysicSys::NewPhysic
		virtual PhysicPimpl Instantiate( b2World& world, GameObject& parent, const b2Vec2& position, Radians angle ) const =0;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_SCHEMA_HPP_INCLUDED
