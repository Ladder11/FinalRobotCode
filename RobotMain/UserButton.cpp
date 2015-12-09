/** Abstraction for a button on the robot
  * @author Jordan Burklund
  * @date Sept. 2015
  **/

#include "UserButton.h"

/** Constructor
  * @param digital pin the button is plugged into
  **/
UserButton::UserButton(int pin) : BUTTON_PIN(pin) {

}

/** Set up the pin for the button **/
void UserButton::initialize() {
	pinMode(BUTTON_PIN, INPUT_PULLUP);
}

/** Check if the button is pressed **/
bool UserButton::isPressed() {
	return !digitalRead(BUTTON_PIN);
}

