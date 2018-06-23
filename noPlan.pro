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
    dummy_match.cpp \
    intention/PointIntetion.cpp \
    math/vector2.cpp \
    ui/MainWindow.cpp \
    coach/coach.cpp \
    coach/dummy_position.cpp \
    detection/data_manager.cpp \
    detection/netraw.cpp \
    detection/noplan_detection.cpp \
    detection/robocup_ssl_client.cpp \
    intention/PointIntetion.cpp \
    match/match.cpp \
    math/vector2.cpp \
    play/simplePlay.cpp \
    proto/messages_robocup_ssl_detection.pb.cc \
    proto/messages_robocup_ssl_geometry.pb.cc \
    proto/messages_robocup_ssl_geometry_legacy.pb.cc \
    proto/messages_robocup_ssl_refbox_log.pb.cc \
    proto/messages_robocup_ssl_wrapper.pb.cc \
    proto/messages_robocup_ssl_wrapper_legacy.pb.cc \
    simulated/Box2D/Collision/Shapes/b2ChainShape.cpp \
    simulated/Box2D/Collision/Shapes/b2CircleShape.cpp \
    simulated/Box2D/Collision/Shapes/b2EdgeShape.cpp \
    simulated/Box2D/Collision/Shapes/b2PolygonShape.cpp \
    simulated/Box2D/Collision/b2BroadPhase.cpp \
    simulated/Box2D/Collision/b2CollideCircle.cpp \
    simulated/Box2D/Collision/b2CollideEdge.cpp \
    simulated/Box2D/Collision/b2CollidePolygon.cpp \
    simulated/Box2D/Collision/b2Collision.cpp \
    simulated/Box2D/Collision/b2Distance.cpp \
    simulated/Box2D/Collision/b2DynamicTree.cpp \
    simulated/Box2D/Collision/b2TimeOfImpact.cpp \
    simulated/Box2D/Common/b2BlockAllocator.cpp \
    simulated/Box2D/Common/b2Draw.cpp \
    simulated/Box2D/Common/b2Math.cpp \
    simulated/Box2D/Common/b2Settings.cpp \
    simulated/Box2D/Common/b2StackAllocator.cpp \
    simulated/Box2D/Common/b2Timer.cpp \
    simulated/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2Contact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    simulated/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    simulated/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    simulated/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2GearJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2Joint.cpp \
    simulated/Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    simulated/Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    simulated/Box2D/Dynamics/b2Body.cpp \
    simulated/Box2D/Dynamics/b2ContactManager.cpp \
    simulated/Box2D/Dynamics/b2Fixture.cpp \
    simulated/Box2D/Dynamics/b2Island.cpp \
    simulated/Box2D/Dynamics/b2World.cpp \
    simulated/Box2D/Dynamics/b2WorldCallbacks.cpp \
    simulated/Box2D/Rope/b2Rope.cpp \
    simulated/Ball.cpp \
    simulated/Field.cpp \
    simulated/main.cpp \
    simulated/Robot.cpp \
    simulated/SimulatedMatch.cpp \
    ui/main.cpp \
    ui/MainWindow.cpp \
    dummy_match.cpp \
    main.cpp

SUBDIRS += \
    noPlan.pro

DISTFILES += \
    proto/compile.sh \
    proto/messages_robocup_ssl_detection.proto \
    proto/messages_robocup_ssl_geometry.proto \
    proto/messages_robocup_ssl_geometry_legacy.proto \
    proto/messages_robocup_ssl_refbox_log.proto \
    proto/messages_robocup_ssl_wrapper.proto \
    proto/messages_robocup_ssl_wrapper_legacy.proto \
    README.md \
    simulated/ball_1024x1024.png \
    simulated/ball_128x128.png \
    simulated/ball_256x256.png \
    simulated/ball_32x32.png \
    simulated/ball_512x512.png \
    simulated/ball_64x64.png \
    simulated/blue_1024x1024.png \
    simulated/blue_128x128.png \
    simulated/blue_256x256.png \
    simulated/blue_32x32.png \
    simulated/blue_512x512.png \
    simulated/blue_64x64.png \
    simulated/field.png \
    simulated/green_boxCheckmark.png \
    simulated/green_button04.png \
    simulated/green_cross.png \
    simulated/green_panel.png \
    simulated/grey_background.png \
    simulated/grey_box.png \
    simulated/grey_panel.png \
    simulated/yellow_1024x1024.png \
    simulated/yellow_128x128.png \
    simulated/yellow_256x256.png \
    simulated/yellow_32x32.png \
    simulated/yellow_512x512.png \
    simulated/yellow_64x64.png \
    simulated/field.svg

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
    intention/intention.h \
    math/vector2.h \
    stdafx.h \
    ui/MainWindow.h \
    coach/coach.h \
    detection/data_manager.h \
    detection/netraw.h \
    detection/noplan_detection.h \
    detection/robocup_ssl_client.h \
    detection/util.h \
    intention/intention.h \
    match/match.h \
    math/vector2.h \
    proto/messages_robocup_ssl_detection.pb.h \
    proto/messages_robocup_ssl_geometry.pb.h \
    proto/messages_robocup_ssl_geometry_legacy.pb.h \
    proto/messages_robocup_ssl_refbox_log.pb.h \
    proto/messages_robocup_ssl_wrapper.pb.h \
    proto/messages_robocup_ssl_wrapper_legacy.pb.h \
    simulated/Box2D/Collision/Shapes/b2ChainShape.h \
    simulated/Box2D/Collision/Shapes/b2CircleShape.h \
    simulated/Box2D/Collision/Shapes/b2EdgeShape.h \
    simulated/Box2D/Collision/Shapes/b2PolygonShape.h \
    simulated/Box2D/Collision/Shapes/b2Shape.h \
    simulated/Box2D/Collision/b2BroadPhase.h \
    simulated/Box2D/Collision/b2Collision.h \
    simulated/Box2D/Collision/b2Distance.h \
    simulated/Box2D/Collision/b2DynamicTree.h \
    simulated/Box2D/Collision/b2TimeOfImpact.h \
    simulated/Box2D/Common/b2BlockAllocator.h \
    simulated/Box2D/Common/b2Draw.h \
    simulated/Box2D/Common/b2GrowableStack.h \
    simulated/Box2D/Common/b2Math.h \
    simulated/Box2D/Common/b2Settings.h \
    simulated/Box2D/Common/b2StackAllocator.h \
    simulated/Box2D/Common/b2Timer.h \
    simulated/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    simulated/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    simulated/Box2D/Dynamics/Contacts/b2CircleContact.h \
    simulated/Box2D/Dynamics/Contacts/b2Contact.h \
    simulated/Box2D/Dynamics/Contacts/b2ContactSolver.h \
    simulated/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    simulated/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    simulated/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    simulated/Box2D/Dynamics/Contacts/b2PolygonContact.h \
    simulated/Box2D/Dynamics/Joints/b2DistanceJoint.h \
    simulated/Box2D/Dynamics/Joints/b2FrictionJoint.h \
    simulated/Box2D/Dynamics/Joints/b2GearJoint.h \
    simulated/Box2D/Dynamics/Joints/b2Joint.h \
    simulated/Box2D/Dynamics/Joints/b2MotorJoint.h \
    simulated/Box2D/Dynamics/Joints/b2MouseJoint.h \
    simulated/Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    simulated/Box2D/Dynamics/Joints/b2PulleyJoint.h \
    simulated/Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    simulated/Box2D/Dynamics/Joints/b2RopeJoint.h \
    simulated/Box2D/Dynamics/Joints/b2WeldJoint.h \
    simulated/Box2D/Dynamics/Joints/b2WheelJoint.h \
    simulated/Box2D/Dynamics/b2Body.h \
    simulated/Box2D/Dynamics/b2ContactManager.h \
    simulated/Box2D/Dynamics/b2Fixture.h \
    simulated/Box2D/Dynamics/b2Island.h \
    simulated/Box2D/Dynamics/b2TimeStep.h \
    simulated/Box2D/Dynamics/b2World.h \
    simulated/Box2D/Dynamics/b2WorldCallbacks.h \
    simulated/Box2D/Rope/b2Rope.h \
    simulated/Box2D/Box2D.h \
    simulated/Ball.h \
    simulated/Commons.h \
    simulated/Field.h \
    simulated/Robot.h \
    simulated/SimulatedMatch.h \
    transmission/transmission.h \
    ui/MainWindow.h \
    commons.h \
    player.h \
    stdafx.h

FORMS += \
        ui/MainWindow.ui

RESOURCES += \
    ui/Ui.qrc \
    simulated/res.qrc
