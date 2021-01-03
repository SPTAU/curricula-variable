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

Course::Course()
{
	_id = "-1";
	_name = "-1";
	_period = "-1";
	_credit = "-1";
	_semester = "-1";
	_maximum = 0;
	_studentAmount = 0;
}
Course::Course(string &id,string &name,string &period,
	string &credit,string &semester,int &maximum)
{
	_id.assign(id);
	_name.assign(name);
	_period.assign(period);
	_credit.assign(credit);
	_semester.assign(semester);
	_maximum = maximum;
	_studentAmount = 0;
}
Course::~Course()
{
	for (int i=0;i<_studentAmount;i++)
	{
		Delete(studentDV[i]._studentID);
	}
	studentDV.clear();
	studentDM.clear();
}

void Course::SetID(string &id)					//���ÿγ̴���
{
	_id.assign(id);
}
void Course::SetName(string &name)				//���ÿγ�����
{
	_name.assign(name);
}
void Course::SetPeriod(string &period)			//������ѧʱ
{
	_period.assign(period);
}
void Course::SetCredit(string &credit)			//����ѧ��
{
	_credit.assign(credit);
}
void Course::SetSemester(string &semester)		//���ÿ���ѧ��
{
	_semester.assign(semester);
}
void Course::SetMaximum(int maximum)			//����ѡ����������
{
	_maximum = maximum;
}
string& Course::GetID()							//��ȡ�γ̴���
{
	return _id;
}
string& Course::GetName()						//��ȡ�γ�����
{
	return _name;
}
string& Course::GetPeriod()						//��ȡ��ѧʱ
{
	return _period;
}
string& Course::GetCredit()						//��ȡѧ��
{
	return _credit;
}
string& Course::GetSemester()					//��ȡ����ѧ��
{
	return _semester;
}
int& Course::GetMaximum()						//��ȡѡ����������
{
	return _maximum;
}
int& Course::GetStudentAmount()					//��ȡѡ��ѧ����Ŀ
{
	return _studentAmount;
}
void Course::Add(Student &stu)					//���ѡ��ѧ��
{
	struct StudentData tmp = {stu.GetID(), stu.GetName(),stu.GetDepartment(), stu.GetClass(), stu.GetPhoneNumber()};
	studentDV.push_back(tmp);										//��vector������Ԫ��
	studentDM.insert(make_pair(stu.GetID(), studentDV.size() - 1));	//��map������Ԫ��
	_studentAmount = studentDV.size();								//����ѧ����Ŀ
	Sort();															//��������
}
void Course::Delete(string &studentID)			//ɾ��ѡ��ѧ��
{
	studentDV.erase(studentDV.begin() + studentDM[studentID]);	//ɾ��vector��Ԫ��
	studentDMI = studentDM.find(studentID);
	studentDM.erase(studentDMI);								//ɾ��map��Ԫ��
	_studentAmount = studentDV.size();							//����ѡ����Ŀ
	Sort();														//��������
}
void Course::DisplayCourse()					//��ʾѡ����Ϣ
{
	cout << *this << endl;
}
void Course::DisplayStudent()					//��ʾѡ��ѧ����Ϣ
{
    for(studentDVI = studentDV.begin();studentDVI != studentDV.end();++studentDVI)
    {
        cout << *studentDVI << endl;
    }
}
void Course::Sort()								//��ѡ��ѧ����������
{
    if (studentDV.size() > 1)
    {
        studentDM.clear();
        sort(studentDV.begin(), studentDV.end(), comp);
        for(int i=0;i<_studentAmount;i++)
        {
            studentDM.insert(make_pair(studentDV[i]._studentID, i));
        }
    }
}
bool Course::comp(StudentData &stu1,StudentData &stu2)		//�Զ���Ƚϱ�׼
{
    stringstream stream;
    stream << stu1._studentID;
    int studentID1;
    stream >> studentID1;
    stream << stu2._studentID;
    int studentID2;
    stream >> studentID2;
	bool index = (studentID1 < studentID2);
	return index;
}
Course& Course::operator= (const Course& cour)				//���ظ�ֵ�����
{
	_id.assign(cour._id);
	_name.assign(cour._name);
	_period.assign(cour._period);
	_credit.assign(cour._credit);
	_semester.assign(cour._semester);
	_maximum = cour._maximum;
    return *this;
}
