#include "Robot.h"

void Robot::fileCheckInt(std::string val, int& org) {
    try { org=std::stoi(val); } //if value can be an int return it
    catch (std::exception& e) { org=org; }  //else return the passed default value
}