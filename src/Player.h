#pragma once

#include <SFML/Graphics.hpp>

#include "Controlled.h"
#include "Entity.h"

class Player : public Controlled, public Entity
{
    public:
        Player();
        virtual ~Player();

    private:

};
