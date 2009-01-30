#ifndef AMMO_INPUT_INPUT_ACTION_HPP
#define AMMO_INPUT_INPUT_ACTION_HPP

#include <boost/shared_ptr.hpp>
#include "SFML/Window/Input.hpp"

namespace ammo
{
    class InputImpl;

    class InputAction
    {
    public:
        InputAction(InputImpl* impl);
        virtual void Update(const sf::Input& input) = 0;

    protected:
        InputImpl* _impl;
    };
}

#endif // AMMO_INPUT_INPUT_ACTION_HPP