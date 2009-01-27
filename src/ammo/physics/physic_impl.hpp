#ifndef AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED

#include <cstdlib>
class b2Vec2;

namespace ammo
{
	class PhysicImpl
	{
	public:
		PhysicImpl( void ) : m_ref_count(0) { }
		virtual ~PhysicImpl( void ) { }

      virtual b2Vec2 GetPosition( void ) const =0;
      virtual void SetPosition( const b2Vec2& pos ) =0;

      virtual b2Vec2 GetVelocity( void ) const =0;
      virtual void SetVelocity( const b2Vec2& vel ) =0;

		virtual float GetTheta( void ) const =0;
		virtual void SetTheta( float theta ) =0;

		virtual float GetOmega( void ) const =0;
		virtual void SetOmega( float omega ) =0;

		void inc_ref( void )
		{ ++m_ref_count; }

		bool dec_ref( void )
		{ return !(--m_ref_count); }

		std::size_t ref_count( void ) const
		{ return m_ref_count; }

	private:
		std::size_t m_ref_count;
	};

	inline void intrusive_ptr_add_ref( PhysicImpl* ptr )
	{ ptr->inc_ref();	}

	inline void intrusive_ptr_release( PhysicImpl* ptr )
	{
		if( ptr->dec_ref() )
			delete ptr;
	}
}

#endif // AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
