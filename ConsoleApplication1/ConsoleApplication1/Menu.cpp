#include "Menu.h"

bool continueProgram(int status)
{
    if (status == 1)
        cout << ">>>You are logging in.\n";
    else if (status == 2)
        cout << ">>>You are choosing from a Menu.\n";
    int continueChoice;
    cout << "***Input '1' to continue program or '0' to return: ";
    if (cin >> continueChoice)
    {
        if (continueChoice == 1)
            return true;
        if (continueChoice == 0)
            return false;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "***Please read the instruction again!\n";
    return continueProgram(status);
}

void menuForStaff()
{
    system("cls");
    cout << "All the functions for staff: Press a number to choose.\n";
    cout << "   01. Create a school year.\n";
    cout << "   02. Create classes.\n";
    cout << "   03. Create a semester.\n";
    cout << "   04. Choose current sesmester.\n";
    cout << "   05. Add new 1st year student to 1st year class.\n";
    cout << "   06. Add a course.\n";
    cout << "   07. View the list of courses in current semester.\n";
    cout << "   08. Update course information.\n";
    cout << "   09. Add a student to the course.\n";
    cout << "   10. Remove a student from the course.\n";
    cout << "   11. Delete a course.\n";
    cout << "   12. View a list of classes.\n";
    cout << "   13. View a list of students in a class.\n";
    cout << "   14. View a list of courses.\n";
    cout << "   15. View a list of students in a course.\n";
    cout << "   16. View staff info.\n";
    cout << "   17. Change staff's password.\n";
    cout << "   18. Export a list of students in a course.\n";
    cout << "   19. Import the scoreboard of a course.\n";
    cout << "   20. View the scoreboard of a course.\n";
    cout << "   21. Update a student's result.\n";
    cout << "   22. View the scoreboard of a class.\n";
    cout << "   23. Logout.\n";
    cout << "   24. End program.\n";
    cout << ">>>>Staff choice: ";
}
void menuForStudent()
{
    system("cls");
    cout << "All the functions for student: Press a number to choose.\n";
    cout << "   1. View a list of my course.\n";
    cout << "   2. View my scoreboard.\n";
    cout << "   3. View student info.\n";
    cout << "   4. Change student's password.\n";
    cout << "   5. Logout.\n";
    cout << "   6. End program.\n";
    cout << ">>>>Student choice: ";
}
