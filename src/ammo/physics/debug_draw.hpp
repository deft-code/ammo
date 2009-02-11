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
			Set_Render_Mode,
			Add_Vertex
		};
	}

	class DebugDrawSchema : public GraphicDef
	{
	public:
		DebugDrawSchema( unsigned& physics_generation );

		virtual std::size_t numFiles(void) const
		{ return 0;	}

		virtual const std::string& filename(std::size_t index) const
		{ return *reinterpret_cast<std::string*>(NULL); }

		virtual GraphicPimpl load(void) const;

	private:
		const unsigned& _physics_generation;
	};

	class DebugDrawImpl : public GraphicImpl
	{
	public:
		DebugDrawImpl( const unsigned& physics_generation );

		virtual bool done(void) const;
		virtual void hide(void);
		virtual void show(void);
		virtual bool Meta_N(int meta, double& n);
		virtual bool Meta_VP(int meta, b2Vec2& v, void* p);

		virtual void draw(sf::RenderWindow& render);
		virtual void update(float dt);

		virtual b2Vec2 GetPosition(void) const	{ return b2Vec2_zero; }
		virtual sf::Blend::Mode GetRenderMode(void) const { return (sf::Blend::Mode)0; }
		virtual float GetRotationDegrees(void) const	{ return 0; }
		virtual b2Vec2 GetSize(void) const { return b2Vec2_zero; }
		virtual float GetZOrder(void) const	{ return 0; }
		virtual void SetPosition(const b2Vec2& pos) { }
		virtual void SetRenderMode(const sf::Blend::Mode mode) {	}
		virtual void SetRotationDegrees(const float rot) {	}
		virtual void SetRotationRadians(const float rot) {	}
		virtual void SetSize(const b2Vec2& size) { }
		virtual void SetZOrder(float z) { }

		virtual void storeImage(std::size_t index, Image_ptr image)	{ }

		
	private:
		const unsigned& _physics_generation;
		unsigned _initial_generation;
		bool _visible;

		sf::GLPrimative _primative;
	};

}

#endif //  AMMO_PHYSICS_DEBUG_DRAW_HPP_INCLUDED
