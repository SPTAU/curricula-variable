//
// Created by SPTAU on 2020/12/30.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "CourseData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
using namespace std;

Student::Student()
{
	_id = "-1";
	_name = "-1";
	_gender = "-1";
	_age = "-1";
	_department = "-1";
	_class = "-1";
	_phoneNumber = "-1";
	_courseAmount = 0;
}
Student::Student(string &id, string &name, string &gender, string &age, string &department, string &classes,
				string &phoneNumber, int courseAmount):_courseAmount(courseAmount)
{
	_id.assign(id);
	_name.assign(name);
	_gender.assign(gender);
	_age.assign(age);
	_department.assign(department);
	_class.assign(classes);
	_phoneNumber.assign(phoneNumber);
}

Student::~Student()
{
	for (int i=0;i<_courseAmount;i++)
	{
		Delete(courseDV[i]._courseID, false);	//������ѡ��ѡ�γ�
	}
	courseDV.clear();
	courseDM.clear();
}

void Student::SetID(string &id)					//����ѧ��
{
	_id.assign(id);
}
void Student::SetName(string &name)				//��������
{
	_name.assign(name);
}
void Student::SetGender(string &gender)			//�����Ա�
{
	_gender.assign(gender);
}
void Student::SetAge(string &age)				//��������
{
	_age.assign(age);
}
void Student::SetDepartment(string &department)	//����ϵ��
{
	_department.assign(department);
}
void Student::SetClass(string &classes)			//���ð༶
{
	_class.assign(classes);
}
void Student::SetPhoneNumber(string &phoneNumber)	//������ϵ��ʽ
{
	_phoneNumber.assign(phoneNumber);
}
void Student::SetCourseAmount(int courseAmount)	//����ѡ����Ŀ
{
	_courseAmount = courseAmount;
}
string& Student::GetID()						//��ȡѧ��
{
	return _id;
}
string& Student::GetName()						//��ȡ����
{
	return _name;
}
string& Student::GetGender()					//��ȡ�Ա�
{
	return _gender;
}
string& Student::GetAge()						//��ȡ����
{
	return _age;
}
string& Student::GetDepartment()				//��ȡϵ��
{
	return _department;
}
string& Student::GetClass()						//��ȡ�༶
{
	return _class;
}
string& Student::GetPhoneNumber()				//��ȡ��ϵ��ʽ
{
	return _phoneNumber;
}
int& Student::GetCourseAmount()					//��ȡѡ����Ŀ
{
	return _courseAmount;
}
string& Student::GetCourseID(int &index)		//��ȡ�γ̴���
{
	return courseDV[index]._courseID;
}
void Student::Add(Course &cour, bool mode)		//��ӿγ�
{
	if (mode)									//ģʽһ��ѧ������ѡ��
	{
		if(cour.GetStudentAmount() < cour.GetMaximum())	//�ж���ѡ�γ��Ƿ�����
		{
			struct CourseData tmp = {cour.GetID(), cour.GetName(),cour.GetPeriod(), cour.GetCredit(), cour.GetSemester()};
			courseDMI = courseDM.find(cour.GetID());
			if (courseDMI == courseDM.end())	//�ж��Ƿ���ѡ�ÿ�
			{
				courseDV.push_back(tmp);		//��vector������Ԫ��
				courseDM.insert(make_pair(cour.GetID(), courseDV.size() - 1));	//��map������Ԫ��
				_courseAmount = courseDV.size();		//����ѡ����Ŀ
				Sort();									//��������
				cour.Add(*this);						//�ص�Course���Ա�������ѧ����Ϣ
				cout << "ѡ�γɹ���" << endl;
			}
			else
			{
				cout << "��ѡ�ÿΣ�" << endl;
			}
		}
		else
		{
			cout << "����������" << endl;
		}
	}
	else										//ģʽ�������ļ��ж�ȡ��Ϣ���ѡ��
	{
		struct CourseData tmp = {cour.GetID(), cour.GetName(), cour.GetPeriod(), cour.GetCredit(), cour.GetSemester()};
		courseDV.push_back(tmp);				//��vector������Ԫ��
		courseDM.insert(make_pair(cour.GetID(), courseDV.size() - 1));	//��map������Ԫ��
		Sort();									//��������
		cour.Add(*this);						//�ص�Course���Ա�������ѧ����Ϣ
	}
}
void Student::Delete(string &courseID,bool mode)	//ɾ���γ�
{
	courseDMI = courseDM.find(courseID);
	if (mode)									//ģʽһ��ѧ��������ѡ
	{
		if (courseDMI != courseDM.end())		//�ж��Ƿ���ѡ�ÿ�
		{
			courseDV.erase(courseDV.begin() + courseDM[courseID]);		//ɾ��vector��Ԫ��
			courseDM.erase(courseDMI);									//ɾ��map��Ԫ��
			_courseAmount = courseDV.size();							//����ѡ����Ŀ
			Sort();														//��������
			cout << "��ѡ�ɹ���" << endl;
		}
		else
		{
			cout << "δѡ�ÿΣ�" << endl;
		}
	}
	else										//ģʽ����������ѡ����ɾ��ѧ����ɾ���γ�
	{
		courseDV.erase(courseDV.begin() + courseDM[courseID]);			//ɾ��vector��Ԫ��
		courseDM.erase(courseDMI);										//ɾ��map��Ԫ��
		_courseAmount = courseDV.size();								//����ѡ����Ŀ
		Sort();															//��������
	}
}
void Student::DisplayStudent()					//��ʾѧ����Ϣ
{
	cout << *this << endl;
}
void Student::DisplayCourse()					//��ʾѡ����Ϣ
{
    for(courseDVI = courseDV.begin();courseDVI != courseDV.end();++courseDVI)
    {
        cout << *courseDVI << endl;
    }
}
void Student::Sort()							//����ѡ�γ̽�������
{
    if (courseDV.size() > 1)
    {
        courseDM.clear();											//���map����
        sort(courseDV.begin(), courseDV.end(), comp);				//��vector������Ԫ������
        for(int i=0;i<_courseAmount;i++)
        {
            courseDM.insert(make_pair(courseDV[i]._courseID, i));	//���β���mapԪ��
        }
    }
}
bool Student::comp(CourseData &cour1,CourseData &cour2)			//�Զ���Ƚϱ�׼
{
    stringstream stream;
    stream << cour1._courseID;
    int courseID1;
    stream >> courseID1;
    stream << cour2._courseID;
    int courseID2;
    stream >> courseID2;
	bool index = (courseID1 < courseID2);
	return index;
}
Student& Student::operator= (const Student &stu)				//���ظ�ֵ�����
{
	_id.assign(stu._id);
	_name.assign(stu._name);
	_gender.assign(stu._gender);
	_age.assign(stu._age);
	_department.assign(stu._department);
	_class.assign(stu._class);
	_phoneNumber.assign(stu._phoneNumber);
    return *this;
}
