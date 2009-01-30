#ifndef AMMO_INPUT_INPUT_SYS_HPP
#define AMMO_INPUT_INPUT_SYS_HPP

#include <map>
#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include "SFML/Window/Input.hpp"

#include "ammo/enums/playeractions.hpp"
#include "ammo/input/input_impl.hpp"

namespace ammo
{
    class InputAction;
    class Input;

    class InputSys
    {
    public:
        void AddInputMap(std::string name, std::vector<InputAction*> inputs);
        Input GetInput(std::string name);
        void Update(const sf::Input& input, float dt);

    protected:
        std::map<std::string, InputImpl> _impls;
    };
}

#endif