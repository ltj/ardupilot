#ifndef AP_SENSOR_H
#define AP_SENSOR_H

#include <inttypes.h>
#include <AP_Param.h>
#include <AP_HAL.h>

class AP_Sensor {
public:
	AP_Sensor() : 
		_last_update(0)
	{
		_flags.initialised = false;
		_flags.healthy = false;
		AP_Param::setup_object_defaults(this, var_info);
	}

	bool init();
	bool read();
	int16_t get_value(void);

	uint32_t get_last_update() const { return _last_update; };

	static const struct AP_Param::GroupInfo var_info[];

protected:
	struct Sensor_flags {
		uint8_t initialised :1; // trur if sensor is init.
        uint8_t healthy :1;  	// true if sensor is healthy
    } _flags;
	uint32_t _last_update; // in ms

private:
	int16_t _sensor_value;
};

#endif // AP_SENSOR_H