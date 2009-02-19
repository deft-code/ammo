#ifndef AMMO_GRAPHICS_SPRITE_HPP_INCLUDED
#define AMMO_GRAPHICS_SPRITE_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.hpp"
#include "ammo/graphics/graphic_def.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <string>

namespace ammo
{
   class SpriteImpl : public GraphicImpl
   {
   public:
      SpriteImpl( float lifetime );
      virtual ~SpriteImpl( void ) { }

      virtual void update(float dt);
      virtual bool done(void) const;
      virtual void draw(sf::RenderWindow& render);

      virtual void storeImage(std::size_t index, Image_ptr image);

      virtual void hide(void);
      virtual void show(void);

      virtual float GetRotationDegrees (void ) const;
      virtual void SetRotationDegrees(const float rot);
      virtual void SetRotationRadians(const float rot);

      virtual sf::Blend::Mode GetRenderMode( void ) const ;
      virtual void SetRenderMode( const sf::Blend::Mode mode );

      virtual b2Vec2 GetPosition( void ) const;
      virtual void SetPosition( const b2Vec2& pos );

      virtual b2Vec2 GetSize( void ) const;
		virtual void SetSize( const b2Vec2& size );

		virtual float GetZOrder( void ) const;
		virtual void SetZOrder( float z );

		virtual bool Meta_N( int meta, double& n );
		virtual bool Meta_VP( int meta, b2Vec2& v, void* p );

   private:
      sf::Sprite m_sprite;
      Image_ptr m_image;

		float m_z_order;
      bool m_show;
      float m_life;
      float m_lifetime;
   };

   class SpriteDef : public GraphicSchema
   {
   public:
      SpriteDef( void );
      SpriteDef( const std::string& filename );
      virtual ~SpriteDef( void ) { }

      virtual const std::string& filename(std::size_t index) const;
      virtual std::size_t numFiles(void) const;

      virtual GraphicPimpl load(void) const;

      std::string m_filename;
      float m_lifetime;
   };

}

#endif // AMMO_GRAPHICS_SPRITE_HPP_INCLUDED
