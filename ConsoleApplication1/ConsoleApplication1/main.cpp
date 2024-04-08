﻿#include "Header.h"

int main()
{
    ifstream fin;
    ofstream fout;
    YearNode *headYear = nullptr;
    YearNode* curYear = nullptr;
    ClassNode *headClass = nullptr;
    CourseNode *headCourse = nullptr;
    YearNode *tailYear = nullptr;
    ClassNode *curClass = nullptr;
    SemesterInfo *curSes = nullptr;
    CourseNode *curCourse = nullptr;
    bool exit = false;

    // Load data

    cout << ">>>>Welcome to course management system.\n";

    cout << "<>Load users data...";
    UserNode *headUser = nullptr;
    UserNode *taillUser = nullptr;
    
    fin.open("DataFile/Users.txt");
    if (fin.is_open())
    {
        importUserData(headUser, taillUser, fin);
        cout << "Successful.\n";
        fin.close();
    }
    else
    {
        cout << "Failed.\n";
        exit = true;
    }

    cout << "<>Load school years data...";
    fin.open("DataFile/SchoolYear.txt");
    if (fin.is_open())
    {
        importSchoolYearData(headYear, tailYear, fin);
        cout << "Succesful.\n";
        fin.close();
    }
    else
    {
        cout << "Failed.\n";
        exit = true;
        ;
    }

    cout << "<>Load classes data...";
    YearNode *yy = headYear;
    while (yy)
    {
        string direct = "DataFile/" + yy->data + "Classes.txt";
        fin.open(direct);
        ClassNode *tail = nullptr;
        if (fin.is_open())
        {
            importClassData(yy->classes, tail, fin);
            fin.close();
        }
        else
        {
            exit = true;
        }
        yy = yy->pNext;
    }
    if (exit)
        cout << "Failed.\n";
    else
        cout << "Successful.\n";

    bool ok1 = false;
    cout << "<>Load students to class...";
    yy = headYear;
    while (yy)
    {
        ClassNode *temp = yy->classes;
        while (temp)
        {
            string direct = "DataFile/" + temp->data.name + ".csv";
            fin.open(direct);
            if (fin.good())
            {
                importStudentToClass(temp->student, fin);
                fin.close();
            }
            else
            {
                ok1 = true;
            }
            temp = temp->pNext;
        }
        yy = yy->pNext;
    }
    if (ok1) cout << "Failed.\n";
    else cout << "Successful.\n";

    cout << "<>Load course to semester...";
    yy = headYear;
    bool ok2 = false;
    while (yy) {
        importCourseToSemester(yy, fin, ok2);
        yy = yy->pNext;
    }
    if (ok2) cout << "Failed.\n";
    else cout << "Successful.\n";

    exit = !(ok1 == false && exit == false && ok2 == false);
    // User log in
    UserNode *logged_in = nullptr;
    while (exit == false && continueProgram(1))
    {
        system("cls");
        if (login(headUser, logged_in))
        {
            cout << ">>>Logged in successfully<<<\n";
            bool logout = false; // haven't logged out

            while (exit == false && logout == false && continueProgram(2))
            {
                // Output Menu
                if (logged_in->data.is_staff)
                {
                    menuForStaff();
                    int staffChoice;
                    while (!(cin >> staffChoice))
                    {
                        cout << ">>>>Wrong input. Staff choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (staffChoice)
                    {
                    case 1:
                        // Tương tự case 3
                        fout.open("DataFile/SchoolYear.txt");
                        if (fout.is_open())
                        {
                            createASchoolYear(headYear, tailYear);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else
                            cout << "Create school year failed.\n";
                        break;
                    case 2:
                        // Add class thì sau đó phải tạo một file csv tương ứng lớp đó
                        addNewClass(headYear, fout);
                        break;
                    case 3:
                        // Phải mở đc file và export đc thì mới tạo thành công do nếu để export ở cuối chương trình nếu có bug ở chỗ mở file thì coi như mấy cái mình add là vô nghĩa vì k export đc
                        fout.open("DataFile/SchoolYear.txt");
                        if (fout.is_open())
                        {
                            createSemester(headYear);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else
                            cout << "Create semester failed.\n";
                        break;
                    case 4:
                        curSes = chooseASemester(headYear, curYear);
                        break;
                    case 5:
                        addNewStudentToClass(taillUser, headYear, fin);
                        break;
                    case 6:
                        if (curYear && curSes) {
                            addCourse(curYear, curSes, fout);
                        } else cout << "Please choose semester first (option 4).\n";
                        break;
                    case 7:
                        if (curYear && curSes) {
                            if (curSes->course)
                                viewListOfCourse(curSes->course);
                            else cout << "There is no course in this semester.\n";
                        }
                        else cout << "Please choose semester first.\n";
                        break;
                    case 8:
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes);
                            if (curCourse)
                            {
                                updateCourseIn4(curCourse);
                                exportCourseToSemester(curYear, curSes, fout);
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "No data" << endl;
                        break;
                    case 9:
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes);
                            if (curCourse)
                            {
                                addStudentToCourse(curCourse);
                                exportStudentToCourse(curYear, curCourse, fout);
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "No data" << endl;
                        break;
                    case 10:
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes);
                            if (curCourse) {
                                removeStudentFromCourse(curCourse);
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Please choose semester first.\n";
                        break;
                    case 11:
                        if (curYear && curSes) {
                            deleteACourse(curSes);
                        }
                        else cout << "Please choose semester first.\n";
                        break;
                    case 12:
                        int choice;
                        cout << "   1.View all classes.\n";
                        cout << "   2.View classes in a school year.\n";
                        cout << ">>>Your choice: "; cin >> choice;
                        if (choice == 1) {
                            viewAllClasses(headYear);
                        }
                        else if (choice == 2) {
                            viewAListOfClasses(headYear);
                        }
                        else cout << "Wrong option!!!\n";
                        break;
                    case 13:
                        viewListOfStudentInClass(headYear); 
                        break;
                    case 14:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear) {
                            cout << "List of courses in semester " << curSes->order << "of school year " << curYear->data << ":\n";
                            viewListOfCourse(curSes->course);
                        }
                        else cout << "Wrong.\n";
                        break;
                    case 15:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear) {
                            viewListOfStudentInCourse(curSes->course, "");
                        }
                        break;
                    case 16:
                        viewProfileInfo(logged_in);
                        break;
                    case 17:
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open())
                        {
                            changePassword(logged_in);
                            exportUserData(headUser, fout);
                            fout.close();
                        }
                        else
                        {
                            cout << "Change password failed.\n";
                        }
                        break;
                    case 18:
                        if(fout.is_open())
                        {
                            curSes = chooseASemester(headYear, curYear);
                            if (curSes && curYear)
                            {
                                curCourse = findCourse(curSes);
                                exportListofStudentinCourse(fout, curCourse, curCourse->data.ID, curCourse->data.course_name);
                            }
                            break;
                        }
                        else
                        {
                            cout << "Open failed. Please make sure you choose the right file\n";
                            break;
                        }
                    case 19:
                        //importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year); //in Course.h
                        break;
                    case 20:
                        /*YearNode * year = nullptr;
                        if (findSchoolYear(year))
                        {
                            SemesterInfo* ses = chooseASemester(headYear, year);
                            if (ses)
                            {
                                CourseNode* course = findCourse(ses);
                                // ViewTheScoreboardOfCourse(CourseNode* head, string course_id); 
                                //đang viết trong course.cpp
                            }
                        }*/
                        break;
                    case 21:
                        // updateAStudentResult(); //in Student.h
                        break;
                    case 22:
                        fout.open("DataFile/Class.txt");
                        if (fout.is_open()) viewScoreboardofClass(headClass);
                        else cout << "Wrong\n";
                        break;
                    case 23:
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 24:
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
                else
                {
                    menuForStudent();
                    int studentChoice;
                    while (!(cin >> studentChoice))
                    {
                        cout << ">>>>Wrong input. Student choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (studentChoice)
                    {
                    case 1:
                        // viewStudentCourse(string student_id, CourseNode* head); //đang code ở course.cpp
                        break;
                    case 2:
                        // viewStudentScoreboard(string student_id, CourseNode* head); //đang code ở course.cpp
                        break;
                    case 3:
                        viewProfileInfo(logged_in);
                        break;
                    case 4:
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open())
                        {
                            changePassword(logged_in);
                            exportUserData(headUser, fout);
                            fout.close();
                        }
                        else
                        {
                            cout << "Change password failed.\n";
                        }
                        break;
                    case 5:
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 6:
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
            }
        }
        else
            cout << "Login failed. Please check your username and password and try again.\n";
    }

    //Delete users
    deleteUserData(headUser);

    //Delete student in class
    //Delete classes
    yy = headYear;
    while (yy) {
        deAlocatedClassesData(yy->classes);
        yy = yy->pNext;
    }
    yy = headYear;

    // Delete student in course
    // Delete courses in semester
    // Delete semester in year
    // Delete year
    deAllocateDataYear(headYear);
    return 0;
}