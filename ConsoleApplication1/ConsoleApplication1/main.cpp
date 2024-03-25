#include "Header.h"

int main()
{
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
                    checkStaffChoice();
                }
                else
                {
                    menuForStudent();
                    checkStudentChoice();
                }
            }
        }
        else
            cout << "Login failed. Please check your username and password and try again.\n";
    }
    return 0;
}