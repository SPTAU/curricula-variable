//
// Created by MR on 2021/1/1.
//

#ifndef SYSTEMDESIGN_SHOW_H
#define SYSTEMDESIGN_SHOW_H

#include <iostream>

    void ShowMainMenu();                    //主菜单
    void ShowStudentLogInID();              //学生身份登录学号验证
    void ShowStudentLogInName();            //学生身份登录姓名验证
    void ShowManagementLogIn();             //管理员身份登录密码验证
    void ShowStudentMenu();                 //学生操作菜单
    void ShowStudentAddCourseMenu();        //选课菜单
    void ShowManagementMenu();              //管理员操作菜单
    void ShowManagementCourseMenu();        //管理课程菜单
    void ShowManagementStudentMenu();       //管理学生菜单
    void ShowFindCourseMenu();              //查询课程操作菜单
    void ShowFindStudentMenu();             //查询学生操作菜单
    void ShowCourseDataHeader();            //课程列表表头
    void ShowStudentDataHeader();           //学生列表表头
    void ShowCourseStudentHeader();         //选修课程学生列表表头
    void ShowStudentCourseHeader();         //学生选修课程列表表头
    void ShowStudentDataPrompt();           //显示学生个人信息提示
    void ShowCourseDataPrompt();            //显示选课课程信息提示
    void ShowFoundPrompt();                 //查询成功提示
    void ShowNotFoundPrompt();              //查询失败提示
    void ShowEditCoursePrompt();            //显示编辑课程提示
    void ShowEditStudentPrompt();           //显示编辑学生提示
    void ShowFindCourseIDPrompt();          //利用课程代码查询提示
    void ShowFindCourseNamePrompt();        //利用课程名称查询提示
    void ShowFindStudentIDPrompt();         //利用学生学号查询提示
    void ShowFindStudentNamePrompt();       //利用学生姓名查询提示
    void ShowFindCourseAgainPrompt();       //是否继续查询课程提示
    void ShowFindStudentAgainPrompt();      //是否继续查询学生提示
    void ShowAddCoursePrompt();             //利用课程代码添加课程提示
    void ShowAddCourseAgainPrompt();        //是否继续添加课程提示
    void ShowDeleteCoursePrompt();          //利用课程代码删除课程提示
    void ShowDeleteCourseAgainPrompt();     //是否继续删除课程提示
    void ShowPrintCourseStudentPrompt();    //显示课程选修学生信息提示
    void ShowPrintStudentCoursePrompt();    //显示学生选修课程信息提示
    void ShowTotalCoursePrompt();           //显示课程总数提示
    void ShowTotalStudentPrompt();          //显示学生总数提示
    void ShowExitPrompt();                  //退出程序保存数据提示


#endif //SYSTEMDESIGN_SHOW_H
