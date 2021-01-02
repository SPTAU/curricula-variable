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

ostream&operator<<(ostream &os,Student &stu);		//����Student��������
istream&operator>>(istream &is,Student &stu);		//����Student���������
ostream&operator<<(ostream &os,Course &cour);		//����Course��������
istream&operator>>(istream &is,Course &cour);		//����Course���������
ostream&operator<<(ostream &os,StudentData &stu);	//����StudentData�ṹ��������
ostream&operator<<(ostream &os,CourseData &cour);	//����CourseData�ṹ��������

#endif //SYSTEMDESIGN_OPERATOR_H
