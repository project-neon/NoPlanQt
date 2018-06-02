QT += gui

CONFIG += c++11 console

 QT += widgets

LIBS += -lprotobuf
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    proto/messages_robocup_ssl_detection.pb.cc \
    proto/messages_robocup_ssl_geometry.pb.cc \
    proto/messages_robocup_ssl_geometry_legacy.pb.cc \
    proto/messages_robocup_ssl_refbox_log.pb.cc \
    proto/messages_robocup_ssl_wrapper.pb.cc \
    proto/messages_robocup_ssl_wrapper_legacy.pb.cc \
    detection/netraw.cpp \
    detection/robocup_ssl_client.cpp \
    detection/data_manager.cpp \
    detection/noplan_detection.cpp \
    coach/coach.cpp \
    main.cpp \
    match/match.cpp \
    play/simplePlay.cpp \
    dummy_match.cpp

SUBDIRS += \
    noPlan.pro

DISTFILES += \
    proto/compile.sh \
    proto/messages_robocup_ssl_detection.proto \
    proto/messages_robocup_ssl_geometry.proto \
    proto/messages_robocup_ssl_geometry_legacy.proto \
    proto/messages_robocup_ssl_refbox_log.proto \
    proto/messages_robocup_ssl_wrapper.proto \
    proto/messages_robocup_ssl_wrapper_legacy.proto

HEADERS += \
    proto/messages_robocup_ssl_detection.pb.h \
    proto/messages_robocup_ssl_geometry.pb.h \
    proto/messages_robocup_ssl_geometry_legacy.pb.h \
    proto/messages_robocup_ssl_refbox_log.pb.h \
    proto/messages_robocup_ssl_wrapper.pb.h \
    proto/messages_robocup_ssl_wrapper_legacy.pb.h \
    detection/netraw.h \
    detection/robocup_ssl_client.h \
    detection/util.h \
    detection/data_manager.h \
    detection/noplan_detection.h \
    transmission/transmission.h \
    coach/coach.h \
    match/match.h \
    commons.h \
    player.h \
