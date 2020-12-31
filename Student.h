//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_STUDENT_H
#define SYSTEMDESIGN_STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "CourseData_Struct.h"
using namespace std;

class Course;

class Student
{
    vector<CourseData> courseDV;
    vector<CourseData>::iterator courseDVI;
    map<string,int> courseDM;
    map<string,int>::iterator courseDMI;
public:
    Student();
    Student(string &id,string &name,string &gender,string &age,
            string &department,string &classes,string &phoneNumber);
    ~Student();
private:
    string _id;                 //学号
    string _name;               //姓名
    string _gender;             //性别
    string _age;                //年龄
    string _department;         //系别
    string _class;              //班级
    string _phoneNumber;        //联系方式
    int _courseAmount;          //选择课程数目
public:
    void SetID(string &id);                         //设置学号
    void SetName(string &name);                     //设置姓名
    void SetGender(string &gender);                 //设置性别
    void SetAge(string &age);                       //设置年龄
    void SetDepartment(string &department);         //设置系别
    void SetClass(string &classes);                 //设置班级
    void SetPhoneNumber(string &phoneNumber);       //设置联系方式
    string &GetID();            //获取学号
    string &GetName();          //获取姓名
    string &GetGender();        //获取性别
    string &GetAge();           //获取年龄
    string &GetDepartment();    //获取系别
    string &GetClass();         //获取班级
    string &GetPhoneNumber();   //获取联系方式
    int &GetCourseAmount();     //获取选课数目
    string &GetCourseID(int &index);                //获取课程代码
    void Add(Course &cour);                         //添加课程
    void Delete(string &courseID,bool mode);        //删除课程
    void DisplayStudent();                          //显示学生信息
    void DisplayCourse();                           //显示选课信息
    void Sort();                                    //对所选课程进行排序
    static bool comp(CourseData &cour1, CourseData &cour2);                 //自定义比较标准
    friend ostream&operator<<(ostream &os, Student &stu);                   //重载Student输出流
    friend istream&operator>>(istream &is, Student &stu);                   //重载Student输入流
    friend ostream&operator<<(ostream &os, vector<CourseData>& _vec);       //重载vector<CourseData>输出流
    friend istream&operator>>(ostream &is, vector<CourseData>& _vec);       //重载vector<CourseData>输入流
};

#endif //SYSTEMDESIGN_STUDENT_H
