//
// Created by MR on 2021/1/1.
//
#include <iostream>
#include <sstream>
#include "Operator.h"
using namespace std;

ostream&operator<<(ostream &os,Student &stu)                    //����Student��������
{
    os << "\t" << setw(10) << stu._id << "\t" << setw(8) << stu._name << "\t" << setw(4) << stu._gender;
    os << "\t" << setw(4) << stu._age << "\t" << setw(20) << stu._department;
    os << "\t" << setw(20) << stu._class<< "\t" << setw(11) << stu._phoneNumber << endl;
    return os;
}
istream&operator>>(istream &is,Student &stu)                    //����Student���������
{
    string tmpID, tmpName, tmpGender, tmpAge, tmpDepartment, tmpClass, tmpPhoneNumber;
    is >> tmpID;
    stu.SetID(tmpID);
    if (tmpID != "-1")                                          //�����벻Ϊ"-1"
    {
        is >> tmpName >> tmpGender >> tmpAge >> tmpDepartment >> tmpClass >> tmpPhoneNumber;
        stu.SetName(tmpName);
        stu.SetGender(tmpGender);
        stu.SetAge(tmpAge);
        stu.SetDepartment(tmpDepartment);
        stu.SetClass(tmpClass);
        stu.SetPhoneNumber(tmpPhoneNumber);
    }
    return is;
}
ostream&operator<<(ostream &os,Course &cour)                    //����Course��������
{
    os << "\t" << setw(10) << cour._id << "\t" << setw(20) << cour._name << "\t" << setw(4) << cour._period;
    os << "\t" << setw(4) << cour._credit << "\t" << setw(8) << cour._semester;
    os << "\t" << setw(8) << cour._maximum << "\\" << setw(8) << cour._studentAmount << endl;
    return os;
}
istream&operator>>(istream &is,Course &cour)                    //����Course���������
{
    string tmpID, tmpName, tmpPeriod, tmpCredit, tmpSemester, tmpMaximum;
    is >> tmpID;
    cour.SetID(tmpID);
    if (tmpID != "-1")                                          //�����벻Ϊ"-1"
    {
        is >> tmpName >> tmpPeriod >> tmpCredit >> tmpSemester >> tmpMaximum;
        cour.SetName(tmpName);
        cour.SetPeriod(tmpPeriod);
        cour.SetCredit(tmpCredit);
        cour.SetSemester(tmpSemester);
        stringstream stream;
        stream << tmpMaximum;
        int maximum;
        stream >> maximum;
        cour.SetMaximum(maximum);
    }
    return is;
}
ostream&operator<<(ostream &os,StudentData &stu)                //����StudentData�ṹ��������
{
    os << "\t" << setw(10) << stu._studentID << "\t" << setw(8) << stu._studentName;
    os << "\t" << setw(20) << stu._studentDepartment << "\t" << setw(20) << stu._studentClass;
    os << "\t" << setw(11) << stu._studentPhoneNumber << endl;
    return os;
}
ostream&operator<<(ostream &os,CourseData &cour)                //����CourseData�ṹ��������
{
    os << "\t" << setw(10) << cour._courseID << "\t" << setw(20) << cour._courseName << "\t" << setw(4) << cour._coursePeriod;
    os << "\t" << setw(4) << cour._courseCredit << "\t" << setw(8) << cour._courseSemester << endl;
    return os;
}