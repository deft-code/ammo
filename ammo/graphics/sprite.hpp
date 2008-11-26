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

   private:
      sf::Sprite m_sprite;
      Image_ptr m_image;

      bool m_show;
      float m_life;
      float m_lifetime;
   };

   class SpriteDef : public GraphicDef
   {
   public:
      SpriteDef( void );
      virtual ~SpriteDef( void ) { }

      virtual const std::string& filename(std::size_t index) const;
      virtual std::size_t numFiles(void) const;

      virtual GraphicPimpl load(void) const;

      std::string m_filename;
      float m_lifetime;
   };

}

#endif // AMMO_GRAPHICS_SPRITE_HPP_INCLUDED
