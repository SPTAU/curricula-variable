//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_OPERATOR_H
#define SYSTEMDESIGN_OPERATOR_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CourseData_Struct.h"
#include "StudentData_Struct.h"
#include "Course.h"
#include "Student.h"
using namespace std;

ostream&operator<<(ostream &os,Student &stu);
istream&operator>>(istream &is,Student &stu);
ostream&operator<<(ostream &os,Course &cour);
istream&operator>>(istream &is,Course &cour);
ostream&operator<<(ostream &os,StudentData &stu);
ostream&operator<<(ostream &os,CourseData &cour);

#endif //SYSTEMDESIGN_OPERATOR_H
