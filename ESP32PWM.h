/*
  ESP32PWM.h - ESP32 Platform PWM wrapper
  2018 Ian McLinden
*/

// ensure this library description is only included once
#ifndef H_ESP32PWM
#define H_ESP32PWM

class ESP32PWM {
    public:
    ESP32PWM(int pin, unsigned long frequency);
    ESP32PWM(int pin, double frequency);
    ESP32PWM(int pin, int frequency);
    ESP32PWM(int pin);

    void begin();
    
    void analogWrite(uint8_t value);
    uint8_t analogRead();
    
    void setDuty(uint8_t value);

    void enable();
    void disable();
    bool isEnabled();
    
    void setFrequency(unsigned long frequency);
    void setFrequency(double frequency);
    void setFrequency(int frequency);
    unsigned long getFrequency();

    private:
    void _init(int pin, unsigned long frequency);
    void _setFrequency(unsigned long frequency);
    uint8_t _duty;
    bool _enabled;
    unsigned long _frequency;
    int _pin;
    int _channel;
};
#endif
