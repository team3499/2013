#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Gamepad/Gamepad.h"

class OI {
private:

public:
	OI();
	
	Gamepad *drivePad;
	Gamepad *accessoryPad;
};

#endif
