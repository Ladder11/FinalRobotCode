/** Constants used in sending Telemetry packets
  * @author Jordan Burklund
  * @date Dec. 2015
  **/

#include <stdint.h>

const uint8_t START_BYTE = 0xFF;

const uint8_t COMMAND_START = 0x01;
const uint8_t COMMAND_STOP = 0x02;
const uint8_t COMMAND_ROBOT_POSE = 0x03;
const uint8_t COMMAND_FLAME_LOC = 0x04;
const uint8_t COMMAND_CAMERA_DATA = 0x05;
const uint8_t COMMAND_BATT_VOLT = 0x06;
const uint8_t COMMAND_GYRO_DATA = 0x07;
const uint8_t COMMAND_STATUS = 0x08;
const uint8_t COMMAND_RUNNING = 0x09;
const uint8_t COMMAND_STOPPED = 0x0A;

const uint8_t LEN_START = 4;
const uint8_t LEN_STOP = 4;
const uint8_t LEN_ROBOT_POSE = 13;
const uint8_t LEN_FLAME_LOC = 13;
const uint8_t LEN_CAMERA_DATA = 9;
const uint8_t LEN_BATT_VOLT = 7;
const uint8_t LEN_GYRO_DATA = 7;
const uint8_t LEN_STATUS = 6;
const uint8_t LEN_RUNNING = 4;
const uint8_t LEN_STOPPED = 4;

const uint8_t STATUS_WAIT4START = 0x01;
const uint8_t STATUS_WALLFOLLOW = 0x02;
const uint8_t STATUS_APPROACH_FLAME = 0x03;
const uint8_t STATUS_CALC_FLAME_LOC = 0x04;
const uint8_t STATUS_EXT_FLAME = 0x05;
const uint8_t STATUS_RETURN_HOME = 0x06;
const uint8_t STATUS_HOME = 0x07;

const uint8_t SUBSTATUS_TOOFARFROMWALL = 0x01;
const uint8_t SUBSTATUS_TURNING_TO_CANDLE_SEEN_POS = 0x02;
const uint8_t SUBSTATUS_DRIVING_TO_CANDLE_SEEN_POS = 0x03;
const uint8_t SUBSTATUS_WALLFOLLOW = 0x04;
const uint8_t SUBSTATUS_NONE = 0xFF;

//Pins for the Serial3 ports
const int SERIAL3_RX_PIN = 15;
const int SERIAL3_TX_PIN = 14;
