//
// Created by MR on 2020/12/31.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CourseData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
#include "StudentManagement.h"
using namespace std;

StudentManagement::StudentManagement()
{

}
StudentManagement::~StudentManagement()
{

}

void StudentManagement::Add()
{
    Student tmp;
    while (true)
    {
        system("cls");
        cin >> tmp;
        if(tmp.GetID() != "-1")
        {
            studentMI = studentM.find(tmp.GetID());
            if (studentMI == studentM.end())
            {
                studentV.push_back(tmp);
                studentM.insert(make_pair(tmp.GetID(), studentV.size() - 1));
                Sort();
                cout << "成功添加学生" << endl;
            }
            else
            {
                cout << "此学号学生已存在" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
void StudentManagement::Delete()
{
    string studentID;
    while(true)
    {
        system("cls");
        cout << "输入要删除的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID == "-1")
        {
            studentMI = studentM.find(studentID);
            if (studentMI != studentM.end())
            {
                studentV.erase(studentV.begin() + studentM[studentID]);          //删除vector中元素
                studentM.erase(studentMI);                                      //删除map中元素
                Sort();                                                                 //容器排序
                _studentTotal = studentV.size();                                        //更新选课数目
            }
            else
            {
                cout << "学号输入有误，请重新输入" << endl;
            }
        }
        else
        {
            break;
        }
        system("pause");
    }
}
void StudentManagement::Edit()
{
    string studentID;
    system("cls");
    while(true)
    {
        cout << "输入要修改的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID == "-1")
        {
            studentMI = studentM.find(studentID);
            if (studentMI == studentM.end())
            {
                cout << "修改前的信息：" << endl;
                cout << studentV[studentM[studentID]] << endl;
                cin >> stu;
                studentV[studentM[studentID]] = stu;
                cout << "修改后的信息：" << endl;
                cout << studentV[studentM[studentID]] << endl;
                Sort();
            } else {
                cout << "学号输入有误，请重新输入" << endl;
            }
        }
        break;
    }
}
int StudentManagement::Find(string &studentData, int &mode)
{
    if (mode)                                           //模式一：载入学号
    {
        for(int i=0;i<_studentTotal;i++)
        {
            if(studentV[i].GetID()==studentData)
            {
                return i;
            }
        }
    }
    else                                                //模式二：载入姓名
    {
        for(int i=0;i<_studentTotal;i++)
        {
            if(studentV[i].GetName()==studentData)
            {
                return i;
            }
        }
    }
    return -1;
}
int StudentManagement::Total()
{
    return _studentTotal;
}
void StudentManagement::Print()
{
    for (int i=0;i<_studentTotal;i++)
    {
        cout << studentV[i] << endl;
    }
}
void StudentManagement::Save()
{
    ofstream outfile("3118002296_student.txt",ios::out);
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
        system("cls");
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;
        exit(1);
    }
}
void StudentManagement::Load()
{
    int a;
    course x;
    string zz,hao;
    student x1;
    float l;

    ifstream infile("3118002296_student.txt",ios::in);
    if(!infile)
    {
        /*
        s.clear();
        while(infile>>x1)
        {
            if(x1.getnumber()=="-1") break;
            infile>>l;
            x1.setjidian(l);
            infile>>a;
            while(a--)
            {infile>>zz>>hao;
                x1.add(c[qquerycourse(zz,hao)]);
            }
            x1.setn(a);x1.displayalll();
            s.push_back(x1);
            mas.insert(make_pair(x1.getnumber(),s.size()-1));
        }
         */
        infile.close();
        system("cls");
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;
        exit(1);
    }
}
void StudentManagement::Sort()
{
    studentM.clear();                                                   //清空map容器
    sort(studentV.begin(), studentV.end(), comp);               //对vector容器内元素排序
    for(int i=0;i<_studentTotal;i++)
    {
        studentM.insert(make_pair(studentV[i].GetID(), i));       //依次插入map元素
}
bool StudentManagement::comp(Student &stu1,Student &stu2)
{
    return stu1.GetID() < stu2.GetID();
}
