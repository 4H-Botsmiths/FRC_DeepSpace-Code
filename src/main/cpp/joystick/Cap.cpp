#include "Robot.h"

double Robot::Cap(double v, double r) {
    if (v<=0)
        return (v < -r ? r : v);
    else
        return (v > r ? r : v);
}