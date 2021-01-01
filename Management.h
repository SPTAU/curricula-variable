//
// Created by SPTAU on 2021/1/1.
//

#ifndef SYSTEMDESIGN_MANAGEMENT_H
#define SYSTEMDESIGN_MANAGEMENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
#include "CourseData_Struct.h"
#include "Student.h"
#include "Course.h"

using namespace std;

class Management
{
public:
    Management();
    ~Management();
private:
    int _studentTotal;
    int _courseTotal;
protected:
    vector<Student> studentV;
    vector<Student>::iterator studentVI;
    map<string,int> studentM;
    map<string,int>::iterator studentMI;
    vector<Course> courseV;
    map<string,int> courseM;
    map<string,int>::iterator courseMI;
public:
    void AddStudent();
    void DeleteStudent();
    void EditStudent();
    int FindStudent(string &studentData, int mode);
    int &TotalStudent();
    void PrintStudent();
    void SaveStudent();
    void LoadStudent();
    void SortStudent();
    static bool CompStudent(Student &stu1, Student &stu2);//自定义比较标准
    void StudentAddCourse(string &courseID);
    void StudentDeleteCourse(string &courseID);
    void AddCourse();
    void DeleteCourse();
    void EditCourse();
    int FindCourse(string &studentData, int mode);
    int &TotalCourse();
    void PrintCourse();
    void SaveCourse();
    void LoadCourse();
    void SortCourse();
    static bool CompCourse(Course &cour1, Course &cour2);//自定义比较标准
};


#endif //SYSTEMDESIGN_MANAGEMENT_H
