#include "ammo/input/single_key_boolean.hpp"

#include "ammo/input/input_impl.hpp"

namespace ammo
{
    SingleKeyBoolean::SingleKeyBoolean(sf::Key::Code key, enums::enumPlayerAction action):
        _action(action),
        _key(key)
    {
    }

    void SingleKeyBoolean::Update(const sf::Input input, float dt)
    {
        if (input.IsKeyDown(_key))
        {
            _impl->SetValue(_action, 1.f);
        }
        else
        {
            _impl->SetValue(_action, 0.f);
        }
    }
}