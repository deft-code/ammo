#include "graphic.hpp"

#include "graphic_impl.hpp"

namespace // anonymous
{
   /// implements the Null Object Design Pattern for Graphic objects
   class NullGraphicImpl : public ammo::GraphicImpl
   {
   public:
      virtual void update( float dt ) { }
      virtual bool done( void ) const { return true; }
      virtual void draw( sf::RenderWindow& render ) { }
      virtual void storeImage( std::size_t index, ammo::Image_ptr image ) { }
      virtual void show( void ) { }
      virtual void hide( void ) { }
      virtual b2Vec2 GetPosition( void ) const { return b2Vec2_zero; }
      virtual void SetPosition( const b2Vec2& pos ) { }
      virtual b2Vec2 GetSize( void ) const { return b2Vec2_zero; }
		virtual void SetSize( const b2Vec2& size ) {	}
		virtual float GetZOrder( void ) const { return 0.f; }
		virtual void SetZOrder( float z ) {	}
   };

   void do_nothing( ammo::GraphicImpl* unused ) { }

   NullGraphicImpl s_null_graphic;
   ammo::GraphicPimpl s_null_pimpl( &s_null_graphic, do_nothing );
} // anonymous namespace

namespace ammo
{
   Graphic::Graphic( void )
    : m_pimpl(s_null_pimpl)
   { }
   
   Graphic::Graphic( GraphicPimpl pimpl )
    : m_pimpl(pimpl)
   { }
   
   void Graphic::show( void )
   {
      m_pimpl->show();
   }
   
   void Graphic::hide( void )
   {
      m_pimpl->hide();
   }

   b2Vec2 Graphic::GetPosition( void ) const
   {
      return m_pimpl->GetPosition();
   }

   void Graphic::SetPosition( const b2Vec2& pos )
   {
      m_pimpl->SetPosition( pos );
   }

   void Graphic::SetX( float x )
   {
      m_pimpl->SetPosition( b2Vec2(x, m_pimpl->GetPosition().y));
   }

   void Graphic::SetY( float y )
   {
      m_pimpl->SetPosition( b2Vec2(m_pimpl->GetPosition().x, y));
   }

   void Graphic::Move( const b2Vec2& delta )
   {
      m_pimpl->SetPosition( m_pimpl->GetPosition() + delta );
   }

   b2Vec2 Graphic::GetSize( void ) const
   {
      return m_pimpl->GetSize();
   }

	void Graphic::SetSize( const b2Vec2& size )
	{
      m_pimpl->SetSize(size);
	}

	float Graphic::GetZOrder( void ) const
	{
		return m_pimpl->GetZOrder();
	}

	void Graphic::SetZOrder( float z )
	{
		m_pimpl->SetZOrder(z);
	}
}
