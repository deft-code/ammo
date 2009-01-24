#ifndef AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
#define AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED

class b2Vec2;

namespace ammo
{
	class PhysicImpl
	{
	public:
		virtual ~PhysicImpl( void ) { }

      virtual b2Vec2 GetPosition( void ) const =0;
      virtual void SetPosition( const b2Vec2& pos ) =0;

      virtual b2Vec2 GetVelocity( void ) const =0;
      virtual void SetVelocity( const b2Vec2& vel ) =0;

		virtual float GetTheta( void ) const =0;
		virtual void SetTheta( float theta ) =0;

		virtual float GetOmega( void ) const =0;
		virtual void SetOmega( float omega ) =0;
	};
}

#endif // AMMO_PHYSICS_PHYSIC_IMPL_HPP_INCLUDED
