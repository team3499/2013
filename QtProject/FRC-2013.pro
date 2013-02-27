TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    ../Team3499Robot.cpp \
    ../Target.cpp \
    ../OI.cpp \
    ../CommandBase.cpp \
    ../Commands/ExampleCommand.cpp \
    ../Gamepad/Gamepad.cpp \
    ../Team3499/Rect.cpp \
    ../Team3499/Point.cpp \
    ../ImageProcessor.cpp \
    ../TargetReport.cpp \
    ../Commands/gamepadtesting.cpp

OTHER_FILES += \
    ../sample.txt \
    ../README.md \
    ../.gitignore \
    ../Gamepad/Thanks.txt \
    compile.bat \
    ftp_commands \
    ftp_commands \
    deploy.bat

HEADERS += \
    ../Target.h \
    ../Robotmap.h \
    ../OI.h \
    ../CommandBase.h \
    ../Commands/ExampleCommand.h \
    ../Gamepad/Gamepad.h \
    ../Team3499/Rect.h \
    ../Team3499/Point.h \
    ../ImageProcessor.h \
    ../TargetReport.h \
    ../Commands/gamepadtesting.h

