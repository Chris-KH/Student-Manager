#include "Header.h"
bool continueProgram(bool &logout)
{
    int continueChoice;
    cout << "Input '1' to continue program or '0' to return: ";
    cin >> continueChoice;
    if (continueChoice == 1)
        return true;
    if (continueChoice == 0)
    {
        logoutProgram(logout);
        return false;
    }
    cout << "Please read the instruction again!\n";
    return continueProgram(logout);
}

void logoutProgram(bool &logout)
{
    int logoutChoice;
    cout << "Input '0' to logout or '1' to continue: ";
    cin >> logoutChoice;
    if (logoutChoice == 0)
        logout = true;
    else if (logoutChoice == 1)
        logout = false;
    cout << "Please read the instruction again!\n";
    logoutProgram(logout);
}

void menuForStaff()
{
    cout << "All the functions for staff: Press a number to choose.\n";
    cout << "   1. Create a school year.\n";
    cout << "   2. Create classes.\n";
    cout << "   3. Add new 1st year students.\n";
    cout << "   4. Create a semester.\n";
    cout << "   5. Add a course.\n";
    cout << "   6. View the list of courses.\n";
    cout << "   7. Update course information.\n";
    cout << "   8. Add a student to the course.\n";
    cout << "   9. Remove a student from the course.\n";
    cout << "   10. Delete a course.\n";
    cout << "   11. View a list of classes.\n";
    cout << "   12. View a list of students in a class.\n";
    cout << "   13. View a list of courses.\n";
    cout << "   14. View a list of students in a course.\n";
    cout << "   15. View staff info.\n";
    cout << "   16. Change staff's password.\n";
    cout << "   17. Export a list of students in a course.\n";
    cout << "   18. Import the scoreboard of a course.\n";
    cout << "   19. View the scoreboard of a course.\n";
    cout << "   20. Update a student's result.\n";
    cout << "   21. View the scoreboard of a class.\n";
    cout << ">>>>Staff choice: ";
}
void menuForStudent()
{
    cout << "All the functions for student: Press a number to choose.\n";
    cout << "   1. View a list of my course.\n";
    cout << "   2. View my scoreboard.\n";
    cout << "   3. View student info.\n";
    cout << "   4. Change student's password.\n";
    cout << ">>>>Student choice: ";
}