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
    static int32_t value = 0;
    uint64_t usec = gps.time_epoch_usec();
    const Location &loc = gps.location();
    // mavlink_msg_sensor_send(MAVLINK_COMM_1, value++, "test_sensor", usec, loc.alt, loc.lng, loc.lat);
    hal.console->print("Lat: ");
    print_latlon(hal.console, loc.lat);
    hal.console->print(" Lon: ");
    print_latlon(hal.console, loc.lng);
    hal.console->printf(" mavink msg sent, val: %d, %.2fm \n", value, loc.alt * 0.01f);
}
#endif