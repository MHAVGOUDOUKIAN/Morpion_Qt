cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

set(PROJECT_NAME $ENV{TITLE})
project(${PROJECT_NAME})

set (CMAKE_CXX_FLAGS "-no-pie")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set( SOURCES
    main.cpp
    qtLauncher/Launcher.cpp
    Engine/Engine.cpp
    Engine/EventHandler.cpp
    Engine/TimeManager.cpp
    Game/Game.cpp
    Game/Client.cpp
    Game/Server.cpp
    Game/User.cpp
    Game/Board.cpp
    Game/MessageDisplayer.cpp
)

set( HEADERS
    qtLauncher/Launcher.hpp
    Engine/Engine.hpp
    Engine/EventHandler.hpp
    Engine/TimeManager.hpp
    Game/Game.hpp
    Game/Client.hpp
    Game/Server.hpp
    Game/User.hpp
    Game/Board.hpp
    Game/MessageDisplayer.hpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} 
    Qt5::Widgets
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    pthread
)

set(PERMISSIONS OWNER_READ 
    OWNER_WRITE 
    OWNER_EXECUTE 
    GROUP_READ 
    GROUP_WRITE 
    GROUP_EXECUTE 
    WORLD_READ 
    WORLD_WRITE 
    WORLD_EXECUTE
)

install(FILES ${PROJECT_NAME}  DESTINATION ${PROJECT_SOURCE_DIR}/.. PERMISSIONS ${PERMISSIONS} )