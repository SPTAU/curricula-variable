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
    Student stu;
    Student *ps;
    vector<Student> studentV;
    vector<Student>::iterator studentVI;
    map<string,int> studentM;
    map<string,int>::iterator studentMI;
public:
    StudentManagement();
    ~StudentManagement();
private:
    int _studentTotal;
public:
    void Add();
    void Delete();
    void Edit();
    int Find(string &studentData, int &mode);
    int Total();
    void Print();
    void Save();
    void Load();
    void Sort();
    static bool comp(Student &stu1, Student &stu2);//自定义比较标准
};


#endif //SYSTEMDESIGN_STUDENTMANAGEMENT_H
