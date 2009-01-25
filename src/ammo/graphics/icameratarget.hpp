#ifndef I_CAMERA_TARGET_HPP
#define I_CAMERA_TARGET_HPP

#include <Box2D.h>
namespace ammo
{
  // This interface defines objects that the camera is capable of following.
  class ICameraTarget
  {
  public:
    virtual b2Vec2 GetPosition( void ) const = 0;
  };
}
#endif // I_CAMERA_TARGET_HPP