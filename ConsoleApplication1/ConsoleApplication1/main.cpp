#include "Header.h"

int main()
{
    YearNode *curYear = nullptr;
    ClassNode *curClass = nullptr;
    CourseNode *curCourse = nullptr;

    // Load data
    cout << ">>>>Welcome to course management system.\n";

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
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                    case 13:
                        break;
                    case 14:
                        break;
                    case 15:
                        viewProfileInfo(logged_in);
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