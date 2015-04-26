/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifdef USERHOOK_INIT
void userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
    teensy.init();
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
    int16_t value = 0;
    const Location &loc = gps.location();
    uint64_t usec = gps.time_epoch_usec();
    uint32_t fix = gps.last_fix_time_ms();
    if (teensy.read(&value) >= 0) {
        mavlink_msg_int_sensor_send(MAVLINK_COMM_1, value, "wifi_test", usec, loc.alt, loc.lng, loc.lat);
        hal.console->printf("value: %d, fix: %u \n", value, fix);
        hal.console->println("Mavlink message (200) sent");
    }
}
#endif