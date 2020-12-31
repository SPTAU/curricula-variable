//
// Created by SPTAU on 2020/12/30.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CourseData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
using namespace std;

Student::Student()
{
    _id = "-";
    _name = "-";
    _gender = "-";
    _age = "-";
    _department = "-";
    _class = "-";
    _phoneNumber = "-";
}
Student::Student(string &id, string &name, string &gender, string &age, string &department, string &classes,
                 string &phoneNumber)
{
    _id.assign(id);
    _name.assign(name);
    _gender.assign(gender);
    _age.assign(age);
    _department.assign(department);
    _class.assign(classes);
    _phoneNumber.assign(phoneNumber);
}
Student::~Student()
{
    for (int i=0;i<_courseAmount;i++)
    {
        Delete(courseDV[i]._courseID, true);
    }
}

void Student::SetID(string &id)                     //设置学号
{
    _id.assign(id);
}
void Student::SetName(string &name)                 //设置姓名
{
    _name.assign(name);
}
void Student::SetGender(string &gender)             //设置性别
{
    _gender.assign(gender);
}
void Student::SetAge(string &age)                   //设置年龄
{
    _age.assign(age);
}
void Student::SetDepartment(string &department)     //设置系别
{
    _department.assign(department);
}
void Student::SetClass(string &classes)             //设置班级
{
    _class.assign(classes);
}
void Student::SetPhoneNumber(string &phoneNumber)   //设置联系方式
{
    _phoneNumber.assign(phoneNumber);
}
string Student::GetID()                             //获取学号
{
    return _id;
}
string Student::GetName()                           //获取姓名
{
    return _name;
}
string Student::GetGender()                         //获取性别
{
    return _gender;
}
string Student::GetAge()                            //获取年龄
{
    return _age;
}
string Student::GetDepartment()                     //获取系别
{
    return _department;
}
string Student::GetClass()                          //获取班级
{
    return _class;
}
string Student::GetPhoneNumber()                    //获取联系方式
{
    return _phoneNumber;
}
void Student::Add(Course &cour)                     //添加课程
{
    if(cour.GetStudentAmount() < cour.GetMaximum())
    {
        struct CourseData tmp = {&cour, cour.GetID(), cour.GetName(), cour.GetPeriod(), cour.GetCredit(), cour.GetSemester()};
        courseDV.push_back(tmp);                     //在vector最后添加元素
        courseDM.insert(make_pair(cour.GetID(), courseDV.size() - 1));    //在map最后插入元素
        Sort();                                     //容器排序
        _courseAmount = courseDV.size();             //更新选课数目
        cour.Add(*this);
        cout << cour << endl;
        cout << "选课成功！" << endl;
    }
    else
    {
        cout << "人数已满！" << endl;
    }
}
void Student::Delete(string &courseID,bool mode)    //删除课程
{
    if (mode)
    {
        courseDMI = courseDM.find(courseID);
        if (courseDMI != courseDM.end())
        {
            courseDV[courseDM[courseID]].pc->Delete(this->_id, false);
            courseDV.erase(courseDV.begin() + courseDM[courseID]);
            courseDM.erase(courseDMI);
            Sort();
            _courseAmount = courseDV.size();
            cout << courseDV[courseDM[courseID]] << endl;
            cout << "退选成功！" << endl;
        }
        else
        {
            cout << "未选该课！" << endl;
        }
    }
    else
    {
        courseDV.erase(courseDV.begin() + courseDM[courseID]);
        courseDM.erase(courseDMI);
        Sort();
        _courseAmount = courseDV.size();
    }
}
void Student::DisplayStudent()                      //显示学生信息
{
    //清屏
    cout << *this << endl;
}
void Student::DisplayCourse()                       //显示选课信息
{
    //清屏
    for (int i=0;i<_courseAmount;i++)
    {
        cout << courseDV[i] << endl;
    }
}
void Student::Sort()                                //对所选课程进行排序
{
    courseDM.clear();
    sort(courseDV.begin(), courseDV.end(), comp);
    for(int i=0;i<_courseAmount;i++)
    {
        courseDM.insert(make_pair(courseDV[i]._courseID, i));
    }
}
bool Student::comp(CourseData &cour1,CourseData &cour2)      //自定义比较标准
{
    return cour1._courseID<cour2._courseID;
}
