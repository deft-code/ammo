#include "ammo/game/gameobject.hpp"

namespace ammo
{
  void GameObject::DeserializeDestruction(RakNet::BitStream * bitStream, 
    RakNet::SerializationType serializationType, SystemAddress sender, RakNetTime timestamp)
  {
    _parent->GetGameState()->UnregisterGameObject(this);
  }
}