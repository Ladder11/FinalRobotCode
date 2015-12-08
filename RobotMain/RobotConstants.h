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
const int MOTOR_LEFT_F_PIN = 6;
const int MOTOR_LEFT_R_PIN = 7;
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

#endif
