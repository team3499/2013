TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    ../Team3499Robot.cpp \
    ../Target.cpp \
    ../OI.cpp \
    ../CommandBase.cpp \
    ../Commands/ShooterWheelUserControl.cpp \
    ../Commands/MecanumnDrive.cpp \
    ../Commands/ExampleCommand.cpp \
    ../Gamepad/Gamepad.cpp \
    ../Subsystems/Wheels.cpp \
    ../Subsystems/ShooterWheel.cpp \
    ../Subsystems/ExampleSubsystem.cpp \
    ../Subsystems/ConfigSubsystem.cpp \
    ../Subsystems/CameraLEDsSubsystem.cpp \
    ../Team3499/Rect.cpp \
    ../Team3499/Point.cpp \
    ../Commands/ShooterWheelStop.cpp \
    ../Commands/ShooterWheelStart.cpp

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
    ../Commands/ShooterWheelUserControl.h \
    ../Commands/MecanumnDrive.h \
    ../Commands/ExampleCommand.h \
    ../Gamepad/Gamepad.h \
    ../Subsystems/Wheels.h \
    ../Subsystems/ShooterWheel.h \
    ../Subsystems/ExampleSubsystem.h \
    ../Subsystems/ConfigSubsystem.h \
    ../Subsystems/CameraLEDsSubsystem.h \
    ../Team3499/Rect.h \
    ../Team3499/Point.h \
    ../Commands/ShooterWheelStop.h \
    ../Commands/ShooterWheelStart.h

