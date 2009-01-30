#ifndef AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED

#include "ammo/physics/physic_sys.hpp"
#include "ammo/physics/physic_blue_print.hpp"

#include <Box2D.h>

#include <string>

namespace ammo
{
	class GameObject;

	class PassivePhysicSys : public PhysicSys
	{
	public:
		virtual bool IsPhysic(const std::string& name) const;
		virtual Physic GetPhysic(const std::string& name, GameObject& parent);
		virtual void Update(float dt);
	private:
		virtual void add_bp_ptr( const std::string& name, const PhysicBluePrint_ptr& bp );
	};
}

#endif // AMMO_PHYSICS_PASSIVE_PHYSIC_SYS_HPP_INCLUDED
