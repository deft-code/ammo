#ifndef AMMO_INPUT_INPUT_SYS_HPP
#define AMMO_INPUT_INPUT_SYS_HPP

#include <vector>

#include <boost/shared_ptr.hpp>

#include "ammo/enums/playeractions.hpp"

namespace ammo
{
    class InputAction;
    class InputImpl;
    class Input;
    typedef boost::shared_ptr<InputAction> InputAction_ptr;
    typedef boost::shared_ptr<InputImpl> InputImpl_ptr;
    typedef boost::shared_ptr<Input> Input_ptr;

    class InputSys
    {
    public:
        Input_ptr AddInputMap(std::vector<InputAction_ptr> inputs);

    protected:
        std::vector<InputImpl_ptr> _inputs;
    };
}

#endif