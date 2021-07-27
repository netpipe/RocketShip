#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T09:16:17
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    CIrrRocketEventReceiver.cpp \
    CIrrRocketGUI.cpp \
    Event.cpp \
    EventInstancer.cpp \
    IrrRocketFileInterface.cpp \
    IrrRocketInterface.cpp \
    IrrRocketRenderer.cpp \
        main.cpp \
        mainwindow.cpp \
    irrcorerenderer.cpp

HEADERS += \
    CIrrRocketEventReceiver.h \
    CIrrRocketGUI.h \
    Event.h \
    EventInstancer.h \
    IrrRocketFileInterface.h \
    IrrRocketInterface.h \
    IrrRocketRenderer.h \
        mainwindow.h \
    irrcorerenderer.h

FORMS += \
        mainwindow.ui


win32:INCLUDEPATH+=C:\Users\TEST\Downloads\irrlicht-1.8.4\irrlicht-1.8.4\include
#else:unix:INCLUDEPATH+= /home/Dev/libs/game/irrlicht/Irrlicht-SVN/include/ /home/Dev/libs/game/irrlicht/Irrlicht-SVN/lib/Linux/
else:unix:INCLUDEPATH+=/run/media/netpipe/df7f53ef-2a98-4562-a498-7da578dab660/games/Luna/LunaLibs/irrlicht-1.8.4/include/ -L/home/netpipe/gamedev2/irrlicht-1.8.4/include ../libRocket/Include

win32:LIBS += -LC:\Users\TEST\Downloads\irrlicht-1.8.4\irrlicht-1.8.4\lib\Win32-visualstudio -lIrrlicht
#else:unix:LIBS += -L/home/Dev/libs/game/irrlicht/Irrlicht-SVN/lib/Linux/ -lIrrlicht -lGL -lX11 -lXxf86vm
else:unix:LIBS += -L/run/media/netpipe/df7f53ef-2a98-4562-a498-7da578dab660/games/Luna/LunaLibs/irrlicht-1.8.4/lib/Linux/ -L/home/netpipe/gamedev2/irrlicht-1.8.4/lib/Linux/  -L../libRocket/Build -lIrrlicht -lGL -lX11 -lXxf86vm -lfreetype -lRocketCore -lRocketControls -lpthread



#win32:CONFIG(release, debug|release): LIBS += -L/home/Dev/libs/game/Irrlicht-SVN/lib/Linux/release/ -lIrrlicht
#else:win32:CONFIG(debug, debug|release): LIBS += -L/home/Dev/libs/game/Irrlicht-SVN/lib/Linux/debug/ -lIrrlicht
#else:unix: LIBS += -L/home/Dev/libs/game/Irrlicht-SVN/lib/Linux/ -lIrrlicht -lX11 -lGL -lXxf86vm

#INCLUDEPATH += /home/Dev/libs/game/Irrlicht-SVN/include
#DEPENDPATH += /home/Dev/libs/game/Irrlicht-SVN/include

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /home/Dev/libs/game/Irrlicht-SVN/lib/Linux/release/libIrrlicht.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /home/Dev/libs/game/Irrlicht-SVN/lib/Linux/debug/libIrrlicht.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /home/Dev/libs/game/Irrlicht-SVN/lib/Linux/release/Irrlicht.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /home/Dev/libs/game/Irrlicht-SVN/lib/Linux/debug/Irrlicht.lib
#else:unix: PRE_TARGETDEPS += /home/Dev/libs/game/Irrlicht-SVN/lib/Linux/libIrrlicht.a
