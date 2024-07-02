QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commands/command.cpp \
    commands/loginrequest.cpp \
    dialogs/editor.cpp \
    dialogs/settings.cpp \
    items/item.cpp \
    items/itemwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    projectOperations/openproject.cpp \
    projectOperations/saveproject.cpp

HEADERS += \
    commands/command.h \
    commands/loginrequest.h \
    dialogs/editor.h \
    dialogs/settings.h \
    items/item.h \
    items/itemwidget.h \
    mainwindow.h \
    projectOperations/openproject.h \
    projectOperations/saveproject.h

FORMS += \
    dialogs/editor.ui \
    dialogs/settings.ui \
    items/itemwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
