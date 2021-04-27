# Locker Buddy - An Embedded C Project
## ‣ What does it do?
###  This application runs on the Arduino Uno hardware, with the intent to simulate a battery-powered, portable locking system to be fitted in an enclosure.
## ‣ Prototype
## ‣ How does it work?
###  The user interacts with the Locker Buddy by entering a 4 digit pin into a keypad. If the password matches the one stored on the microcontroller, a buzzer signal is emitted before the solenoid lock opens up. The user can now open up the locker. When this happens, the infrared break beam sensor that is responsible for detecting door movement changes its state and observes when the beam realigns. As soon as it does, the solenoid lock is engaged and locks back up.
