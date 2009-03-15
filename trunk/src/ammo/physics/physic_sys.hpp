/// @file physic_sys.hpp

#ifndef AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED

#include <string>
#include "ammo/physics/physic.hpp"
#include "ammo/physics/physic_blue_print.fwd.hpp"

namespace ammo
{
	class GameObject;

	/// abstract base class for Physic systems
	class PhysicSys
	{
	public:
		/// Add a physic schema to the system
		///
		/// @tparam Schema a sub-class of ammo::PhysicSchema
		/// @param name unique name for new schema
		/// @param schema new schema
		template< typename Schema >
		void AddSchema( const std::string& name, const Schema& schema );

		/// @param name shema name to check
		/// @return whether name refers to a registered schema
		virtual bool IsPhysic( const std::string& name ) const =0;

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @return physic token
		virtual Physic NewPhysic( const std::string& name, GameObject& parent ) =0;

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @param position initial position of physic
		/// @return physic token
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position ) =0;

		/// instantiate a new physic object
		///
		/// @param name name of schema to use
		/// @param parent Game object instantiating the physic
		/// @param position initial position of physic
		/// @param theta initial orientation of physic
		/// @return physic token
		virtual Physic NewPhysic( const std::string& name, GameObject& parent, const b2Vec2& position, float theta ) =0;

		/// called every frame
		/// @param dt seconds elapsed last frame
		virtual void Update( float dt ) =0;

	private:
		/// helper function for AddSchema
		/// @param name new schema name
		/// @param schema the new schema
		virtual void add_bp_ptr( const std::string& name, const PhysicSchema_ptr& bp ) =0;
	};

	template< typename Schema >
	void PhysicSys::AddSchema( const std::string& name, const Schema& bp )
	{
		PhysicSchema_ptr new_bp( new Schema(bp));
		add_bp_ptr( name, new_bp );
	}
}

#endif //  AMMO_PHYSICS_PHYSIC_SYS_HPP_INCLUDED
