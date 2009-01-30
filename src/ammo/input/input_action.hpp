#ifndef AMMO_INPUT_INPUT_ACTION_HPP
#define AMMO_INPUT_INPUT_ACTION_HPP

#include <boost/shared_ptr.hpp>
#include "SFML/Window/Input.hpp"

namespace ammo
{
    class InputImpl;
    typedef boost::shared_ptr<InputImpl> InputImpl_ptr;

    class InputAction
    {
    public:
        InputAction(InputImpl_ptr impl);
        virtual void HandleInput(sf::Input& input) = 0;

    protected:
        InputImpl_ptr _impl;
    };
    typedef boost::shared_ptr<InputAction> InputAction_ptr;
}

#endif // AMMO_INPUT_INPUT_ACTION_HPP