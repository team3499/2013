#ifndef CONFIG_SUBSYSTEM_H
#define CONFIG_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ConfigSubsystem: public Subsystem {

private:
  DigitalIOButton **    configInput;
  unsigned int          configInputCount;

public:
  typedef enum {
    UNKNOWN = 0,
    FRONTLEFT,
    FRONTRIGHT,
    BACKRIGHT,
    BACKLEFT
  } PyramidCorner;

                        ConfigSubsystem();
  virtual               ~ConfigSubsystem();

  void InitDefaultCommand();

  // Reads the config switch inputs.  The no argument form returns an
  // 8 bit bitmap cooresponding to the switch settings.  Pass a number
  // to read the particular switch as a boolean.
  unsigned char         ReadConfigInput() const;
  bool                  ReadConfigInput(unsigned int number) const;

  // The position of the robot for game start as configured.
  PyramidCorner         PyramidPosition() const;

};

#endif /* CONFIG_SUBSYSTEM_H */
