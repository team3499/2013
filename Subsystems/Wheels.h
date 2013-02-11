#ifndef WHEELS_H
#define WHEELS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "SpeedController.h"

/**
 * @author Ethan
 */
class Wheels: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
  SpeedController *frontLeftMotor;
  SpeedController *frontRightMotor;
  SpeedController *rearLeftMotor;
  SpeedController *rearRightMotor;
public:

	Wheels(int frontLeft, int frontRight,
	       int rearLeft, int rearRight);
	void InitDefaultCommand();
	
    void Set(float frontLeft, float frontRight,
  		         float rearLeft, float rearRight);
};

#endif // #ifndef WHEELS_H
