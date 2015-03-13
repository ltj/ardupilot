#include <AP_HAL.h>

#include "AP_GenericI2C_Teensy.h"

extern const AP_HAL::HAL& hal;

#define TEENSY_ADDRESS 0xEE

bool AP_GenericI2C_Teensy::init() {

	hal.scheduler->suspend_timer_procs();
    hal.scheduler->delay(10);

    _i2c_sem = hal.i2c->get_semaphore();
    if (!_i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)) {
        hal.scheduler->panic(PSTR("Failed to get Teensy semaphore"));
    }

    _i2c_sem->give();
    hal.scheduler->resume_timer_procs();
    _initialised = true;
	return true;
}

bool AP_GenericI2C_Teensy::read() {
	if(!_initialised) return false;

	if (!_i2c_sem->take(1)) {
       // the bus is busy - try again later
       return false;
   	}

   	uint8_t value;

   	if (hal.i2c->readRegister((uint8_t)TEENSY_ADDRESS, 0x00, &value) != 0) {
        _value = (int16_t)value;
        _sensor_value = _value;
    }

   	_i2c_sem->give();



	return true;
}