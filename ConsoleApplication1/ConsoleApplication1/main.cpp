#include "Header.h"

int main()
{
    YearNode *curYear = nullptr;
    ClassNode *curClass = nullptr;
    CourseNode *curCourse = nullptr;

    // Load data
    cout << "Welcome to course management system.\n";

    UserNode *users = nullptr;
    ifstream fin("DataFile/Users.txt");
    if (fin.is_open())
    {
        importUserData(users, fin);
        fin.close();
    }
    else
    {
        cout << "Unable to load data user.\n";
        return 0;
    }
    // User log in
    UserNode *logged_in = nullptr;
    bool logout = false;
    while (continueProgram(logout))
    {
        if (login(users, logged_in))
        {
            cout << "Logged in successfully.\n";
            logout = false;
            while (logout == false && continueProgram(logout))
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
                        // createASchoolYear(YearNode*& Head, int& NumOfSchoolYear); //in Year.h
                        break;
                    case 2:
                        // addNewClass(ClassNode*& head); //in Class.h
                        break;
                    case 3:
                        // importClass(ClassNode*& head, ifstream& fin); //in Class.h
                        break;
                    case 4:
                        // createSemester(YearNode* year); //in Semester.h
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
                        // addStudentToCourse();
                        break;
                    case 9:
                        // removeStudentFromCourse();
                        break;
                    case 10:
                        // deleteACourse();
                        break;
                    case 11:
                        // viewAListOfClasses();
                        break;
                    case 12:
                        // viewAListOfStudentsInClass();
                        break;
                    case 13:
                        // viewListOfCourse();
                        break;
                    case 14:
                        break;
                    case 15:
                        break;
                    case 16:
                        break;
                    case 17:
                        break;
                    case 18:
                        break;
                    case 19:
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
                        break;
                    case 2:
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

    delete curYear;
    delete curCourse;
    delete curClass;
    return 0;
}