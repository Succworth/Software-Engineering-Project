QT += testlib
QT += gui core sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES += \
        tst_login.cpp \
        #../app/crackingasl.cpp \
        #../app/mainmenu.cpp \
        ../app/answerkey.cpp \

HEADERS += \
        #../app/crackingasl.h \
        #../app/mainmenu.h \
        ../app/answerkey.h \

#FORMS += \
    #crackingasl.ui \
    #mainmenu.ui

INCLUDEPATH += \
        ../app \


#configuration to copy db and assets to build dir
CONFIG(debug, debug|release) {
    VARIANT = debug
} else {
    VARIANT = release
}
CONFIG += file_copies
#names for file copys
COPIES += db assets
#files to copy
db.files += $$files(../app/db/data.db)
assets.files += $$files(../app/Assets.rcc)
#destination paths
db.path = $$OUT_PWD/$$VARIANT/db
assets.path = $$OUT_PWD/$$VARIANT/
