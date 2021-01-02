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

void Management::AddStudent()                                   //管理员添加课程
{
    system("cls");                                      //清屏
    while (true)
    {
        Student tmpStudent;
        cout << "\n" << endl;
        cout << "请依次输入学号、姓名、性别、年龄、系别、班级、联系方式，输入-1结束"<<endl;
        cin >> tmpStudent;
        if(tmpStudent.GetID() != "-1")                          //若输入不为"-1"
        {
            studentMI = studentM.find(tmpStudent.GetID());      //查询目标学生
            if (studentMI == studentM.end())                    //若未找到目标学生
            {
                studentV.push_back(tmpStudent);                 //加载到Vector容器中
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));        //插入到Map容器中
                _studentTotal++;                                //更新学生数目
                SortStudent();                                  //对学生容器内学生进行排序
                cout << "成功添加学生！" << endl;
            }
            else                                                //若找到目标学生
            {
                cout << "此学号学生已存在！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
        system("pause");                                //输入任意键继续
    }
}
void Management::DeleteStudent()                                //管理员删除学生
{
    string studentID;
    system("cls");                                      //清屏
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要删除的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID != "-1")                                   //若输入不为"-1"
        {
            studentMI = studentM.find(studentID);               //查询目标课程
            if (studentMI != studentM.end())                    //若找到目标课程
            {
                studentV.erase(studentV.begin() + studentM[studentID]);     //删除vector中元素
                studentM.erase(studentMI);              //删除map中元素
                _studentTotal = studentV.size();                //更新选课数目
                SortStudent();                                  //容器排序
                cout << "成功删除学生！" << endl;
            }
            else                                                //若未找到目标课程
            {
                cout << "记录为空！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
        system("pause");                                //输入任意键继续
    }
}
void Management::EditStudent()                                  //管理员编辑学生
{
    string studentID;
    Student tmpStudent;
    system("cls");                                      //清屏
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要修改的学生的学号,输入-1结束" << endl;
        cin >> studentID;
        if(studentID != "-1")                                   //若输入不为"-1"
        {
            studentMI = studentM.find(studentID);               //查询目标学生
            if (studentMI == studentM.end())                    //若找到目标学生
            {
                cout << "\n" << endl;
                cout << "修改前的信息：" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << studentV[studentM[studentID]] << endl;
                ShowEditStudentPrompt();
                cin >> tmpStudent;
                if (FindCourse(tmpStudent.GetID(),true) == -1)      //查询是否存在相同学号学生
                {
                    studentV[studentM[studentID]] = tmpStudent; //若找到相同学号学生
                    cout << "\n" << endl;
                    cout << "修改后的信息：" << endl;
                    cout << "*******************************************************************************************************"
                            "****************"  << endl;
                    cout << studentV[studentM[studentID]] << endl;          //显示修改后信息
                    SortStudent();                              //对学生容器内学生进行排序
                    cout << "成功修改学生！" << endl;
                }
                else                                            //若找到相同学号学生
                {
                    cout << "此学号学生已存在！" << endl;
                }
            }
            else                                                //若未找到目标学生
            {
                cout << "记录为空！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
    }
    system("pause");                                    //输入任意键继续
}
int Management::FindStudent(string &studentData, int mode)      //管理员查询学生
{
    if (mode)                                                   //模式一：查询学号
    {
        for(int i = 0;i < _studentTotal;i++)                    //遍历Course类的Vector容器
        {
            if(studentV[i].GetID() == studentData)
            {
                return i;                                       //返回目标课程的下标
            }
        }
    }
    else                                                        //模式二：查询姓名
    {
        for(int i = 0;i < _studentTotal;i++)                    //遍历Course类的Vector容器
        {
            if(studentV[i].GetName() == studentData)
            {
                return i;                                       //返回目标课程的下标
            }
        }
    }
    return -1;                                                  //查询失败，返回-1
}
int& Management::TotalStudent()                                 //获取学生总数
{
    system("cls");                                      //清屏
    ShowTotalStudentPrompt();                                   //显示学生总数提示
    cout << _studentTotal << endl;                              //显示学生总数
    system("pause");                                    //输入任意键继续
    return _studentTotal;                                       //返回学生总数
}
void Management::PrintStudent()                                 //显示所有学生信息
{
    system("cls");                                      //清屏
    ShowStudentDataHeader();                                    //显示学生列表表头
    for (int i=0;i<_studentTotal;i++)                           //依次显示学生信息
    {
        cout << studentV[i] << endl;
    }
}
void Management::SaveStudent()                                  //保存学生数据
{
    ofstream outfile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_student.txt",ios::out|ios::trunc);       //覆盖写入方式打开文件
    if(outfile)                                                 //若成功打开
    {
        for(int i = 0;i < _studentTotal;i++)                    //依次导入学生信息
        {
            outfile << studentV[i].GetID() << "\t" << studentV[i].GetName() << "\t" << studentV[i].GetGender() << "\t";
            outfile << studentV[i].GetAge() << "\t" << studentV[i].GetDepartment() << studentV[i].GetClass() << "\t";
            outfile << studentV[i].GetPhoneNumber() << "\t" << studentV[i].GetCourseAmount() << endl;
            for(int j = 0;j<studentV[i].GetCourseAmount();j++)
            {
                outfile << studentV[i].GetCourseID(j) << endl;
            }
        }
        outfile << "-1" << endl;                                //输入结束标识
        outfile.close();                                        //关闭文件
        cout << "学生数据保存成功！" << endl;
        system("pause");                                //输入任意键继续
        system("cls");                                  //清屏
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;    //提示错误信息
    }
}
void Management::LoadStudent()                                  //加载学生数据
{
    int tmpCourseAmount;
    string tmpCourseID;
    Student tmpStudent;
    ifstream infile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_student.txt",ios::in);                //只读方式打开文件
    if(infile)
    {
        studentV.clear();                                       //清空Vector容器
        cout << "\t" << setw(10) << "学号" << "\t" << setw(8) << "姓名" << "\t" << setw(4) << "性别";
        cout << "\t" << setw(4) << "年龄" << "\t" << setw(20) << "系别";
        cout << "\t" << setw(20) << "班级"<< "\t" << setw(11) << "联系方式"  << endl;
        while(infile >> tmpStudent)                             //将文件中部分数据写入缓存区
        {
            if(tmpStudent.GetID() != "-1")                      //判断是否读取到结束标识
            {
                int courseAmount = 0;
                stringstream stream;
                infile >> tmpCourseAmount;
                stream << tmpCourseAmount;                      //String to Int转换
                stream >> courseAmount;
                for (int i=0;i < courseAmount; i++)             //判断学生已选课程数目
                {
                    tmpStudent.SetCourseAmount(i+1);        //
                    infile >> tmpCourseID;
                    tmpStudent.Add(courseV[courseM[tmpCourseID]], false);
                }
                tmpStudent.DisplayStudent();                    //显示已读入数据
                studentV.push_back(tmpStudent);                 //载入到Vector容器中
                studentM.insert(make_pair(tmpStudent.GetID(), studentV.size() - 1));        //载入Map容器中
                _studentTotal++;                                //更新学生总数
                SortStudent();                                  //对课程容器内课程进行排序
            }
            else                                                //若读取到结束标识
            {
                break;
            }
        }
        infile.close();                                         //关闭文件
        cout << "学生数据加载成功！" << endl;
        system("pause");                              //输入任意键继续
        system("cls");                              //清屏
    }
    else
    {
        cout << "open 3118002296_student.txt error!" <<endl;    //提示错误信息
    }
}
void Management::SortStudent()                                  //对学生容器内学生进行排序
{
    studentM.clear();                                                           //清空map容器
    sort(studentV.begin(), studentV.end(), CompStudent);            //对vector容器内元素排序
    for(int i=0;i<_studentTotal;i++)
    {
        studentM.insert(make_pair(studentV[i].GetID(), i));             //依次插入map元素
    }
}
bool Management::CompStudent(Student &stu1, Student &stu2)      //自定义比较标准
{
    bool index = (stu1.GetID() < stu2.GetID());                 //仅比较学生学号
    return index;
}
void Management::StudentAddCourse(string &courseID)             //学生选修课程
{
    int index = FindCourse(courseID,true);          //查询目标课程
    if (index != -1)                                            //若找到目标课程
    {
        studentVI->Add(courseV[courseM[courseID]],true);            //选修目标课程
    }
    else
    {
        cout << "此课程代码课程不存在！" << endl;                  //若未找到目标课程
    }
}
void Management::StudentDeleteCourse(string &courseID)          //学生退选课程
{
    int index = FindCourse(courseID,true);          //查询目标课程
    if (index != -1)                                            //若找到目标课程
    {
        studentVI->Delete(courseID,true);           //退选目标课程
    }
    else                                                        //若未找到目标课程
    {
        cout << "此课程代码课程不存在！" << endl;
    }
}
void Management::AddCourse()                                    //管理员添加课程
{
    system("cls");                                  //清屏
    while (true)
    {
        Course tmpCourse;
        cout << "\n" << endl;
        cout << "请依次输入课程代码、课程名称、学时、学分、开课学期、选修人数上限，输入-1结束"<<endl;
        cin >> tmpCourse;
        if(tmpCourse.GetID() != "-1")                           //若输入不为"-1"
        {
            courseMI = courseM.find(tmpCourse.GetID());         //查询目标课程
            if (courseMI == courseM.end())                      //若未找到目标课程
            {
                courseV.push_back(tmpCourse);                   //加载到Vector容器中
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));       //插入到Map容器中
                _courseTotal++;                                 //更新课程数目
                SortCourse();                                   //对课程容器内课程进行排序
                cout << "成功添加课程！" << endl;
            }
            else                                                //若找到目标课程
            {
                cout << "此课程代码课程已存在！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
        system("pause");                            //输入任意键继续
    }
}
void Management::DeleteCourse()                                 //管理员删除课程
{
    string courseID;
    system("cls");                                  //清屏
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要删除的课程的课程代码,输入-1结束" << endl;
        cin >> courseID;
        if(courseID != "-1")                                    //若输入不为"-1"
        {
            courseMI = courseM.find(courseID);                  //查询目标课程
            if (courseMI != courseM.end())                      //若找到目标课程
            {
                for (int i = courseV[courseM[courseID]].GetStudentAmount(); i > 0; i--)     //遍历所有已选该课学生
                {
                    courseV[courseM[courseID]].Delete(courseV[courseM[courseID]].studentDV[i]._studentID);  //回调函数令已选该课学生退选该课
                }
                courseV.erase(courseV.begin() + courseM[courseID]);                 //删除vector中元素
                courseM.erase(studentMI);               //删除map中元素
                SortCourse();                                   //容器排序
                _courseTotal = courseV.size();                  //更新课程数目
                cout << "成功删除课程！" << endl;
            }
            else                                                //若未找到目标课程
            {
                cout << "记录为空！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
    }
    system("pause");                                //输入任意键继续
}
void Management::EditCourse()                                   //管理员编辑课程
{
    string courseID;
    Course tmpCourse;
    system("cls");                                      //清屏
    while(true)
    {
        cout << "\n" << endl;
        cout << "输入要修改的课程的课程代码,输入-1结束" << endl;
        cin >> courseID;
        if(courseID != "-1")                                    //若输入不为"-1"
        {
            courseMI = courseM.find(courseID);                  //查询目标课程
            if (courseMI != courseM.end())                      //若找到目标课程
            {
                cout << "\n" << endl;
                cout << "修改前的信息：" << endl;
                cout << "*******************************************************************************************************"
                        "****************"  << endl;
                cout << courseV[courseM[courseID]] << endl;     //显示修改前信息
                ShowEditCoursePrompt();
                cin >> tmpCourse;
                if (FindCourse(tmpCourse.GetID(),true) == -1)   //查询是否存在相同课程代码课程
                {
                    courseV[courseM[courseID]] = tmpCourse;     //若找到相同课程代码课程
                    cout << "\n" << endl;
                    cout << "修改后的信息：" << endl;
                    cout << "*******************************************************************************************************"
                            "****************"  << endl;
                    cout << courseV[courseM[courseID]] << endl; //显示修改后信息
                    SortCourse();                               //对课程容器内课程进行排序
                    cout << "成功修改课程！" << endl;
                }
                else                                            //若找到相同课程代码课程
                {
                    cout << "此课程代码课程已存在！" << endl;
                }
            }
            else                                                //若未找到目标课程
            {
                cout << "记录为空！" << endl;
            }
        }
        else                                                    //跳出while循环
        {
            break;
        }
        system("pause");                                //输入任意键继续
    }
}
int Management::FindCourse(string &courseData, int mode)        //管理员查询课程
{
    if (mode)                                                   //模式一：查询课程代码
    {
        for(int i = 0;i < _courseTotal;i++)                     //遍历Course类的Vector容器
        {
            if(courseV[i].GetID() == courseData)
            {
                return i;                                       //返回目标课程的下标
            }
        }
    }
    else                                                        //模式二：查询课程名
    {
        for(int i=0;i<_courseTotal;i++)                         //遍历Course类的Vector容器
        {
            if(courseV[i].GetName() == courseData)
            {
                return i;                                       //返回目标课程的下标
            }
        }
    }
    return -1;                                                  //查询失败，返回-1
}
int& Management::TotalCourse()                                  //获取课程总数
{
    system("cls");                                  //清屏
    ShowTotalCoursePrompt();                                    //显示课程总数提示
    cout << _courseTotal << endl;                               //显示课程总数
    system("pause");                                  //输入任意键继续
    return _courseTotal;                                         //返回课程总数
}
void Management::PrintCourse()                                  //显示所有课程信息
{
    system("cls");                                      //清屏
    ShowCourseDataHeader();                                     //显示课程列表表头
    for (int i=0;i<_courseTotal;i++)                            //依次显示课程信息
    {
        cout << courseV[i] << endl;
    }
}
void Management::SaveCourse()                                   //保存课程数据
{
    ofstream outfile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_course.txt",ios::out|ios::trunc);    //覆盖写入方式打开文件
    if(outfile)                                                 //若成功打开
    {
        for(int i = 0;i < _courseTotal;i++)                     //依次导入课程信息
        {
            outfile << courseV[i].GetID() << "\t" << courseV[i].GetName() << "\t" << courseV[i].GetPeriod() << "\t";
            outfile << courseV[i].GetCredit() << "\t" << courseV[i].GetSemester() << courseV[i].GetMaximum() << endl;
        }
        outfile << "-1" << endl;                                    //输入结束标识
        outfile.close();                                            //关闭文件
        cout << "课程数据保存成功！" << endl;
        system("pause");                                //输入任意键继续
        system("cls");                                  //清屏
    }
    else
    {
        cout << "open 3118002296_course.txt error!" <<endl;         //提示错误信息
    }
}
void Management::LoadCourse()                                       //加载课程数据
{
    Course tmpCourse;
    ifstream infile("F:\\Data\\Program\\CPP\\SystemDesign\\3118002296_course.txt",ios::in);                 //只读方式打开文件
    if(infile)                                                      //若成功打开
    {
        system("cls");                                      //清屏
        courseV.clear();                                            //清空Vector容器
        cout << "\t" << setw(10) << "课程代码" << "\t" << setw(20) << "课程名称" << "\t" << setw(4) << "学时";
        cout << "\t" << setw(4) << "学分" << "\t" << setw(8) << "开课学期";
        cout << "\t" << setw(8) << "人数上限" << endl;              //显示课程数据表头
        while (infile >> tmpCourse)                                 //将文件中部分数据写入缓存区
        {
            if (tmpCourse.GetID() != "-1")                              //判断是否读取到结束标识
            {
                tmpCourse.DisplayCourse();                          //显示已读入数据
                courseV.push_back(tmpCourse);                       //载入到Vector容器中
                courseM.insert(make_pair(tmpCourse.GetID(), courseV.size() - 1));               //载入Map容器中
                _courseTotal++;                                     //更新课程总数
                SortCourse();                                       //对课程容器内课程进行排序
            }
            else                                                    //若读取到结束标识
            {
                break;
            }
        }
        infile.close();                                             //关闭文件
        cout << "\n" << endl;
        cout << "课程数据加载成功！" << endl;
        system("pause");                                    //输入任意键继续
        system("cls");                                  //清屏
    }
    else
    {
        cout << "3118002296_course.txt 无法打开!" <<endl;           //提示错误信息
    }
}
void Management::SortCourse()                                           //对课程容器内课程进行排序
{
    courseM.clear();                                                   //清空map容器
    sort(courseV.begin(), courseV.end(), CompCourse);               //对vector容器内元素排序
    for(int i=0;i<_courseTotal;i++)
    {
        courseM.insert(make_pair(courseV[i].GetID(), i));       //依次插入map元素
    }
}
bool Management::CompCourse(Course &cour1, Course &cour2)               //自定义比较标准
{
    bool index = (cour1.GetID() < cour2.GetID());                       //仅比较课程代码
    return index;
}