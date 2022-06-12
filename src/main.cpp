#include <iostream>
#include "qtLauncher/Launcher.hpp"
#include "Engine/Engine.hpp"
#include <unistd.h>

int launchSetup(int argc, char* argv[]) {
        QApplication setup(argc, argv);

        Launcher m;

        return setup.exec(); // Fonction bloquante tant que l'application Qt est active
}

void launchApp() {
    Engine app;
    app.run();
}

int main(int argc, char *argv[]) {

    launchSetup(argc, argv);
    launchApp();

    return 0;
}