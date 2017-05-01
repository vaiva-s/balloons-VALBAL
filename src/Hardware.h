/*
  Stanford Student Space Initiative
  Balloons | VALBAL | April 2017
  Davy Ragland | dragland@stanford.edu
  Claire Huang | chuang20@stanford.edu
  Matthew Tan | mratan@stanford.edu

  File: Hardware.h
  --------------------------
  Interface to PCB hardware.
*/

#ifndef HARDWARE_H
#define HARDWARE_H

#include "Config.h"
#include <EEPROM.h>
#include <PID_v1.h>

class Hardware {
public:
/**********************************  SETUP  ***********************************/
  Hardware() :
    pid(&PIDTempVar, &PIDOutVar, &PIDSetVar, 2, 5, 1, DIRECT) {
  }
  void     init();
/********************************  FUNCTIONS  *********************************/
  void     runLED(bool on);
  void     faultLED();

  bool     startupPayload(bool shouldStartup);

  bool     startUpHeaters(bool shouldStartup);
  void     heater(double tempSetpoint, double temp, bool strong, bool weak);
  void     turnOffHeaters();
  void     setHeaterMode(bool on);

  void     queueValve(uint32_t  duration, bool real);
  void     queueBallast(uint32_t  duration, bool real);
  void     clearValveQueue();
  void     clearBallastQueue();
  bool     checkValve(float current);
  bool     checkBallast(float current);
  uint32_t getValveQueue();
  uint32_t getBallastQueue();

  void     cutDown(bool on);

  void     EEPROMWritelong(uint8_t address, int32_t value);
  int32_t  EEPROMReadlong(uint8_t address);

private:
/*********************************  HELPERS  **********************************/
  void     stopValve();
  void     openValve();
  void     closeValve();

  void     stopBallast();
  void     dropBallast(bool direction);

/*********************************  OBJECTS  **********************************/
  enum state_t {OPEN, OPENING, CLOSED, CLOSING};
  state_t  valveState = CLOSED;
  state_t  ballastState = CLOSED;
  uint32_t valveQueue = 0;
  uint32_t valveQueueFake = 0;
  uint32_t ballastQueue = 0;
  uint32_t ballastQueueFake = 0;
  uint32_t valveLeakStartTime = 0;
  uint32_t valveActionStartTime = 0;
  uint32_t ballastActionStartTime = 0;
  uint32_t valveCheckTime = 0;
  uint32_t ballastCheckTime = 0;
  uint32_t ballastDirectionTime = 0;
  bool     ballastDirection = false;

  double   PIDSetVar;
  double   PIDOutVar;
  double   PIDTempVar;
  PID pid;
};

#endif
