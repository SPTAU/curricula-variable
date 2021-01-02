//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CourseData_Struct.h"
#include "StudentData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Management.h"
#include "Show.h"
#include "Control.h"
using namespace std;



void Control::Menu()                            //进入主菜单
{
    bool opt = true;                            //循环的标志位
    while (opt == true)
    {
        system("cls");                  //清屏
        ShowMainMenu();                         //主菜单
        char index;
        cin >> index;                           //输入选择
        switch (index)                          //判断用户的选择
        {
            case '1':
                StudentLogIn();                 //学生身份登录
                break;
            case '2':
                ManagementLogIn();              //管理员身份登录
                break;
            case '3':
                Save();                         //保存数据
                break;
            case '4':
                Load();                         //加载数据
                break;
            case '5':
                opt = Exit();                   //退出菜单
                break;
            default:
                cout << "输入非法，请重新选择!" << endl;
                break;
        }
    }
}
void Control::StudentLogIn()                    //学生身份登录
{
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowStudentLogInID();                   //学生身份登录学号验证
        cin >> tmp;                             //输入学号
        if (tmp != "-1")                        //若输入不为"-1"
        {
            studentMI = studentM.find(tmp);     //验证输入学号
            if (studentMI != studentM.end())    //若输入学号正确
            {
                string tmpID = tmp;
                ShowStudentLogInName();         //学生身份登录姓名验证
                cin >> tmp;                     //输入姓名
                if (tmp != "-1")                //若输入不为"-1"
                {
                    if (studentV[studentM[tmpID]].GetName() == tmp)         //验证输入姓名
                    {
                        studentVI = studentV.begin() + studentM[tmpID];     //令迭代器指向用户学生
                        StudentMenu();          //进入学生操作菜单
                        opt = false;            //设置标志位为false，退出循环
                    }
                    else                        //若输入姓名错误
                    {
                        cout << "姓名与学号不匹配！" << endl;
                    }
                }
                else                            //若输入为"-1"
                {
                    cout << "已返回主目录!"<< endl;
                    system("pause");    //输入任意键继续
                    system("cls");      //清屏
                    opt = false;                //设置标志位为false，退出循环
                }
            }
            else                                //若输入学号错误
            {
                cout << "该学号不存在！" << endl;
            }
        }
        else                                    //若输入为"-1"
        {
            cout << "已返回主目录!" << endl;
            system("pause");            //输入任意键继续
            system("cls");              //清屏
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::StudentMenu()                     //进入学生操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowStudentMenu();                      //学生操作菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户的选择
        {
            case '1':
                StudentAddCourseMenu();         //进入学生选课菜单
                break;
            case '2':
                StudentDeletingCourse();        //学生退选操作
                break;
            case '3':
                StudentPrintData();             //显示学生个人信息
                break;
            case '4':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!";
                break;
        }
    }
}
void Control::StudentAddCourseMenu()            //进入学生选课菜单
{
    system("cls");                      //清屏
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowStudentAddCourseMenu();             //选课菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户的选择
        {
            case '1':
                opt = StudentAddingCourse();    //学生选课操作
                break;
            case '2':
                FindCourseID();                 //利用课程代码查询提示
                break;
            case '3':
                FindCourseName();               //利用课程名称查询提示
                break;
            default:
                cout << "非法输入，已返回上一层!";
                opt = false;
                break;
        }
    }
}
bool Control::StudentAddingCourse()             //学生选课操作
{
    system("cls");                      //清屏
    ShowCourseDataHeader();                     //课程列表表头
    PrintCourse();                              //显示所有课程信息
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowAddCoursePrompt();                  //利用课程代码添加课程提示
        cin >> tmp;                             //输入课程代码
        if (tmp != "-1")                        //若输入不为"-1"
        {
            StudentAddCourse(tmp);          //学生选修课程
            ShowAddCourseAgainPrompt();         //是否继续添加课程提示
            cin >> tmp;                         //接受输入
            if (tmp == "n" || tmp == "N")       //若输入为"n"或"N"
            {
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
    return false;                               //返回false，退出循环
}
void Control::StudentDeletingCourse()           //学生退选操作
{
    system("cls");                      //清屏
    ShowCourseDataPrompt();                     //显示选课课程信息提示
    ShowStudentCourseHeader();                  //学生选修课程列表表头
    studentVI->DisplayCourse();                 //显示选课信息
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowDeleteCoursePrompt();               //利用课程代码删除课程提示
        cin >> tmp;                             //输入课程代码
        if (tmp != "-1")                        //若输入不为"-1"
        {
            StudentDeleteCourse(tmp);       //学生退选课程
            ShowDeleteCourseAgainPrompt();      //是否继续删除课程提示
            cin >> tmp;                         //接受输入
            if (tmp == "n" || tmp == "N")       //若输入为"n"或"N"
            {
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::StudentPrintData()                //显示学生个人信息
{
    system("cls");                      //清屏
    ShowStudentDataPrompt();                    //显示学生个人信息提示
    studentVI->DisplayStudent();                //显示学生信息
    cout << "\n" << endl;
    ShowCourseDataPrompt();                     //显示选课课程信息提示
    studentVI->DisplayCourse();                 //显示选课信息
    cout << "\n" << endl;
    system("pause");                    //输入任意键继续
}
void Control::ManagementLogIn()                 //管理员身份登录
{
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowManagementLogIn();                  //管理员身份登录密码验证
        cin >> tmp;                             //输入密码
        if (tmp == "3118002296")                //验证密码
        {
            ManagementMenu();                   //进入管理员操作菜单
            opt = false;                        //设置标志位为false，退出循环
        }
        else if (tmp != "-1")                   //若输入不为"-1"且密码验证失败
        {
            cout << "密码错误！" << endl;
        }
        else                                    //若输入为"-1"
        {
            cout << "已返回主目录!" << endl;
            system("pause");            //输入任意键继续
            system("cls");              //清屏
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::ManagementMenu()                  //进入管理员操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowManagementMenu();                   //管理员操作菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case '1':
                ManagementStudentMenu();        //进入管理学生操作菜单
                break;
            case '2':
                ManagementCourseMenu();         //进入管理课程操作菜单
                break;
            case '3':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::ManagementStudentMenu()           //进入管理学生操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowManagementStudentMenu();            //管理学生菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case '1':
                AddStudent();                   //管理员添加学生
                break;
            case '2':
                DeleteStudent();                //管理员删除学生
                break;
            case '3':
                EditStudent();                  //管理员编辑学生
                break;
            case '4':
                FindStudentMenu();              //进入查询学生操作菜单
                break;
            case '5':
                PrintStudentAll();              //显示所有学生信息
                break;
            case '6':
                TotalStudent();                 //获取学生总数
                break;
            case '7':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindStudentMenu()                 //进入查询学生操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowFindStudentMenu();                  //查询学生操作菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case '1':
                FindStudentID();                //利用学生学号查询
                break;
            case '2':
                FindStudentName();              //利用学生姓名查询
                break;
            case '3':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindStudentID()                   //利用学生学号查询
{
    system("cls");                      //清屏
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowFindStudentIDPrompt();              //利用学生学号查询提示
        cin >> tmp;                             //输入学生学号
        if (tmp != "-1")                        //若输入不为"-1"
        {
            int index = FindCourse(tmp,true);       //查询目标学生
            if (index != -1)                    //若找到目标学生
            {
                ShowFoundPrompt();              //查询成功提示
                ShowStudentDataHeader();        //学生列表表头
                studentV[index].DisplayStudent();       //显示学生信息
                ShowFindStudentAgainPrompt();   //是否继续查询学生提示
                cin >> tmp;                     //接受输入
                if (tmp == "n" || tmp == "N")   //若输入为"n"或"N"
                {
                    opt = false;                //设置标志位为false，退出循环
                }
            }
            else                                //若未找到目标学生
            {
                ShowNotFoundPrompt();           //查询失败提示
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::FindStudentName()                 //利用学生姓名查询
{
    system("cls");                      //清屏
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowFindStudentNamePrompt();            //利用学生姓名查询提示
        cin >> tmp;                             //输入学生姓名
        if (tmp != "-1")                        //若输入不为"-1"
        {
            int index = FindStudent(tmp, false);        //查询目标学生
            if (index != -1)                    //若找到目标学生
            {
                ShowFoundPrompt();              //查询成功提示
                ShowStudentDataHeader();        //学生列表表头
                studentV[index].DisplayStudent();       //显示学生信息
                ShowFindStudentAgainPrompt();   //是否继续查询学生提示
                cin >> tmp;                     //接受输入
                if (tmp == "n" || tmp == "N")   //若输入为"n"或"N"
                {
                    opt = false;                //设置标志位为false，退出循环
                }
            }
            else                                //若未找到目标学生
            {
                ShowNotFoundPrompt();           //查询失败提示
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::PrintStudentAll()                 //显示所有学生信息
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        PrintStudent();                         //显示所有学生信息
        opt = PrintStudentCourse();             //显示学生选修课程信息
    }
}
bool Control::PrintStudentCourse()              //显示学生选修课程信息
{
    string index;
    ShowPrintStudentCoursePrompt();             //显示学生选修课程信息提示
    cin >> index;                               //输入学号
    if (index != "-1")                          //若输入不为"-1"
    {
        if (FindStudent(index, true) != -1)     //查询目标学生，若找到目标学生
        {
            ShowCourseDataPrompt();             //显示选课课程信息提示
            ShowStudentCourseHeader();          //学生选修课程列表表头
            studentV[FindStudent(index, true)].DisplayCourse();     //显示选课信息
            system("pause");            //输入任意键继续
        }
        else                                    //若未找到目标学生
        {
            cout << "\n" << endl;
            cout << "记录为空！" << endl;
        }
        return true;                            //返回true，继续循环
    }
    else                                        //若输入为"-1"
    {
        return false;                           //返回false，退出循环
    }
}
void Control::ManagementCourseMenu()            //进入管理课程操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowManagementCourseMenu();             //管理课程菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case '1':
                AddCourse();                    //管理员添加课程
                break;
            case '2':
                DeleteCourse();                 //管理员删除课程
                break;
            case '3':
                EditCourse();                   //管理员编辑课程
                break;
            case '4':
                FindCourseMenu();               //进入查询课程操作菜单
                break;
            case '5':
                PrintCourseAll();               //显示所有课程信息
                break;
            case '6':
                TotalCourse();                  //获取课程总数
                break;
            case '7':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindCourseMenu()                  //进入查询课程操作菜单
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        system("cls");                  //清屏
        ShowFindCourseMenu();                   //查询课程操作菜单
        char index;
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case '1':
                FindCourseID();                 //利用课程代码查询提示
                break;
            case '2':
                FindCourseName();               //利用课程名称查询提示
                break;
            case '3':
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindCourseID()                    //利用课程代码查询提示
{
    system("cls");                      //清屏
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowFindCourseIDPrompt();               //利用课程代码查询提示
        cin >> tmp;                             //输入课程代码
        if (tmp != "-1")                        //若输入不为"-1"
        {
            int index = FindCourse(tmp,true);       //查询目标课程
            if (index != -1)                    //若找到目标课程
            {
                ShowFoundPrompt();              //查询成功提示
                ShowCourseDataHeader();         //课程列表表头
                courseV[index].DisplayCourse(); //显示选课信息
                ShowFindCourseAgainPrompt();    //是否继续查询课程提示
                cin >> tmp;                     //接受输入
                if (tmp == "n" || tmp == "N")   //若输入为"n"或"N"
                {
                    opt = false;                //设置标志位为false，退出循环
                }
            }
            else                                //若未找到目标课程
            {
                ShowNotFoundPrompt();           //查询失败提示
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::FindCourseName()                  //利用课程名称查询提示
{
    system("cls");                      //清屏
    string tmp;
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        ShowFindCourseNamePrompt();             //利用课程名称查询提示
        cin >> tmp;                             //输入课程名称
        if (tmp != "-1")                        //若输入不为"-1"
        {
            int index = FindCourse(tmp, false);     //查询目标课程
            if (index != -1)                    //若找到目标课程
            {
                ShowFoundPrompt();              //查询成功提示
                ShowCourseDataHeader();         //课程列表表头
                courseV[index].DisplayCourse(); //显示选课信息
                ShowFindCourseAgainPrompt();    //是否继续查询课程提示
                cin >> tmp;                     //接受输入
                if (tmp == "n" || tmp == "N")   //若输入为"n"或"N"
                {
                    opt = false;                //设置标志位为false，退出循环
                }
            }
            else                                //若未找到目标课程
            {
                ShowNotFoundPrompt();           //查询失败提示
                opt = false;                    //设置标志位为false，退出循环
            }
        }
        else                                    //若输入为"-1"
        {
            opt = false;                        //设置标志位为false，退出循环
        }
    }
}
void Control::PrintCourseAll()                  //显示所有课程信息
{
    bool opt = true;                            //循环的标志位
    while (opt)
    {
        PrintCourse();                          //显示所有课程信息
        opt = PrintCourseStudent();             //显示课程选修学生信息
    }
}
bool Control::PrintCourseStudent()              //显示课程选修学生信息
{
    string index;
    ShowPrintCourseStudentPrompt();             //显示课程选修学生信息提示
    cin >> index;                               //输入课程代码
    if (index != "-1")                          //若输入不为"-1"
    {
        int i = FindCourse(index, true);        //查询目标学生
        if (i != -1)                            //若找到目标课程
        {
            ShowStudentDataPrompt();            //显示学生个人信息提示
            ShowCourseStudentHeader();          //选修课程学生列表表头
            courseV[i].DisplayStudent();        //显示选课学生信息
            system("pause");            //输入任意键继续
        }
        else                                    //若未找到目标课程
        {
            cout << "\n" << endl;
            cout << "记录为空！" << endl;
        }
        return true;                            //返回true，继续循环
    }
    else                                        //若输入为"-1"
    {
        return false;                           //返回true，退出循环
    }
}
void Control::Save()                            //保存数据
{
    SaveStudent();                              //保存学生数据
    SaveCourse();                               //保存课程数据
}
void Control::Load()                            //加载数据
{
    LoadCourse();                               //加载课程数据
    LoadStudent();                              //加载学生数据
}
bool Control::Exit()                            //退出菜单
{
    char index;
    bool opt = true;                            //循环的标志位
    bool returnIndex = true;                    //返回值
    while (opt)
    {
        ShowExitPrompt();                       //退出程序保存数据提示
        cin >> index;                           //接受输入
        switch (index)                          //判断用户输入
        {
            case 'y':
            case 'Y':
                returnIndex = false;            //设置返回值为false，退出循环
                opt = false;                    //设置标志位为false，退出循环
                break;
            case 'n':
            case 'N':
                returnIndex = true;             //设置返回值为true，继续循环
                opt = false;                    //设置标志位为false，退出循环
                break;
            default:
                cout << "非法输入！" << endl;
                break;
        }
    }
    return returnIndex;
}
