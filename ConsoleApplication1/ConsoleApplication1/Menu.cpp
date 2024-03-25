#include "Header.h"
bool continueProgram(bool &logout)
{
    int continueChoice;
    cout << "If you want to continue, please input \'1\'. However, if you want to return, please input \'0\'." << endl;
    cout << "Your input: ";
    cin >> continueChoice;
    if (continueChoice == 1)
        return true;
    if (continueChoice == 0)
    {
        logoutProgram(logout);
        return false;
    }
    cout << "Please read the instruction again!" << endl;
    continueProgram(logout);
}

void logoutProgram(bool &logout)
{
    int logoutChoice;
    cout << "If you want to logout, please input \'0\'. If not, please input \'1\'" << endl;
    cout << "Your choice: ";
    cin >> logoutChoice;
    if (logoutChoice == 0)
        logout = true;
    else if (logoutChoice == 1)
        logout = false;
    else
    {
        cout << "Please read the instruction again!" << endl;
        logoutProgram(logout);
    }
}

void menuForStaff()
{
    cout << "All the functions for staff: Press a number to choose" << endl;
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
    cout << "15. View staff info" << endl;
    cout << "16. Change staff's password" << endl;
    cout << endl;

    cout << "At the end of a semester:" << endl;
    cout << "15. Export a list of students in a course" << endl;
    cout << "16. Import the scoreboard of a course" << endl;
    cout << "17. View the scoreboard of a course" << endl;
    cout << "18. Update a student's result" << endl;
    cout << "19. View the scoreboard of a class" << endl;
    cout << endl;

    cout << "Staff choice: ";
}
void menuForStudent()
{
    cout << "All the functions for student: Press a number to choose" << endl;
    cout << endl;

    cout << "In a semester: " << endl;
    cout << "1. View a list of my course" << endl;
    cout << endl;

    cout << "When the scoreboard has been published by academic staff member: " << endl;
    cout << "2. View my scoreboard" << endl;
    cout << endl;

    cout << "At any time:" << endl;
    cout << "3. View student info" << endl;
    cout << "4. Change student's password" << endl;
    cout << endl;

    cout << "Student choice: ";
}
/*
void checkStaffChoice()
{
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
void checkStudentChoice()
{
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
*/