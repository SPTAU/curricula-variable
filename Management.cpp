//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "CourseData_Struct.h"
#include "StudentData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
#include "Management.h"
#include "Show.h"
using namespace std;

Management::Management()
{
    _studentTotal = 0;
    _courseTotal = 0;
}
Management::~Management() = default;

void Management::AddStudent()
{
    system("cls");
    while (true)
    {
        Student tmpStudent;
        cout << "\n" << endl;
        cout << "请依次输入学号、姓名、性别、年龄、系别、班级、联系方式，输入-1结束"<<endl;
        cin >> tmpStudent;
        if(tmpStudent.GetID() != "-1")
        {
            studentMI = studentM.find(tmpStudent.GetID());
            if (studentMI == studentM.end())
            {
                studentV.push_back(tmpStudent);
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));
                SortStudent();
                cout << "成功添加学生！" << endl;
            }
            else
            {
                cout << "此学号学生已存在！" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
void Management::DeleteStudent()
{
    string studentID;
    system("cls");
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要删除的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID != "-1")
        {
            studentMI = studentM.find(studentID);
            if (studentMI != studentM.end())
            {
                studentV.erase(studentV.begin() + studentM[studentID]);          //删除vector中元素
                studentM.erase(studentMI);                                      //删除map中元素
                SortStudent();                                                                 //容器排序
                _studentTotal = studentV.size();                                        //更新选课数目
                cout << "成功删除学生！" << endl;
            }
            else
            {
                cout << "记录为空！" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
void Management::EditStudent()
{
    string studentID;
    system("cls");
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要修改的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID != "-1")
        {
            studentMI = studentM.find(studentID);
            if (studentMI == studentM.end())
            {
                cout << "修改前的信息：" << endl;
                cout << studentV[studentM[studentID]] << endl;
                cin >> studentV[studentM[studentID]];
                cout << "修改后的信息：" << endl;
                cout << studentV[studentM[studentID]] << endl;
                SortStudent();
            } else {
                cout << "记录为空！" << endl;
            }
        }
        else
        {
            break;
        }
    }
    system("pause");
}
int Management::FindStudent(string &studentData, int mode)
{
    if (mode)                                           //模式一：查询学号
    {
        for(int i = 0;i < _studentTotal;i++)
        {
            if(studentV[i].GetID() == studentData)
            {
                return i;
            }
        }
    }
    else                                                //模式二：查询姓名
    {
        for(int i = 0;i < _studentTotal;i++)
        {
            if(studentV[i].GetName() == studentData)
            {
                return i;
            }
        }
    }
    return -1;
}
int& Management::TotalStudent()
{
    system("cls");
    ShowTotalStudentPrompt();
    cout << _studentTotal << endl;
    system("pause");
    return _studentTotal;
}
void Management::PrintStudent()
{
    system("cls");
    ShowStudentDataHeader();
    for (int i=0;i<_studentTotal;i++)
    {
        cout << studentV[i] << endl;
    }
    system("pause");
}
void Management::SaveStudent()
{
    ofstream outfile("3118002296_student.txt",ios::out|ios::trunc);
    if(outfile)
    {
        for(int i = 0;i < _studentTotal;i++)
        {
            outfile << studentV[i].GetID() << "\t" << studentV[i].GetName() << "\t" << studentV[i].GetGender() << "\t";
            outfile << studentV[i].GetAge() << "\t" << studentV[i].GetDepartment() << studentV[i].GetClass() << "\t";
            outfile << studentV[i].GetPhoneNumber() << "\t" << studentV[i].GetCourseAmount() << endl;
            for(int j = 0;j<studentV[i].GetCourseAmount();j++)
            {
                outfile << studentV[i].GetCourseID(j) << endl;
            }
        }
        outfile << "-1" << endl;
        outfile.close();
        cout << "学生数据保存成功！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;
        exit(1);
    }
}
void Management::LoadStudent()
{
    int tmpCourseAmount;
    string tmpCourseID;
    Student tmpStudent;
    ifstream infile("3118002296_student.txt",ios::in);
    if(!infile)
    {
        studentV.clear();
        cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(4) << "性别";
        cout << "\t" << setw(4) << "年龄" << "\t" << setw(20) << "系别";
        cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
        while(infile >> tmpStudent)
        {
            if(tmpStudent.GetID() != "-1")
            {
                infile >> tmpCourseAmount;
                tmpStudent.SetCourseAmount(tmpCourseAmount);
                while(tmpCourseAmount--)
                {
                    infile >> tmpCourseID;
                    tmpStudent.Add(courseV[courseM[tmpCourseID]], false);
                }
                tmpStudent.DisplayStudent();
                studentV.push_back(tmpStudent);
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));
            }
            else
            {
                break;
            }
        }
        infile.close();
        cout << "学生数据加载成功！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;
        exit(1);
    }
}
void Management::SortStudent()
{
    studentM.clear();                                                   //清空map容器
    sort(studentV.begin(), studentV.end(), CompStudent);               //对vector容器内元素排序
    for(int i=0;i<_studentTotal;i++)
    {
        studentM.insert(make_pair(studentV[i].GetID(), i));       //依次插入map元素
    }
}
bool Management::CompStudent(Student &stu1, Student &stu2)
{
    return stu1.GetID() < stu2.GetID();
}
void Management::StudentAddCourse(string &courseID)
{
    int index = FindCourse(courseID,true);
    if (index != -1)
    {
        studentVI->Add(courseV[courseM[courseID]],true);
    }
    else
    {
        cout << "此课程代码课程不存在！" << endl;
    }
}
void Management::StudentDeleteCourse(string &courseID)
{
    int index = FindCourse(courseID,true);
    if (index != -1)
    {
        studentVI->Delete(courseID,true);
    }
    else
    {
        cout << "此课程代码课程不存在！" << endl;
    }
}
void Management::AddCourse()
{
    system("cls");
    while (true)
    {
        Course tmpCourse;
        cout << "\n" << endl;
        cout << "请依次输入学号、姓名、性别、年龄、系别、班级、联系方式，输入-1结束"<<endl;
        cin >> tmpCourse;
        if(tmpCourse.GetID() != "-1")
        {
            courseMI = courseM.find(tmpCourse.GetID());
            if (courseMI == courseM.end())
            {
                courseV.push_back(tmpCourse);
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));
                SortCourse();
                cout << "成功添加课程！" << endl;
            }
            else
            {
                cout << "此课程代码课程已存在！" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
void Management::DeleteCourse()
{
    string courseID;
    system("cls");
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要删除的课程的课程代码,输入-1结束" << endl;
        cin >> courseID;
        if(courseID != "-1")
        {
            courseMI = courseM.find(courseID);
            if (courseMI != courseM.end())
            {
                courseV.erase(courseV.begin() + courseM[courseID]);          //删除vector中元素
                courseM.erase(studentMI);                                      //删除map中元素
                SortCourse();                                                                 //容器排序
                _courseTotal = courseV.size();                                        //更新选课数目
                cout << "成功删除课程！" << endl;
            }
            else
            {
                cout << "记录为空！" << endl;
            }
        }
        else
        {
            break;
        }
    }
    system("pause");
}
void Management::EditCourse()
{
    string courseID;
    system("cls");
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要修改的课程的课程代码,输入-1结束" << endl;
        cin >> courseID;
        if(courseID != "-1")
        {
            courseMI = courseM.find(courseID);
            if (courseMI == courseM.end())
            {
                cout << "\n" << endl;
                cout << "修改前的信息：" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << courseV[courseM[courseID]] << endl;
                cin >> courseV[courseM[courseID]];
                cout << "\n" << endl;
                cout << "修改后的信息：" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << courseV[courseM[courseID]] << endl;
                SortCourse();
            } else {
                cout << "记录为空！" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
int Management::FindCourse(string &courseData, int mode)
{
    if (mode)                                           //模式一：查询课程代码
    {
        for(int i = 0;i < _courseTotal;i++)
        {
            if(courseV[i].GetID() == courseData)
            {
                return i;
            }
        }
    }
    else                                                //模式二：查询课程名
    {
        for(int i=0;i<_courseTotal;i++)
        {
            if(courseV[i].GetName() == courseData)
            {
                return i;
            }
        }
    }
    return -1;
}
int& Management::TotalCourse()
{
    system("cls");
    ShowTotalCoursePrompt();
    cout << _courseTotal << endl;
    system("pause");
    return _courseTotal;
}
void Management::PrintCourse()
{
    system("cls");
    ShowCourseDataHeader();
    for (int i=0;i<_courseTotal;i++)
    {
        cout << courseV[i] << endl;
    }
    system("pause");
}
void Management::SaveCourse()
{
    ofstream outfile("3118002296_course.txt",ios::out|ios::trunc);
    if(outfile)
    {
        for(int i = 0;i < _courseTotal;i++)
        {
            outfile << courseV[i].GetID() << "\t" << courseV[i].GetName() << "\t" << courseV[i].GetPeriod() << "\t";
            outfile << courseV[i].GetCredit() << "\t" << courseV[i].GetSemester() << courseV[i].GetMaximum() << endl;
        }
        outfile << "-1" << endl;
        outfile.close();
        cout << "课程数据保存成功！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "open 3118002296_course.txt error!" <<endl;
        exit(1);
    }
}
void Management::LoadCourse()
{
    Course tmpCourse;
    ifstream infile("3118002296_course.txt",ios::in);
    if(infile)
    {
        system("cls");
        courseV.clear();
        cout << "\t" << setw(10) << "课程代码" << "\t" << setw(12) << "课程名称" << "\t" << setw(4) << "学时";
        cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期";
        cout << "\t" << setw(8) << "人数上限" << "\\" << setw(8) << "选修人数" << endl;
        while (infile >> tmpCourse) {
            if (tmpCourse.GetID() != "-1") {
                tmpCourse.DisplayStudent();
                courseV.push_back(tmpCourse);
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));
            }
            else
            {
                break;
            }
        }
        infile.close();
        cout << "\n" << endl;
        cout << "课程数据加载成功！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "open 3118002296_course.txt error!" <<endl;
        exit(1);
    }
}
void Management::SortCourse()
{
    courseM.clear();                                                   //清空map容器
    sort(courseV.begin(), courseV.end(), CompCourse);               //对vector容器内元素排序
    for(int i=0;i<_courseTotal;i++)
    {
        courseM.insert(make_pair(courseV[i].GetID(), i));       //依次插入map元素
    }
}
bool Management::CompCourse(Course &cour1, Course &cour2)
{
    return cour1.GetID() < cour2.GetID();
}