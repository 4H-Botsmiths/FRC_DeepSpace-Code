#include "Robot.h"

#include <iostream>

void Robot::fileCheckDouble(std::string val, double& org) {
    try { org=std::stod(val); } //if value can be double return it
    catch (std::exception& e) { org=org; }  //else return the passed default value
}