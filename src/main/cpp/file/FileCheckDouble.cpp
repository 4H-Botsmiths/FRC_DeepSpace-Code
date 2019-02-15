#include "Robot.h"

#include <iostream>

double Robot::fileCheckDouble(std::string val, double& org) {
    try { return std::stod(val); } //if value can be double return it
    catch (std::exception& e) { return org; }  //else return the passed default value
}