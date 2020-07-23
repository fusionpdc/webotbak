#include"GeckoRunner.hpp"

  // get the time step of the current world.
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  
  
  int main(int argc, char **argv) {

  motion_controller.Set_Distance(0,20,24);// create the Robot instance.
  
  //direction_inertialunit=robot->getInertialUnit(InertialUnit_NAME[0]);
  //direction_inertialunit->enable(timeStep);
 
  for(int i=0;i<4;i++)
  {
   limb_force_sensor[i] = robot->getTouchSensor(TOUCH_SENSOR_NAMES[0]);
   limb_force_sensor[i]->enable(timeStep);
   
    for(int j=0;j<3;j++)
    {
      limb_motors[i][j] = robot->getMotor(MOTION_NAMES[i][j]);
    }
  }
  
  /////////////*******************************************///////////////
  while (robot->step(timeStep) != -1) {
  
   motion_controller.getNextStep();
  // const double *c=direction_inertialunit->getRollPitchYaw();
   //cout<<c[0]<<"  "<<c[1]<<"  "<<c[2]<<endl;
    
   for(int i=0;i<4;i++)
  {
  motion_controller.touchState[i]=limb_force_sensor[i]->getValue();
  }
 
  for(int i=0;i<4;i++)
  {  
    for(int j=0;j<3;j++)
    {
      limb_motors[i][j]->setPosition(motion_controller.a[i][j]);
    }
      cout<<limb_force_sensor[i]->getValue()<<"    ";
  }
    cout<<endl;

    //  motion_controller.Outputall_PWM();
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();

    // Process sensor data here.
    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  }

  // Enter here exit cleanup code.

  delete robot;
  return 0;
  }
