#include "active_physic_sys.hpp"
#include "physic_impl.hpp"
#include "../error.hpp"

namespace ammo
{
	static b2AABB s_world_aabb = { b2Vec2(-1000.f,-1000.f), b2Vec2(1000.f,1000.f) };

	ActivePhysicSys::ActivePhysicSys( void )
	 : m_world( s_world_aabb, b2Vec2_zero, true ),
		m_total_time(0.f),
		m_max_time(1.f),
		m_step_time(0.5f), // 20 frames per second
		m_pos_iterations(10),
		m_vel_iterations(10)
	{ }

	bool ActivePhysicSys::IsPhysic(const std::string& name) const
	{
		return m_blueprints.find(name) != m_blueprints.end();
	}

	Physic ActivePhysicSys::GetPhysic(const std::string& name)
	{
		std::map<std::string,PhysicBluePrint_ptr>::iterator found =
			m_blueprints.find(name);

		if( found == m_blueprints.end() )
		{
			throw Error(Errors::e_Missing_Definition, name );
		}

		PhysicPimpl ptr( found->second->Instantiate(m_world) );

		return Physic(ptr);
	}
	
	void ActivePhysicSys::Update(float dt)
	{
		m_total_time += dt;
		m_total_time = std::min(m_total_time,m_max_time);
		while( m_total_time > m_step_time )
		{
			m_world.Step(m_step_time,m_pos_iterations, m_vel_iterations);
			m_total_time -= m_step_time;
		}
	}
	
	void ActivePhysicSys::add_bp_ptr( const std::string& name, const PhysicBluePrint_ptr& bp )
	{
		bool success = m_blueprints.insert( std::make_pair(name,bp) ).second;

		if( ! success )
		{
			throw Error( Errors::e_Overwrite_Definition );
		}
	}
}
