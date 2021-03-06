/**
 * Constants for the robot, like pin numbers, scale factors, etc.
 **/

#ifndef ROBOTCONSTANTS_H
#define ROBOTCONSTANTS_H

//Ultrasonic Sensor Pins
const int US_RIGHT_INPUT_PIN = 24;
const int US_RIGHT_OUTPUT_PIN = 25;
const int US_FRONT_INPUT_PIN = 26;
const int US_FRONT_OUTPUT_PIN = 27;
const int US_LEFT_INPUT_PIN = 28;
const int US_LEFT_OUTPUT_PIN = 29;

const int ENC_LEFT_SS = 23;
const int ENC_RIGHT_SS = 22;
const int MOTOR_LEFT_F_PIN = 7;
const int MOTOR_LEFT_R_PIN = 6;
const int MOTOR_RIGHT_F_PIN = 4;
const int MOTOR_RIGHT_R_PIN = 5;

const float gearRatio = 0.3;
const float trackWidth = 5.3125;
const float wheelDia = 2.75;
const float speedConversion = 19.1/wheelDia/gearRatio;
const float turnConversion = gearRatio*wheelDia*3.1415;

const float gearboxRatio = 50;
const int encoderCounts = 64;
const float scaleFactor = 60000.0/(float)encoderCounts/gearboxRatio;

const int PROP_PIN = 11;

const int BL_LEFT_FRONT = 48;
const int BL_LEFT_FRONT_GND = 49;
const int BL_LEFT_REAR = 46;
const int BL_LEFT_REAR_GND = 47;

const int BL_RIGHT_FRONT = 34;
const int BL_RIGHT_FRONT_GND = 35;
const int BL_RIGHT_REAR = 32;
const int BL_RIGHT_REAR_GND = 33;

const int LB_LEFT = 9;
const int LB_RIGHT = 8;

const float cameraHeight = 7.5;

#endif
