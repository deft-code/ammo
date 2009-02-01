#include "physic.hpp"

#include "physic_impl.hpp"
#include "ammo/game/gameobject.hpp"

namespace ammo
{

namespace //anonymous
{
	class NullPhysicImpl : public PhysicImpl
	{
	public:
		NullPhysicImpl( void ) { inc_ref();	}

		virtual b2Vec2 GetPosition(void) const
		{ return b2Vec2_zero; }

		virtual void SetPosition(const b2Vec2& pos) { }

		virtual b2Vec2 GetVelocity(void) const
		{ return b2Vec2_zero; }

		virtual void SetVelocity(const b2Vec2& pos) { }

		virtual float GetTheta(void) const
		{ return 0.f; }

		virtual void SetTheta(float theta) { }

		virtual float GetOmega(void) const
		{ return 0.f; }

		virtual void SetOmega(float theta) { }

		virtual GameObject& GetParent( void ) const
		{ return *reinterpret_cast<GameObject*>(NULL); }

		virtual void AddContact( const b2ContactResult& point, b2Shape* me ) { }

		virtual std::size_t GetNumContacts( void ) const
		{ return 0;	}

		virtual const b2ContactResult& GetContact( std::size_t index ) const
		{ return *reinterpret_cast<b2ContactResult*>(NULL);	}

		virtual PhysicPimpl GetContactPhysic( std::size_t index ) const
		{ return PhysicPimpl();	}
		
	};

	NullPhysicImpl null_impl; //< null object

} // anonymous namespace

Physic::Physic( void )
 : m_pimpl( &null_impl )
{ }

Physic::Physic( const PhysicPimpl& pimpl )
 : m_pimpl( pimpl )
{ }

b2Vec2 Physic::GetPosition( void ) const
{ return m_pimpl->GetPosition();	}

void Physic::SetPosition( const b2Vec2& pos )
{ m_pimpl->SetPosition( pos ); }

b2Vec2 Physic::GetVelocity( void ) const
{ return m_pimpl->GetVelocity();	}

void Physic::SetVelocity( const b2Vec2& vel )
{ m_pimpl->SetVelocity(vel); }

float Physic::GetTheta( void ) const
{ return m_pimpl->GetTheta();	}

void Physic::SetTheta( float theta )
{ m_pimpl->SetTheta(theta); }

float Physic::GetOmega( void ) const
{ return m_pimpl->GetOmega();	}

void Physic::SetOmega( float omega )
{ m_pimpl->SetOmega(omega); }

GameObject& Physic::GetParent( void ) const
{ return m_pimpl->GetParent();	}

} // ammo
