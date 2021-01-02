//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_COURSE_H
#define SYSTEMDESIGN_COURSE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
using namespace std;

class Student;

class Course
{
public:
    Course();
    Course(string &id,string &name,string &period,
           string &credit,string &semester,int &maximum);
    Course(Course& cour);
    ~Course();
private:
    string _id;                 //课程代码
    string _name;               //课程名称
    string _period;             //学时
    string _credit;             //学分
    string _semester;           //开课学期
    int _maximum;               //选修人数上限
    int _studentAmount;         //选修学生数目
public:
    vector<StudentData> studentDV;              //StudentData的Vector容器
    map<string,int> studentDM;                  //StudentData的Map容器
    map<string,int>::iterator studentDMI;       //StudentData的Map容器的迭代器
    void SetID(string &id);                     //设置课程代码
    void SetName(string &name);                 //设置课程名称
    void SetPeriod(string &period);             //设置总学时
    void SetCredit(string &credit);             //设置学分
    void SetSemester(string &semester);         //设置开课学期
    void SetMaximum(int maximum);               //设置选修人数上限
    string &GetID();            //获取课程代码
    string &GetName();          //获取课程名称
    string &GetPeriod();        //获取总学时
    string &GetCredit();        //获取学分
    string &GetSemester();      //获取开课学期
    int& GetMaximum();          //获取选修人数上限
    int& GetStudentAmount();    //获取选修学生数目
    void Add(Student &stu);                     //添加选课学生
    void Delete(string &studentID);             //删除选课学生
    void DisplayCourse();                       //显示选课信息
    void DisplayStudent();                      //显示选课学生信息
    void Sort();                                //对选课学生进行排序
    static bool comp(StudentData &cour1, StudentData &cour2);               //自定义比较标准
    Course &operator= (const Course &cour);                                 //重载赋值运算符
    friend ostream&operator<<(ostream &os, Course &stu);                    //重载Course输出流
    friend istream&operator>>(istream &is, Course &stu);                    //重载Course输入流
};


#endif //SYSTEMDESIGN_COURSE_H
