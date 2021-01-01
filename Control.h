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
    void Menu();
    void StudentLogIn();
    void StudentMenu();
    void StudentAddCourseMenu();
    bool StudentAddingCourse();
    void StudentDeletingCourse();
    void StudentPrintData();
    void ManagementLogIn();
    void ManagementMenu();
    void ManagementStudentMenu();
    void FindStudentMenu();
    void FindStudentID();
    void FindStudentName();
    void PrintStudentCourse();
    void ManagementCourseMenu();
    void FindCourseMenu();
    void FindCourseID();
    void FindCourseName();
    void PrintCourseStudent();
    void Save();
    void Load();
    bool Exit();
};


#endif //SYSTEMDESIGN_CONTROL_H
