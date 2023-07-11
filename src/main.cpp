#include <iostream>

#include "App.h"

int main(int argc, char *argv[])
{
    App app("Adventure Game");

    try
    {
        app.startup();
        app.run();
        app.shutdown();
    }
    catch (std::exception& e)
    {
        std::cout << "EXCEPTION LOST TO MAIN: " << e.what() << std::endl;
    }


    return app.quit();
}
