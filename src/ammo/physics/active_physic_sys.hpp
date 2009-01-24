#ifndef AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED

#include "ammo/physics/physic_sys.hpp"
#include "ammo/physics/physic_blue_print.hpp"

#include <Box2D.h>

#include <string>
#include <map>

namespace ammo
{
	class ActivePhysicSys : public PhysicSys
	{
	public:

		ActivePhysicSys( void );

		virtual bool IsPhysic(const std::string& name) const;
		
		virtual Physic GetPhysic(const std::string& name);
		
		virtual void Update(float dt);

	private:
		virtual void add_bp_ptr( const std::string& name, const PhysicBluePrint_ptr& bp );

		std::map<std::string,PhysicBluePrint_ptr> m_blueprints;

		b2World m_world;

		float m_total_time;
		float m_max_time;
		float m_step_time;
		long m_pos_iterations;
		long m_vel_iterations;
	};
}

#endif // AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED