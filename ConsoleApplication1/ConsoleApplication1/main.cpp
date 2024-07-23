#include "Header.h"

int main()
{
    ifstream fin;
    ofstream fout;
    YearNode *headYear = nullptr;
    YearNode* curYear = nullptr;
    YearNode *tailYear = nullptr;
    YearNode *tempYear = nullptr;
    SemesterInfo *curSes = nullptr;
    SemesterInfo *tempSes = nullptr;
    CourseNode *headCourse = nullptr;
    CourseNode *curCourse = nullptr;
    ClassNode *curClass = nullptr;
    ClassNode *headClass = nullptr;
    StudentNode* curStu = nullptr;
    bool exit = false;

    // Load data

    cout << ANSI_CYAN << ">>>>WELCOME TO THE COURSE MANAGEMENT SYSTEM.\n\n";

    //Load users data
    cout << ANSI_CYAN << "<>Load users data...";
    UserNode *headUser = nullptr;
    UserNode *tailUser = nullptr;
    
    fin.open("DataFile/Users.txt");
    if (fin.is_open())
    {
        importUserData(headUser, tailUser, fin);
        cout << ANSI_GREEN << "Successful.\n";
        fin.close();
    }
    else
    {
        cout << ANSI_RED << "Failed.\n";
        exit = true;
    }

    //Load school year data
    cout << ANSI_CYAN << "<>Load school years data...";
    fin.open("DataFile/SchoolYear.txt");
    if (fin.is_open())
    {
        importSchoolYearData(headYear, tailYear, fin);
        cout << ANSI_GREEN << "Succesful.\n";
        fin.close();
    }
    else
    {
        cout << ANSI_RED << "Failed.\n";
        exit = true;
    }

    //Load class data
    cout << ANSI_CYAN << "<>Load classes data...";
    YearNode *yy = headYear;
    while (yy)
    {
        string direct = "DataFile/" + yy->data + "Classes.txt";
        fin.open(direct);
        ClassNode *tail = nullptr;
        if (fin.is_open())
        {
            importClassData(yy->classes, tail, fin);
            fin.close();
        }
        else
        {
            exit = true;
        }
        yy = yy->pNext;
    }
    if (exit)
        cout << ANSI_RED << "Failed.\n";
    else
        cout << ANSI_GREEN << "Successful.\n";


    //Load students to class
    bool ok1 = false;
    cout << ANSI_CYAN << "<>Load students to class...";
    yy = headYear;
    while (yy)
    {
        ClassNode *temp = yy->classes;
        while (temp)
        {
            string direct = "DataFile/" + temp->data.name + ".csv";
            fin.open(direct);
            if (fin.good())
            {
                importStudentToClass(temp->student, fin);
                fin.close();
            }
            temp = temp->pNext;
        }
        yy = yy->pNext;
    }
    if (ok1) cerr << ANSI_RED << "Failed.\n";
    else cerr << ANSI_GREEN << "Successful.\n";

    //Load course data to semester
    cout << ANSI_CYAN << "<>Load course to semester...";
    yy = headYear;
    bool ok2 = false;
    while (yy) {
        importCourseToSemester(yy, fin, ok2);
        yy = yy->pNext;
    }
    if (ok2) cout << ANSI_RED << "Failed.\n";
    else cout << ANSI_GREEN << "Successful.\n";

    
    //Load student to course
    cout << ANSI_CYAN << "<>Load student to course...";
    yy = headYear;
    bool ok3 = false;
    while (yy)
    {
        for (int i = 0; i < 3; i++)
        {
            if (yy->semester[i].created == false) continue;
            curCourse = yy->semester[i].course;
            while (curCourse)
            {
                fin.open("DataFile/Courses/" + yy->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv");
                if (fin.is_open())
                {
                    importStudentToClass(curCourse->student, fin);
                    fin.close();
                }
                fin.open("DataFile/Courses/SB/" + yy->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");
                if (fin.is_open())
                {
                    importScoreboard(curCourse->student, fin);
                    fin.close();
                }
                curCourse = curCourse->pNext;
            }
        }
        yy = yy->pNext;
    }
    if (!ok3) cout << ANSI_GREEN << "Successful.\n";
    else cout << ANSI_RED << "Failed.\n";
    
    exit = !(ok1 == false && ok2 == false && ok3 == false && exit == false);
    cout << ANSI_WHITE << "\n";
    //Starting program....
    UserNode *logged_in = nullptr;
    while (exit == false && continueProgram(1))
    {
        system("cls");
        if (login(headUser, logged_in))
        {
            cout << ANSI_GREEN << ">>>Logged in successfully<<<\n";
            bool logout = false; // haven't logged out

            while (exit == false && logout == false && continueProgram(2))
            {
                // Output Menu
                if (logged_in->data.is_staff)
                {
                    menuForStaff();
                    int staffChoice;
                    while (!(cin >> staffChoice))
                    {
                        cout << ANSI_RED << ">>>>Wrong input." << ANSI_YELLOW << " Staff choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    cout << ANSI_WHITE;
                    switch (staffChoice)
                    {
                    case 1: //Checked
                        // Tương tự case 3
                        fout.open("DataFile/SchoolYear.txt", ios::trunc);
                        if (fout.is_open()) {
                            createASchoolYear(headYear, tailYear);
                            exportSchoolYearData(headYear, fout);
                            fout.close();
                        }
                        else cout << ANSI_RED << "Create school year failed.\n";
                        break;
                    case 2:
                        // Add class thì sau đó phải tạo một file csv tương ứng lớp đó
                        addNewClass(headYear, fout);
                        break;
                    case 3: //checked
                        fout.open("DataFile/SchoolYear.txt", ios::trunc);
                        if (fout.is_open())
                        {
                            createSemester(headYear);
                            exportSchoolYearData(headYear, fout);
                        }
                        else cout << ANSI_RED << "Create semester failed.\n";
                        break;
                    case 4: //checked
                        curSes = chooseASemester(headYear, curYear);
                        break;
                    case 5: //checked
                        addNewStudentToClass(tailUser, headYear, fin);
                        break;
                    case 6: //checked
                        if (curYear && curSes) {
                            addCourse(curYear, curSes);
                        } else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 7: //checked
                        if (curYear && curSes) {
                            if (curSes->course)
                                viewListOfCourse(curSes->course);
                            else cout << ANSI_RED << "There is no course in the current semester.\n";
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 8: //checked
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                updateCourseIn4(curYear ,curCourse);
                                exportCourseToSemester(curYear, curSes, fout);
                            }
                            else cout << ANSI_RED << "This course does not exist.\n";
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 9: //checked
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                addStudentToCourse(headYear,curCourse);
                                fout.open("DataFile/Courses/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv");
                                if (fout.is_open())
                                {
                                    exportStudent(curCourse->student, fout);
                                    fout.close();
                                }
                                else cout << ANSI_RED << "Export student in a course failed" << endl;
                            }
                            else cout << ANSI_RED << "This course does not exist.\n";
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 10: //checked
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes->course);
                            if (curCourse) {
                                removeStudentFromCourse(curCourse);
                                fout.open("DataFile/Courses/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv");
                                if (fout.is_open())
                                {
                                    exportStudent(curCourse->student, fout);
                                    fout.close();
                                }
                            }
                            else cout << ANSI_RED << "This course does not exist.\n";
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 11: //checked
                        if (curYear && curSes) {
                            deleteACourse(curYear, curSes, fout);
                        } else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 12: //checked
                        int choice;
                        cout << "   1.View all classes.\n";
                        cout << "   2.View classes in a school year.\n";
                        cout << ">>>Your choice: "; 
                        cin >> choice;
                        if (choice == 1) {
                            viewAllClasses(headYear);
                        }
                        else if (choice == 2) {
                            viewAListOfClasses(headYear);
                        }
                        else cout << ANSI_RED << "Wrong option!!!\n";
                        break;
                    case 13: // checked
                        viewListOfStudentInClass(headYear); 
                        break;
                    case 14:// checked
                        tempYear = nullptr;
                        tempSes = chooseASemester(headYear, tempYear);
                        if (tempSes && tempYear) 
                        {
                            if (tempSes->course==nullptr)
                                cout << ANSI_RED << "There is no course in semester " << tempSes->order << " of school year " << tempYear->data << "\n";
                            else
                            {
                                cout << ANSI_WHITE << "List of courses in semester " << tempSes->order << " of school year " << tempYear->data << ":\n";
                                viewListOfCourse(tempSes->course);
                            }
                        }
                        break;
                    case 15: // checked
                        tempYear = nullptr;
                        tempSes = chooseASemester(headYear, tempYear);
                        if (tempSes && tempYear) 
                            viewListOfStudentInCourse(tempSes->course);
                        break;
                    case 16: // checked
                        viewProfileInfo(logged_in);
                        break;
                    case 17: // checked
                        fout.open("DataFile/Users.txt");
                        if (fout.good())
                        {
                            changePassword(logged_in);
                            exportUserData(headUser, fout);
                            fout.close();
                        }
                        else {
                            cout << ANSI_RED << "Change password failed.\n";
                        }
                        break;
                    case 18: //checked
                        if (curSes && curYear)
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                string path = "ExportFile/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv";
                                fout.open(path);
                                if (fout.is_open())
                                {
                                    exportStudent(curCourse->student, fout);
                                    fout.close();
                                    cout << ANSI_GREEN << "Export a list of student in a course successfully." << endl;
                                    cout << ANSI_WHITE << "Directory of the exported file: " << path << endl;
                                }
                                else
                                    cout << ANSI_RED << "Export a list of student in a course failed.\n";
                            }
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 19: //checked
                        if (curSes && curYear)
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                fin.open("InputFile/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");

                                if (fin.is_open())
                                {
                                    importScoreboard(curCourse->student, fin);
                                    fin.close();
                                    fout.open("DataFile/Courses/SB/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");
                                    if (fout.is_open())
                                    {
                                        exportScoreboard(curCourse->student, fout);
                                        fout.close();
                                    }
                                    else cout << ANSI_RED << "Can't export scoreboard file.\n";
                                }
                                else cout << ANSI_RED << "Can't open scoreboard file.\n";
                            }
                            cout << ANSI_GREEN << "Import scoreboard successfully.\n";
                        }   
                        else cout << ANSI_RED << "Please choose semester first (option 4th).\n";
                        fin.close();
                        break;     
                    case 20: //checked
                        if (curSes && curYear)
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse) viewTheScoreboardOfCourse(curCourse);
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 21: //checked
                        if (curSes && curYear) 
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                curStu = chooseStudentInACourse(curCourse);
                                if (curStu)
                                {
                                    updateAStudentResult(curStu);
                                    fout.open("DataFile/Courses/SB/" + curYear->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");
                                    if (fout.is_open())
                                    {
                                        exportScoreboard(curCourse->student, fout);
                                        fout.close();
                                    }
                                }
                                else cout << ANSI_RED << "This student does not exist.\n";
                            }
                            else cout << ANSI_RED << "This course does not exist.\n";
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 22: //checked
                        if (curSes && curYear)
                        {
                            cout << "List of classes in school year " << curYear->data << endl;
                            int cnt = 0;
                            ClassNode* temp = curYear->classes;
                            while (temp != nullptr)
                            {
                                cout << ++cnt << ". " << temp->data.name << " " << endl;
                                temp = temp->pNext;
                            }
                            viewScoreboardofClass(headYear, curYear, curSes->order-1, cnt);
                        }
                        else cout << ANSI_RED << "Please choose semester first (option 4).\n";
                        break;
                    case 23:
                        cout << ANSI_GREEN << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 24:
                        exit = true;
                        break;
                    default:
                        cout << ANSI_RED << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
                else
                {
                    menuForStudent();
                    int studentChoice;
                    while (!(cin >> studentChoice))
                    {
                        cout << ANSI_RED << ">>>>Wrong input." << ANSI_YELLOW << " Student choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    system("cls");
                    cout << ANSI_WHITE;
                    switch (studentChoice)
                    {
                    case 1: // checked
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear) 
                        {
                            viewStudentCourse(logged_in->data.username, curSes->course);
                        }
                        break;
                    case 2: // checked
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear)
                        {
                            viewStudentScoreboard(logged_in->data.username, curSes->course);
                        }
                        break;
                    case 3: // checked
                        viewProfileInfo(logged_in);
                        break;
                    case 4: //checked
                        fout.open("DataFile/Users.txt");
                        if (fout.is_open())
                        {
                            changePassword(logged_in);
                            exportUserData(headUser, fout);
                            fout.close();
                        }
                        else
                        {
                            cout << ANSI_RED << "Change password failed.\n";
                        }
                        break;
                    case 5:
                        cout << ANSI_GREEN << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 6:
                        exit = true;
                        break;
                    default:
                        cout << ANSI_RED << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
            }
        }
        else
            cout << ANSI_RED << "Login failed. Please check your username and password and try again.\n";
    }
    
    system("cls");
    // Delete users
    deleteUserData(headUser);

    // Delete classes (and all students in class)
    yy = headYear;
    while (yy) {
        deAlocatedClassesData(yy->classes);
        yy = yy->pNext;
    }
    yy = headYear;

    // Delete year (and all data included in year)
    deAllocateDataYear(headYear);
    return 0;
}