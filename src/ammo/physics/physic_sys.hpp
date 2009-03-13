#ifndef AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED

#include <string>
#include "ammo/physics/physic.hpp"
#include "ammo/physics/physic_blue_print.fwd.hpp"

namespace ammo
{
	class GameObject;

	class PhysicSys
	{
	public:
		template< typename BP >
		void AddBluePrint( const std::string& name, const BP& bp );

		virtual bool IsPhysic( const std::string& name ) const =0;

		virtual Physic NewPhysic( const std::string& name, GameObject& parent ) =0;
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position ) =0;
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position, float theta ) =0;

		virtual void Update( float dt ) =0;

	private:
		virtual void add_bp_ptr( const std::string& name, const PhysicSchema_ptr& bp ) =0;
	};

	template< typename BP >
	void PhysicSys::AddBluePrint( const std::string& name, const BP& bp )
	{
		PhysicSchema_ptr new_bp( new BP(bp));
		add_bp_ptr( name, new_bp );
	}
}
#endif //  AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED
