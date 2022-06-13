#include <iostream>
#include "qtLauncher/Launcher.hpp"
#include "Engine/Engine.hpp"
#include <unistd.h>

bool runApp = false;

int launchSetup(int argc, char* argv[]) {
        QApplication setup(argc, argv);

        Launcher m(&runApp);

        return setup.exec(); // Fonction bloquante tant que l'application Qt est active
}

void launchApp() {
    Engine app;
    app.run();
}

int main(int argc, char *argv[]) {

    launchSetup(argc, argv);
    if(runApp) launchApp();

    return 0;
}