#include "Drivetrain.h"

/** Constructor
  * Creates regulated motor objects for the left and right side of the robot based on pin assigments in RobotConstants.h
  **/
Drivetrain::Drivetrain() {
	leftMotor = new RegulatedMotor(MOTOR_LEFT_F_PIN, MOTOR_LEFT_R_PIN, ENC_LEFT_SS);
	rightMotor = new RegulatedMotor(MOTOR_RIGHT_F_PIN, MOTOR_RIGHT_R_PIN, ENC_RIGHT_SS);
}

/**
 * Initializes motors
 **/
void Drivetrain::initialize() {
	leftMotor->initialize();
	rightMotor->initialize();
	xPos = 0;
	yPos = 0;
	prevLeft = 0;
	prevRight = 0;
	_theta = 0;
}

/**
 * Moves the robot at a linear speed (fwd/rev) and a turning speed (l/r)
 * @param float Velocity The tangential velocity of the center of the robot (in/s)
 * @param float turnVelocity The turning velocity of the robot (deg/s)
 **/
void Drivetrain::drive(float velocity, float turnVelocity) {
	turnVelocity = turnVelocity*3.1415/360;
	V_r = velocity+(trackWidth*turnVelocity)/2.0;
	V_l = velocity-(trackWidth*turnVelocity)/2.0;
	//Serial.println(V_r*_speedConversion);
	//Serial.println(V_l*_speedConversion);
	rightMotor->setRPM(V_r*speedConversion);
	leftMotor->setRPM(V_l*speedConversion);
	updateRobotPos();
}

/**
 * Sets motor output speed directly to zero, bypassing the PID
 **/
void Drivetrain::stop() {
	leftMotor->setRPM(0);
	rightMotor->setRPM(0);
	updateRobotPos();
}

/**
 * @return Current X position of the robot, the left or right position relative to the origin based on robot coordinate system
 **/
double Drivetrain::getXOdoEst() {
	return xPos;
}

/**
 * @return Current Y position of the robot, the forward or reverse position relative to the origin based on the robot coordinate system
 **/
double Drivetrain::getYOdoEst() {
	return yPos;
}

/**
 * @return The X position of the robot when it first saw the candle
 **/
double Drivetrain::getCandleFoundX() {
  return candleFoundX;
}

/**
 * @return The Y position of the robot when it first saw the candle
 **/
double Drivetrain::getCandleFoundY(){
  return candleFoundY;
}

/**
 * Sets the Y position when the candle is found
 **/
void Drivetrain::setCandleFoundY(){
  candleFoundY=yPos;
}

/**
 * Sets the X position when the candle is found
 **/
void Drivetrain::setCandleFoundX(){
  candleFoundX=xPos;
}

/**
 * Assumes that the robot is facing along the +y axis when turned on
 * @return float theta Deviation from the +y axis, in radians
 **/
double Drivetrain::getOrientOdoEst() {
	return _theta; 
}

/**
 * Updates the odometry estimates for the robot's x, y, and theta positions
 **/
void Drivetrain::updateRobotPos() {

	currLeft = leftMotor->getRevolutions();
	currRight = rightMotor->getRevolutions();

	leftDelta = currLeft-prevLeft;
	rightDelta = currRight-prevRight;
	robotDelta = (leftDelta+rightDelta)/2*turnConversion;

	_theta+=atan((leftDelta-rightDelta)*turnConversion/trackWidth);
	if (_theta > 3.1415) {
		_theta -= 6.283;
	} 

	if (_theta < -3.1415) {
		_theta += 6.283;
	}

	xPos+=robotDelta*sin(_theta);
	yPos+=robotDelta*cos(_theta);

	prevLeft = currLeft;
	prevRight = currRight;
}
