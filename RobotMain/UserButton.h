#ifndef USERBUTTON_H
#define USERBUTTON_H

#include <Arduino.h>

class UserButton {
public:
	UserButton(int pin);
	void initialize();
	bool isPressed();
private:
	const int BUTTON_PIN;
}; 

#endif
