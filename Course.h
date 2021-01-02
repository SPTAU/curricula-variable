//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_COURSE_H
#define SYSTEMDESIGN_COURSE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
using namespace std;

class Student;

class Course
{
public:
    Course();
    Course(string &id,string &name,string &period,
           string &credit,string &semester,int &maximum);
    Course(Course& cour);
    ~Course();
private:
    string _id;                 //�γ̴���
    string _name;               //�γ�����
    string _period;             //ѧʱ
    string _credit;             //ѧ��
    string _semester;           //����ѧ��
    int _maximum;               //ѡ����������
    int _studentAmount;         //ѡ��ѧ����Ŀ
public:
    vector<StudentData> studentDV;              //StudentData��Vector����
    map<string,int> studentDM;                  //StudentData��Map����
    map<string,int>::iterator studentDMI;       //StudentData��Map�����ĵ�����
    void SetID(string &id);                     //���ÿγ̴���
    void SetName(string &name);                 //���ÿγ�����
    void SetPeriod(string &period);             //������ѧʱ
    void SetCredit(string &credit);             //����ѧ��
    void SetSemester(string &semester);         //���ÿ���ѧ��
    void SetMaximum(int maximum);               //����ѡ����������
    string &GetID();            //��ȡ�γ̴���
    string &GetName();          //��ȡ�γ�����
    string &GetPeriod();        //��ȡ��ѧʱ
    string &GetCredit();        //��ȡѧ��
    string &GetSemester();      //��ȡ����ѧ��
    int& GetMaximum();          //��ȡѡ����������
    int& GetStudentAmount();    //��ȡѡ��ѧ����Ŀ
    void Add(Student &stu);                     //���ѡ��ѧ��
    void Delete(string &studentID);             //ɾ��ѡ��ѧ��
    void DisplayCourse();                       //��ʾѡ����Ϣ
    void DisplayStudent();                      //��ʾѡ��ѧ����Ϣ
    void Sort();                                //��ѡ��ѧ����������
    static bool comp(StudentData &cour1, StudentData &cour2);               //�Զ���Ƚϱ�׼
    Course &operator= (const Course &cour);                                 //���ظ�ֵ�����
    friend ostream&operator<<(ostream &os, Course &stu);                    //����Course�����
    friend istream&operator>>(istream &is, Course &stu);                    //����Course������
};


#endif //SYSTEMDESIGN_COURSE_H
