//
// Created by SPTAU on 2021/1/1.
//

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "CourseData_Struct.h"
#include "StudentData_Struct.h"
#include "Course.h"
#include "Student.h"
#include "Operator.h"
#include "Management.h"
#include "Show.h"
using namespace std;

Management::Management()
{
    _studentTotal = 0;
    _courseTotal = 0;
}
Management::~Management() = default;

void Management::AddStudent()                                   //����Ա��ӿγ�
{
    system("cls");                                      //����
    while (true)
    {
        Student tmpStudent;
        cout << "\n" << endl;
        cout << "����������ѧ�š��������Ա����䡢ϵ�𡢰༶����ϵ��ʽ������-1����"<<endl;
        cin >> tmpStudent;
        if(tmpStudent.GetID() != "-1")                          //�����벻Ϊ"-1"
        {
            studentMI = studentM.find(tmpStudent.GetID());      //��ѯĿ��ѧ��
            if (studentMI == studentM.end())                    //��δ�ҵ�Ŀ��ѧ��
            {
                studentV.push_back(tmpStudent);                 //���ص�Vector������
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));        //���뵽Map������
                _studentTotal++;                                //����ѧ����Ŀ
                SortStudent();                                  //��ѧ��������ѧ����������
                cout << "�ɹ����ѧ����" << endl;
            }
            else                                                //���ҵ�Ŀ��ѧ��
            {
                cout << "��ѧ��ѧ���Ѵ��ڣ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
        system("pause");                                //�������������
    }
}
void Management::DeleteStudent()                                //����Աɾ��ѧ��
{
    string studentID;
    system("cls");                                      //����
    while(true)
    {
        cout << "\n" << endl;
        cout << "����Ҫɾ����ѧ����ѧ��,����-1����" << endl;
        cin >> studentID;
        if(studentID != "-1")                                   //�����벻Ϊ"-1"
        {
            studentMI = studentM.find(studentID);               //��ѯĿ��γ�
            if (studentMI != studentM.end())                    //���ҵ�Ŀ��γ�
            {
                studentV.erase(studentV.begin() + studentM[studentID]);     //ɾ��vector��Ԫ��
                studentM.erase(studentMI);              //ɾ��map��Ԫ��
                _studentTotal = studentV.size();                //����ѡ����Ŀ
                SortStudent();                                  //��������
                cout << "�ɹ�ɾ��ѧ����" << endl;
            }
            else                                                //��δ�ҵ�Ŀ��γ�
            {
                cout << "��¼Ϊ�գ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
        system("pause");                                //�������������
    }
}
void Management::EditStudent()                                  //����Ա�༭ѧ��
{
    string studentID;
    Student tmpStudent;
    system("cls");                                      //����
    while(true)
    {
        cout << "\n" << endl;
        cout << "����Ҫ�޸ĵ�ѧ����ѧ��,����-1����" << endl;
        cin >> studentID;
        if(studentID != "-1")                                   //�����벻Ϊ"-1"
        {
            studentMI = studentM.find(studentID);               //��ѯĿ��ѧ��
            if (studentMI == studentM.end())                    //���ҵ�Ŀ��ѧ��
            {
                cout << "\n" << endl;
                cout << "�޸�ǰ����Ϣ��" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << studentV[studentM[studentID]] << endl;
                ShowEditStudentPrompt();
                cin >> tmpStudent;
                if (FindCourse(tmpStudent.GetID(),true) == -1)      //��ѯ�Ƿ������ͬѧ��ѧ��
                {
                    studentV[studentM[studentID]] = tmpStudent; //���ҵ���ͬѧ��ѧ��
                    cout << "\n" << endl;
                    cout << "�޸ĺ����Ϣ��" << endl;
                    cout << "*******************************************************************************************************"
                            "****************"  << endl;
                    cout << studentV[studentM[studentID]] << endl;          //��ʾ�޸ĺ���Ϣ
                    SortStudent();                              //��ѧ��������ѧ����������
                    cout << "�ɹ��޸�ѧ����" << endl;
                }
                else                                            //���ҵ���ͬѧ��ѧ��
                {
                    cout << "��ѧ��ѧ���Ѵ��ڣ�" << endl;
                }
            }
            else                                                //��δ�ҵ�Ŀ��ѧ��
            {
                cout << "��¼Ϊ�գ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
    }
    system("pause");                                    //�������������
}
int Management::FindStudent(string &studentData, int mode)      //����Ա��ѯѧ��
{
    if (mode)                                                   //ģʽһ����ѯѧ��
    {
        for(int i = 0;i < _studentTotal;i++)                    //����Course���Vector����
        {
            if(studentV[i].GetID() == studentData)
            {
                return i;                                       //����Ŀ��γ̵��±�
            }
        }
    }
    else                                                        //ģʽ������ѯ����
    {
        for(int i = 0;i < _studentTotal;i++)                    //����Course���Vector����
        {
            if(studentV[i].GetName() == studentData)
            {
                return i;                                       //����Ŀ��γ̵��±�
            }
        }
    }
    return -1;                                                  //��ѯʧ�ܣ�����-1
}
int& Management::TotalStudent()                                 //��ȡѧ������
{
    system("cls");                                      //����
    ShowTotalStudentPrompt();                                   //��ʾѧ��������ʾ
    cout << _studentTotal << endl;                              //��ʾѧ������
    system("pause");                                    //�������������
    return _studentTotal;                                       //����ѧ������
}
void Management::PrintStudent()                                 //��ʾ����ѧ����Ϣ
{
    system("cls");                                      //����
    ShowStudentDataHeader();                                    //��ʾѧ���б��ͷ
    for (int i=0;i<_studentTotal;i++)                           //������ʾѧ����Ϣ
    {
        cout << studentV[i] << endl;
    }
}
void Management::SaveStudent()                                  //����ѧ������
{
    ofstream outfile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_student.txt",ios::out|ios::trunc);       //����д�뷽ʽ���ļ�
    if(outfile)                                                 //���ɹ���
    {
        for(int i = 0;i < _studentTotal;i++)                    //���ε���ѧ����Ϣ
        {
            outfile << studentV[i].GetID() << "\t" << studentV[i].GetName() << "\t" << studentV[i].GetGender() << "\t";
            outfile << studentV[i].GetAge() << "\t" << studentV[i].GetDepartment() << studentV[i].GetClass() << "\t";
            outfile << studentV[i].GetPhoneNumber() << "\t" << studentV[i].GetCourseAmount() << endl;
            for(int j = 0;j<studentV[i].GetCourseAmount();j++)
            {
                outfile << studentV[i].GetCourseID(j) << endl;
            }
        }
        outfile << "-1" << endl;                                //���������ʶ
        outfile.close();                                        //�ر��ļ�
        cout << "ѧ�����ݱ���ɹ���" << endl;
        system("pause");                                //�������������
        system("cls");                                  //����
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;    //��ʾ������Ϣ
    }
}
void Management::LoadStudent()                                  //����ѧ������
{
    int tmpCourseAmount;
    string tmpCourseID;
    Student tmpStudent;
    ifstream infile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_student.txt",ios::in);                //ֻ����ʽ���ļ�
    if(infile)
    {
        studentV.clear();                                       //���Vector����
        cout << "\t" << setw(10) << "ѧ��" << "\t" << setw(8) << "����" << "\t" << setw(4) << "�Ա�";
        cout << "\t" << setw(4) << "����" << "\t" << setw(20) << "ϵ��";
        cout << "\t" << setw(20) << "�༶"<< "\t" << setw(11) << "��ϵ��ʽ"  << endl;
        while(infile >> tmpStudent)                             //���ļ��в�������д�뻺����
        {
            if(tmpStudent.GetID() != "-1")                      //�ж��Ƿ��ȡ��������ʶ
            {
                int courseAmount = 0;
                stringstream stream;
                infile >> tmpCourseAmount;
                stream << tmpCourseAmount;                      //String to Intת��
                stream >> courseAmount;
                for (int i=0;i < courseAmount; i++)             //�ж�ѧ����ѡ�γ���Ŀ
                {
                    tmpStudent.SetCourseAmount(i+1);        //
                    infile >> tmpCourseID;
                    tmpStudent.Add(courseV[courseM[tmpCourseID]], false);
                }
                tmpStudent.DisplayStudent();                    //��ʾ�Ѷ�������
                studentV.push_back(tmpStudent);                 //���뵽Vector������
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));        //����Map������
                _studentTotal++;                                //����ѧ������
                SortStudent();                                  //�Կγ������ڿγ̽�������
            }
            else                                                //����ȡ��������ʶ
            {
                break;
            }
        }
        infile.close();                                         //�ر��ļ�
        cout << "ѧ�����ݼ��سɹ���" << endl;
        system("pause");                              //�������������
        system("cls");                              //����
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;    //��ʾ������Ϣ
    }
}
void Management::SortStudent()                                  //��ѧ��������ѧ����������
{
    studentM.clear();                                                           //���map����
    sort(studentV.begin(), studentV.end(), CompStudent);            //��vector������Ԫ������
    for(int i=0;i<_studentTotal;i++)
    {
        studentM.insert(make_pair(studentV[i].GetID(), i));             //���β���mapԪ��
    }
}
bool Management::CompStudent(Student &stu1, Student &stu2)      //�Զ���Ƚϱ�׼
{
    bool index = (stu1.GetID() < stu2.GetID());                 //���Ƚ�ѧ��ѧ��
    return index;
}
void Management::StudentAddCourse(string &courseID)             //ѧ��ѡ�޿γ�
{
    int index = FindCourse(courseID,true);          //��ѯĿ��γ�
    if (index != -1)                                            //���ҵ�Ŀ��γ�
    {
        studentVI->Add(courseV[courseM[courseID]],true);            //ѡ��Ŀ��γ�
    }
    else
    {
        cout << "�˿γ̴���γ̲����ڣ�" << endl;                  //��δ�ҵ�Ŀ��γ�
    }
}
void Management::StudentDeleteCourse(string &courseID)          //ѧ����ѡ�γ�
{
    int index = FindCourse(courseID,true);          //��ѯĿ��γ�
    if (index != -1)                                            //���ҵ�Ŀ��γ�
    {
        studentVI->Delete(courseID,true);           //��ѡĿ��γ�
    }
    else                                                        //��δ�ҵ�Ŀ��γ�
    {
        cout << "�˿γ̴���γ̲����ڣ�" << endl;
    }
}
void Management::AddCourse()                                    //����Ա��ӿγ�
{
    system("cls");                                  //����
    while (true)
    {
        Course tmpCourse;
        cout << "\n" << endl;
        cout << "����������γ̴��롢�γ����ơ�ѧʱ��ѧ�֡�����ѧ�ڡ�ѡ���������ޣ�����-1����"<<endl;
        cin >> tmpCourse;
        if(tmpCourse.GetID() != "-1")                           //�����벻Ϊ"-1"
        {
            courseMI = courseM.find(tmpCourse.GetID());         //��ѯĿ��γ�
            if (courseMI == courseM.end())                      //��δ�ҵ�Ŀ��γ�
            {
                courseV.push_back(tmpCourse);                   //���ص�Vector������
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));       //���뵽Map������
                _courseTotal++;                                 //���¿γ���Ŀ
                SortCourse();                                   //�Կγ������ڿγ̽�������
                cout << "�ɹ���ӿγ̣�" << endl;
            }
            else                                                //���ҵ�Ŀ��γ�
            {
                cout << "�˿γ̴���γ��Ѵ��ڣ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
        system("pause");                            //�������������
    }
}
void Management::DeleteCourse()                                 //����Աɾ���γ�
{
    string courseID;
    system("cls");                                  //����
    while(true)
    {
        cout << "\n" << endl;
        cout << "����Ҫɾ���Ŀγ̵Ŀγ̴���,����-1����" << endl;
        cin >> courseID;
        if(courseID != "-1")                                    //�����벻Ϊ"-1"
        {
            courseMI = courseM.find(courseID);                  //��ѯĿ��γ�
            if (courseMI != courseM.end())                      //���ҵ�Ŀ��γ�
            {
                for (int i = courseV[courseM[courseID]].GetStudentAmount(); i > 0; i--)     //����������ѡ�ÿ�ѧ��
                {
                    courseV[courseM[courseID]].Delete(courseV[courseM[courseID]].studentDV[i]._studentID);  //�ص���������ѡ�ÿ�ѧ����ѡ�ÿ�
                }
                courseV.erase(courseV.begin() + courseM[courseID]);                 //ɾ��vector��Ԫ��
                courseM.erase(studentMI);               //ɾ��map��Ԫ��
                SortCourse();                                   //��������
                _courseTotal = courseV.size();                  //���¿γ���Ŀ
                cout << "�ɹ�ɾ���γ̣�" << endl;
            }
            else                                                //��δ�ҵ�Ŀ��γ�
            {
                cout << "��¼Ϊ�գ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
    }
    system("pause");                                //�������������
}
void Management::EditCourse()                                   //����Ա�༭�γ�
{
    string courseID;
    Course tmpCourse;
    system("cls");                                      //����
    while(true)
    {
        cout << "\n" << endl;
        cout << "����Ҫ�޸ĵĿγ̵Ŀγ̴���,����-1����" << endl;
        cin >> courseID;
        if(courseID != "-1")                                    //�����벻Ϊ"-1"
        {
            courseMI = courseM.find(courseID);                  //��ѯĿ��γ�
            if (courseMI != courseM.end())                      //���ҵ�Ŀ��γ�
            {
                cout << "\n" << endl;
                cout << "�޸�ǰ����Ϣ��" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << courseV[courseM[courseID]] << endl;     //��ʾ�޸�ǰ��Ϣ
                ShowEditCoursePrompt();
                cin >> tmpCourse;
                if (FindCourse(tmpCourse.GetID(),true) == -1)   //��ѯ�Ƿ������ͬ�γ̴���γ�
                {
                    courseV[courseM[courseID]] = tmpCourse;     //���ҵ���ͬ�γ̴���γ�
                    cout << "\n" << endl;
                    cout << "�޸ĺ����Ϣ��" << endl;
                    cout << "*******************************************************************************************************"
                            "****************"  << endl;
                    cout << courseV[courseM[courseID]] << endl; //��ʾ�޸ĺ���Ϣ
                    SortCourse();                               //�Կγ������ڿγ̽�������
                    cout << "�ɹ��޸Ŀγ̣�" << endl;
                }
                else                                            //���ҵ���ͬ�γ̴���γ�
                {
                    cout << "�˿γ̴���γ��Ѵ��ڣ�" << endl;
                }
            }
            else                                                //��δ�ҵ�Ŀ��γ�
            {
                cout << "��¼Ϊ�գ�" << endl;
            }
        }
        else                                                    //����whileѭ��
        {
            break;
        }
        system("pause");                                //�������������
    }
}
int Management::FindCourse(string &courseData, int mode)        //����Ա��ѯ�γ�
{
    if (mode)                                                   //ģʽһ����ѯ�γ̴���
    {
        for(int i = 0;i < _courseTotal;i++)                     //����Course���Vector����
        {
            if(courseV[i].GetID() == courseData)
            {
                return i;                                       //����Ŀ��γ̵��±�
            }
        }
    }
    else                                                        //ģʽ������ѯ�γ���
    {
        for(int i=0;i<_courseTotal;i++)                         //����Course���Vector����
        {
            if(courseV[i].GetName() == courseData)
            {
                return i;                                       //����Ŀ��γ̵��±�
            }
        }
    }
    return -1;                                                  //��ѯʧ�ܣ�����-1
}
int& Management::TotalCourse()                                  //��ȡ�γ�����
{
    system("cls");                                  //����
    ShowTotalCoursePrompt();                                    //��ʾ�γ�������ʾ
    cout << _courseTotal << endl;                               //��ʾ�γ�����
    system("pause");                                  //�������������
    return _courseTotal;                                         //���ؿγ�����
}
void Management::PrintCourse()                                  //��ʾ���пγ���Ϣ
{
    system("cls");                                      //����
    ShowCourseDataHeader();                                     //��ʾ�γ��б��ͷ
    for (int i=0;i<_courseTotal;i++)                            //������ʾ�γ���Ϣ
    {
        cout << courseV[i] << endl;
    }
}
void Management::SaveCourse()                                   //����γ�����
{
    ofstream outfile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_course.txt",ios::out|ios::trunc);    //����д�뷽ʽ���ļ�
    if(outfile)                                                 //���ɹ���
    {
        for(int i = 0;i < _courseTotal;i++)                     //���ε���γ���Ϣ
        {
            outfile << courseV[i].GetID() << "\t" << courseV[i].GetName() << "\t" << courseV[i].GetPeriod() << "\t";
            outfile << courseV[i].GetCredit() << "\t" << courseV[i].GetSemester() << courseV[i].GetMaximum() << endl;
        }
        outfile << "-1" << endl;                                    //���������ʶ
        outfile.close();                                            //�ر��ļ�
        cout << "�γ����ݱ���ɹ���" << endl;
        system("pause");                                //�������������
        system("cls");                                  //����
    }
    else
    {
        cout << "open 3118002296_course.txt error!" <<endl;         //��ʾ������Ϣ
    }
}
void Management::LoadCourse()                                       //���ؿγ�����
{
    Course tmpCourse;
    ifstream infile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_course.txt",ios::in);                 //ֻ����ʽ���ļ�
    if(infile)                                                      //���ɹ���
    {
        system("cls");                                      //����
        courseV.clear();                                            //���Vector����
        cout << "\t" << setw(10) << "�γ̴���" << "\t" << setw(20) << "�γ�����" << "\t" << setw(4) << "ѧʱ";
        cout << "\t" << setw(4) << "ѧ��" << "\t" << setw(8) << "����ѧ��";
        cout << "\t" << setw(8) << "��������" << endl;              //��ʾ�γ����ݱ�ͷ
        while (infile >> tmpCourse)                                 //���ļ��в�������д�뻺����
        {
            if (tmpCourse.GetID() != "-1")                              //�ж��Ƿ��ȡ��������ʶ
            {
                tmpCourse.DisplayCourse();                          //��ʾ�Ѷ�������
                courseV.push_back(tmpCourse);                       //���뵽Vector������
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));               //����Map������
                _courseTotal++;                                     //���¿γ�����
                SortCourse();                                       //�Կγ������ڿγ̽�������
            }
            else                                                    //����ȡ��������ʶ
            {
                break;
            }
        }
        infile.close();                                             //�ر��ļ�
        cout << "\n" << endl;
        cout << "�γ����ݼ��سɹ���" << endl;
        system("pause");                                    //�������������
        system("cls");                                  //����
    }
    else
    {
        cout << "3118002296_course.txt �޷���!" <<endl;           //��ʾ������Ϣ
    }
}
void Management::SortCourse()                                           //�Կγ������ڿγ̽�������
{
    courseM.clear();                                                   //���map����
    sort(courseV.begin(), courseV.end(), CompCourse);               //��vector������Ԫ������
    for(int i=0;i<_courseTotal;i++)
    {
        courseM.insert(make_pair(courseV[i].GetID(), i));       //���β���mapԪ��
    }
}
bool Management::CompCourse(Course &cour1, Course &cour2)               //�Զ���Ƚϱ�׼
{
    bool index = (cour1.GetID() < cour2.GetID());                       //���ȽϿγ̴���
    return index;
}