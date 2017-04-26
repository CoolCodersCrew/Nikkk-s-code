#include "main.h"
//Global Variables
int slewTmp;
int slewTarget[10];

//Helpers
int min(int i1, int i2){
  if(i1>=i2) return i2;
  else return i1;
}
int max(int i1, int i2){
  if(i1<=i2) return i2;
  else return i1;
}
void slewControlTask (void * parameter) {
  extern int slewTmp;
  extern int slewTarget[10];
  while (1) {
    for (int i = 0; i < 10; i++){
      slewTmp = motorGet(i+1);
      slewTmp += min(15, abs(slewTarget[i]-slewTmp))*(slewTarget[i]-slewTmp)/abs(slewTarget[i]-slewTmp);
      motorSet (i+1, slewTmp);
    }
    wait (20);
  }
}
void smartMotorSet(int motor, int cmd){
  extern int slewTarget[10];
  if(abs(cmd)<15) cmd=0;
  slewTarget[motor-1]=cmd;
}

void tankDrive(){
  smartMotorSet((MOTOR_DRIVE_LEFT_FRONT),(joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1)));
  smartMotorSet((MOTOR_DRIVE_RIGHT_FRONT), (-joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1)));
  smartMotorSet((MOTOR_DRIVE_LEFT_REAR), (joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1)));
  smartMotorSet((MOTOR_DRIVE_RIGHT_REAR), (-joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1)));
}
/*void smartMotorSet(int port, int speed){
  for(speed = 0; speed <= 120; speed + 15){
    int slew[] = {15, 30, 45, 60, 75, 90, 105, 120};

  }
}
*/
