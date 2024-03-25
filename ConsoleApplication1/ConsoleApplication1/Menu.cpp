#include "Library.h"
#include "Menu.h"
bool continueProgram()
{
    if (returnProgram()) return false; // Cái này có thật sự cần không
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
bool returnProgram()
{
    int returnChoice;
    cout << "If you want to return, please input \'0\'. However, if you want to continue, please input \'1\'." << endl;
    cout << "Your choice: "; cin >> returnChoice;
    if (returnChoice == 0)
        return true;
    if (returnChoice == 1)
        return false;
    cout << "Please read the instruction again!" << endl;
    returnProgram();
}
void menuForStaff()
{
    cout << "All the functions: Press a number to choose" << endl;
    cout << endl;

    cout << "At the beginning of the year:" << endl;
    cout << "1. Create a school year" << endl;
    cout << "2. Create classes" << endl;
    cout << "3. Add new 1st year students" << endl;
    cout << endl;

    cout << "At the beginning of a semester: " << endl;
    cout << "4. Create a semester" << endl;
    cout << "5. Add a course" << endl;
    cout << "6. View the list of courses" << endl;
    cout << "7. Update course information" << endl;
    cout << "8. Add a student to the course" << endl;
    cout << "9. Remove a student from the course" << endl;
    cout << "10. Delete a course" << endl;
    cout << endl;

    cout << "At anytime:" << endl;
    cout << "11. View a list of classes" << endl;
    cout << "12. View a list of students in a class" << endl;
    cout << "13. View a list of courses" << endl;
    cout << "14. View a list of students in a course" << endl;
    cout << "Staff choice: ";
}