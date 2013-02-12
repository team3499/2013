#ifndef SHOOTER_WHEEL_H
#define SHOOTER_WHEEL_H
#include "SpeedController.h"
#include "WPILib.h"

/**
 * @author Ethan
 */
class ShooterWheel: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterWheel(int port);
	void InitDefaultCommand();
    
    void setSpeed(float speed);
    
private:
    SpeedController *speedController;
};

#endif
