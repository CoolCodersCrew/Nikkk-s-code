//Drive Motors- motors for driving and such
#define MOTOR_DRIVE_LEFT_FRONT 2
#define MOTOR_DRIVE_RIGHT_FRONT  3
#define MOTOR_DRIVE_LEFT_REAR 4
#define MOTOR_DRIVE_RIGHT_REAR 5
//Arm Motors- Motors for lifting and such

//Claw Motors- Intense grasping

//Digital Sensors- sensors for sensing and such
#define SENSOR_QUAD_LEFT_FRONT 2
#define SENSOR_QUAD_RIGHT_FRONT 3
#define SENSOR_QUAD_LEFT_REAR 4
#define SENSOR_QUAD_RIGHT_REAR 5
//Analog Sensor Values

void tankDrive();
void smartMotorSet();
void slewControlTask(void * parameter);
