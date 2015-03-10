// MESSAGE SENSOR_RESPOND PACKING

#define MAVLINK_MSG_ID_SENSOR_RESPOND 146

typedef struct __mavlink_sensor_respond_t
{
 int32_t sensor_number; ///< number of sensor
 int32_t sensor_value; ///< value
} mavlink_sensor_respond_t;

#define MAVLINK_MSG_ID_SENSOR_RESPOND_LEN 8
#define MAVLINK_MSG_ID_146_LEN 8

#define MAVLINK_MSG_ID_SENSOR_RESPOND_CRC 215
#define MAVLINK_MSG_ID_146_CRC 215



#define MAVLINK_MESSAGE_INFO_SENSOR_RESPOND { \
	"SENSOR_RESPOND", \
	2, \
	{  { "sensor_number", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sensor_respond_t, sensor_number) }, \
         { "sensor_value", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_sensor_respond_t, sensor_value) }, \
         } \
}


/**
 * @brief Pack a sensor_respond message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sensor_number number of sensor
 * @param sensor_value value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_respond_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t sensor_number, int32_t sensor_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_RESPOND_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);
	_mav_put_int32_t(buf, 4, sensor_value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#else
	mavlink_sensor_respond_t packet;
	packet.sensor_number = sensor_number;
	packet.sensor_value = sensor_value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_RESPOND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
}

/**
 * @brief Pack a sensor_respond message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_number number of sensor
 * @param sensor_value value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_respond_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t sensor_number,int32_t sensor_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_RESPOND_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);
	_mav_put_int32_t(buf, 4, sensor_value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#else
	mavlink_sensor_respond_t packet;
	packet.sensor_number = sensor_number;
	packet.sensor_value = sensor_value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_RESPOND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
}

/**
 * @brief Encode a sensor_respond struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_respond_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_respond_t* sensor_respond)
{
	return mavlink_msg_sensor_respond_pack(system_id, component_id, msg, sensor_respond->sensor_number, sensor_respond->sensor_value);
}

/**
 * @brief Encode a sensor_respond struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_respond_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_respond_t* sensor_respond)
{
	return mavlink_msg_sensor_respond_pack_chan(system_id, component_id, chan, msg, sensor_respond->sensor_number, sensor_respond->sensor_value);
}

/**
 * @brief Send a sensor_respond message
 * @param chan MAVLink channel to send the message
 *
 * @param sensor_number number of sensor
 * @param sensor_value value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_respond_send(mavlink_channel_t chan, int32_t sensor_number, int32_t sensor_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_RESPOND_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);
	_mav_put_int32_t(buf, 4, sensor_value);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
#else
	mavlink_sensor_respond_t packet;
	packet.sensor_number = sensor_number;
	packet.sensor_value = sensor_value;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SENSOR_RESPOND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_respond_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t sensor_number, int32_t sensor_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, sensor_number);
	_mav_put_int32_t(buf, 4, sensor_value);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, buf, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
#else
	mavlink_sensor_respond_t *packet = (mavlink_sensor_respond_t *)msgbuf;
	packet->sensor_number = sensor_number;
	packet->sensor_value = sensor_value;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, (const char *)packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN, MAVLINK_MSG_ID_SENSOR_RESPOND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_RESPOND, (const char *)packet, MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SENSOR_RESPOND UNPACKING


/**
 * @brief Get field sensor_number from sensor_respond message
 *
 * @return number of sensor
 */
static inline int32_t mavlink_msg_sensor_respond_get_sensor_number(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field sensor_value from sensor_respond message
 *
 * @return value
 */
static inline int32_t mavlink_msg_sensor_respond_get_sensor_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a sensor_respond message into a struct
 *
 * @param msg The message to decode
 * @param sensor_respond C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_respond_decode(const mavlink_message_t* msg, mavlink_sensor_respond_t* sensor_respond)
{
#if MAVLINK_NEED_BYTE_SWAP
	sensor_respond->sensor_number = mavlink_msg_sensor_respond_get_sensor_number(msg);
	sensor_respond->sensor_value = mavlink_msg_sensor_respond_get_sensor_value(msg);
#else
	memcpy(sensor_respond, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SENSOR_RESPOND_LEN);
#endif
}
