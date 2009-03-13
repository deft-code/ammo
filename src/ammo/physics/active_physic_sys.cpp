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
		_generation(0),
		_draw_cb(_generation)
	{ }

	bool ActivePhysicSys::IsPhysic(const std::string& name) const
	{
		return m_schemas.find(name) != m_schemas.end();
	}

	PhysicSchema_ptr ActivePhysicSys::findSchema( const std::string& name )
	{
		std::map<std::string,PhysicSchema_ptr>::iterator found =
			m_schemas.find(name);

		if( found == m_schemas.end() )
		{
			throw Error(Errors::e_Missing_Definition, name );
		}

		return found->second;
	}
	

	Physic ActivePhysicSys::NewPhysic(const std::string& name, GameObject& parent )
	{
		PhysicPimpl ptr( findSchema(name)->Instantiate( m_world, parent) );

		return Physic(ptr);
	}
	
	Physic ActivePhysicSys::NewPhysic(const std::string& name, GameObject& parent, const b2Vec2& position )
	{
		PhysicPimpl ptr( findSchema(name)->Instantiate( m_world, parent, position) );

		return Physic(ptr);
	}
	
	Physic ActivePhysicSys::NewPhysic(const std::string& name, GameObject& parent, const b2Vec2& position, float theta )
	{
		PhysicPimpl ptr( findSchema(name)->Instantiate( m_world, parent, position, theta) );

		return Physic(ptr);
	}
	
	void ActivePhysicSys::Update(float dt)
	{
		m_total_time += dt;
		m_total_time = std::min(m_total_time,m_max_time);
		while( m_total_time > m_step_time )
		{
			++_generation;
			m_world.Step(m_step_time,m_pos_iterations, m_vel_iterations);
			m_total_time -= m_step_time;
		}
	}

	void ActivePhysicSys::EnableDebugDraw( GraphicSys& graphic_sys, float z_order )
	{
		_draw_cb.SetGraphicSys(graphic_sys);
		_draw_cb.SetFlags( b2DebugDraw::e_aabbBit | b2DebugDraw::e_shapeBit );
		_draw_cb.SetZOrder( z_order );
		m_world.SetDebugDraw( &_draw_cb );
	}
	
	void ActivePhysicSys::DisableDebugDraw( void  )
	{
		_draw_cb.SetFlags( 0 );
		m_world.SetDebugDraw( NULL );
	}
	
	void ActivePhysicSys::add_bp_ptr( const std::string& name, const PhysicSchema_ptr& bp )
	{
		bool success = m_schemas.insert( std::make_pair(name,bp) ).second;

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
