#include <AP_Math.h>
#include <AP_Common.h>
#include <AP_Sensor.h>
#include <AP_Progmem.h>
#include <AP_HAL.h>

#define SENSOR_ADDRESS 0x44

extern const AP_HAL::HAL& hal;

const AP_Param::GroupInfo AP_Sensor::var_info[] PROGMEM = {

	AP_GROUPEND
};

bool AP_Sensor::init() {

	hal.scheduler->suspend_timer_procs();
    hal.scheduler->delay(10);

    AP_HAL::Semaphore*  _i2c_sem = hal.i2c->get_semaphore();
    if (!_i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)) {
        hal.scheduler->panic(PSTR("Failed to get Teensy semaphore"));
    }

    uint8_t data[] = {0x00, 54};
    // write byte to add 0
    hal.i2c->writeRegisters(SENSOR_ADDRESS, 0x10, 2, data);

    _i2c_sem->give();
    hal.scheduler->resume_timer_procs();
    _flags.initialised = true;
	return true;
}

bool AP_Sensor::read() {
	if(!_flags.initialised) return false;

	uint8_t buf[3];
	AP_HAL::Semaphore*  _i2c_sem = hal.i2c->get_semaphore();

	if (!_i2c_sem->take(1)) {
       // the bus is busy - try again later
       return false;
   	}

    // write byte to add 0
    hal.i2c->writeRegister(SENSOR_ADDRESS, 0x20, 0x00);
   	//hal.i2c->setHighSpeed(false);
   	//hal.i2c->writeRegister(SENSOR_ADDRESS, 0x40, 0x00);

   	if (hal.i2c->read(SENSOR_ADDRESS, 1, buf) != 0) {
        _sensor_value = buf[0];
    }

   	_i2c_sem->give();

	return true;
}

int16_t AP_Sensor::get_value() {
	return _sensor_value;
}

