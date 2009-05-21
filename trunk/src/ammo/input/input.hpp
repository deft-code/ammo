#ifndef AMMO_INPUT_INPUT_HPP
#define AMMO_INPUT_INPUT_HPP

#include <boost/shared_ptr.hpp>
#include "ammo/enums/playeractions.hpp"

namespace ammo
{
    class InputImpl;

    class Input
    {
    public:
        Input();
        Input(InputImpl* impl);
        float GetValue(enums::enumPlayerAction action) const;
        bool GetBoolValue(enums::enumPlayerAction action) const;
        void SetValue(enums::enumPlayerAction action, float val);

    private:
        InputImpl* _impl;
    };
}

#endif // AMMO_INPUT_INPUT_H

