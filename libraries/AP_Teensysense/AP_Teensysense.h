#ifndef AP_TEENSYSENSE_H
#define AP_TEENSYSENSE_H

#include <inttypes.h>
#include <AP_Param.h>
#include <AP_HAL.h>
#include <AP_Common.h>

class AP_Teensysense {
public:
	AP_Teensysense();
	void init();
	int16_t read();

private:
	int16_t _sensor_value;
	int 	_sensor_fd;
	bool	_initialised;

};

#endif