# A mini smart house implementation using Atmel AVR32 microcontrollers

The project consists of 2 microcontrollers
#### First MCU interfaces with
* A keypad
* Buzzer
* Motor on PWM
* 3 LEDs
* UART interface
* LCD

#### Second MCU interfaces with
* LCD
* Bi-directional motor
* Buzzer
* ADC (2 channels)
* UART interface

In the first MCU, the keypad is used to enter a password, and a welcoming message will appear on the LCD. Then you can open/close the door (bi-directional motor) in the second MCU through UART. If the entered password is wrong 3 times in a row, the 2 buzzers connected to the 2 MCUs will be on for 10 seconds and no one can enter a password within that time.

In the second MCU, the 2 ADC channels will act as temprature and light sensors, and their readings will be displayed on the LCD. Additionally, the second MCU will send the temprature and light intensity to the first MCU where the PWM motor speed will be determined by the temprature, and the 3 LEDs will react to the light intensity.

Implemented passwords are:
* 123
* 456
* 789

Simulation was done using proteus 8. The design file "Simulation.DSN" is provided along with a screenshot explaining some buttons purposes.
