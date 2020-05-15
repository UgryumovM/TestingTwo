include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt


QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += main.cpp \
    ../app/cn.cpp \
    ../app/load.cpp \
    ../app/m.cpp \
    ../app/save.cpp \
    ../app/show.cpp \
    ../app/rightcdel.cpp \
    ../app/shownumspaces.cpp \
    ../app/text/append_line.cpp \
    ../app/text/changeline.cpp \
    ../app/text/create_text.cpp \
    ../app/text/getcursorl.cpp \
    ../app/text/getcursorp.cpp \
    ../app/text/move_cursor.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/rch.cpp \
    ../app/text/remove_all.cpp

INCLUDEPATH += ../app

HEADERS += m_test.h \
    ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    changeline_test.h \
    func.h \
    rch_test.h \
    save_test.h \
    shownum_test.h





