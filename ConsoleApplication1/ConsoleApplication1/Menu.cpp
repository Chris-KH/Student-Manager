#include "Library.h"
#include "Menu.h"
bool continueProgram()
{
    if (logOutProgram())
        return false;
    int continueChoice;
    cout << "If you want to continue, please input \'1\'. However, if you want to return, please input \'0\'." << endl;
    cout << "Your input: ";
    cin >> continueChoice;
    if (continueChoice == 1)
        return true;
    if (continueChoice == 0)
        return false;
    cout << "Please read the instruction again!" << endl;
    continueProgram();
}
bool logOutProgram()
{
    int logoutChoice;
    cout << "If you want to log out, please input \'0\'. However, if you want to continue, please input \'1\'." << endl;
    cout << "Your input: ";
    cin >> logoutChoice;
    if (logoutChoice == 0)
        return true;
    if (logoutChoice == 1)
        return false;
    cout << "Please read the instruction again!" << endl;
    logOutProgram();
}
void menuForStaff()
{
    cout << "All the functions: Press a number to choose";
    cout << "1. Create a school year" << endl;
    cout << "2. Create a semester" << endl;
    cout << "3. View a list of the course studied in the semester (Student)" << endl;
    cout << "4. View a list of classes" << endl;
    cout << "5. View a list of students in a class (for example, 20APCS1�)" << endl;
    cout << "6. View a list of courses" << endl;
    cout << "7. View a list of students in a course" << endl;
    cout << "8. Export a list of students in a course to a CSV file" << endl;
    cout << "9. Import the scoreboard of a course" << endl;
    cout << "10. View the scoreboard of a course" << endl;
    cout << "11. Update a student's result" << endl;
    cout << "12. View the scoreboard of a class" << endl;
    cout << "13. View the total scoreboard (Student)" << endl;
    cout << "Staff choice: ";
}