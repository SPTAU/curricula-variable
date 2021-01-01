//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <iomanip>
#include <fstream>
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
#include "Operator.h"
#include "Control.h"
using namespace std;



void Control::Menu()
{
    bool opt = true;        //是否循环的一个标志
    while (opt == true)
    {
        system("cls");
        ShowMainMenu();
        //接收输入选择
        char index;
        cin >> index;
        //判断用户的选择
        switch (index)
        {
            case '1':
                StudentLogIn();        //小目录
                break;
            case '2':
                ManagementLogIn();        //小目录
                break;
            case '3':
                Save();        //小目录
                break;
            case '4':
                Load();        //小目录
                break;
            case '5':
                opt = Exit();        //把标志位为假，就退出了循环
                break;
            default:
                cout << "输入非法，请重新选择!" << endl;
                break;
        }
    }
}
void Control::StudentLogIn()
{
    string tmp;
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowStudentLogInID();
        cin >> tmp;
        if (tmp != "-1")
        {
            studentMI = studentM.find(tmp);
            if (studentMI != studentM.end())
            {
                string tmpID = tmp;
                ShowStudentLogInName();
                cin >> tmp;
                if (tmp != "-1")
                {
                    if (studentV[studentM[tmpID]].GetName() == tmp)
                    {
                        studentVI = studentV.begin() + distance(studentMI,studentM.begin());
                        StudentMenu();
                        opt = false;
                    }
                    else
                    {
                        cout << "姓名与学号不匹配！" << endl;
                    }
                }
                else
                {
                    cout << "已返回主目录!"<< endl;
                    opt = false;
                }
            }
            else
            {
                cout << "该学号不存在！" << endl;
            }
        }
        else
        {
            cout << "已返回主目录!" << endl;
            opt = false;
        }
    }
}
void Control::StudentMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowStudentMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                StudentAddCourseMenu();        //小目录
                break;
            case '2':
                StudentDeletingCourse();
                break;
            case '3':
                StudentPrintData();
                break;
            case '4':
                opt = false;
                break;
            default:
                cout << "\t\t非法输入!\n";
                break;
        }
    }
}
void Control::StudentAddCourseMenu()
{
    system("cls");
    bool opt = true;
    while (opt)
    {
        ShowStudentAddCourseMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                opt = StudentAddingCourse();        //小目录
                break;
            case '2':
                FindCourseID();
                break;
            case '3':
                FindCourseName();
                break;
            default:
                cout << "\t\t非法输入，已返回上一层!\n";
                opt = false;
                break;
        }
    }
}
bool Control::StudentAddingCourse()
{
    system("cls");
    ShowCourseDataHeader();
    PrintCourse();
    string tmp;
    bool opt = true;
    while (opt)
    {
        ShowAddCoursePrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            StudentAddCourse(tmp);
            ShowAddCourseAgainPrompt();
            cin >> tmp;
            if (tmp == "n" && tmp == "N")
            {
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
    return false;
}
void Control::StudentDeletingCourse()
{
    system("cls");
    ShowStudentCourseDataPrompt();
    ShowStudentCourseHeader();
    studentVI->DisplayCourse();
    string tmp;
    bool opt = true;
    while (opt)
    {
        ShowDeleteCoursePrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            StudentDeleteCourse(tmp);
            ShowDeleteCourseAgainPrompt();
            cin >> tmp;
            if (tmp == "n" && tmp == "N")
            {
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
}
void Control::StudentPrintData()
{
    system("cls");
    ShowStudentDataPrompt();
    studentVI->DisplayStudent();
    cout << "\n" << endl;
    ShowStudentCourseDataPrompt();
    studentVI->DisplayCourse();
    cout << "\n" << endl;
    system("pause");
}
void Control::ManagementLogIn()
{
    string tmp;
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowManagementLogIn();
        cin >> tmp;
        if (tmp == "3118002296")
        {
            ManagementMenu();
            opt = false;
        }
        else if (tmp != "-1")
        {
            cout << "密码错误！" << endl;
        }
        else
        {
            cout << "已返回主目录!" << endl;
            opt = false;
        }
    }
}
void Control::ManagementMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowManagementMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                ManagementStudentMenu();        //小目录
                break;
            case '2':
                ManagementCourseMenu();
                break;
            case '3':
                opt = false;
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::ManagementStudentMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowManagementStudentMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                AddStudent();        //小目录
                break;
            case '2':
                DeleteStudent();
                break;
            case '3':
                EditStudent();
                break;
            case '4':
                FindStudentMenu();
                break;
            case '5':
                PrintStudent();
                break;
            case '6':
                TotalStudent();
                break;
            case '7':
                opt = false;
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindStudentMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowFindStudentMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                FindStudentID();        //小目录
                break;
            case '2':
                FindStudentName();
                break;
            case '3':
                opt = false;
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindStudentID()
{
    system("cls");
    string tmp;
    bool opt = true;
    while (opt)
    {
        cout << "\n" << endl;
        ShowFindStudentIDPrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            int index = FindCourse(tmp,true);
            if (index != -1)
            {
                ShowFoundPrompt();
                ShowStudentDataHeader();
                studentV[index].DisplayStudent();
                ShowFindStudentAgainPrompt();
                cin >> tmp;
                if (tmp == "n" && tmp == "N")
                {
                    opt = false;
                }
            }
            else
            {
                ShowNotFoundPrompt();
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
}
void Control::FindStudentName()
{
    system("cls");
    string tmp;
    bool opt = true;
    while (opt)
    {
        cout << "\n" << endl;
        ShowFindStudentNamePrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            int index = FindStudent(tmp, false);
            if (index != -1)
            {
                ShowFoundPrompt();
                ShowStudentDataHeader();
                studentV[index].DisplayStudent();
                ShowFindStudentAgainPrompt();
                cin >> tmp;
                if (tmp == "n" && tmp == "N")
                {
                    opt = false;
                }
            }
            else
            {
                ShowNotFoundPrompt();
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
}
void Control::PrintStudentCourse()
{
    *
}
void Control::ManagementCourseMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowManagementCourseMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                AddCourse();        //小目录
                break;
            case '2':
                DeleteCourse();
                break;
            case '3':
                EditCourse();
                break;
            case '4':
                FindCourseMenu();
                break;
            case '5':
                PrintCourse();
                break;
            case '6':
                TotalCourse();
                break;
            case '7':
                opt = false;
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindCourseMenu()
{
    bool opt = true;
    while (opt)
    {
        system("cls");
        ShowFindCourseMenu();
        char index;
        cin >> index;      //接受输入
        switch (index)
        {
            case '1':
                FindCourseID();        //小目录
                break;
            case '2':
                FindCourseName();
                break;
            case '3':
                opt = false;
                break;
            default:
                cout << "非法输入!" << endl;
                break;
        }
    }
}
void Control::FindCourseID()
{
    system("cls");
    string tmp;
    bool opt = true;
    while (opt)
    {
        cout << "\n" << endl;
        ShowFindCourseIDPrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            int index = FindCourse(tmp,true);
            if (index != -1)
            {
                ShowFoundPrompt();
                ShowCourseDataHeader();
                courseV[index].DisplayCourse();
                ShowFindCourseAgainPrompt();
                cin >> tmp;
                if (tmp == "n" && tmp == "N")
                {
                    opt = false;
                }
            }
            else
            {
                ShowNotFoundPrompt();
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
}
void Control::FindCourseName()
{
    system("cls");
    string tmp;
    bool opt = true;
    while (opt)
    {
        cout << "\n" << endl;
        ShowFindCourseNamePrompt();
        cin >> tmp;
        if (tmp != "-1")
        {
            int index = FindCourse(tmp, false);
            if (index != -1)
            {
                ShowFoundPrompt();
                ShowCourseDataHeader();
                courseV[index].DisplayCourse();
                ShowFindCourseAgainPrompt();
                cin >> tmp;
                if (tmp == "n" && tmp == "N")
                {
                    opt = false;
                }
            }
            else
            {
                ShowNotFoundPrompt();
                opt = false;
            }
        }
        else
        {
            opt = false;
        }
    }
}
void Control::PrintCourseStudent()
{
    *
}
void Control::Save()
{
    SaveStudent();
    SaveCourse();
}
void Control::Load()
{
    LoadCourse();
    LoadStudent();
}
bool Control::Exit()
{
    char index;
    bool opt = true;
    bool returnIndex = true;
    while (opt)
    {
        ShowExitPrompt();
        cin >> index;
        switch (index)
        {
            case 'y':
            case 'Y':
                returnIndex = false;
                opt = false;
                break;
            case 'n':
            case 'N':
                returnIndex = true;
                opt = false;
                break;
            default:
                cout << "非法输入！" << endl;
                break;
        }
    }
    return returnIndex;
}
