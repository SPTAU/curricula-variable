//
// Created by SPTAU on 2021/1/1.
//

#ifndef SYSTEMDESIGN_MANAGEMENT_H
#define SYSTEMDESIGN_MANAGEMENT_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "StudentData_Struct.h"
#include "CourseData_Struct.h"
#include "Student.h"
#include "Course.h"

using namespace std;

class Management
{
public:
	Management();
	~Management();
private:
	int _studentTotal;										//ѧ������
	int _courseTotal;										//�γ�����
protected:
	vector<Student> studentV;								//Student��Vector����
	vector<Student>::iterator studentVI;					//Student��Vector�����ĵ�����
	map<string,int> studentM;								//Student��Map����
	map<string,int>::iterator studentMI;					//Student��Map�����ĵ�����
	vector<Course> courseV;									//Student��Vector����
	map<string,int> courseM;								//Student��Map����
	map<string,int>::iterator courseMI;						//Student��Map�����ĵ�����
public:
	void AddStudent();										//����Ա���ѧ��
	void DeleteStudent();									//����Աɾ��ѧ��
	void EditStudent();										//����Ա�༭ѧ��
	int FindStudent(string &studentData, int mode);			//����Ա��ѯѧ��
	int &TotalStudent();									//��ȡѧ������
	void PrintStudent();									//��ʾ����ѧ����Ϣ
	void SaveStudent();										//����ѧ������
	void LoadStudent();										//����ѧ������
	void SortStudent();										//��ѧ��������ѧ����������
	static bool CompStudent(Student &stu1, Student &stu2);	//�Զ���Ƚϱ�׼
	void StudentAddCourse(string &courseID);				//ѧ��ѡ�޿γ�
	void StudentDeleteCourse(string &courseID);				//ѧ����ѡ�γ�
	void AddCourse();										//����Ա��ӿγ�
	void DeleteCourse();									//����Աɾ���γ�
	void EditCourse();										//����Ա�༭�γ�
	int FindCourse(string &studentData, int mode);			//����Ա��ѯ�γ�
	int &TotalCourse();										//��ȡ�γ�����
	void PrintCourse();										//��ʾ���пγ���Ϣ
	void SaveCourse();										//����γ�����
	void LoadCourse();										//���ؿγ�����
	void SortCourse();										//�Կγ������ڿγ̽�������
	static bool CompCourse(Course &cour1, Course &cour2);	//�Զ���Ƚϱ�׼
};


#endif //SYSTEMDESIGN_MANAGEMENT_H
