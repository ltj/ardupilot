/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
#ifndef GenericI2C_H
#define GenericI2C_H

#include <inttypes.h>
#include <AP_Common.h>
#include <AP_Param.h>

#define SENSOR_VALUE_DEFAULT 42

class GenericI2C {
public:
	GenericI2C();

	virtual bool init();
	virtual bool read(void) = 0;

	static const struct AP_Param::GroupInfo var_info[];

protected:
	AP_Int16 _sensor_value;
};

#endif