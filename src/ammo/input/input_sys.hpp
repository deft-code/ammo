#ifndef AMMO_INPUT_INPUT_SYS_HPP
#define AMMO_INPUT_INPUT_SYS_HPP

#include <map>
#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include "SFML/Window/Input.hpp"

#include "ammo/enums/playeractions.hpp"
#include "ammo/input/input_impl.hpp"

#include "RakNetTypes.h"

namespace ammo
{
    class InputAction;
    class Input;
    

    class InputSys
    {
    public:
        void AddInputMap(SystemAddress owner, std::vector<InputAction*> inputs);
        Input GetInput(SystemAddress owner);
        void Update(const sf::Input& input, float dt);

    protected:
        std::map<SystemAddress, InputImpl> _impls;
    };
}

#endif
