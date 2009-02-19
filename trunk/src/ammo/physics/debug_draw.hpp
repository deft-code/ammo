#ifndef AMMO_PHYSICS_DEBUG_DRAW_HPP_INCLUDED
#define AMMO_PHYSICS_DEBUG_DRAW_HPP_INCLUDED

#include "ammo/graphics/graphic_def.hpp"
#include "ammo/graphics/graphic_impl.hpp"
#include "ammo/util/GLPrimative.hpp"

namespace ammo
{
	namespace DebugDraw
	{
		enum Meta
		{
			Add_Vertex
		};
	}

	class DebugDrawSchema : public GraphicSchema
	{
	public:
		DebugDrawSchema( sf::Render::Mode mode, const unsigned& physics_generation );

		DebugDrawSchema& Set( sf::Render::Mode mode );

		virtual std::size_t numFiles(void) const
		{ return 0;	}

		virtual const std::string& filename(std::size_t index) const
		{ return *reinterpret_cast<std::string*>(NULL); }

		virtual GraphicPimpl Instantiate(void) const;

		float z_order;

	private:
		sf::Render::Mode _mode;
		const unsigned& _physics_generation;
	};

	class DebugDrawImpl : public GraphicImpl
	{
	public:
		DebugDrawImpl( sf::Render::Mode mode, float z_order, const unsigned& physics_generation );

		virtual bool done(void) const;
		virtual void hide(void);
		virtual void show(void);
		virtual float GetZOrder(void) const;
		virtual void SetZOrder(float z);
		virtual bool Meta( int meta, ... );

		virtual void draw(sf::RenderWindow& render);
		virtual void update(float dt);

		virtual b2Vec2 GetPosition(void) const	{ return b2Vec2_zero; }
		virtual sf::Blend::Mode GetRenderMode(void) const { return (sf::Blend::Mode)0; }
		virtual float GetRotationDegrees(void) const	{ return 0; }
		virtual b2Vec2 GetSize(void) const { return b2Vec2_zero; }
		virtual void SetPosition(const b2Vec2& pos) { }
		virtual void SetRenderMode(const sf::Blend::Mode mode) {	}
		virtual void SetRotationDegrees(const float rot) {	}
		virtual void SetRotationRadians(const float rot) {	}
		virtual void SetSize(const b2Vec2& size) { }

		virtual void storeImage(std::size_t index, Image_ptr image)	{ }
		
	private:
		const unsigned& _physics_generation;
		unsigned _initial_generation;
		bool _visible;
		float _z_order;
		sf::GLPrimative _primative;
	};

}

#endif //  AMMO_PHYSICS_DEBUG_DRAW_HPP_INCLUDED
