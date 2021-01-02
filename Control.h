//
// Created by SPTAU on 2021/1/1.
//

#ifndef SYSTEMDESIGN_CONTROL_H
#define SYSTEMDESIGN_CONTROL_H

#include <iostream>
using namespace std;

class Control : public Management
{
public:
	Control() = default;
	~Control() = default;
public:
	void Menu();					//�������˵�
	void StudentLogIn();			//ѧ����ݵ�¼
	void StudentMenu();				//����ѧ�������˵�
	void StudentAddCourseMenu();	//����ѧ��ѡ�β˵�
	bool StudentAddingCourse();		//ѧ��ѡ�β���
	void StudentDeletingCourse();	//ѧ����ѡ����
	void StudentPrintData();		//��ʾѧ��������Ϣ
	void ManagementLogIn();			//����Ա��ݵ�¼
	void ManagementMenu();			//�������Ա�����˵�
	void ManagementStudentMenu();	//�������ѧ�������˵�
	void FindStudentMenu();			//�����ѯѧ�������˵�
	void FindStudentID();			//����ѧ��ѧ�Ų�ѯ
	void FindStudentName();			//����ѧ��������ѯ
	void PrintStudentAll();			//��ʾ����ѧ����Ϣ
	bool PrintStudentCourse();		//��ʾѧ��ѡ�޿γ���Ϣ
	void ManagementCourseMenu();	//�������γ̲����˵�
	void FindCourseMenu();			//�����ѯ�γ̲����˵�
	void FindCourseID();			//���ÿγ̴����ѯ��ʾ
	void FindCourseName();			//���ÿγ����Ʋ�ѯ��ʾ
	void PrintCourseAll();			//��ʾ���пγ���Ϣ
	bool PrintCourseStudent();		//��ʾ�γ�ѡ��ѧ����Ϣ
	void Save();					//��������
	void Load();					//��������
	bool static Exit();				//�˳��˵�
};


#endif //SYSTEMDESIGN_CONTROL_H
