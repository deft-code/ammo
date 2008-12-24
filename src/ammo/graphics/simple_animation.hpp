#ifndef AMMO_GRAPHICS_SIMPLE_ANIMATION_HPP_INCLUDED
#define AMMO_GRAPHICS_SIMPLE_ANIMATION_HPP_INCLUDED

#include "ammo/graphics/graphic_impl.hpp"
#include "ammo/graphics/graphic_def.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <string>
#include <vector>

namespace ammo
{
   class SimpleAnimationImpl : public GraphicImpl
   {
   public:
      SimpleAnimationImpl( float lifetime, const std::vector<float>& times );
      virtual ~SimpleAnimationImpl( void ) { }

      virtual void update(float dt);
      virtual bool done(void) const;
      virtual void draw(sf::RenderWindow& render);

      virtual void storeImage(std::size_t index, Image_ptr image);

      virtual void hide(void);
      virtual void show(void);

      virtual b2Vec2 GetPosition( void ) const;
      virtual void SetPosition( const b2Vec2& pos );

      virtual b2Vec2 GetSize( void ) const;
		virtual void SetSize( const b2Vec2& size );

		virtual float GetZOrder( void ) const;
		virtual void SetZOrder( float z );

   private:
		void setFrame( std::size_t frame );

      sf::Sprite m_sprite;
      std::vector<float> m_times;
      std::vector<Image_ptr> m_images;

		float m_z_order;
      bool m_show;
      float m_time;
      std::size_t m_current;
      float m_life;
      float m_lifetime;
   };

   class SimpleAnimationDef : public GraphicDef
   {
   public:
      SimpleAnimationDef( void );
      virtual ~SimpleAnimationDef( void ) { }

      virtual const std::string& filename(std::size_t index) const;
      virtual std::size_t numFiles(void) const;

      virtual GraphicPimpl load(void) const;

      inline void addFrame( float time, const std::string& filename );

      std::vector<float> m_times;
      std::vector<std::string> m_filenames;
      float m_lifetime;
   };

   inline void SimpleAnimationDef::addFrame( float time, const std::string& filename )
   {
      m_times.push_back(time);
      m_filenames.push_back(filename);
   }


}

#endif // AMMO_GRAPHICS_SIMPLE_ANIMATION_HPP_INCLUDED