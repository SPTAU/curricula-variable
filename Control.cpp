//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CourseData_Struct.h"
#include "StudentData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Management.h"
#include "Show.h"
#include "Control.h"
using namespace std;



void Control::Menu()						//�������˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt == true)
	{
		system("cls");						//����
		ShowMainMenu();						//���˵�
		char index;
		cin >> index;						//����ѡ��
		switch (index)						//�ж��û���ѡ��
		{
			case '1':
				StudentLogIn();				//ѧ����ݵ�¼
				break;
			case '2':
				ManagementLogIn();			//����Ա��ݵ�¼
				break;
			case '3':
				Save();						//��������
				break;
			case '4':
				Load();						//��������
				break;
			case '5':
				opt = Exit();				//�˳��˵�
				break;
			default:
				cout << "����Ƿ���������ѡ��!" << endl;
				break;
		}
	}
}
void Control::StudentLogIn()				//ѧ����ݵ�¼
{
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowStudentLogInID();				//ѧ����ݵ�¼ѧ����֤
		cin >> tmp;							//����ѧ��
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			studentMI = studentM.find(tmp);	//��֤����ѧ��
			if (studentMI != studentM.end())//������ѧ����ȷ
			{
				string tmpID = tmp;
				ShowStudentLogInName();		//ѧ����ݵ�¼������֤
				cin >> tmp;					//��������
				if (tmp != "-1")			//�����벻Ϊ"-1"
				{
					if (studentV[studentM[tmpID]].GetName() == tmp)		//��֤��������
					{
						studentVI = studentV.begin() + studentM[tmpID];	//�������ָ���û�ѧ��
						StudentMenu();		//����ѧ�������˵�
						opt = false;		//���ñ�־λΪfalse���˳�ѭ��
					}
					else					//��������������
					{
						cout << "������ѧ�Ų�ƥ�䣡" << endl;
					}
				}
				else						//������Ϊ"-1"
				{
					cout << "�ѷ�����Ŀ¼!"<< endl;
					system("pause");		//�������������
					system("cls");			//����
					opt = false;			//���ñ�־λΪfalse���˳�ѭ��
				}
			}
			else							//������ѧ�Ŵ���
			{
				cout << "��ѧ�Ų����ڣ�" << endl;
			}
		}
		else								//������Ϊ"-1"
		{
			cout << "�ѷ�����Ŀ¼!" << endl;
			system("pause");				//�������������
			system("cls");					//����
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::StudentMenu()					//����ѧ�������˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");				//����
		ShowStudentMenu();					//ѧ�������˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û���ѡ��
		{
			case '1':
				StudentAddCourseMenu();		//����ѧ��ѡ�β˵�
				break;
			case '2':
				StudentDeletingCourse();	//ѧ����ѡ����
				break;
			case '3':
				StudentPrintData();			//��ʾѧ��������Ϣ
				break;
			case '4':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!";
				break;
		}
	}
}
void Control::StudentAddCourseMenu()		//����ѧ��ѡ�β˵�
{
	system("cls");							//����
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowStudentAddCourseMenu();			//ѡ�β˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û���ѡ��
		{
			case '1':
				opt = StudentAddingCourse();//ѧ��ѡ�β���
				break;
			case '2':
				FindCourseID();				//���ÿγ̴����ѯ��ʾ
				break;
			case '3':
				FindCourseName();			//���ÿγ����Ʋ�ѯ��ʾ
				break;
			default:
				cout << "�Ƿ����룬�ѷ�����һ��!";
				opt = false;
				break;
		}
	}
}
bool Control::StudentAddingCourse()			//ѧ��ѡ�β���
{
	system("cls");							//����
	ShowCourseDataHeader();					//�γ��б��ͷ
	PrintCourse();							//��ʾ���пγ���Ϣ
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowAddCoursePrompt();				//���ÿγ̴�����ӿγ���ʾ
		cin >> tmp;							//����γ̴���
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			StudentAddCourse(tmp);			//ѧ��ѡ�޿γ�
			ShowAddCourseAgainPrompt();		//�Ƿ������ӿγ���ʾ
			cin >> tmp;						//��������
			if (tmp == "n" || tmp == "N")	//������Ϊ"n"��"N"
			{
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
	return false;							//����false���˳�ѭ��
}
void Control::StudentDeletingCourse()		//ѧ����ѡ����
{
	system("cls");					//����
	ShowCourseDataPrompt();					//��ʾѡ�ογ���Ϣ��ʾ
	ShowStudentCourseHeader();				//ѧ��ѡ�޿γ��б��ͷ
	studentVI->DisplayCourse();				//��ʾѡ����Ϣ
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowDeleteCoursePrompt();			//���ÿγ̴���ɾ���γ���ʾ
		cin >> tmp;							//����γ̴���
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			StudentDeleteCourse(tmp);		//ѧ����ѡ�γ�
			ShowDeleteCourseAgainPrompt();	//�Ƿ����ɾ���γ���ʾ
			cin >> tmp;						//��������
			if (tmp == "n" || tmp == "N")	//������Ϊ"n"��"N"
			{
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::StudentPrintData()			//��ʾѧ��������Ϣ
{
	system("cls");							//����
	ShowStudentDataPrompt();				//��ʾѧ��������Ϣ��ʾ
	studentVI->DisplayStudent();			//��ʾѧ����Ϣ
	cout << "\n" << endl;
	ShowCourseDataPrompt();					//��ʾѡ�ογ���Ϣ��ʾ
	studentVI->DisplayCourse();				//��ʾѡ����Ϣ
	cout << "\n" << endl;
	system("pause");						//�������������
}
void Control::ManagementLogIn()				//����Ա��ݵ�¼
{
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowManagementLogIn();				//����Ա��ݵ�¼������֤
		cin >> tmp;							//��������
		if (tmp == "3118002296")			//��֤����
		{
			ManagementMenu();				//�������Ա�����˵�
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
		else if (tmp != "-1")				//�����벻Ϊ"-1"��������֤ʧ��
		{
			cout << "�������" << endl;
		}
		else								//������Ϊ"-1"
		{
			cout << "�ѷ�����Ŀ¼!" << endl;
			system("pause");				//�������������
			system("cls");					//����
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::ManagementMenu()				//�������Ա�����˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");						//����
		ShowManagementMenu();				//����Ա�����˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case '1':
				ManagementStudentMenu();	//�������ѧ�������˵�
				break;
			case '2':
				ManagementCourseMenu();		//�������γ̲����˵�
				break;
			case '3':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!" << endl;
				break;
		}
	}
}
void Control::ManagementStudentMenu()		//�������ѧ�������˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");						//����
		ShowManagementStudentMenu();		//����ѧ���˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case '1':
				AddStudent();				//����Ա���ѧ��
				break;
			case '2':
				DeleteStudent();			//����Աɾ��ѧ��
				break;
			case '3':
				EditStudent();				//����Ա�༭ѧ��
				break;
			case '4':
				FindStudentMenu();			//�����ѯѧ�������˵�
				break;
			case '5':
				PrintStudentAll();			//��ʾ����ѧ����Ϣ
				break;
			case '6':
				TotalStudent();				//��ȡѧ������
				break;
			case '7':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!" << endl;
				break;
		}
	}
}
void Control::FindStudentMenu()				//�����ѯѧ�������˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");						//����
		ShowFindStudentMenu();				//��ѯѧ�������˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case '1':
				FindStudentID();			//����ѧ��ѧ�Ų�ѯ
				break;
			case '2':
				FindStudentName();			//����ѧ��������ѯ
				break;
			case '3':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!" << endl;
				break;
		}
	}
}
void Control::FindStudentID()				//����ѧ��ѧ�Ų�ѯ
{
	system("cls");							//����
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowFindStudentIDPrompt();			//����ѧ��ѧ�Ų�ѯ��ʾ
		cin >> tmp;							//����ѧ��ѧ��
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			int index = FindCourse(tmp,true);		//��ѯĿ��ѧ��
			if (index != -1)						//���ҵ�Ŀ��ѧ��
			{
				ShowFoundPrompt();					//��ѯ�ɹ���ʾ
				ShowStudentDataHeader();			//ѧ���б��ͷ
				studentV[index].DisplayStudent();	//��ʾѧ����Ϣ
				ShowFindStudentAgainPrompt();		//�Ƿ������ѯѧ����ʾ
				cin >> tmp;							//��������
				if (tmp == "n" || tmp == "N")		//������Ϊ"n"��"N"
				{
					opt = false;			//���ñ�־λΪfalse���˳�ѭ��
				}
			}
			else							//��δ�ҵ�Ŀ��ѧ��
			{
				ShowNotFoundPrompt();		//��ѯʧ����ʾ
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::FindStudentName()				//����ѧ��������ѯ
{
	system("cls");							//����
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowFindStudentNamePrompt();		//����ѧ��������ѯ��ʾ
		cin >> tmp;							//����ѧ������
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			int index = FindStudent(tmp, false);	//��ѯĿ��ѧ��
			if (index != -1)						//���ҵ�Ŀ��ѧ��
			{
				ShowFoundPrompt();					//��ѯ�ɹ���ʾ
				ShowStudentDataHeader();			//ѧ���б��ͷ
				studentV[index].DisplayStudent();	//��ʾѧ����Ϣ
				ShowFindStudentAgainPrompt();		//�Ƿ������ѯѧ����ʾ
				cin >> tmp;							//��������
				if (tmp == "n" || tmp == "N")		//������Ϊ"n"��"N"
				{
					opt = false;			//���ñ�־λΪfalse���˳�ѭ��
				}
			}
			else							//��δ�ҵ�Ŀ��ѧ��
			{
				ShowNotFoundPrompt();		//��ѯʧ����ʾ
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::PrintStudentAll()				//��ʾ����ѧ����Ϣ
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		PrintStudent();						//��ʾ����ѧ����Ϣ
		opt = PrintStudentCourse();			//��ʾѧ��ѡ�޿γ���Ϣ
	}
}
bool Control::PrintStudentCourse()			//��ʾѧ��ѡ�޿γ���Ϣ
{
	string index;
	ShowPrintStudentCoursePrompt();			//��ʾѧ��ѡ�޿γ���Ϣ��ʾ
	cin >> index;							//����ѧ��
	if (index != "-1")						//�����벻Ϊ"-1"
	{
		if (FindStudent(index, true) != -1)	//��ѯĿ��ѧ�������ҵ�Ŀ��ѧ��
		{
			ShowCourseDataPrompt();			//��ʾѡ�ογ���Ϣ��ʾ
			ShowStudentCourseHeader();		//ѧ��ѡ�޿γ��б��ͷ
			studentV[FindStudent(index, true)].DisplayCourse();	//��ʾѡ����Ϣ
			system("pause");				//�������������
		}
		else								//��δ�ҵ�Ŀ��ѧ��
		{
			cout << "\n" << endl;
			cout << "��¼Ϊ�գ�" << endl;
		}
		return true;						//����true������ѭ��
	}
	else									//������Ϊ"-1"
	{
		return false;						//����false���˳�ѭ��
	}
}
void Control::ManagementCourseMenu()		//�������γ̲����˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");						//����
		ShowManagementCourseMenu();			//����γ̲˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case '1':
				AddCourse();				//����Ա��ӿγ�
				break;
			case '2':
				DeleteCourse();				//����Աɾ���γ�
				break;
			case '3':
				EditCourse();				//����Ա�༭�γ�
				break;
			case '4':
				FindCourseMenu();			//�����ѯ�γ̲����˵�
				break;
			case '5':
				PrintCourseAll();			//��ʾ���пγ���Ϣ
				break;
			case '6':
				TotalCourse();				//��ȡ�γ�����
				break;
			case '7':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!" << endl;
				break;
		}
	}
}
void Control::FindCourseMenu()				//�����ѯ�γ̲����˵�
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		system("cls");						//����
		ShowFindCourseMenu();				//��ѯ�γ̲����˵�
		char index;
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case '1':
				FindCourseID();				//���ÿγ̴����ѯ��ʾ
				break;
			case '2':
				FindCourseName();			//���ÿγ����Ʋ�ѯ��ʾ
				break;
			case '3':
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ�����!" << endl;
				break;
		}
	}
}
void Control::FindCourseID()				//���ÿγ̴����ѯ��ʾ
{
	system("cls");							//����
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowFindCourseIDPrompt();			//���ÿγ̴����ѯ��ʾ
		cin >> tmp;							//����γ̴���
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			int index = FindCourse(tmp,true);	//��ѯĿ��γ�
			if (index != -1)					//���ҵ�Ŀ��γ�
			{
				ShowFoundPrompt();				//��ѯ�ɹ���ʾ
				ShowCourseDataHeader();			//�γ��б��ͷ
				courseV[index].DisplayCourse(); //��ʾѡ����Ϣ
				ShowFindCourseAgainPrompt();	//�Ƿ������ѯ�γ���ʾ
				cin >> tmp;						//��������
				if (tmp == "n" || tmp == "N")	//������Ϊ"n"��"N"
				{
					opt = false;			//���ñ�־λΪfalse���˳�ѭ��
				}
			}
			else							//��δ�ҵ�Ŀ��γ�
			{
				ShowNotFoundPrompt();		//��ѯʧ����ʾ
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::FindCourseName()				//���ÿγ����Ʋ�ѯ��ʾ
{
	system("cls");							//����
	string tmp;
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		ShowFindCourseNamePrompt();			//���ÿγ����Ʋ�ѯ��ʾ
		cin >> tmp;							//����γ�����
		if (tmp != "-1")					//�����벻Ϊ"-1"
		{
			int index = FindCourse(tmp, false);		//��ѯĿ��γ�
			if (index != -1)						//���ҵ�Ŀ��γ�
			{
				ShowFoundPrompt();					//��ѯ�ɹ���ʾ
				ShowCourseDataHeader();				//�γ��б��ͷ
				courseV[index].DisplayCourse(); 	//��ʾѡ����Ϣ
				ShowFindCourseAgainPrompt();		//�Ƿ������ѯ�γ���ʾ
				cin >> tmp;							//��������
				if (tmp == "n" || tmp == "N")		//������Ϊ"n"��"N"
				{
					opt = false;			//���ñ�־λΪfalse���˳�ѭ��
				}
			}
			else							//��δ�ҵ�Ŀ��γ�
			{
				ShowNotFoundPrompt();		//��ѯʧ����ʾ
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
			}
		}
		else								//������Ϊ"-1"
		{
			opt = false;					//���ñ�־λΪfalse���˳�ѭ��
		}
	}
}
void Control::PrintCourseAll()				//��ʾ���пγ���Ϣ
{
	bool opt = true;						//ѭ���ı�־λ
	while (opt)
	{
		PrintCourse();						//��ʾ���пγ���Ϣ
		opt = PrintCourseStudent();			//��ʾ�γ�ѡ��ѧ����Ϣ
	}
}
bool Control::PrintCourseStudent()			//��ʾ�γ�ѡ��ѧ����Ϣ
{
	string index;
	ShowPrintCourseStudentPrompt();			//��ʾ�γ�ѡ��ѧ����Ϣ��ʾ
	cin >> index;							//����γ̴���
	if (index != "-1")						//�����벻Ϊ"-1"
	{
		int i = FindCourse(index, true);	//��ѯĿ��ѧ��
		if (i != -1)						//���ҵ�Ŀ��γ�
		{
			ShowStudentDataPrompt();		//��ʾѧ��������Ϣ��ʾ
			ShowCourseStudentHeader();		//ѡ�޿γ�ѧ���б��ͷ
			courseV[i].DisplayStudent();	//��ʾѡ��ѧ����Ϣ
			system("pause");				//�������������
		}
		else								//��δ�ҵ�Ŀ��γ�
		{
			cout << "\n" << endl;
			cout << "��¼Ϊ�գ�" << endl;
		}
		return true;						//����true������ѭ��
	}
	else									//������Ϊ"-1"
	{
		return false;						//����true���˳�ѭ��
	}
}
void Control::Save()						//��������
{
	SaveStudent();							//����ѧ������
	SaveCourse();							//����γ�����
}
void Control::Load()						//��������
{
	LoadCourse();							//���ؿγ�����
	LoadStudent();							//����ѧ������
}
bool Control::Exit()						//�˳��˵�
{
	char index;
	bool opt = true;						//ѭ���ı�־λ
	bool returnIndex = true;				//����ֵ
	while (opt)
	{
		ShowExitPrompt();					//�˳����򱣴�������ʾ
		cin >> index;						//��������
		switch (index)						//�ж��û�����
		{
			case 'y':
			case 'Y':
				returnIndex = false;		//���÷���ֵΪfalse���˳�ѭ��
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			case 'n':
			case 'N':
				returnIndex = true;			//���÷���ֵΪtrue������ѭ��
				opt = false;				//���ñ�־λΪfalse���˳�ѭ��
				break;
			default:
				cout << "�Ƿ����룡" << endl;
				break;
		}
	}
	return returnIndex;
}
