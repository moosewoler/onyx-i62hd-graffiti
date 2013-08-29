TARGET = onyx-i62hd-graffiti.oar
QT      += widgets network webkit
HEADERS += \
    src/mwo_mainwindow.h \
    src/mwo_application.h \
    src/mwolib/graffiti_hui.h

SOURCES += \
    src/mwo_mainwindow.cpp \
    src/mwo_application.cpp \
    src/main.cpp \
    src/mwolib/graffiti_hui.cpp

unix:!macx: LIBS += -lonyxapp -lonyx_base -lonyx_ui -lonyx_screen -lonyx_sys -lonyx_data

