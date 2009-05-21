#ifndef GAMEOBJECTS_ENUMS_HPP
#define GAMEOBJECTS_ENUMS_HPP

// This is currently the way we store our game objects, so we can easily
// serialize their type. 
namespace ammo
{
  namespace enums
  {
    enum enumGameObject
    {
      PLAYER_OBJECT,
      SAMPLE_OBJECT
    };
  }
}

#endif
