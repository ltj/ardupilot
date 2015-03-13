/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
#ifndef AP_GenericI2C_Teensy_H
#define AP_GenericI2C_Teensy_H

#include <AP_HAL.h>
#include "../AP_Common/AP_Common.h"

#include "GenericI2C.h"

class AP_GenericI2C_Teensy : public GenericI2C
{
private:
    uint32_t            _retry_time; // when unhealthy the millis() value to retry at
    AP_HAL::Semaphore*  _i2c_sem;
    bool                _initialised;

    int16_t			    _value;

public:
    AP_GenericI2C_Teensy() : GenericI2C() {
    }

    bool        init(void);
    bool        read(void);

};
#endif