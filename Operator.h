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

ostream&operator<<(ostream &os,Student &stu);       //重载Student类的输出流
istream&operator>>(istream &is,Student &stu);       //重载Student类的输入流
ostream&operator<<(ostream &os,Course &cour);       //重载Course类的输出流
istream&operator>>(istream &is,Course &cour);       //重载Course类的输入流
ostream&operator<<(ostream &os,StudentData &stu);   //重载StudentData结构体的输出流
ostream&operator<<(ostream &os,CourseData &cour);   //重载CourseData结构体的输出流

#endif //SYSTEMDESIGN_OPERATOR_H
