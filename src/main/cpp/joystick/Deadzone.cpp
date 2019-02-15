#include "Robot.h"

#include <stdlib.h>
#include <math.h>

//disregards values witin a certain range
//if above a certain range, scale it up so 100% is still 100%
double Robot::Deadzone(double v, double r) {
	double old=v;
	v=abs(v);
	return copysign(v<r?0:(v-r)/(1-r), old);
}
double Robot::Deadzone(double v) {
	double old=v;
	v=abs(v);
	return copysign(v<controller_deadzone?0:(v-controller_deadzone)/(1-controller_deadzone), old);
}