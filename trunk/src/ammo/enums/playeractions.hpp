#ifndef PLAYER_ACTIONS_HPP
#define PLAYER_ACTIONS_HPP
namespace ammo
{
  namespace enums
  {
#define PLAYER_ACTIONS_COUNT (6)
    enum enumPlayerAction
    {
      THRUST,
      REVERSE,
      LEFT,
      RIGHT,
      AFTERBURN,
      FIRE
    };
  }
}
#endif // PLAYER_ACTIONS_HPP