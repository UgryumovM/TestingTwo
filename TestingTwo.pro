TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

SUBDIRS = app tests docs
INCLUDEPATH += ../docs
DISTFILES += sonar-project.properties

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0



CONFIG += ordered
