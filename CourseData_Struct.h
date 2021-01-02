//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_COURSEDATA_STRUCT_H
#define SYSTEMDESIGN_COURSEDATA_STRUCT_H

#include <string>
using namespace std;

class Course;

struct CourseData
{
    string _courseID;                       //�γ̴���
    string _courseName;                     //�γ�����
    string _coursePeriod;                   //��ѧʱ
    string _courseCredit;                   //ѧ��
    string _courseSemester;                 //����ѧ��
    friend ostream&operator<<(ostream &os,CourseData &cour);
};

#endif //SYSTEMDESIGN_COURSEDATA_STRUCT_H
