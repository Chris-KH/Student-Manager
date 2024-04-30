#include "Menu.h"

bool continueProgram(int status)
{
    if (status == 1)
        cout << ANSI_YELLOW << ">>>You are logging in.\n";
    else if (status == 2)
        cout << ANSI_YELLOW << ">>>You are choosing from a Menu.\n";
    int continueChoice;
    cout << ANSI_YELLOW << "***Input '1' to continue program or '0' to return: ";
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
    cout << ANSI_YELLOW << "All the functions for staff: Press a number to choose.\n" << ANSI_MAGENTA;
    cout << "    1. Create a school year.\n";
    cout << "    2. Create classes.\n";
    cout << "    3. Create a semester.\n";
    cout << "    4. Choose current sesmester (this semester will be used for other functions).\n";
    cout << "    5. Add new 1st year student to 1st year class.\n";
    cout << "    6. Add a course to current semester.\n";
    cout << "    7. View the list of courses in current semester.\n";
    cout << "    8. Update course information in current semester.\n";
    cout << "    9. Add a student to the course in current semester.\n";
    cout << "   10. Remove a student from the course in current semester.\n";
    cout << "   11. Delete a course in current semester.\n";
    cout << "   12. View a list of classes.\n";
    cout << "   13. View a list of students in a class.\n";
    cout << "   14. View a list of courses in any semester.\n";
    cout << "   15. View a list of students in a course in any semester.\n";
    cout << "   16. View staff info.\n";
    cout << "   17. Change staff's password.\n";
    cout << "   18. Export a list of students in any course in current semester.\n";
    cout << "   19. Import the scoreboard of any course in current semester.\n";
    cout << "   20. View the scoreboard of any course in current semester.\n";
    cout << "   21. Update any student's result in any course in current semester.\n";
    cout << "   22. View the scoreboard of any class.\n";
    cout << "   23. Logout.\n";
    cout << "   24. End program.\n";
    cout << ANSI_YELLOW << ">>>>Staff choice: ";
}
void menuForStudent()
{
    system("cls");
    cout << ANSI_YELLOW << "All the functions for student: Press a number to choose.\n" << ANSI_MAGENTA;
    cout << "   1. View a list of my course.\n";
    cout << "   2. View my scoreboard.\n";
    cout << "   3. View student's info.\n";
    cout << "   4. Change student's password.\n";
    cout << "   5. Logout.\n";
    cout << "   6. End program.\n";
    cout << ANSI_YELLOW << ">>>>Student choice: ";
}
