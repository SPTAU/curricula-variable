//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_COURSEDATA_STRUCT_H
#define SYSTEMDESIGN_COURSEDATA_STRUCT_H

#include <string>
using namespace std;

class Course;

struct CourseData
{
    Course *pc;                             //course指针
    string _courseID;                       //课程代码
    string _courseName;                     //课程名称
    string _coursePeriod;                   //总学时
    string _courseCredit;                   //学分
    string _courseSemester;                 //开课学期
    friend ostream&operator<<(ostream &os,CourseData &cour);
    friend istream&operator>>(istream &is,CourseData &cour);
};

#endif //SYSTEMDESIGN_COURSEDATA_STRUCT_H
