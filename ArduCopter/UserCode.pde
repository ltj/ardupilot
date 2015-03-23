/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifdef USERHOOK_INIT
void userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP
void userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void userhook_SuperSlowLoop()
{
    // put your 1Hz code here
	// I2C test
	bool gotSema = true;
	uint8_t buf[7];

	AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();
	if (i2c_sem == NULL || !i2c_sem->take(1)) {
        gotSema = false;
    }

    if(gotSema) {
    	hal.console->println("Reading registers");

    	uint8_t toSend[1] = { 0x00 };
    	uint8_t result = hal.i2c->write(104, 1, toSend);
		hal.console->printf("I2C write result: %d \n", result);

    	// uint8_t result = hal.i2c->readRegisters((uint8_t)0x68, 0, 7, buf);
    	
    	result = hal.i2c->read(104, 7, buf);
    	hal.console->printf("I2C read result: %d \n", result);

    	hal.console->print("DateTime: ");
    	for(int i=0; i<7; i++) {
    		// int8_t binval = buf[i] - 6 * (buf[i] >> 4);
    		hal.console->printf("%u ", buf[i]);
    	}
    	hal.console->println();

    	i2c_sem->give();
    }

    // get some GPS data and send out custom MAVLINK
    static int32_t value = 0;
    uint64_t usec = gps.time_epoch_usec();
    const Location &loc = gps.location();
    mavlink_msg_sensor_send(MAVLINK_COMM_1, value++, "test_sensor", usec, loc.alt, loc.lng, loc.lat);
    hal.console->print("Lat: ");
    print_latlon(hal.console, loc.lat);
    hal.console->print(" Lon: ");
    print_latlon(hal.console, loc.lng);
    hal.console->printf(" mavink msg sent, val: %d, %.2fm \n", value, loc.alt * 0.01f);
}
#endif