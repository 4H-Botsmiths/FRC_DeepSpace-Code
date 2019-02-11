#include "Robot.h"

void Robot::Move(double x, double y, double z) {
    drive_train.DriveCartesian(x, -y, z);
}