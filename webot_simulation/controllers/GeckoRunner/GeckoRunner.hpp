// File:          GeckoRunner.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include<ctime>
#include<iostream>
#include<math.h>

//#include "Motion.hpp"
#include "Motion.cpp" 
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/TouchSensor.hpp>
#include <webots/Compass.hpp>
#include <webots/InertialUnit.hpp>
// All the webots classes are defined in the "webots" namespace
using namespace webots;

const char* MOTION_NAMES[4][3] = {
   {"RF0", "RF1", "RF2"},
   {"RH0", "RH1", "RH2"},
   {"LF0", "LF1", "LF2"},
   {"LH0", "LH1", "LH2"}
};

const char* SENSOR_NAMES[4][3] = {
   {"RF0 sensor", "RF1 sensor", "RF2 sensor"},
   {"RH0 sensor", "RH1 sensor", "RH2 sensor"},
   {"LF0 sensor", "LF1 sensor", "LF2 sensor"},
   {"LH0 sensor", "LH1 sensor", "LH2 sensor"}
};
const char* TOUCH_SENSOR_NAMES[4] = {
"RF touch sensor", "RH touch sensor", 
"LF touch sensor", "LH touch sensor"
};

const char *InertialUnit_NAME[1]={"body_internialunit"};

//extern float limb_force_sensor[4];

Motor *limb_motors[4][3];
TouchSensor *limb_force_sensor[4];
Motion motion_controller;
Robot *robot = new Robot();
InertialUnit *direction_inertialunit();
int timeStep = (int)robot->getBasicTimeStep();//wb_touch_sensor_enable(timeStep);

  
//virtual enable (timeStep);
// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
/*  // delay
static void sleep_ms(unsigned int secs)
{
struct timeval tval;

tval.tv_sec=secs/1000;

tval.tv_usec=(secs*1000)%1000000;

select(0,NULL,NULL,NULL,&tval);
}
*/
// This fution used to delay ms in linux environment 