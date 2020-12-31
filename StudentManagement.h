//
// Created by MR on 2020/12/31.
//

#ifndef SYSTEMDESIGN_STUDENTMANAGEMENT_H
#define SYSTEMDESIGN_STUDENTMANAGEMENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
#include "CourseData_Struct.h"
using namespace std;

class Student;
class Course;

class StudentManagement
{
    vector<Student> studentV;
    vector<Student>::iterator studentVI;
    map<string,int> studentM;
    map<string,int>::iterator studentMI;
public:

private:

public:
    void Add();
    void Delete();
    void Edit();
    void Find();
    void Total();
    void Print();
    void save();
    void load();
};


#endif //SYSTEMDESIGN_STUDENTMANAGEMENT_H
