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
    ../Commands/ShooterWheelStop.cpp \
    ../Commands/ShooterWheelStart.cpp \
    ../Commands/ShooterWheelUserControl.cpp \
    ../Commands/UserControlPan.cpp \
    ../Commands/UserControlTilt.cpp \
    ../Gamepad/Gamepad.cpp \
    ../Team3499/Rect.cpp \
    ../Team3499/Point.cpp \
    ../Subsystems/Wheels.cpp \
    ../Subsystems/TiltSsubsystem.cpp \
    ../Subsystems/ShooterWheel.cpp \
    ../Subsystems/PanSubsystem.cpp \
    ../Subsystems/Feeder.cpp \
    ../Subsystems/ExampleSubsystem.cpp \
    ../Subsystems/ConfigSubsystem.cpp \
    ../Subsystems/CameraLEDsSubsystem.cpp \
    ../Commands/UserControlFeeder.cpp \
    ../Commands/FeederLaunchOne.cpp

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
    ../Commands/ShooterWheelStop.h \
    ../Commands/ShooterWheelUserControl.h \
    ../Commands/UserControlPan.h \
    ../Commands/UserControlTilt.h \
    ../Commands/ShooterWheelStart.h \
    ../Gamepad/Gamepad.h \
    ../Team3499/Rect.h \
    ../Team3499/Point.h \
    ../Subsystems/Wheels.h \
    ../Subsystems/TiltSubsystem.h \
    ../Subsystems/ShooterWheel.h \
    ../Subsystems/PanSubsystem.h \
    ../Subsystems/Feeder.h \
    ../Subsystems/ExampleSubsystem.h \
    ../Subsystems/ConfigSubsystem.h \
    ../Subsystems/CameraLEDsSubsystem.h \
    ../Commands/UserControlFeeder.h \
    ../Commands/FeederLaunchOne.h

