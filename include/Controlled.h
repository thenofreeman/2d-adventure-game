#include <SFML/Graphics.hpp>

class Controlled
{
    public:
        Controlled();
        virtual ~Controlled();

        void action(); // eg. attack
        void interact(); // eg. talk, open chest

    private:

};
