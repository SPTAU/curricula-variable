//
// Created by SPTAU on 2020/12/30.
//

#ifndef SYSTEMDESIGN_STUDENT_H
#define SYSTEMDESIGN_STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include "CourseData_Struct.h"
using namespace std;

class Course;
class Management;

class Student
{
public:
	Student();
	Student(string &id, string &name, string &gender, string &age, string &department,
			string &classes, string &phoneNumber, int courseAmount = 0);
	~Student();
private:
	string _id;				//ѧ��
	string _name;			//����
	string _gender;			//�Ա�
	string _age;			//����
	string _department;		//ϵ��
	string _class;			//�༶
	string _phoneNumber;	//��ϵ��ʽ
	int _courseAmount;		//ѡ��γ���Ŀ
public:
	vector<CourseData> courseDV;				//CourseData��Vector����
    vector<CourseData>::iterator courseDVI;				//CourseData��Vector�����ĵ�����
	map<string,int> courseDM;					//CourseData��Map����
	map<string,int>::iterator courseDMI;		//CourseData��Map�����ĵ�����
	void SetID(string &id);						//����ѧ��
	void SetName(string &name);					//��������
	void SetGender(string &gender);				//�����Ա�
	void SetAge(string &age);					//��������
	void SetDepartment(string &department);		//����ϵ��
	void SetClass(string &classes);				//���ð༶
	void SetPhoneNumber(string &phoneNumber);	//������ϵ��ʽ
	void SetCourseAmount(int courseAmount);		//����ѡ����Ŀ
	string &GetID();			//��ȡѧ��
	string &GetName();			//��ȡ����
	string &GetGender();		//��ȡ�Ա�
	string &GetAge();			//��ȡ����
	string &GetDepartment();	//��ȡϵ��
	string &GetClass();			//��ȡ�༶
	string &GetPhoneNumber();	//��ȡ��ϵ��ʽ
	int &GetCourseAmount();		//��ȡѡ����Ŀ
	string &GetCourseID(int &index);			//��ȡ�γ̴���
	void Add(Course &cour, bool mode);			//��ӿγ�
	void Delete(string &courseID,bool mode);	//ɾ���γ�
	void DisplayStudent();						//��ʾѧ����Ϣ
	void DisplayCourse();						//��ʾѡ����Ϣ
	void Sort();								//����ѡ�γ̽�������
	static bool comp(CourseData &cour1, CourseData &cour2);		//�Զ���Ƚϱ�׼
	Student &operator= (const Student &stu);					//���ظ�ֵ�����
	friend ostream&operator<<(ostream &os, Student &stu);		//����Student�����
	friend istream&operator>>(istream &is, Student &stu);		//����Student������
};

#endif //SYSTEMDESIGN_STUDENT_H
