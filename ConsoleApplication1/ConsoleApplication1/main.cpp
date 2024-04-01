#include "Header.h"

int main()
{
    ifstream fin;
    ofstream fout;
    YearNode *headYear = nullptr;
    ClassNode *headClass = nullptr;
    CourseNode *headCourse = nullptr;
    YearNode *tailYear = nullptr;
    ClassNode *curClass = nullptr;
    SemesterInfo *curSes = nullptr;
    CourseNode *curCourse = nullptr;
    bool exit = false;

    // Load data

    /*
    fin.open("ImportExportFile/ClassData.txt");
    if (fin.is_open())
        importClassData(headClass, curClass, fin);
    else cout << "Unable to load class data.\n";
    fin.close();
    */

    cout << ">>>>Welcome to course management system.\n";

    cout << "<>Load users data...";
    UserNode *users = nullptr;

    fin.open("DataFile/Users.txt");
    if (fin.is_open())
    {
        importUserData(users, fin);
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

    bool ok = false;
    cout << "<>Load students in class...";
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
                ok = true;
            }
            temp = temp->pNext;
        }
        yy = yy->pNext;
    }
    if (ok)
        cout << "Failed.\n";
    else
        cout << "Successful.\n";

    exit = !(ok == false && exit == false);
    // User log in
    UserNode *logged_in = nullptr;

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
                            createSemester(headYear, curSes);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else
                            cout << "Create semester failed.\n";
                        break;
                    case 4:
                        addNewStudentToClass(headYear, fin);
                        break;
                    case 5:
                        addCourse(curSes, curCourse);
                        break;
                    case 6:
                        viewListOfCourse(headCourse); //choose year -> semester //in Course.h
                        break;
                    case 7:
                        // updateCourseInfo(CourseNode* head, string course_id); //in Course.h
                        break;
                    case 8:
                        // addStudentToCourse(CourseNode* head, string course_id, StudentNode* new_student); //in Course.h
                        break;
                    case 9:
                        removeStudentFromCourse(curSes->course, "", "");
                        break;
                    case 10:
                        // deleteACourse(CourseNode* head, string course_id); in Course.h
                        break;
                    case 11:
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
                    case 12:
                        viewListOfStudentInClass(headYear); // in Class.h
                        break;
                    case 13:
                        viewListOfCourse(curSes->course);
                        break;
                    case 14:
                        viewListOfStudentInCourse(curSes->course, "");
                        break;
                    case 15:
                        viewProfileInfo(logged_in);
                        break;
                    case 16:
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open())
                        {
                            changePassword(logged_in);
                            exportUserData(users, fout);
                            fout.close();
                        }
                        else
                        {
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
                        // Export class
                        yy = headYear;
                        while (yy)
                        {
                            string direct = "DataFile/" + yy->data + "Classes.txt";
                            fout.open(direct);
                            if (fout.is_open())
                            {
                                exportClassData(yy->classes, fout);
                                fout.close();
                            }
                            else
                            {
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
                    while (!(cin >> studentChoice))
                    {
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
                        if (fout.is_open())
                        {
                            changePassword(logged_in);
                            exportUserData(users, fout);
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
    /*
    fout.open("ImportExportFile/ClassData.txt");
    if (fout.is_open())
        exportClassData(headClass, fout);
    else
        cout << "Unable to export class data.\n";
    fout.close();
    */
    delete curCourse;
    delete curClass;
    return 0;
}