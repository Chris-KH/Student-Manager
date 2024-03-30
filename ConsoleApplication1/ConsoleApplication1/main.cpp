﻿#include "Header.h"

int main()
{
    ifstream fin;
    ofstream fout;
    YearNode *headYear = nullptr;
    ClassNode *headClass = nullptr;
    CourseNode *headCourse = nullptr;
    YearNode *tailYear = nullptr;
    ClassNode *curClass = nullptr;
    CourseNode *curCourse = nullptr;

    // Load data

    /*
    fin.open("ImportExportFile/ClassData.txt");
    if (fin.is_open())
        importClassData(headClass, curClass, fin);
    else cout << "Unable to load class data.\n";
    fin.close();
    */

    cout << ">>>>Welcome to course management system.\n";

    cout << "Load users data...\n";
    UserNode *users = nullptr;

    importUserData(users, fin);

    cout << "Load school years data...\n";
    importSchoolYearData(headYear, tailYear, fin);

    cout << "Load classes data...\n";
    YearNode *yy = headYear;
    while (yy)
    {
        string direct = "DataFile/" + yy->data + "Classes.txt";
        fin.open(direct);
        ClassNode* tail = nullptr;
        if (fin.is_open())
        {
            importClassData(yy->classes, tail, fin);
            fin.close();
        }
        else
        {
            cout << "Unable to load data.\n";
            exit(1);
        }
        yy = yy->pNext;
    }

    cout << "Load students in class...\n";
    yy = headYear;
    while (yy) {
        ClassNode* temp = yy->classes;
        while (temp) 
        {
            string direct = "DataFile/" + temp->data.name + ".csv";
            fin.open(direct);
            if (fin.good()) {
                importStudentToClass(temp->student, fin);
                fin.close();
            }
            else {
                cout << "Unable to load data.\n";
                exit(1);
            }
            temp = temp->pNext;
        }
        yy = yy->pNext;
    }

    // User log in
    UserNode *logged_in = nullptr;
    bool exit = false;
    
    while (exit == false && continueProgram())
    {
        if (login(users, logged_in))
        {
            cout << ">>>Logged in successfully<<<\n";
            bool logout = false; // haven't logged out

            while (exit == false && logout == false && continueProgram())
            {
                // Output Menu
                if (logged_in->data.is_staff)
                {
                    menuForStaff();
                    int staffChoice;
                    while (!(cin >> staffChoice)) {
                        cout << ">>>>Wrong input. Staff choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (staffChoice)
                    {
                    case 1:
                        //Tương tự case 3
                        fout.open("DataFile/SchoolYear.txt");
                        if (fout.is_open()) {
                            createASchoolYear(headYear, tailYear);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else cout << "Create school year failed.\n";
                        break;
                    case 2:
                        //Add class thì sau đó phải tạo một file csv tương ứng lớp đó
                        addNewClass(headYear, fout);
                        break;
                    case 3:
                        //Tạo một school year mới thì phải export ngay luôn dể nếu tạo thêm một năm khác nữa thì có thể check xem đã tạo năm đó chưa
                        fout.open("DataFile/SchoolYear.txt");
                        if (fout.is_open()) {
                            createSemester(headYear);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else cout << "Create semester failed.\n";
                        break;
                    case 4:
                       
                        break;
                    case 5:
                        // addCourse();
                        break;
                    case 6:
                        // viewListOfCourse(CourseNode* head); //choose year -> semester //in Course.h
                        break;
                    case 7:
                        // updateCourseIn4(CourseNode* head, string course_id); //in Course.h
                        break;
                    case 8:
                        // addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student); //in Course.h
                        break;
                    case 9:
                        // removeStudentFromCourse(CourseNode* head, string course_id, string student_id); //in Course.h
                        break;
                    case 10:
                        // deleteACourse(CourseNode* head, string course_id); in Course.h
                        break;
                    case 11:
                        viewAListOfClasses(headYear);
                        break;
                    case 12:
                        viewListOfStudentInClass(headYear); //in Class.h
                        break;
                    case 13:
                        // void viewListofCourse(CourseNode* course); //in Course.h
                        break;
                    case 14:
                        // viewListOfStudentInCourse(CourseNode* head, string course_id); //in Course.h
                        break;
                    case 15:
                        viewProfileInfo(logged_in);
                        break;
                    case 16:
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open()) {
                            changePassword(logged_in);
                            exportUserData(users, fout);
                            fout.close();
                        }
                        else {
                            cout << "Change password failed.\n";
                        }
                        break;
                    case 17:
                        // ExportListOfStudentInCourse(ofstream& fout, CourseNode* head, string course_id, string sy_name); //in Course.h
                        break;
                    case 18:
                        // importScoreboard(ifstream& fin, CourseNode*& head, int semester, int year); //in Course.h
                        break;
                    case 19:
                        // ViewTheScoreboardOfCourse(CourseNode* head, string course_id); //in Course.h
                        break;
                    case 20:
                        // updateAStudentResult(); //in Student.h
                        break;
                    case 21:
                        // viewScoreboardOfClass(); //in Class.h
                        break;
                    case 22:
                        //Export class
                        yy = headYear;
                        while (yy) {
                            string direct = "DataFile/" + yy->data + "Classes.txt";
                            fout.open(direct);
                            if (fout.is_open()) {
                                exportClassData(yy->classes, fout);
                                fout.close();
                            }
                            else {
                                cout << "File is not open. Export failed.\n";
                                break;
                            }
                            yy = yy->pNext;
                        }
                        cout << "Export classes successfully.\n";
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
                    cin >> studentChoice;
                    while (!(cin >> studentChoice)) {
                        cout << ">>>>Wrong input. Student choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (studentChoice)
                    {
                    case 1:
                        // viewStudentCourse(string student_id, CourseNode* head); //in Course.h
                        break;
                    case 2:
                        // viewStudentScoreboard(string student_id, CourseNode* head); //in Course.h
                        break;
                    case 3:
                        viewProfileInfo(logged_in);
                        break;
                    case 4:
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open()) {
                            changePassword(logged_in);
                            exportUserData(users, fout);
                            fout.close();
                        }
                        else {
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
    fin.close();
    fout.open("ImportExportFile/ClassData.txt");
    if (fout.is_open())
        exportClassData(headClass, fout);
    else
        cout << "Unable to export class data.\n";
    fout.close();

    delete curCourse;
    delete curClass;
    return 0;
}