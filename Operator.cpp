//
// Created by MR on 2021/1/1.
//
#include <iostream>
#include "Operator.h"
using namespace std;

ostream&operator<<(ostream &os,Student &stu)
{
    os << "\t" << setw(10) << stu._id << "\t" << setw(8) << stu._name << "\t" << setw(4) << stu._gender;
    os << "\t" << setw(4) << stu._age << "\t" << setw(20) << stu._department;
    os << "\t" << setw(20) << stu._class<< "\t" << setw(11) << stu._phoneNumber << endl;
    return os;
}
istream&operator>>(istream &is,Student &stu)
{
    string tmpID, tmpName, tmpGender, tmpAge, tmpDepartment, tmpClass, tmpPhoneNumber;
    is >> tmpID >> tmpName >> tmpGender >> tmpAge >> tmpDepartment >> tmpClass >> tmpPhoneNumber;
    stu.SetID(tmpID);
    stu.SetName(tmpName);
    stu.SetGender(tmpGender);
    stu.SetAge(tmpAge);
    stu.SetDepartment(tmpDepartment);
    stu.SetClass(tmpClass);
    stu.SetPhoneNumber(tmpPhoneNumber);
    return is;
}
ostream&operator<<(ostream &os,Course &cour)
{
    os << "\t" << setw(10) << cour._id << "\t" << setw(12) << cour._name << "\t" << setw(4) << cour._period;
    os << "\t" << setw(4) << cour._credit << "\t" << setw(8) << cour._semester;
    os << "\t" << setw(8) << cour._maximum << "\\" << setw(8) << cour._studentAmount << endl;
    return os;
}
istream&operator>>(istream &is,Course &cour)
{
    string tmpID, tmpName, tmpPeriod, tmpCredit, tmpSemester, tmpMaximum;
    is >> tmpID >> tmpName >> tmpPeriod >> tmpCredit >> tmpSemester >> tmpMaximum;
    cour.SetID(tmpID);
    cour.SetName(tmpName);
    cour.SetPeriod(tmpPeriod);
    cour.SetCredit(tmpCredit);
    cour.SetSemester(tmpSemester);
    cour.SetMaximum(stoi(tmpMaximum));
    return is;
}
ostream&operator<<(ostream &os,StudentData &stu)
{
    os << "\t" << setw(10) << stu._studentID << "\t" << setw(8) << stu._studentName;
    os << "\t" << setw(20) << stu._studentDepartment << "\t" << setw(20) << stu._studentClass;
    os << "\t" << setw(11) << stu._studentPhoneNumber << endl;
    return os;
}
ostream&operator<<(ostream &os,CourseData &cour)
{
    os << "\t" << setw(10) << cour._courseID << "\t" << setw(12) << cour._courseName << "\t" << setw(4) << cour._coursePeriod;
    os << "\t" << setw(4) << cour._courseCredit << "\t" << setw(8) << cour._courseSemester << endl;
    return os;
}
