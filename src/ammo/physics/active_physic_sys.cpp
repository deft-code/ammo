#include "active_physic_sys.hpp"
#include "physic_impl.hpp"
#include "../error.hpp"
#include "ammo/game/gameobject.hpp"
#include "debug_draw.hpp"

namespace ammo
{
	static b2AABB s_world_aabb = { b2Vec2(-1000.f,-1000.f), b2Vec2(1000.f,1000.f) };

	ActivePhysicSys::ActivePhysicSys( void )
	 : m_world( s_world_aabb, b2Vec2_zero, true ),
		m_total_time(0.f),
		m_max_time(1.f),
		m_step_time(0.05f), // 20 frames per second
		m_pos_iterations(10),
		m_vel_iterations(10),
		_generation(0)
	{ }

	bool ActivePhysicSys::IsPhysic(const std::string& name) const
	{
		return m_blueprints.find(name) != m_blueprints.end();
	}

	Physic ActivePhysicSys::GetPhysic(const std::string& name, GameObject& parent )
	{
		std::map<std::string,PhysicBluePrint_ptr>::iterator found =
			m_blueprints.find(name);

		if( found == m_blueprints.end() )
		{
			throw Error(Errors::e_Missing_Definition, name );
		}

		PhysicPimpl ptr( found->second->Instantiate( m_world, parent) );

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
			++_generation;
		}
	}

	void ActivePhysicSys::EnableDebugDraw( GraphicSys& graphic_sys, float z_order )
	{
		graphic_sys.RemoveBluePrint("debug_draw");
		DebugDrawSchema draw_schema(_generation);
		graphic_sys.AddBluePrint("debug_draw", draw_schema );
		_draw_cb.SetGraphicSys(graphic_sys);
		_draw_cb.SetFlags( b2DebugDraw::e_aabbBit | b2DebugDraw::e_shapeBit );
		_draw_cb.SetZOrder( z_order );
	}
	
	void ActivePhysicSys::DisableDebugDraw( void  )
	{
		_draw_cb.SetFlags( 0 );
	}
	
	void ActivePhysicSys::add_bp_ptr( const std::string& name, const PhysicBluePrint_ptr& bp )
	{
		bool success = m_blueprints.insert( std::make_pair(name,bp) ).second;

		if( ! success )
		{
			throw Error( Errors::e_Overwrite_Definition );
		}
	}

	void ActivePhysicSys::ContactListener::Result( const b2ContactResult* point )
	{
		PhysicImpl* physic;

		physic = reinterpret_cast<PhysicImpl*>(
				point->shape1->GetBody()->GetUserData() );
		physic->AddContact( *point, point->shape1 );

		physic = reinterpret_cast<PhysicImpl*>(
				point->shape2->GetBody()->GetUserData() );
		physic->AddContact( *point, point->shape2 );
	}
}