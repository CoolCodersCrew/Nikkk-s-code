#include "main.h"
//Global Variables
int slewTmp;
int slewTarget[10];
////

////Slew Rate////
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
////////
void tankDrive(){
  smartMotorSet((MOTOR_DRIVE_LEFT_FRONT),(joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7));
  smartMotorSet((MOTOR_DRIVE_RIGHT_FRONT), (-joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7));
  smartMotorSet((MOTOR_DRIVE_LEFT_REAR), (joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7));
  smartMotorSet((MOTOR_DRIVE_RIGHT_REAR), (-joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1)- 7));
}
///////
void corrections(){
  int leftFrontCounts;
  int rightFrontCounts;
  int leftRearCounts;
  int rightRearCounts;
  imeGetVelocity(IME_LEFT_FRONT, &leftFrontCounts);
  imeGetVelocity(IME_RIGHT_FRONT, &rightFrontCounts);
  imeGetVelocity(IME_LEFT_REAR, &leftRearCounts);
  imeGetVelocity(IME_RIGHT_REAR, &rightRearCounts);
  int leftFrontCountsDesired = joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7;
  int rightFrontCountsDesired = -joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7;
  int leftRearCountsDesired = joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7;
  int rightRearCountsDesired = -joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1) - 7;
  while(1==1){
    if(leftFrontCounts < leftFrontCountsDesired){
      smartMotorSet((MOTOR_DRIVE_LEFT_FRONT), motorGet(MOTOR_DRIVE_LEFT_FRONT) + 1);
    }
    if(leftFrontCounts > leftFrontCountsDesired){
      smartMotorSet((MOTOR_DRIVE_LEFT_FRONT), motorGet(MOTOR_DRIVE_LEFT_FRONT) - 1);
    }
    if(rightFrontCounts < rightFrontCountsDesired){
      smartMotorSet((MOTOR_DRIVE_RIGHT_FRONT), motorGet(MOTOR_DRIVE_RIGHT_FRONT) + 1);
    }
    if(rightFrontCounts > rightFrontCountsDesired){
      smartMotorSet((MOTOR_DRIVE_RIGHT_FRONT), motorGet(MOTOR_DRIVE_RIGHT_FRONT) - 1);
    }
    if(leftRearCounts < leftRearCountsDesired){
      smartMotorSet(MOTOR_DRIVE_LEFT_REAR, motorGet(MOTOR_DRIVE_LEFT_REAR) + 1);
    }
    if(leftRearCounts > leftFrontCountsDesired){
      smartMotorSet(MOTOR_DRIVE_LEFT_REAR, motorGet(MOTOR_DRIVE_LEFT_REAR) - 1);
    }
    if(rightRearCounts < rightRearCountsDesired){
      smartMotorSet(MOTOR_DRIVE_RIGHT_REAR, motorGet(MOTOR_DRIVE_RIGHT_REAR) + 1);
    }
    if(rightRearCounts > rightRearCountsDesired){
      smartMotorSet(MOTOR_DRIVE_RIGHT_REAR, motorGet(MOTOR_DRIVE_RIGHT_REAR) - 1);
    }
  }
}

/*void smartMotorSet(int port, int speed){
  for(speed = 0; speed <= 120; speed + 15){
    int slew[] = {15, 30, 45, 60, 75, 90, 105, 120};

  }
}
*/
