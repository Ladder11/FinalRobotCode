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