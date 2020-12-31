//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_STUDENTDATA_STRUCT_H
#define SYSTEMDESIGN_STUDENTDATA_STRUCT_H

#include <string>
using namespace std;

class Student;

struct StudentData
{
    Student *ps;                            //student指针
    string _studentID;                      //学号
    string _studentName;                    //姓名
    string _studentDepartment;              //系别
    string _studentClass;                   //班级
    string _studentPhoneNumber;             //联系方式
    friend ostream&operator<<(ostream &os,StudentData &stu);
    friend istream&operator>>(istream &is,StudentData &stu);
    ~StudentData()
    {
        delete ps;
    }
};

#endif //SYSTEMDESIGN_STUDENTDATA_STRUCT_H
