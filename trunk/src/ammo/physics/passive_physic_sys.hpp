#ifndef AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED

#include "ammo/physics/physic_sys.hpp"
#include "ammo/physics/physic_schema.hpp"

#include <Box2D.h>

#include <string>

namespace ammo
{
	class GameObject;

	class PassivePhysicSys : public PhysicSys
	{
	public:
		virtual bool IsPhysic(const std::string& name) const;

		virtual Physic NewPhysic(const std::string& name, GameObject& parent);
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position );
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position, Radians angle );

		virtual void Update(float dt);

	private:
		virtual void add_bp_ptr( const std::string& name, const PhysicSchema_ptr& bp );
	};
}

#endif // AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED
