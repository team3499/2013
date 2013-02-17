#include "ConfigSubsystem.h"
#include "../Robotmap.h"

ConfigSubsystem::ConfigSubsystem() : Subsystem("ConfigSubsystem") {
    configInputCount = 4;   // must match the number of DigitalIOButtons allocated
    configInput      = new DigitalIOButton*[configInputCount];

    configInput[0]   = new DigitalIOButton(CONFIG_0_CHANNEL);  // Pyramid position Left/Right
    configInput[1]   = new DigitalIOButton(CONFIG_1_CHANNEL);  // Pyramid position Front/Back
    configInput[2]   = new DigitalIOButton(CONFIG_2_CHANNEL);  // Autonomous configuration
    configInput[3]   = new DigitalIOButton(CONFIG_3_CHANNEL);  // Autonomous configuration
}

ConfigSubsystem::~ConfigSubsystem() {
    for (unsigned int i = 0; i < configInputCount; i++) { delete configInput[i]; }
    delete[] configInput;
}

void ConfigSubsystem::InitDefaultCommand() {
    // no default command
}

// Returns a bitmap of the configuration switches.  Undefined switches
// will return a 0 in their position.
unsigned char ConfigSubsystem::ReadConfigInput() const {
    unsigned char value = 0x00;

    for (unsigned int i = 0; i < configInputCount; i++) {
        value |= (unsigned char)ReadConfigInput(i) << i;
    }

    return value;
}

// Reads a config input and returns the value as a boolean.  Returns
// false if the config input is not defined.
bool ConfigSubsystem::ReadConfigInput(unsigned int number) const {
    if (number < configInputCount) {
        return configInput[number]->Get();
    }

    return false;
}

// Returns the configured robot position based on configuration setting
ConfigSubsystem::PyramidCorner ConfigSubsystem::PyramidPosition() const {
    unsigned char config = ReadConfigInput();

    switch (config & 0x03) {
    case 0x00:
        return FRONTLEFT;
        break;
    case 0x01:
        return FRONTRIGHT;
        break;
    case 0x02:
        return BACKLEFT;
        break;
    case 0x03:
        return BACKRIGHT;
        break;
    default:
        break;
    }

    return UNKNOWN;
}
