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
	int _studentTotal;										//学生总数
	int _courseTotal;										//课程总数
protected:
	vector<Student> studentV;								//Student的Vector容器
	vector<Student>::iterator studentVI;					//Student的Vector容器的迭代器
	map<string,int> studentM;								//Student的Map容器
	map<string,int>::iterator studentMI;					//Student的Map容器的迭代器
	vector<Course> courseV;									//Student的Vector容器
	map<string,int> courseM;								//Student的Map容器
	map<string,int>::iterator courseMI;						//Student的Map容器的迭代器
public:
	void AddStudent();										//管理员添加学生
	void DeleteStudent();									//管理员删除学生
	void EditStudent();										//管理员编辑学生
	int FindStudent(string &studentData, int mode);			//管理员查询学生
	int &TotalStudent();									//获取学生总数
	void PrintStudent();									//显示所有学生信息
	void SaveStudent();										//保存学生数据
	void LoadStudent();										//加载学生数据
	void SortStudent();										//对学生容器内学生进行排序
	static bool CompStudent(Student &stu1, Student &stu2);	//自定义比较标准
	void StudentAddCourse(string &courseID);				//学生选修课程
	void StudentDeleteCourse(string &courseID);				//学生退选课程
	void AddCourse();										//管理员添加课程
	void DeleteCourse();									//管理员删除课程
	void EditCourse();										//管理员编辑课程
	int FindCourse(string &studentData, int mode);			//管理员查询课程
	int &TotalCourse();										//获取课程总数
	void PrintCourse();										//显示所有课程信息
	void SaveCourse();										//保存课程数据
	void LoadCourse();										//加载课程数据
	void SortCourse();										//对课程容器内课程进行排序
	static bool CompCourse(Course &cour1, Course &cour2);	//自定义比较标准
};


#endif //SYSTEMDESIGN_MANAGEMENT_H
