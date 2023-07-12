#include <iostream>

#include "App.h"

#include "AssetManager.h"

int main(int argc, char *argv[])
{
    AssetManager ams;

    App app("Adventure Game");

    app.startup();
    app.run();
    app.shutdown();

    return app.quit();
}
