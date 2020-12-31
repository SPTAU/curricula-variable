//
// Created by MR on 2020/12/31.
//

#ifndef SYSTEMDESIGN_COURSEMANAGEMENT_H
#define SYSTEMDESIGN_COURSEMANAGEMENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
#include "CourseData_Struct.h"
using namespace std;

class Student;
class Course;

class CourseManagement
{
    Course *pc;
    vector<Course> courseV;
    vector<Course>::iterator courseVI;
    map<string,int> courseM;
    map<string,int>::iterator courseMI;
public:
    CourseManagement();
    ~CourseManagement();
private:
    int _studentTotal;
public:
    void Add();
    void Delete();
    void Edit();
    void Find();
    void Total();
    void Print();
    void Save();
    void Load();
    void Sort();
    static bool comp(Course &cour1, Course &cour2);//自定义比较标准
};


#endif //SYSTEMDESIGN_COURSEMANAGEMENT_H
