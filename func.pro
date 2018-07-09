TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    test.cpp

HEADERS += \
    Functor.h \
    SimpFunc.h \
    PtrFunc.h \
    Funcbase.h \
    MFunctor.h \
    WrongFunc.h \
    VecFunctor.h

