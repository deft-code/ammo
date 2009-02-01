#include "passive_physic_sys.hpp"
#include "physic_impl.hpp"

namespace ammo
{
	namespace // anonymous
	{
		class PassivePhysicImpl : public PhysicImpl
		{
		public:
			PassivePhysicImpl( GameObject& parent )
			 : m_pos(b2Vec2_zero),
				m_vel(b2Vec2_zero),
				m_theta(0.f),
				m_omega(0.f),
				_parent(parent)
			{ }

			virtual b2Vec2 GetPosition( void ) const
			{ return m_pos; }

			virtual void SetPosition( const b2Vec2& pos )
			{ m_pos = pos;	}

			virtual b2Vec2 GetVelocity( void ) const
			{ return m_vel; }

			virtual void SetVelocity( const b2Vec2& vel )
			{ m_vel = vel;	}

			virtual float GetTheta( void ) const
			{ return m_theta;	}

			virtual void SetTheta( float theta )
			{ m_theta = theta; }

			virtual float GetOmega( void ) const
			{ return m_omega;	}

			virtual void SetOmega( float omega )
			{ m_omega = omega; }

			virtual GameObject& GetParent( void ) const
			{ return _parent;	}

			virtual void AddContact( const b2ContactResult& point, b2Shape* me ) { }

			virtual std::size_t GetNumContacts( void ) const
			{ return 0;	}

			virtual const b2ContactResult& GetContact( std::size_t index ) const
			{ return *reinterpret_cast<b2ContactResult*>(NULL); }

			virtual PhysicPimpl GetContactPhysic( std::size_t index ) const
			{ return PhysicPimpl();	}

		private:
			b2Vec2 m_pos;
			b2Vec2 m_vel;
			float m_theta;
			float m_omega;
			GameObject& _parent;
		};
	} // anonymous namespace
	
	bool PassivePhysicSys::IsPhysic(const std::string& name) const
	{ return true;	}
	
	Physic PassivePhysicSys::GetPhysic(const std::string& name, GameObject& parent)
	{
		PhysicPimpl ptr( new PassivePhysicImpl(parent) );
		return Physic(ptr);
	}
	
	void PassivePhysicSys::Update(float dt) {	}
	
	void PassivePhysicSys::add_bp_ptr( const std::string& name, const PhysicBluePrint_ptr& bp ) { }
}
