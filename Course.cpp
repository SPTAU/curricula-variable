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

Course::Course()
{
	_id = "-1";
	_name = "-1";
	_period = "-1";
	_credit = "-1";
	_semester = "-1";
	_maximum = 0;
	_studentAmount = 0;
}
Course::Course(string &id,string &name,string &period,
	string &credit,string &semester,int &maximum)
{
	_id.assign(id);
	_name.assign(name);
	_period.assign(period);
	_credit.assign(credit);
	_semester.assign(semester);
	_maximum = maximum;
	_studentAmount = 0;
}
Course::~Course()
{
	for (int i=0;i<_studentAmount;i++)
	{
		Delete(studentDV[i]._studentID);
	}
	studentDV.clear();
	studentDM.clear();
}

void Course::SetID(string &id)					//设置课程代码
{
	_id.assign(id);
}
void Course::SetName(string &name)				//设置课程名称
{
	_name.assign(name);
}
void Course::SetPeriod(string &period)			//设置总学时
{
	_period.assign(period);
}
void Course::SetCredit(string &credit)			//设置学分
{
	_credit.assign(credit);
}
void Course::SetSemester(string &semester)		//设置开课学期
{
	_semester.assign(semester);
}
void Course::SetMaximum(int maximum)			//设置选修人数上限
{
	_maximum = maximum;
}
string& Course::GetID()							//获取课程代码
{
	return _id;
}
string& Course::GetName()						//获取课程名称
{
	return _name;
}
string& Course::GetPeriod()						//获取总学时
{
	return _period;
}
string& Course::GetCredit()						//获取学分
{
	return _credit;
}
string& Course::GetSemester()					//获取开课学期
{
	return _semester;
}
int& Course::GetMaximum()						//获取选修人数上限
{
	return _maximum;
}
int& Course::GetStudentAmount()					//获取选修学生数目
{
	return _studentAmount;
}
void Course::Add(Student &stu)					//添加选课学生
{
	struct StudentData tmp = {stu.GetID(), stu.GetName(),stu.GetDepartment(), stu.GetClass(), stu.GetPhoneNumber()};
	studentDV.push_back(tmp);										//在vector最后添加元素
	studentDM.insert(make_pair(stu.GetID(), studentDV.size() - 1));	//在map最后插入元素
	_studentAmount = studentDV.size();								//更新学生数目
	Sort();															//容器排序
}
void Course::Delete(string &studentID)			//删除选课学生
{
	studentDV.erase(studentDV.begin() + studentDM[studentID]);	//删除vector中元素
	studentDMI = studentDM.find(studentID);
	studentDM.erase(studentDMI);								//删除map中元素
	_studentAmount = studentDV.size();							//更新选课数目
	Sort();														//容器排序
}
void Course::DisplayCourse()					//显示选课信息
{
	cout << *this << endl;
}
void Course::DisplayStudent()					//显示选课学生信息
{
    for(studentDVI = studentDV.begin();studentDVI != studentDV.end();++studentDVI)
    {
        cout << *studentDVI << endl;
    }
}
void Course::Sort()								//对选课学生进行排序
{
    if (studentDV.size() > 1)
    {
        studentDM.clear();
        sort(studentDV.begin(), studentDV.end(), comp);
        for(int i=0;i<_studentAmount;i++)
        {
            studentDM.insert(make_pair(studentDV[i]._studentID, i));
        }
    }
}
bool Course::comp(StudentData &stu1,StudentData &stu2)		//自定义比较标准
{
    stringstream stream;
    stream << stu1._studentID;
    int studentID1;
    stream >> studentID1;
    stream << stu2._studentID;
    int studentID2;
    stream >> studentID2;
	bool index = (studentID1 < studentID2);
	return index;
}
Course& Course::operator= (const Course& cour)				//重载赋值运算符
{
	_id.assign(cour._id);
	_name.assign(cour._name);
	_period.assign(cour._period);
	_credit.assign(cour._credit);
	_semester.assign(cour._semester);
	_maximum = cour._maximum;
    return *this;
}
