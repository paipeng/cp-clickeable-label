QT -= gui
# QT += multimediawidgets

TEMPLATE = lib
DEFINES += CPCLICKABLELABEL_LIBRARY

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpclickablelabel.cpp

HEADERS += \
    cp-clickable-label_global.h \
    cpclickablelabel.h

TRANSLATIONS += \
    cp-clickable-label_zh_CN.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
