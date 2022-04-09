QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES = Assets.qrc

SOURCES += \
    answerkey.cpp \
    gamewindow.cpp \
    main.cpp \
    crackingasl.cpp \
    mainmenu.cpp \
    user.cpp

HEADERS += \
    answerkey.h \
    crackingasl.h \
    gamewindow.h \
    mainmenu.h \
    user.h

FORMS += \
    crackingasl.ui \
    gamewindow.ui \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#configuration to copy db and assets to build dir
CONFIG(debug, debug|release) {
    VARIANT = debug
} else {
    VARIANT = release
}
CONFIG += file_copies
#names for file copys
COPIES += db #assets
#files to copy
db.files += $$files(db/data.db)
#assets.files += $$files(Assets.qrc)
#destination paths
db.path = $$OUT_PWD/$$VARIANT/db
#assets.path = $$OUT_PWD/$$VARIANT/

#QMAKE_RESOURCE_FLAGS += -binary $$PWD/Assets.qrc -o $$OUT_PWD/Assets.rcc

