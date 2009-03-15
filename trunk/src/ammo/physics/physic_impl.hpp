/// @file ammo/physic/physic_impl.hpp

#ifndef AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED

#include "physic_impl.fwd.hpp"
#include <cstdlib>
struct b2Vec2;
class b2ContactResult;
class b2Shape;

namespace ammo
{
	class GameObject;

	/// All Physic implementations must define this interface
	class PhysicImpl
	{
	public:
		PhysicImpl( void ) : m_ref_count(0) { }

		virtual ~PhysicImpl( void ) { }

		/// @return physic's position
      virtual b2Vec2 GetPosition( void ) const =0;
		/// @param pos physic's new position
      virtual void SetPosition( const b2Vec2& pos ) =0;

		/// @return physic's velocity
      virtual b2Vec2 GetVelocity( void ) const =0;
		/// @param pos physic's new velocity
      virtual void SetVelocity( const b2Vec2& vel ) =0;

		/// @return physic's orientation
		virtual float GetTheta( void ) const =0;
		/// @param pos physic's new orientation
		virtual void SetTheta( float theta ) =0;

		/// @return physic's spin rate
		virtual float GetOmega( void ) const =0;
		/// @param pos physic's new spin rate
		virtual void SetOmega( float omega ) =0;

		/// @return GameObject that instantiated the physic
		virtual GameObject& GetParent( void ) const =0;

		/// Add a contact for this physic
		/// @param point Contact info
		/// @param me which of the two shapes belongs to this physic
		/// @warning for internal use only
		virtual void AddContact( const b2ContactResult& point, b2Shape* me ) =0;

		/// @return number of contacts stored in this physic
		virtual std::size_t GetNumContacts( void ) const =0;

		/// @return other physic involved int contact
		/// @param index contact to inspect
		virtual PhysicPimpl GetContactPhysic( std::size_t index ) const =0;
		/// @return contact info
		/// @param index contact to inspect
		virtual const b2ContactResult& GetContact( std::size_t index ) const =0;

		/// increment the number of references to the physic object
		/// @warning for internal use only
		void inc_ref( void )
		{ ++m_ref_count; }

		/// decrement the number of references to the physic object
		/// @return true if this was the last reference
		/// @warning for internal use only
		bool dec_ref( void )
		{ return !(--m_ref_count); }

		/// @return number of references 
		/// @warning for internal use only
		std::size_t ref_count( void ) const
		{ return m_ref_count; }

	private:
		/// how many references to this physic are there
		std::size_t m_ref_count;
	};

}

#endif // AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
