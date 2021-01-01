//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <iomanip>
#include "Show.h"
using namespace std;

void ShowMainMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "            欢迎进入学生选修课程系统             " << endl;
    cout << "\t\t\t\t" << "*********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 1.  学生身份登录              " << endl;
    cout << "\t\t\t\t" << "                 2.  管理员身份登录             " << endl;
    cout << "\t\t\t\t" << "                 3.  保存数据                " << endl;
    cout << "\t\t\t\t" << "                 4.  加载数据                " << endl;
    cout << "\t\t\t\t" << "                 5.  退出                  " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "*********************************************" << endl;
    cout << "\n 请输入操作对应序号： ";
}
void ShowStudentLogInID()
{
    cout << "请输入您的学号 (输入-1退出)： ";
}
void ShowStudentLogInName()
{
    cout << "请输入您的姓名 (输入-1退出)： ";
}
void ShowManagementLogIn()
{
    cout << "请输入密码 (输入-1退出)： ";
}
void ShowStudentMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 学生操作菜单              " << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 1. 选课                   " << endl;
    cout << "\t\t\t\t" << "                 2. 退课                   " << endl;
    cout << "\t\t\t\t" << "                 3. 个人信息                 " << endl;
    cout << "\t\t\t\t" << "                 4. 返回上一层                " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n 请输入操作对应序号： ";
}
void ShowStudentAddCourseMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 学生选课菜单              " << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "             1. 显示全部课程               " << endl;
    cout << "\t\t\t\t" << "             2. 按课程代码查询选修课             " << endl;
    cout << "\t\t\t\t" << "             3. 按课程名称查询选修课             " << endl;
    cout << "\t\t\t\t" << "             4. 返回上一层                    " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\t\t\t\t" << "\n 请输入操作对应序号： ";
}
void ShowManagementMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 管理操作菜单              " << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 请选择管理对象               " << endl;
    cout << "\t\t\t\t" << "                 1. 学生                   " << endl;
    cout << "\t\t\t\t" << "                 2. 课程                   " << endl;
    cout << "\t\t\t\t" << "                 3. 返回上一层                " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n 请输入操作对应序号： ";
}
void ShowManagementStudentMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 管理学生菜单              " << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 1. 添加学生                   " << endl;
    cout << "\t\t\t\t" << "                 2. 删除学生                   " << endl;
    cout << "\t\t\t\t" << "                 3. 编辑学生                 " << endl;
    cout << "\t\t\t\t" << "                 4. 查询学生                 " << endl;
    cout << "\t\t\t\t" << "                 5. 显示学生                 " << endl;
    cout << "\t\t\t\t" << "                 6. 统计学生                 " << endl;
    cout << "\t\t\t\t" << "                 7. 返回上一层                " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n 请输入操作对应序号： ";
}
void ShowManagementCourseMenu()
{
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 管理课程菜单              " << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "                 1. 添加课程                   " << endl;
    cout << "\t\t\t\t" << "                 2. 删除课程                   " << endl;
    cout << "\t\t\t\t" << "                 3. 编辑课程                 " << endl;
    cout << "\t\t\t\t" << "                 4. 查询课程                 " << endl;
    cout << "\t\t\t\t" << "                 5. 显示课程                 " << endl;
    cout << "\t\t\t\t" << "                 6. 统计课程                 " << endl;
    cout << "\t\t\t\t" << "                 7. 返回上一层                " << endl;
    cout << "\n" << endl;
    cout << "\t\t\t\t" << "********************************************" << endl;
    cout << "\n 请输入操作对应序号： ";
}
void ShowCourseDataHeader()
{
    cout << "\t" << setw(10) << "课程代码" << "\t" << setw(12) << "课程名称" << "\t" << setw(4) << "学时";
    cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期";
    cout << "\t" << setw(8) << "人数上限"<< "\\" << setw(8) << "选修人数"  << endl;
}
void ShowStudentDataHeader()
{
    cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(4) << "性别";
    cout << "\t" << setw(4) << "年龄" << "\t" << setw(20) << "系别";
    cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
}
void ShowCourseStudentHeader()
{
    cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(20) << "系别";
    cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
}
void ShowStudentCourseHeader()
{
    cout << "\t" << setw(10) << "课程代码" << "\t" << setw(12) << "课程名称" << "\t" << setw(4) << "学时";
    cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期" << endl;
}
void ShowStudentDataPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "个人信息：" << endl;
    cout << "*******************************************************************************************************"
            "****************"  << endl;
}
void ShowStudentCourseDataPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "已选课程：" << endl;
    cout << "*******************************************************************************************************"
            "****************"  << endl;
}
void ShowFoundPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "查询成功！" << endl;
    cout << "*******************************************************************************************************"
            "****************"  << endl;
}
void ShowNotFoundPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "记录为空！" << endl;
}
void ShowFindCourseIDPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要查询课程的课程代码(输入-1取消操作)： " ;
}
void ShowFindCourseNamePrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要查询课程的课程名称(输入-1取消操作)： " ;
}
void ShowFindStudentIDPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要查询学生的学号(输入-1取消操作)： " ;
}
void ShowFindStudentNamePrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要查询学生的姓名(输入-1取消操作)： " ;
}
void ShowFindCourseAgainPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "是否想继续查询课程？ <Y/N>： " ;
}
void ShowFindStudentAgainPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "是否想继续查询学生？ <Y/N>： " ;
}
void ShowAddCoursePrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要选修课程的课程代码(输入-1取消操作)： " ;
}
void ShowAddCourseAgainPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "是否想继续选修课程？ <Y/N>： " ;
}
void ShowDeleteCoursePrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "请输入想要退选课程的课程代码(输入-1取消操作)： " ;
}
void ShowDeleteCourseAgainPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "是否想继续退选课程？ <Y/N>： " ;
}
void ShowTotalCoursePrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "选修课程总数：" ;
}
void ShowTotalStudentPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "学生总数：" ;
}
void ShowExitPrompt()
{
    cout << "\n" << endl;
    cout << "\t" << "退出时未保存的数据将会丢失,是否退出？ <Y/N>： " ;
}
