#ifndef AMMO_INPUT_SINGLE_KEY_BOOLEAN_HPP
#define AMMO_INPUT_SINGLE_KEY_BOOLEAN_HPP

#include "SFML/Window/Input.hpp"

#include "ammo/input/input_action.hpp"
#include "ammo/enums/playeractions.hpp"

namespace ammo
{
    class SingleKeyBoolean : public InputAction
    {
    public:
        SingleKeyBoolean(sf::Key::Code key, enums::enumPlayerAction action);
        virtual void Update(const sf::Input& input, float dt);
    protected:
        sf::Key::Code _key;
        enums::enumPlayerAction _action;
    };
}

#endif // AMMO_INPUT_SINGLE_KEY_BOOLEAN_HPP

