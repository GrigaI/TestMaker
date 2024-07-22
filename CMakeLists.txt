cmake_minimum_required(VERSION 3.5)

project(testMaker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5 REQUIRED Core Gui Widgets Network)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

find_package(Qt5 COMPONENTS Gui REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui REQUIRED)

find_package(Qt5 COMPONENTS Network REQUIRED)
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Network REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)

set(PROJECT_SOURCES
    commands/command.cpp 
    commands/loginrequest.cpp 
    dialogs/editor.cpp 
    dialogs/informationdialog.cpp 
    dialogs/settings.cpp 
    items/item.cpp 
    items/itemwidget.cpp 
    main.cpp 
    mainwindow.cpp 
    projectOperations/changecontrol.cpp 
    projectOperations/openproject.cpp 
    projectOperations/saveproject.cpp 
    server/communicationserver.cpp

    #HEADERS  
    commands/command.h 
    commands/loginrequest.h 
    dialogs/editor.h 
    dialogs/informationdialog.h 
    dialogs/settings.h 
    items/item.h 
    items/itemwidget.h 
    mainwindow.h 
    projectOperations/changecontrol.h 
    projectOperations/openproject.h 
    projectOperations/saveproject.h
    server/communicationserver.h

    #FORMS 
    dialogs/editor.ui 
    dialogs/informationdialog.ui 
    dialogs/settings.ui 
    items/itemwidget.ui 
    mainwindow.ui
    
    resource.qrc
)

#set(RESOURCES )

add_executable(testMaker
            ${PROJECT_SOURCES})
# qt library
target_link_libraries(testMaker PRIVATE Qt5::Core)
target_link_libraries(testMaker PRIVATE Qt5::Gui)
target_link_libraries(testMaker PRIVATE Qt5::Widgets)
target_link_libraries(testMaker PRIVATE Qt5::Network)