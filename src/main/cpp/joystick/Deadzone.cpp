#include "Robot.h"

//disregards values witin a certain range
//if above a certain range, scale it up so 100% is still 100%

//double Robot::Deadzone(double v, double r) { return (r<v?0:r-v+(r*(r-v))); }

double Robot::Deadzone(double v, double r) {
	double temp = 0.0;
	if (v <= r && v >= -r) {
			return 0.0;
	}
	else {
		if (v > r) {
			temp = v - r - ((v / 100) * r);
		}
		else if (v < r) {
			temp = v + r + ((v / 100) * r);
		}
	}
	return temp;
}

/*
double Robot::Deadzone(double v, double r) {
    if (v<0)
        return (v>r?0:-r+v-(r*(r+v)));
    else
        return (v<r?0:r-v+(r*(r-v)));
}
*/