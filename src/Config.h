/*
  Stanford Student Space Initiative
  Balloons | VALBAL | June 2017
  Davy Ragland | dragland@stanford.edu

  File: Config.h
  --------------------------
  Global constants specific to each launch.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <stdint.h>
#include <string.h>

/****************************  COMPILE FLAGS  *********************************/
// #define STORAGE_MODE_FLAG // uncomment for power off
// #define RESET_EEPROM_FLAG // uncomment for EEPROM
// #define HITL_ENABLED_FLAG // uncomment for HITL
// #define RB_DISABLED_FLAG  // uncomment for HITL

/*****************************  TEENSY PIN OUTS  ******************************/
static const uint8_t   REBOOT_ENABLE                         =               16;
static const uint8_t   SD_CS                                 =               23;
static const uint8_t   LED_PIN                               =               33;
static const uint8_t   BMP_CS_ONE                            =               32;
static const uint8_t   BMP_CS_TWO                            =               25;
static const uint8_t   BMP_CS_THREE                          =               15;
static const uint8_t   BMP_CS_FOUR                           =               22;
static const uint8_t   VALVE_FORWARD                         =                6;
static const uint8_t   VALVE_REVERSE                         =               20;
static const uint8_t   BALLAST_FORWARD                       =               21;
static const uint8_t   BALLAST_REVERSE                       =                5;
static const uint8_t   HEATER_INTERNAL_STRONG                =                4;
static const uint8_t   HEATER_INTERNAL_WEAK                  =                3;
static const uint8_t   GPS_GATE                              =               17;
static const uint8_t   RB_GATE                               =               28;
static const uint8_t   RB_SLEEP                              =               14;
static const uint8_t   PAYLOAD_GATE                          =               24;
static const uint8_t   BATT_VOLTAGE                          =              A14;
static const uint8_t   BOOST_VOLTAGE                         =              A10;
static const uint8_t   USB_CURRENT                           =              A11;
static const uint8_t   TOTAL_CURRENT                         =                1;
static const uint8_t   RB_CURRENT                            =                2;
static const uint8_t   MOTORS_CURRENT                        =                3;
static const uint8_t   PAYLOAD_CURRENT                       =                4;
static const uint8_t   EXT_TEMP_SENSOR                       =              A15;
static const uint8_t   BLACK_BODY_TEMP_SENSOR                =              A20;

/****************************  EDITABLE CONSTANTS  ****************************/
static const char      MISSION_NUMBER[]                      =         "SSI-54";

static const uint8_t   CUTDOWN_INDEX                         =               99;
static const uint16_t  CUTDOWN_DURATION                      =            10000;

static const uint16_t  GPS_LOCK_TIMEOUT                      =               30;
static const uint16_t  GPS_QUIT_TIMEOUT                      =            10000;

static const uint32_t  GPS_INTERVAL_DEFAULT                  =            12000;
static const uint32_t  RB_INTERVAL_DEFAULT                   =           120000;
static const uint32_t  RB_RESTART_INTERVAL                   =          1800000;
static const uint32_t  RB_DEBUG_INTERVAL                     =            60000;
static const uint16_t  LOOP_INTERVAL                         =               50;

static const uint16_t  DEBUG_ALT                             =              300;
static const uint16_t  COMMS_BUFFER_SIZE                     =              200;
static const uint32_t  FILE_RESET_INTERVAL                   =         86400000;
static const uint32_t  CONSOLE_BAUD                          =           115200;
static const uint32_t  GPS_BAUD                              =             9600;
static const uint32_t  RB_BAUD                               =            19200;

/***************************  Flight Parameters  ******************************/
static const float     TEMP_SETPOINT_DEFAULT                 =              -40;
static const bool      MANUAL_MODE_DEFAULT                   =             true;
static const uint8_t   REPORT_MODE_DEFAULT                   =                2;
static const bool      RB_SHOULD_SLEEP_DEFAULT               =            false;
static const uint32_t  QUEUE_APPEND_THRESHOLD                =             1000;

static const float     PRESS_BASELINE_DEFAULT                =         101325.0;
static const float     INCENTIVE_NOISE_DEFAULT               =                0;
static const float     INCENTIVE_THRESHOLD_DEFAULT           =             0.75;
static const float     RE_ARM_DEFAULT                        =                0;
static const float     BALLAST_ARM_ALT_DEFAULT               =          13250.0;
static const float     BALLAST_ALT_LAST_FILLER               =          14000.0;
static const uint32_t  BALLAST_REVERSE_INTERVAL_DEFAULT      =           600000;
static const uint32_t  VALVE_LEAK_INTERVAL_DEFAULT           =           600000;
static const uint16_t  BALLAST_STALL_CURRENT_DEFAULT         =              270;

static const float     VALVE_SETPOINT_DEFAULT                =          14500.0;
static const uint32_t  VALVE_VENT_DURATION_DEFAULT           =            20000;
static const float     VALVE_ALT_LAST_DEFAULT                =                0;
static const float     VALVE_VELOCITY_DEFAULT                =              1.0;
static const float     VALVE_ALTITUDE_DIFF_DEFAULT           =     1.0 / 1500.0;
static const float     VALVE_LAST_ACTION_DEFAULT             =     1.0 / 1500.0;

static const float     BALLAST_SETPOINT_DEFAULT              =          13500.0;
static const uint32_t  BALLAST_DROP_DURATION_DEFAULT         =            20000;
static const float     BALLAST_ALT_LAST_DEFAULT              =         -90000.0;
static const float     BALLAST_VELOCITY_DEFAULT              =              1.0;
static const float     BALLAST_ALTITUDE_DIFF_DEFAULT         =     1.0 / 1500.0;
static const float     BALLAST_LAST_ACTION_DEFAULT           =     1.0 / 1500.0;

static const uint16_t  VALVE_MOTOR_SPEED_DEFAULT             =              255;
static const uint16_t  BALLAST_MOTOR_SPEED_DEFAULT           =              255;
static const uint32_t  VALVE_OPENING_DURATION_DEFAULT        =             1000;
static const uint32_t  VALVE_CLOSING_DURATION_DEFAULT        =             2500;
static const uint16_t  BALLAST_STALL_TIMEOUT                 =             3000;

static const float     MAX_PRESURE                           =           107500;
static const float     MIN_PRESURE                           =             1131;
static const float     MAX_CONSENSUS_DEVIATION               =              150;
static const uint16_t  MAX_VELOCITY                          =               50;
static const uint16_t  ALTITUDE_STANDARD_DEV                 =                2;
static const uint16_t  ALTITUDE_BUFFER_SIZE                  =             1000;
static const uint16_t  MINIMUM_ALTITUDE_POINTS               =              600;
static const uint16_t  MINIMUM_ASCENT_RATE_POINTS            =              600;

/*****************************  EEPROM ADDRESSES  *****************************/
static const uint8_t   EEPROM_ROCKBLOCK                      =                0;
static const uint8_t   EEPROM_GPS                            =                1;
static const uint8_t   EEPROM_HEATER                         =                2;
static const uint8_t   EEPROM_PAYLOAD                        =                3;

static const uint8_t   EEPROM_VALVE_ALT_LAST                 =                4;
static const uint8_t   EEPROM_BALLAST_ALT_LAST               =                8;

static const uint8_t   EEPROM_VALVE_SETPOINT                 =               12;
static const uint8_t   EEPROM_VALVE_VELOCITY_CONSTANT        =               16;
static const uint8_t   EEPROM_VALVE_ALTITUDE_DIFF_CONSTANT   =               20;
static const uint8_t   EEPROM_VALVE_LAST_ACTION_CONSTANT     =               24;

static const uint8_t   EEPROM_BALLAST_SETPOINT               =               28;
static const uint8_t   EEPROM_BALLAST_VELOCITY_CONSTANT      =               32;
static const uint8_t   EEPROM_BALLAST_ALTITUDE_DIFF_CONSTANT =               36;
static const uint8_t   EEPROM_BALLAST_LAST_ACTION_CONSTANT   =               40;

static const uint8_t   EEPROM_LOG_BLOCK_CUR                  =              112;
static const uint8_t   EEPROM_LOG_FILE_NUM                   =              116;

#endif
