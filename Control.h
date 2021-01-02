//
// Created by SPTAU on 2021/1/1.
//

#ifndef SYSTEMDESIGN_CONTROL_H
#define SYSTEMDESIGN_CONTROL_H

#include <iostream>
using namespace std;

class Control : public Management
{
public:
	Control() = default;
	~Control() = default;
public:
	void Menu();					//进入主菜单
	void StudentLogIn();			//学生身份登录
	void StudentMenu();				//进入学生操作菜单
	void StudentAddCourseMenu();	//进入学生选课菜单
	bool StudentAddingCourse();		//学生选课操作
	void StudentDeletingCourse();	//学生退选操作
	void StudentPrintData();		//显示学生个人信息
	void ManagementLogIn();			//管理员身份登录
	void ManagementMenu();			//进入管理员操作菜单
	void ManagementStudentMenu();	//进入管理学生操作菜单
	void FindStudentMenu();			//进入查询学生操作菜单
	void FindStudentID();			//利用学生学号查询
	void FindStudentName();			//利用学生姓名查询
	void PrintStudentAll();			//显示所有学生信息
	bool PrintStudentCourse();		//显示学生选修课程信息
	void ManagementCourseMenu();	//进入管理课程操作菜单
	void FindCourseMenu();			//进入查询课程操作菜单
	void FindCourseID();			//利用课程代码查询提示
	void FindCourseName();			//利用课程名称查询提示
	void PrintCourseAll();			//显示所有课程信息
	bool PrintCourseStudent();		//显示课程选修学生信息
	void Save();					//保存数据
	void Load();					//加载数据
	bool static Exit();				//退出菜单
};


#endif //SYSTEMDESIGN_CONTROL_H
