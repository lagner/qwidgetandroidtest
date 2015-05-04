#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T11:05:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = androidwidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commonmodel.cpp \
    itemdelegate.cpp \
    customitem.cpp

HEADERS  += mainwindow.h \
    commonmodel.h \
    itemdelegate.h \
    customitem.h

CONFIG += mobility c++11
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

android {
PACKAGE_INSTALL_PATH = /assets
} else {
PACKAGE_INSTALL_PATH = $$OUT_PWD
}

install_it.path = $$PACKAGE_INSTALL_PATH
install_it.files = resources

INSTALLS += install_it

RESOURCES += \
    res.qrc
