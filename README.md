# Denon AVR IR Transmitter Remote Controller

This is an Arduino project to transmit basic IR signals to Denon AVR. Tested on Denon AVR-X1600H with Arduino Mega 2560.

## Required materials
- Jumper cables
- IR diode
- 200-250ohm resistor
- Arduino (lmao)

## Connection:
Connect negative pin of IR diode to GND, connect positive pin of IR diode to PIN 9 via resistor (PIN 9 is for Arduino MEGA 2560 it can be smth else on other boards).

## How does it work:
When you load a program on Arduino it starts to listen on Serial port with 9600 bps. You control it by entering commands. List of available commands:
- power  - power toggle
- u      - up
- d      - down
- l      - left
- r      - right
- e      - enter
- b      - back
- ss     - system setup
- phono  - phono input
- volu   - volume up
- vold   - volume down
- mute   - toggle mute

## Notes:
This project uses pronto codes. Denon publishes their IR pronto codes on: http://assets.denon.com/documentmaster/us/denon%20master%20ir%20hex.xls
They can also be found in this repo.