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
    while (continueProgram())
    {
        if (login(users, logged_in))
        {
            cout << "Logged in successfully.\n";
            while (continueProgram())
            {
                // Output Menu
                int choice;
                if (logged_in->data.is_staff)
                {
                    menuForStaff();
                    cin >> choice;
                    staffChoice(choice);
                }
                else
                {
                    menuForStudent();
                    cin >> choice;
                    studentChoice(choice);
                }
            }
        }
        else
            cout << "Login failed. Please check your username and password and try again.\n";
    }
    return 0;
}
