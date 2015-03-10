// MESSAGE SENSOR_REQUEST PACKING

#define MAVLINK_MSG_ID_SENSOR_REQUEST 145

typedef struct __mavlink_sensor_request_t
{
 int32_t sensor_number; ///< number of sensor
} mavlink_sensor_request_t;

#define MAVLINK_MSG_ID_SENSOR_REQUEST_LEN 4
#define MAVLINK_MSG_ID_145_LEN 4

#define MAVLINK_MSG_ID_SENSOR_REQUEST_CRC 3
#define MAVLINK_MSG_ID_145_CRC 3



#define MAVLINK_MESSAGE_INFO_SENSOR_REQUEST { \
	"SENSOR_REQUEST", \
	1, \
	{  { "sensor_number", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_sensor_request_t, sensor_number) }, \
         } \
}


/**
 * @brief Pack a sensor_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sensor_number number of sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t sensor_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_REQUEST_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#else
	mavlink_sensor_request_t packet;
	packet.sensor_number = sensor_number;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a sensor_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_number number of sensor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t sensor_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_REQUEST_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#else
	mavlink_sensor_request_t packet;
	packet.sensor_number = sensor_number;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SENSOR_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
}

/**
 * @brief Encode a sensor_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_request_t* sensor_request)
{
	return mavlink_msg_sensor_request_pack(system_id, component_id, msg, sensor_request->sensor_number);
}

/**
 * @brief Encode a sensor_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_request_t* sensor_request)
{
	return mavlink_msg_sensor_request_pack_chan(system_id, component_id, chan, msg, sensor_request->sensor_number);
}

/**
 * @brief Send a sensor_request message
 * @param chan MAVLink channel to send the message
 *
 * @param sensor_number number of sensor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_request_send(mavlink_channel_t chan, int32_t sensor_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SENSOR_REQUEST_LEN];
	_mav_put_int32_t(buf, 0, sensor_number);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
#else
	mavlink_sensor_request_t packet;
	packet.sensor_number = sensor_number;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SENSOR_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t sensor_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, sensor_number);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, buf, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
#else
	mavlink_sensor_request_t *packet = (mavlink_sensor_request_t *)msgbuf;
	packet->sensor_number = sensor_number;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, (const char *)packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN, MAVLINK_MSG_ID_SENSOR_REQUEST_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_REQUEST, (const char *)packet, MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SENSOR_REQUEST UNPACKING


/**
 * @brief Get field sensor_number from sensor_request message
 *
 * @return number of sensor
 */
static inline int32_t mavlink_msg_sensor_request_get_sensor_number(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a sensor_request message into a struct
 *
 * @param msg The message to decode
 * @param sensor_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_request_decode(const mavlink_message_t* msg, mavlink_sensor_request_t* sensor_request)
{
#if MAVLINK_NEED_BYTE_SWAP
	sensor_request->sensor_number = mavlink_msg_sensor_request_get_sensor_number(msg);
#else
	memcpy(sensor_request, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SENSOR_REQUEST_LEN);
#endif
}
