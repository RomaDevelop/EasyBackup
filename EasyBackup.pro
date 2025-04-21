QT       += core gui widgets

CONFIG += c++17

SOURCES += \
    DialogPlanEdit.cpp \
    Plan.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    DialogPlanEdit.h \
    MainWindow.h \
    Plan.h

INCLUDEPATH += \
	../include

DEPENDPATH += \
	../include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
