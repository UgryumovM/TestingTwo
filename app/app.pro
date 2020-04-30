TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += \
        cn.cpp \
        load.cpp \
        m.cpp \
        main.cpp \
        rightcdel.cpp \
        save.cpp \
        show.cpp \
        shownumspaces.cpp \
        text/append_line.cpp \
        text/changeline.cpp \
        text/create_text.cpp \
        text/getcursorl.cpp \
        text/getcursorp.cpp \
        text/move_cursor.cpp \
        text/process_forward.cpp \
        text/rch.cpp \
        text/remove_all.cpp

DISTFILES += \
    input.txt \
    output.txt \
    text/libtext.a \

HEADERS += \
    common.h \
    text/_text.h \
    text/text.h


