#include <AP_Common.h>
#include <AP_Progmem.h>
#include <AP_Param.h>
#include <StorageManager.h>
#include <AP_HAL.h>
#include <AP_HAL_AVR.h>
#include <AP_HAL_PX4.h>
#include <AP_HAL_Linux.h>
#include <AP_HAL_FLYMAPLE.h>
#include <AP_HAL_Empty.h>
#include <AP_HAL_VRBRAIN.h>

#include <AP_Math.h>
#include <AP_Compass.h>
#include <AP_Declination.h>
#include <AP_GenericI2C.h> // Compass Library
#include <GCS_MAVLink.h>
#include <AP_Scheduler.h>
#include <DataFlash.h>
#include <AP_GPS.h>
#include <AP_Vehicle.h>
#include <AP_InertialSensor.h>
#include <Filter.h>
#include <AP_Baro.h>
#include <AP_AHRS.h>
#include <AP_Airspeed.h>
#include <AP_NavEKF.h>
#include <AP_ADC.h>
#include <AP_ADC_AnalogSource.h>
#include <AP_Notify.h>
#include <AP_Mission.h>
#include <AP_Terrain.h>
#include <AP_Rally.h>
#include <AP_BattMonitor.h>

const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;

static AP_GenericI2C_Teensy generici2c;

uint32_t timer;

void setup() {
    hal.console->println("Teensy library test");

    if (!generici2c.init()) {
        hal.console->println("Teensy initialisation failed!");
        while (1) ;
    }
    hal.console->println("init done");

    hal.scheduler->delay(1000);
    timer = hal.scheduler->micros();
}

void loop() {

    if((hal.scheduler->micros()- timer) > 100000L) {
        timer = hal.scheduler->micros();
        generici2c.read();
        unsigned long read_time = hal.scheduler->micros() - timer;


        // display all to user
        hal.console->println("Teensy read.");
        hal.console->printf(" t=%u", (unsigned)read_time);
        hal.console->println();
    } else {
	    hal.scheduler->delay(1);
    }
}

AP_HAL_MAIN();
