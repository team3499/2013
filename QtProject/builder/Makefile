WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/2013



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip -I$(PRJ_ROOT_DIR) -I$(PRJ_ROOT_DIR)/Commands -I$(PRJ_ROOT_DIR)/Subsystems

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = 2013/$(MODE_DIR)/2013.out \
	 2013_partialImage/$(MODE_DIR)/2013_partialImage.o


#Rules

# 2013
ifeq ($(DEBUG_MODE),1)
2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
2013/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
2013/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
2013/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
2013/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2013/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2013/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
2013/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
2013/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
2013/$(MODE_DIR)/% : IDE_DEFINES = 
2013/$(MODE_DIR)/% : PROJECT_TYPE = DKM
2013/$(MODE_DIR)/% : DEFINES = 
2013/$(MODE_DIR)/% : EXPAND_DBG = 0
2013/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
2013/$(MODE_DIR)/% : CPU = PPC603
2013/$(MODE_DIR)/% : TOOL_FAMILY = gnu
2013/$(MODE_DIR)/% : TOOL = gnu
2013/$(MODE_DIR)/% : TOOL_PATH = 
2013/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
2013/$(MODE_DIR)/% : LIBPATH = 
2013/$(MODE_DIR)/% : LIBS = 
2013/$(MODE_DIR)/% : OBJ_DIR := 2013/$(MODE_DIR)

OBJECTS_2013 = 2013_partialImage/$(MODE_DIR)/2013_partialImage.o

2013/$(MODE_DIR)/2013.out : $(OBJECTS_2013)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_2013) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_2013) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

2013/$(MODE_DIR)/2013_compile_file : $(FILE) ;

_clean :: 2013/$(MODE_DIR)/2013_clean

2013/$(MODE_DIR)/2013_clean : 
	$(TRACE_FLAG)if [ -d "2013" ]; then cd "2013"; rm -rf $(MODE_DIR); fi


# 2013_partialImage
ifeq ($(DEBUG_MODE),1)
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
2013_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
2013_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
2013_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
2013_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
2013_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
2013_partialImage/$(MODE_DIR)/% : DEFINES = 
2013_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
2013_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
2013_partialImage/$(MODE_DIR)/% : CPU = PPC603
2013_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
2013_partialImage/$(MODE_DIR)/% : TOOL = gnu
2013_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
2013_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
2013_partialImage/$(MODE_DIR)/% : LIBPATH = 
2013_partialImage/$(MODE_DIR)/% : LIBS = 
2013_partialImage/$(MODE_DIR)/% : OBJ_DIR := 2013_partialImage/$(MODE_DIR)



2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Point.o : $(PRJ_ROOT_DIR)/Team3499/Point.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Rect.o : $(PRJ_ROOT_DIR)/Team3499/Rect.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/CameraLEDsSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/CameraLEDsSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ConfigSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/ConfigSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ExampleSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/ExampleSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Feeder.o : $(PRJ_ROOT_DIR)/Subsystems/Feeder.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/PanSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/PanSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ShooterWheel.o : $(PRJ_ROOT_DIR)/Subsystems/ShooterWheel.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/TiltSsubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/TiltSsubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Wheels.o : $(PRJ_ROOT_DIR)/Subsystems/Wheels.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Gamepad/Gamepad.o : $(PRJ_ROOT_DIR)/Gamepad/Gamepad.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ExampleCommand.o : $(PRJ_ROOT_DIR)/Commands/ExampleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/FeederLaunchOne.o : $(PRJ_ROOT_DIR)/Commands/FeederLaunchOne.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/MecanumnDrive.o : $(PRJ_ROOT_DIR)/Commands/MecanumnDrive.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStart.o : $(PRJ_ROOT_DIR)/Commands/ShooterWheelStart.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStop.o : $(PRJ_ROOT_DIR)/Commands/ShooterWheelStop.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelUserControl.o : $(PRJ_ROOT_DIR)/Commands/ShooterWheelUserControl.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlFeeder.o : $(PRJ_ROOT_DIR)/Commands/UserControlFeeder.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlPan.o : $(PRJ_ROOT_DIR)/Commands/UserControlPan.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlTilt.o : $(PRJ_ROOT_DIR)/Commands/UserControlTilt.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/AutonomousCommand.o : $(PRJ_ROOT_DIR)/AutonomousCommands/AutonomousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveCommand.o : $(PRJ_ROOT_DIR)/AutonomousCommands/MoveCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveForward.o : $(PRJ_ROOT_DIR)/AutonomousCommands/MoveForward.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveToSide.o : $(PRJ_ROOT_DIR)/AutonomousCommands/MoveToSide.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/CommandBase.o : $(PRJ_ROOT_DIR)/CommandBase.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/OI.o : $(PRJ_ROOT_DIR)/OI.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Target.o : $(PRJ_ROOT_DIR)/Target.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499Robot.o : $(PRJ_ROOT_DIR)/Team3499Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_2013_partialImage = 2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Point.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Rect.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/CameraLEDsSubsystem.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ConfigSubsystem.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ExampleSubsystem.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Feeder.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/PanSubsystem.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ShooterWheel.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/TiltSsubsystem.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Wheels.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Gamepad/Gamepad.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ExampleCommand.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/FeederLaunchOne.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/MecanumnDrive.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStart.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStop.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelUserControl.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlFeeder.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlPan.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlTilt.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/AutonomousCommand.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveCommand.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveForward.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveToSide.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/CommandBase.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/OI.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Target.o  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499Robot.o 


2013_partialImage/$(MODE_DIR)/2013_partialImage.o : $(OBJECTS_2013_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_2013_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

2013_partialImage/$(MODE_DIR)/2013_partialImage_compile_file : $(FILE) ;

_clean :: 2013_partialImage/$(MODE_DIR)/2013_partialImage_clean

2013_partialImage/$(MODE_DIR)/2013_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "2013_partialImage" ]; then cd "2013_partialImage"; rm -rf $(MODE_DIR); fi

force : 
DEP_FILES := 2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Point.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499/Rect.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/CameraLEDsSubsystem.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ConfigSubsystem.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ExampleSubsystem.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Feeder.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/PanSubsystem.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/ShooterWheel.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/TiltSsubsystem.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Subsystems/Wheels.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Gamepad/Gamepad.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ExampleCommand.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/FeederLaunchOne.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/MecanumnDrive.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStart.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelStop.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/ShooterWheelUserControl.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlFeeder.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlPan.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Commands/UserControlTilt.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/AutonomousCommand.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveCommand.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveForward.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/AutonomousCommands/MoveToSide.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/CommandBase.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/OI.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Target.d  \
	2013_partialImage/$(MODE_DIR)/Objects/2013/Team3499Robot.d 
-include $(DEP_FILES)


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
