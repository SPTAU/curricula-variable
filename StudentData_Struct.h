//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_STUDENTDATA_STRUCT_H
#define SYSTEMDESIGN_STUDENTDATA_STRUCT_H

#include <string>
using namespace std;

class Student;

struct StudentData
{
    string _studentID;                      //ѧ��
    string _studentName;                    //����
    string _studentDepartment;              //ϵ��
    string _studentClass;                   //�༶
    string _studentPhoneNumber;             //��ϵ��ʽ
    friend ostream&operator<<(ostream &os,StudentData &stu);
};

#endif //SYSTEMDESIGN_STUDENTDATA_STRUCT_H
