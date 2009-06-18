#ifndef AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED

#include "ammo/physics/physic_sys.hpp"
#include "ammo/physics/physic_schema.hpp"
#include "ammo/physics/debug_draw_cb.hpp"

#include <Box2D.h>

#include <string>
#include <map>

namespace ammo
{
	class GameObject;

	class ActivePhysicSys : public PhysicSys
	{
	public:

		ActivePhysicSys( float stepTime = .05f );

		virtual bool IsPhysic(const std::string& name) const;
		
		virtual Physic NewPhysic( const std::string& name, GameObject& parent );
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position );
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position, Radians angle );
		
		virtual void Update(float dt);

		void EnableDebugDraw( GraphicSys& graphic_sys, float z_order = 0.f );
		void DisableDebugDraw( void );

	private:
		virtual void add_bp_ptr( const std::string& name, const PhysicSchema_ptr& bp );

		PhysicSchema_ptr findSchema( const std::string& name );
		std::map<std::string,PhysicSchema_ptr> m_schemas;

		class ContactListener : public b2ContactListener
		{
		public:
			virtual void Result(const b2ContactResult* point);
		};

		ContactListener m_contact_listener;

		b2World m_world;

		float m_total_time;
		float m_max_time;
		float m_step_time;
		long m_pos_iterations;
		long m_vel_iterations;
		unsigned _generation;

		DebugDrawCB _draw_cb;
	};
}

#endif // AMMO_PHYSICS_ACTIVE_PHYSIC_SYS_HPP_INCLUDED
