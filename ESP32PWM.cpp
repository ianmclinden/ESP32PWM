/*
  Async.h - ESP32 Platform PWM wrapper
  2018 Ian McLinden
*/

#include "Arduino.h"
#include "ESP32PWM.h"

// ==== Public ================================================================
static int _pwmChannel = 0;

// ---- Constructors ----------------------------------------------------------
ESP32PWM::ESP32PWM(int pin, unsigned long frequency) {
	_init(pin, frequency);
}
ESP32PWM::ESP32PWM(int pin, double frequency) {
	_init(pin,(unsigned long)frequency);
}
ESP32PWM::ESP32PWM(int pin, int frequency) {
	_init(pin,(unsigned long)frequency);
}
ESP32PWM::ESP32PWM(int pin) {
	_init(pin, (unsigned long)500);
}

// ---- Begin -----------------------------------------------------------------
void ESP32PWM::begin() {
	ledcSetup(_channel, _frequency, 8);
	ledcAttachPin(_pin, _channel);
}

// ---- PWM Duty Handlers -----------------------------------------------------
void ESP32PWM::analogWrite(uint8_t value) {
	_duty = value;
	if (_enabled) ledcWrite(_channel, _duty);
}
uint8_t ESP32PWM::analogRead() {
	return _duty;
}
void ESP32PWM::setDuty(uint8_t value) {
	_duty = value;
}

// ---- Pin State Handlers ----------------------------------------------------
void ESP32PWM::enable() {
	_enabled = true;
	ledcWrite(_channel, _duty);
}
void ESP32PWM::disable() {
	_enabled = false;
	ledcWrite(_channel, 0);
}
bool ESP32PWM::isEnabled() {
	return _enabled;
}

// ---- Frequency Handlers ----------------------------------------------------
void ESP32PWM::setFrequency(unsigned long frequency) {
	_setFrequency(frequency);
}
void ESP32PWM::setFrequency(double frequency) {
	_setFrequency((unsigned long)frequency);
}
void ESP32PWM::setFrequency(int frequency) {
	_setFrequency((unsigned long)frequency);
}
unsigned long ESP32PWM::getFrequency() {
	return _frequency;
}

// ==== Private ===============================================================
void ESP32PWM::_init(int pin, unsigned long frequency) {
	_enabled = true;
	_duty = 0;
	_channel = _pwmChannel++; 
	_pin = pin;
	_frequency = frequency;
}

void ESP32PWM::_setFrequency(unsigned long frequency) {
	_frequency = frequency;
	ledcSetup(_channel, _frequency, 8);
}
