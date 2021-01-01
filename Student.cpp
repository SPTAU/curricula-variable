//
// Created by SPTAU on 2020/12/30.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "CourseData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
using namespace std;

Student::Student()
{
    _id = "-1";
    _name = "-1";
    _gender = "-1";
    _age = "-1";
    _department = "-1";
    _class = "-1";
    _phoneNumber = "-1";
    _courseAmount = 0;
}
Student::Student(string &id, string &name, string &gender, string &age, string &department, string &classes,
                 string &phoneNumber, int courseAmount):_courseAmount(courseAmount)
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
        Delete(courseDV[i]._courseID, false);
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
void Student::SetCourseAmount(int &courseAmount)    //设置选课数目
{
    _courseAmount = courseAmount;
}
string& Student::GetID()                            //获取学号
{
    return _id;
}
string& Student::GetName()                          //获取姓名
{
    return _name;
}
string& Student::GetGender()                        //获取性别
{
    return _gender;
}
string& Student::GetAge()                           //获取年龄
{
    return _age;
}
string& Student::GetDepartment()                    //获取系别
{
    return _department;
}
string& Student::GetClass()                         //获取班级
{
    return _class;
}
string& Student::GetPhoneNumber()                   //获取联系方式
{
    return _phoneNumber;
}
int& Student::GetCourseAmount()                     //获取选课数目
{
    return _courseAmount;
}
string& Student::GetCourseID(int &index)            //获取课程代码
{
    return courseDV[index]._courseID;
}
void Student::Add(Course &cour, bool mode)                  //添加课程
{
    if (mode)                                               //模式一：学生主动选课
    {
        if(cour.GetStudentAmount() < cour.GetMaximum())     //判断所选课程是否满人
        {
            struct CourseData tmp = {&cour, cour.GetID(), cour.GetName(),
                                     cour.GetPeriod(), cour.GetCredit(), cour.GetSemester()};
            courseDMI = courseDM.find(cour.GetID());
            if (courseDMI == courseDM.end())                //判断是否已选该课
            {
                courseDV.push_back(tmp);                    //在vector最后添加元素
                courseDM.insert(make_pair(cour.GetID(), courseDV.size() - 1));      //在map最后插入元素
                Sort();                                     //容器排序
                _courseAmount = courseDV.size();            //更新选课数目
                cour.Add(*this);                        //回调Course类成员函数添加学生信息
                cout << "选课成功！" << endl;
            }
            else
            {
                cout << "已选该课！" << endl;
            }
        }
        else
        {
            cout << "人数已满！" << endl;
        }
    }
    else                                            //模式二：从文件中读取信息添加选课
    {
        struct CourseData tmp = {&cour, cour.GetID(), cour.GetName(),
                                 cour.GetPeriod(), cour.GetCredit(), cour.GetSemester()};
        courseDV.push_back(tmp);                    //在vector最后添加元素
        courseDM.insert(make_pair(cour.GetID(), courseDV.size() - 1));      //在map最后插入元素
        Sort();                                     //容器排序
        _courseAmount = courseDV.size();            //更新选课数目
        cour.Add(*this);                        //回调Course类成员函数添加学生信息
    }
}
void Student::Delete(string &courseID,bool mode)    //删除课程
{
    courseDMI = courseDM.find(courseID);
    if (mode)                                       //模式一：学生主动退选
    {
        if (courseDMI != courseDM.end())            //判断是否已选该课
        {
            courseDV[courseDM[courseID]].pc->Delete(this->_id, false);      //回调Course类成员函数删除学生信息
            delete courseDV[courseDM[courseID]].pc;
            courseDV.erase(courseDV.begin() + courseDM[courseID]);          //删除vector中元素
            courseDM.erase(courseDMI);                                      //删除map中元素
            Sort();                                                                 //容器排序
            _courseAmount = courseDV.size();                                        //更新选课数目
            cout << "退选成功！" << endl;
        }
        else
        {
            cout << "未选该课！" << endl;
        }
    }
    else                                            //模式二：被动退选，如删除学生、删除课程
    {
        delete courseDV[courseDM[courseID]].pc;
        courseDV.erase(courseDV.begin() + courseDM[courseID]);              //删除vector中元素
        courseDM.erase(courseDMI);                                          //删除map中元素
        Sort();                                                                     //容器排序
        _courseAmount = courseDV.size();                                            //更新选课数目
    }
}
void Student::DisplayStudent()                      //显示学生信息
{
    system("cls");
    cout << *this << endl;
    system("pause");
}
void Student::DisplayCourse()                       //显示选课信息
{
    system("cls");
    for (int i=0;i<_courseAmount;i++)
    {
        cout << courseDV[i] << endl;
    }
    system("pause");
}
void Student::Sort()                                //对所选课程进行排序
{
    courseDM.clear();                                                   //清空map容器
    sort(courseDV.begin(), courseDV.end(), comp);               //对vector容器内元素排序
    for(int i=0;i<_courseAmount;i++)
    {
        courseDM.insert(make_pair(courseDV[i]._courseID, i));       //依次插入map元素
    }
}
bool Student::comp(CourseData &cour1,CourseData &cour2)                 //自定义比较标准
{
    return cour1._courseID < cour2._courseID;
}
