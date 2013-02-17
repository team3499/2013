#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

//
// Analog Breakout Ports
//
#define AIO_1                  1
#define AIO_2                  2
#define AIO_3                  3
#define AIO_4                  4
#define AIO_5                  5
#define AIO_6                  6
#define AIO_7                  7
#define AIO_8                  8

//
// Digitial Sidecar Ports
//
#define PWM_1                  1
#define PWM_2                  2
#define PWM_3                  3
#define PWM_4                  4
#define PWM_5                  5
#define PWM_6                  6
#define PWM_7                  7
#define PWM_8                  8
#define PWM_9                  9
#define PWM_10                 10

#define DIO_1                  1
#define DIO_2                  2
#define DIO_3                  3
#define DIO_4                  4
#define DIO_5                  5
#define DIO_6                  6
#define DIO_7                  7
#define DIO_8                  8
#define DIO_9                  9
#define DIO_10                 10
#define DIO_11                 11
#define DIO_12                 12
#define DIO_13                 13
#define DIO_14                 14

#define RELAY_1                1
#define RELAY_2                2
#define RELAY_3                3
#define RELAY_4                4
#define RELAY_5                5
#define RELAY_6                6
#define RELAY_7                7
#define RELAY_8                8

//
// Robot Subsystems
//

// Mechanum Drive
//   4 motors on Victor ESCs
#define DRIVE_FRONT_LEFT_CHANNEL          PWM_1
#define DRIVE_FRONT_RIGHT_CHANNEL         PWM_2
#define DRIVE_BACK_LEFT_CHANNEL           PWM_3
#define DRIVE_BACK_RIGHT_CHANNEL          PWM_4

// Triple 'T' Turret System
//   Thrower
//     1 motor on Jaguar ESC
//   Tilter
//     1 motor on Jaguar ESC
//     1 encoder on digital input
//   Turner
//     1 motor on Victor ESC
//     1 encoder on digital input
//   Feeder
//     1 motor on Victor ESC
#define THROWER_MOTOR_CHANNEL             PWM_5
#define TILTER_MOTOR_CHANNEL              PWM_6
#define TILTER_ENCODER_A_CHANNEL          DIO_11
#define TILTER_ENCODER_B_CHANNEL          DIO_12
#define TURNER_MOTOR_CHANNEL              PWM_7
#define TURNER_ENCODER_A_CHANNEL          DIO_13
#define TURNER_ENCODER_B_CHANNEL          DIO_14
#define FEEDER_MOTOR_CHANNEL              PWM_8

// Camera
//   1 digital output
#define CAMERA_IP_ADDR                    "10.34.99.11"
#define CAMERA_GREEN_LEDS_CHANNEL         DIO_1
#define CAMERA_BLUE_LEDS_CHANNEL          DIO_2

// Configuration Switches
//   3 digital inputs
#define CONFIG_0_CHANNEL                  DIO_3
#define CONFIG_1_CHANNEL                  DIO_4
#define CONFIG_2_CHANNEL                  DIO_5
#define CONFIG_3_CHANNEL                  DIO_6

//      o    o    o    o
//      |    |    |    |
//     |^|  |^|  |^|  |^|
//     |I|  |I|  |I|  |I|
//     |_|  |_|  |_|  |_|
//
//      3    2    1    0
// # of channel -- Up = on
//
// 0- Robot positioning 1
// 1- Robot positioning 2
// 2- Autonomous Config 1
// 3- Autonomous Config 2
//

// Rangefinder Arduino
//   1 digital output
//   SPI bus
#define RANGEFINDER_SPI_SELECT_CHANNEL    DIO_10

// Rangefinder cRIO (Alternate to Arduino)
//   6 analog inputs
#define RANGEFINDER_FRONT_CENTER_CHANNEL  AIO_1
#define RANGEFINDER_FRONT_RIGHT_CHANNEL   AIO_2
#define RANGEFINDER_FRONT_LEFT_CHANNEL    AIO_3
#define RANGEFINDER_BACK_CENTER_CHANNEL   AIO_4
#define RANGEFINDER_BACK_RIGHT_CHANNEL    AIO_5
#define RANGEFINDER_BACK_LEFT_CHANNEL     AIO_6

//
// Drive Control Assignments
//
#define DRIVE_GAMEPAD_PORT     1
#define ACCESSORY_GAMEPAD_PORT 2

#endif /* ROBOTMAP_H */
