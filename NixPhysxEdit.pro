#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T20:15:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NixPhysxEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../_src/b2physx.cpp \
    ../_src/globaltimer.cpp \
    box2dqtdraw.cpp \
    mainglwidget.cpp \
    formrigidbody.cpp \
    dialogvec2input.cpp \
    formfixture.cpp \
    nqopengl2dwidget.cpp \
    formshapecircleedit.cpp \
    nbshapecircleglwidget.cpp \
    nbshapepolygonglwidget.cpp \
    formshapepolygonedit.cpp \
    nbshapechainglwidget.cpp \
    formshapechainedit.cpp \
    nbshapeedgeglwidget.cpp \
    formshapeedgeedit.cpp \
    nbqgedit.cpp \
    nbqgeditrigidbody.cpp \
    formjointdistance.cpp \
    nbqgeditjoint.cpp \
    nbqgeditjointdistance.cpp \
    nbqgeditjointrevolute.cpp \
    formjointrevolute.cpp \
    qbitedit.cpp \
    formfilter.cpp \
    dialogshapecircleedit.cpp \
    formvec2dedit.cpp \
    formfloatvalue.cpp \
    obj/nbbody.cpp \
    obj/nbdatamnger.cpp \
    obj/nbfixture.cpp \
    obj/nbjoint.cpp \
    obj/nbjointdistance.cpp \
    obj/nbjointrevolute.cpp \
    obj/nblayer.cpp \
    obj/nbobject.cpp \
    obj/nbshape.cpp \
    obj/nbshapechain.cpp \
    obj/nbshapecircle.cpp \
    obj/nbshapeedge.cpp \
    obj/nbshapepolygon.cpp \
    dialogshapepolygonedit.cpp \
    dialogshape.cpp \
    ../_src/b2vec2x.cpp \
    nbqgeditshape.cpp \
    nbqgeditshapecircle.cpp \
    shapeeditpainter.cpp \
    nbqgeditshapepolygon.cpp \
    obj/nbjointprismatic.cpp \
    formjoint.cpp \
    formjointprismaticatt.cpp \
    AttributeUI/uijointprismatic.cpp

HEADERS  += mainwindow.h \
    ../_src/b2physx.h \
    ../_src/singleton.h \
    ../_src/globaltimer.h \
    box2dqtdraw.h \
    mainglwidget.h \
    formrigidbody.h \
    dialogvec2input.h \
    formfixture.h \
    nqopengl2dwidget.h \
    formshapecircleedit.h \
    nbshapecircleglwidget.h \
    nbshapepolygonglwidget.h \
    formshapepolygonedit.h \
    nbshapechainglwidget.h \
    formshapechainedit.h \
    nbshapeedgeglwidget.h \
    formshapeedgeedit.h \
    nbqgedit.h \
    nbqgeditrigidbody.h \
    formjointdistance.h \
    nbqgeditjoint.h \
    nbqgeditjointdistance.h \
    nbqgeditjointrevolute.h \
    formjointrevolute.h \
    qbitedit.h \
    formfilter.h \
    dialogshapecircleedit.h \
    formvec2dedit.h \
    formfloatvalue.h \
    obj/nbbody.h \
    obj/nbdatamnger.h \
    obj/nbfixture.h \
    obj/nbjoint.h \
    obj/nbjointdistance.h \
    obj/nbjointrevolute.h \
    obj/nblayer.h \
    obj/nbobject.h \
    obj/nbshape.h \
    obj/nbshapechain.h \
    obj/nbshapecircle.h \
    obj/nbshapeedge.h \
    obj/nbshapepolygon.h \
    dialogshapepolygonedit.h \
    dialogshape.h \
    ../_src/b2vec2x.h \
    nbqgeditshape.h \
    nbqgeditshapecircle.h \
    shapeeditpainter.h \
    nbqgeditshapepolygon.h \
    obj/nbjointprismatic.h \
    formjoint.h \
    formjointprismaticatt.h \
    AttributeUI/uijointprismatic.h

FORMS    += mainwindow.ui \
    formrigidbody.ui \
    dialogvec2input.ui \
    formfixture.ui \
    formshapecircleedit.ui \
    formshapepolygonedit.ui \
    formshapechainedit.ui \
    formshapeedgeedit.ui \
    formjointdistance.ui \
    formjointrevolute.ui \
    formfilter.ui \
    dialogshapecircleedit.ui \
    formvec2dedit.ui \
    formfloatvalue.ui \
    dialogshapepolygonedit.ui \
    formjoint.ui \
    formjointprismaticatt.ui

INCLUDEPATH += ../_src/
include(D:/workspace/include/Box2D.pri)
include(d:/workspace/include/tinyxml2.pri)

LIBS += \
-lglu32\

DISTFILES += \
    box2dTestUI.txt \
