#ifndef AMMO_INPUT_INPUT_IMPL_HPP
#define AMMO_INPUT_INPUT_IMPL_HPP

#include <vector>

#include <boost/shared_ptr.hpp>
#include "SFML/Window/Input.hpp"

#include "ammo/enums/playeractions.hpp"

namespace ammo
{
    class InputAction;
    typedef boost::shared_ptr<InputAction> InputAction_ptr;

    class InputImpl
    {
    public:
        InputImpl();
        InputImpl(std::vector<InputAction_ptr> actions);
        void Update(sf::Input& input);
        float GetValue(ammo::enums::enumPlayerAction action) const;
        void SetValue(enums::enumPlayerAction action, float val);

    protected:
        std::vector<float> _state;
        std::vector<InputAction_ptr> _actions;
    };
    typedef boost::shared_ptr<InputImpl> InputImpl_ptr;
}

#endif // AMMO_INPUT_INPUT_IMPL_HPP