#include <AP_Progmem.h>
#include "GenericI2C.h"

const AP_Param::GroupInfo GenericI2C::var_info[] PROGMEM = {

	// @Param: S_VALUE
    // @DisplayName: Some sensor value
    // @Description: Float value read from I2C slave configure uC
    // @Range: -32768 32767
    // @User: Standard
    AP_GROUPINFO("S_VALUE", 1, GenericI2C, _sensor_value, SENSOR_VALUE_DEFAULT),

	AP_GROUPEND
};

GenericI2C::GenericI2C(void) {
	AP_Param::setup_object_defaults(this, var_info);
}

bool GenericI2C::init() {
	return true;
}