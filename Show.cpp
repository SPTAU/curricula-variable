//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <iomanip>
#include "Show.h"
using namespace std;

void ShowMainMenu()										//主菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "				欢迎进入		学生选修课程系统		" << endl;
	cout << "\t\t\t\t" << "	*********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1.  学生身份登录				" << endl;
	cout << "\t\t\t\t" << "					2.  管理员身份登录			" << endl;
	cout << "\t\t\t\t" << "					3.  保存数据					" << endl;
	cout << "\t\t\t\t" << "					4.  加载数据					" << endl;
	cout << "\t\t\t\t" << "					5.  退出						" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	*********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowStudentLogInID()								//学生身份登录学号验证
{
	cout << "请输入您的学号 (输入-1退出)： ";
}
void ShowStudentLogInName()								//学生身份登录姓名验证
{
	cout << "请输入您的姓名 (输入-1退出)： ";
}
void ShowManagementLogIn()								//管理员身份登录密码验证
{
	cout << "请输入密码 (输入-1退出)： ";
}
void ShowStudentMenu()									//学生操作菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					学生操作菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. 选课						" << endl;
	cout << "\t\t\t\t" << "					2. 退课						" << endl;
	cout << "\t\t\t\t" << "					3. 个人信息					" << endl;
	cout << "\t\t\t\t" << "					4. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowStudentAddCourseMenu()							//选课菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					学生选课菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "				1. 显示全部课程					" << endl;
	cout << "\t\t\t\t" << "				2. 按课程代码查询选修课			" << endl;
	cout << "\t\t\t\t" << "				3. 按课程名称查询选修课			" << endl;
	cout << "\t\t\t\t" << "				4. 返回上一层					" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\t\t\t\t" << "\n 请输入操作对应序号： ";
}
void ShowManagementMenu()								//管理员操作菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					管理操作菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					请选择管理对象				" << endl;
	cout << "\t\t\t\t" << "					1. 学生						" << endl;
	cout << "\t\t\t\t" << "					2. 课程						" << endl;
	cout << "\t\t\t\t" << "					3. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowManagementStudentMenu()						//管理学生菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					管理学生菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. 添加学生					" << endl;
	cout << "\t\t\t\t" << "					2. 删除学生					" << endl;
	cout << "\t\t\t\t" << "					3. 编辑学生					" << endl;
	cout << "\t\t\t\t" << "					4. 查询学生					" << endl;
	cout << "\t\t\t\t" << "					5. 显示学生					" << endl;
	cout << "\t\t\t\t" << "					6. 统计学生					" << endl;
	cout << "\t\t\t\t" << "					7. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowFindStudentMenu()								//查询学生操作菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					查询操作菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					请选择查询模式				" << endl;
	cout << "\t\t\t\t" << "					1. 学生学号					" << endl;
	cout << "\t\t\t\t" << "					2. 学生姓名					" << endl;
	cout << "\t\t\t\t" << "					3. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowManagementCourseMenu()							//管理课程菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					管理课程菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. 添加课程					" << endl;
	cout << "\t\t\t\t" << "					2. 删除课程					" << endl;
	cout << "\t\t\t\t" << "					3. 编辑课程					" << endl;
	cout << "\t\t\t\t" << "					4. 查询课程					" << endl;
	cout << "\t\t\t\t" << "					5. 显示课程					" << endl;
	cout << "\t\t\t\t" << "					6. 统计课程					" << endl;
	cout << "\t\t\t\t" << "					7. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowFindCourseMenu()								//查询课程操作菜单
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					查询操作菜单					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					请选择查询模式				" << endl;
	cout << "\t\t\t\t" << "					1. 课程代码					" << endl;
	cout << "\t\t\t\t" << "					2. 课程名称					" << endl;
	cout << "\t\t\t\t" << "					3. 返回上一层				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n 请输入操作对应序号： ";
}
void ShowCourseDataHeader()								//课程列表表头
{
	cout << "\t" << setw(10) << "课程代码" << "\t" << setw(20) << "课程名称" << "\t" << setw(4) << "学时";
	cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期";
	cout << "\t" << setw(8) << "人数上限"<< "\\" << setw(8) << "选修人数"  << endl;
}
void ShowStudentDataHeader()							//学生列表表头
{
	cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(4) << "性别";
	cout << "\t" << setw(4) << "年龄" << "\t" << setw(20) << "系别";
	cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
}
void ShowCourseStudentHeader()							//选修课程学生列表表头
{
	cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(20) << "系别";
	cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
}
void ShowStudentCourseHeader()							//学生选修课程列表表头
{
	cout << "\t" << setw(10) << "课程代码" << "\t" << setw(20) << "课程名称" << "\t" << setw(4) << "学时";
	cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期" << endl;
}
void ShowStudentDataPrompt()							//显示学生个人信息提示
{
	cout << "\n" << endl;
	cout << "\t" << "个人信息：" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowCourseDataPrompt()								//显示选课课程信息提示
{
	cout << "\n" << endl;
	cout << "\t" << "已选课程：" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowFoundPrompt()									//查询成功提示
{
	cout << "\n" << endl;
	cout << "\t" << "查询成功！" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowNotFoundPrompt()								//查询失败提示
{
	cout << "\n" << endl;
	cout << "\t" << "记录为空！" << endl;
}
void ShowEditCoursePrompt()								//显示编辑课程提示
{
	cout << "请依次输入课程代码、课程名称、学时、学分、开课学期、选修人数上限，输入-1结束" << endl;
}
void ShowEditStudentPrompt()							//显示编辑学生提示
{
	cout << "请依次输入学号、姓名、性别、年龄、系别、班级、联系方式，输入-1结束" << endl;
}
void ShowFindCourseIDPrompt()							//利用课程代码查询提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要查询课程的课程代码(输入-1取消操作)： " ;
}
void ShowFindCourseNamePrompt()							//利用课程名称查询提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要查询课程的课程名称(输入-1取消操作)： " ;
}
void ShowFindStudentIDPrompt()							//利用学生学号查询提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要查询学生的学号(输入-1取消操作)： " ;
}
void ShowFindStudentNamePrompt()						//利用学生姓名查询提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要查询学生的姓名(输入-1取消操作)： " ;
}
void ShowFindCourseAgainPrompt()						//是否继续查询课程提示
{
	cout << "\n" << endl;
	cout << "\t" << "是否想继续查询课程？ <Y/N>： " ;
}
void ShowFindStudentAgainPrompt()						//是否继续查询学生提示
{
	cout << "\n" << endl;
	cout << "\t" << "是否想继续查询学生？ <Y/N>： " ;
}
void ShowAddCoursePrompt()								//利用课程代码添加课程提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要选修课程的课程代码(输入-1取消操作)： " ;
}
void ShowAddCourseAgainPrompt()							//是否继续添加课程提示
{
	cout << "\n" << endl;
	cout << "\t" << "是否想继续选修课程？ <Y/N>： " ;
}
void ShowDeleteCoursePrompt()							//利用课程代码删除课程提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要退选课程的课程代码(输入-1取消操作)： " ;
}
void ShowDeleteCourseAgainPrompt()						//是否继续删除课程提示
{
	cout << "\n" << endl;
	cout << "\t" << "是否想继续退选课程？ <Y/N>： " ;
}
void ShowPrintCourseStudentPrompt()						//利用学生学号显示个人信息提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要显示选修学生信息的课程的课程代码(输入-1取消操作)： " ;
}
void ShowPrintStudentCoursePrompt()						//利用课程代码显示课程信息提示
{
	cout << "\n" << endl;
	cout << "\t" << "请输入想要显示选课信息的学生的学号(输入-1取消操作)： " ;
}
void ShowTotalCoursePrompt()							//显示课程总数提示
{
	cout << "\n" << endl;
	cout << "\t" << "选修课程总数：" ;
}
void ShowTotalStudentPrompt()							//显示学生总数提示
{
	cout << "\n" << endl;
	cout << "\t" << "学生总数：" ;
}
void ShowExitPrompt()									//退出程序保存数据提示
{
	cout << "\n" << endl;
	cout << "\t" << "退出时未保存的数据将会丢失,是否退出？ <Y/N>： " ;
}
