#include "physic.hpp"

#include "physic_impl.hpp"

namespace ammo
{

namespace //anonymous
{
	class NullPhysicImpl : public PhysicImpl
	{
	public:
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
	};

} // anonymous namespace

Physic::Physic( void )
 : m_pimpl( new NullPhysicImpl )
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

} // ammo
