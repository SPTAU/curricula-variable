//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <iomanip>
#include "Show.h"
using namespace std;

void ShowMainMenu()										//���˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "				��ӭ����		ѧ��ѡ�޿γ�ϵͳ		" << endl;
	cout << "\t\t\t\t" << "	*********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1.  ѧ����ݵ�¼				" << endl;
	cout << "\t\t\t\t" << "					2.  ����Ա��ݵ�¼			" << endl;
	cout << "\t\t\t\t" << "					3.  ��������					" << endl;
	cout << "\t\t\t\t" << "					4.  ��������					" << endl;
	cout << "\t\t\t\t" << "					5.  �˳�						" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	*********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowStudentLogInID()								//ѧ����ݵ�¼ѧ����֤
{
	cout << "����������ѧ�� (����-1�˳�)�� ";
}
void ShowStudentLogInName()								//ѧ����ݵ�¼������֤
{
	cout << "�������������� (����-1�˳�)�� ";
}
void ShowManagementLogIn()								//����Ա��ݵ�¼������֤
{
	cout << "���������� (����-1�˳�)�� ";
}
void ShowStudentMenu()									//ѧ�������˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					ѧ�������˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. ѡ��						" << endl;
	cout << "\t\t\t\t" << "					2. �˿�						" << endl;
	cout << "\t\t\t\t" << "					3. ������Ϣ					" << endl;
	cout << "\t\t\t\t" << "					4. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowStudentAddCourseMenu()							//ѡ�β˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					ѧ��ѡ�β˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "				1. ��ʾȫ���γ�					" << endl;
	cout << "\t\t\t\t" << "				2. ���γ̴����ѯѡ�޿�			" << endl;
	cout << "\t\t\t\t" << "				3. ���γ����Ʋ�ѯѡ�޿�			" << endl;
	cout << "\t\t\t\t" << "				4. ������һ��					" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\t\t\t\t" << "\n �����������Ӧ��ţ� ";
}
void ShowManagementMenu()								//����Ա�����˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��������˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��ѡ��������				" << endl;
	cout << "\t\t\t\t" << "					1. ѧ��						" << endl;
	cout << "\t\t\t\t" << "					2. �γ�						" << endl;
	cout << "\t\t\t\t" << "					3. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowManagementStudentMenu()						//����ѧ���˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					����ѧ���˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. ���ѧ��					" << endl;
	cout << "\t\t\t\t" << "					2. ɾ��ѧ��					" << endl;
	cout << "\t\t\t\t" << "					3. �༭ѧ��					" << endl;
	cout << "\t\t\t\t" << "					4. ��ѯѧ��					" << endl;
	cout << "\t\t\t\t" << "					5. ��ʾѧ��					" << endl;
	cout << "\t\t\t\t" << "					6. ͳ��ѧ��					" << endl;
	cout << "\t\t\t\t" << "					7. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowFindStudentMenu()								//��ѯѧ�������˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��ѯ�����˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��ѡ���ѯģʽ				" << endl;
	cout << "\t\t\t\t" << "					1. ѧ��ѧ��					" << endl;
	cout << "\t\t\t\t" << "					2. ѧ������					" << endl;
	cout << "\t\t\t\t" << "					3. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowManagementCourseMenu()							//����γ̲˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					����γ̲˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					1. ��ӿγ�					" << endl;
	cout << "\t\t\t\t" << "					2. ɾ���γ�					" << endl;
	cout << "\t\t\t\t" << "					3. �༭�γ�					" << endl;
	cout << "\t\t\t\t" << "					4. ��ѯ�γ�					" << endl;
	cout << "\t\t\t\t" << "					5. ��ʾ�γ�					" << endl;
	cout << "\t\t\t\t" << "					6. ͳ�ƿγ�					" << endl;
	cout << "\t\t\t\t" << "					7. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowFindCourseMenu()								//��ѯ�γ̲����˵�
{
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��ѯ�����˵�					" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "					��ѡ���ѯģʽ				" << endl;
	cout << "\t\t\t\t" << "					1. �γ̴���					" << endl;
	cout << "\t\t\t\t" << "					2. �γ�����					" << endl;
	cout << "\t\t\t\t" << "					3. ������һ��				" << endl;
	cout << "\n" << endl;
	cout << "\t\t\t\t" << "	********************************************" << endl;
	cout << "\n �����������Ӧ��ţ� ";
}
void ShowCourseDataHeader()								//�γ��б��ͷ
{
	cout << "\t" << setw(10) << "�γ̴���" << "\t" << setw(20) << "�γ�����" << "\t" << setw(4) << "ѧʱ";
	cout << "\t" << setw(4) << "ѧ��" << "\t" << setw(8) << "����ѧ��";
	cout << "\t" << setw(8) << "��������"<< "\\" << setw(8) << "ѡ������"  << endl;
}
void ShowStudentDataHeader()							//ѧ���б��ͷ
{
	cout << "\t" << setw(10) << "ѧ��" << "\t" << setw(8) << "����" << "\t" << setw(4) << "�Ա�";
	cout << "\t" << setw(4) << "����" << "\t" << setw(20) << "ϵ��";
	cout << "\t" << setw(20) << "�༶"<< "\t" << setw(11) << "��ϵ��ʽ"  << endl;
}
void ShowCourseStudentHeader()							//ѡ�޿γ�ѧ���б��ͷ
{
	cout << "\t" << setw(10) << "ѧ��" << "\t" << setw(8) << "����" << "\t" << setw(20) << "ϵ��";
	cout << "\t" << setw(20) << "�༶"<< "\t" << setw(11) << "��ϵ��ʽ"  << endl;
}
void ShowStudentCourseHeader()							//ѧ��ѡ�޿γ��б��ͷ
{
	cout << "\t" << setw(10) << "�γ̴���" << "\t" << setw(20) << "�γ�����" << "\t" << setw(4) << "ѧʱ";
	cout << "\t" << setw(4) << "ѧ��" << "\t" << setw(8) << "����ѧ��" << endl;
}
void ShowStudentDataPrompt()							//��ʾѧ��������Ϣ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "������Ϣ��" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowCourseDataPrompt()								//��ʾѡ�ογ���Ϣ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��ѡ�γ̣�" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowFoundPrompt()									//��ѯ�ɹ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��ѯ�ɹ���" << endl;
	cout << "*******************************************************************************************************"
			"****************"  << endl;
}
void ShowNotFoundPrompt()								//��ѯʧ����ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��¼Ϊ�գ�" << endl;
}
void ShowEditCoursePrompt()								//��ʾ�༭�γ���ʾ
{
	cout << "����������γ̴��롢�γ����ơ�ѧʱ��ѧ�֡�����ѧ�ڡ�ѡ���������ޣ�����-1����" << endl;
}
void ShowEditStudentPrompt()							//��ʾ�༭ѧ����ʾ
{
	cout << "����������ѧ�š��������Ա����䡢ϵ�𡢰༶����ϵ��ʽ������-1����" << endl;
}
void ShowFindCourseIDPrompt()							//���ÿγ̴����ѯ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ѯ�γ̵Ŀγ̴���(����-1ȡ������)�� " ;
}
void ShowFindCourseNamePrompt()							//���ÿγ����Ʋ�ѯ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ѯ�γ̵Ŀγ�����(����-1ȡ������)�� " ;
}
void ShowFindStudentIDPrompt()							//����ѧ��ѧ�Ų�ѯ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ѯѧ����ѧ��(����-1ȡ������)�� " ;
}
void ShowFindStudentNamePrompt()						//����ѧ��������ѯ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ѯѧ��������(����-1ȡ������)�� " ;
}
void ShowFindCourseAgainPrompt()						//�Ƿ������ѯ�γ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "�Ƿ��������ѯ�γ̣� <Y/N>�� " ;
}
void ShowFindStudentAgainPrompt()						//�Ƿ������ѯѧ����ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "�Ƿ��������ѯѧ���� <Y/N>�� " ;
}
void ShowAddCoursePrompt()								//���ÿγ̴�����ӿγ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫѡ�޿γ̵Ŀγ̴���(����-1ȡ������)�� " ;
}
void ShowAddCourseAgainPrompt()							//�Ƿ������ӿγ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "�Ƿ������ѡ�޿γ̣� <Y/N>�� " ;
}
void ShowDeleteCoursePrompt()							//���ÿγ̴���ɾ���γ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ѡ�γ̵Ŀγ̴���(����-1ȡ������)�� " ;
}
void ShowDeleteCourseAgainPrompt()						//�Ƿ����ɾ���γ���ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "�Ƿ��������ѡ�γ̣� <Y/N>�� " ;
}
void ShowPrintCourseStudentPrompt()						//����ѧ��ѧ����ʾ������Ϣ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ʾѡ��ѧ����Ϣ�Ŀγ̵Ŀγ̴���(����-1ȡ������)�� " ;
}
void ShowPrintStudentCoursePrompt()						//���ÿγ̴�����ʾ�γ���Ϣ��ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "��������Ҫ��ʾѡ����Ϣ��ѧ����ѧ��(����-1ȡ������)�� " ;
}
void ShowTotalCoursePrompt()							//��ʾ�γ�������ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "ѡ�޿γ�������" ;
}
void ShowTotalStudentPrompt()							//��ʾѧ��������ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "ѧ��������" ;
}
void ShowExitPrompt()									//�˳����򱣴�������ʾ
{
	cout << "\n" << endl;
	cout << "\t" << "�˳�ʱδ��������ݽ��ᶪʧ,�Ƿ��˳��� <Y/N>�� " ;
}
