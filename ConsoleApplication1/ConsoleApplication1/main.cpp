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

    // Load Users
    UserNode *users = nullptr;

    importUserData(users, fin);

    // Load years
    importSchoolYearData(headYear, fin);

    // Load Class
    YearNode *yy = headYear;
    while (yy)
    {
        string direct = "DataFile/" + yy->data + "Classes.txt";
        fin.open(direct);
        if (fin.is_open())
        {
            importClassData(yy->classes, fin);
            fin.close();
        }
        else
        {
            cout << "Unable to load data.\n";
            return 0;
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
                    cin >> staffChoice;
                    switch (staffChoice)
                    {
                    case 1:
                        createASchoolYear(headYear, tailYear); // in Year.h
                        break;
                    case 2:
                        addNewClass(headYear);
                        break;
                    case 3:
                        // importClass(ClassNode*& head, ifstream& fin); //in Class.h //Import phía trên rồi
                        break;
                    case 4:
                        createSemester(headYear); //in Semester.h
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
                        // viewAListOfStudentsInClass(); //in Class.h
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
                        // changePassword(UserNode* &cur); //in User.h
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
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 23:
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction" << endl;
                        break;
                    }
                }
                else
                {
                    menuForStudent();
                    int studentChoice;
                    cin >> studentChoice;
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
                        // changePassword(UserNode* &cur); //in User.h
                        break;
                    case 5:
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction" << endl;
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

    deAllocateDataYear(headYear);
    delete curCourse;
    delete curClass;
    return 0;
}