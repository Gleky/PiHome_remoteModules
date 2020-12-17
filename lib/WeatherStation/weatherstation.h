#pragma once


class WeatherStation
{
public:
    WeatherStation(char const *ip, unsigned short port, unsigned char addres, unsigned short powerPin);

    void init();
    void loop();

private:
    char const * const _ip;
    unsigned short const _port;
    unsigned char const _address;
    unsigned short const _powerPin;

    unsigned long _lastTime = 0;
    unsigned long const _period = 60000;
};
