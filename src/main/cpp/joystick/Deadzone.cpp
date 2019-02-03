#include "Robot.h"

//disregards values witin a certain range
//if above a certain range, scale it up so 100% is still 100%

//double Robot::Deadzone(double v, double r) { return (r<v?0:r-v+(r*(r-v))); }

double Robot::Deadzone(double v, double r) {
    if (v<0)
        return (v>r?0:-r+v-(r*(r+v)));
    else
        return (v<r?0:r-v+(r*(r-v)));
}