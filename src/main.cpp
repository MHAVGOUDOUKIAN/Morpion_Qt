#include <iostream>
#include "qtLauncher/Launcher.hpp"
#include "Engine/Engine.hpp"
#include <csignal>

bool runApp = false;

void signalHandler(int unused)
{
    // I define this function to prevent the server to terminate if a client disconnect
}

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
    signal(SIGPIPE, signalHandler); 
    launchSetup(argc, argv);
    if(runApp) launchApp();

    return 0;
}