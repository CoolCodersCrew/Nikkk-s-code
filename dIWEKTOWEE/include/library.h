#include "main.h"

#define min(a,b) (((a) > (b)) ? (a) : (b))
//Drive Motors- motors for driving and such
#define MOTOR_DRIVE_LEFT_FRONT 2
#define MOTOR_DRIVE_RIGHT_FRONT  3
#define MOTOR_DRIVE_LEFT_REAR 4
#define MOTOR_DRIVE_RIGHT_REAR 5
//Arm Motors- Motors for lifting and such

//Claw Motors- Intense grasping

//Digital Sensors- sensors for sensing and such
#define IME_LEFT_FRONT 2
#define IME_RIGHT_FRONT 3
#define IME_LEFT_REAR 4
#define IME_RIGHT_REAR 5
#define IME_NUMBER 4


//Digital Sensor Values

//Function Declaration
void tankDrive();
void smartMotorSet();
void slewControlTask(void * parameter);
void corrections();
