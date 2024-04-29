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

    cout << ">>>>Welcome to course management system.\n";

    //Load users data
    cout << "<>Load users data...";
    UserNode *headUser = nullptr;
    UserNode *tailUser = nullptr;
    
    fin.open("DataFile/Users.txt");
    if (fin.is_open())
    {
        importUserData(headUser, tailUser, fin); // in User.h, User.cpp
        cout << "Successful.\n";
        fin.close();
    }
    else
    {
        cout << "Failed.\n";
        exit = true;
    }

    //Load school year data
    cout << "<>Load school years data...";
    fin.open("DataFile/SchoolYear.txt");
    if (fin.is_open())
    {
        importSchoolYearData(headYear, tailYear, fin); // in Year.h, Year.cpp
        cout << "Succesful.\n";
        fin.close();
    }
    else
    {
        cout << "Failed.\n";
        exit = true;
    }

    //Load class data
    cout << "<>Load classes data...";
    YearNode *yy = headYear;
    while (yy)
    {
        string direct = "DataFile/" + yy->data + "Classes.txt";
        fin.open(direct);
        ClassNode *tail = nullptr;
        if (fin.is_open())
        {
            importClassData(yy->classes, tail, fin); // in Class.h, Class.cpp
            fin.close();
        }
        else
        {
            exit = true;
        }
        yy = yy->pNext;
    }
    if (exit)
        cout << "Failed.\n";
    else
        cout << "Successful.\n";


    //Load students to class
    bool ok1 = false;
    cout << "<>Load students to class...";
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
                importStudentToClass(temp->student, fin); // in Student.h, Student.cpp
                fin.close();
            }
            temp = temp->pNext;
        }
        yy = yy->pNext;
    }
    if (ok1) cerr << "Failed.\n";
    else cerr << "Successful.\n";

    //Load course data to semester
    cout << "<>Load course to semester...";
    yy = headYear;
    bool ok2 = false;
    while (yy) {
        importCourseToSemester(yy, fin, ok2); // in Year.h, Year.cpp
        yy = yy->pNext;
    }
    if (ok2) cout << "Failed.\n";
    else cout << "Successful.\n";

    
    //Load student to course
    cout << "<>Load student to course...";
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
                    importStudentToClass(curCourse->student, fin); // in Student.h, Student.cpp
                    fin.close();
                }
                fin.open("DataFile/Courses/SB/" + yy->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");
                if (fin.is_open())
                {
                    importScoreboard(curCourse->student, fin);
                    fin.close();
                }
                
                //creating scoreboard files of courses
                /*fout.open("DataFile/Courses/SB/" + yy->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + "-sb.csv");
                if (fout.is_open())
                {
                    StudentNode* head = curCourse->student;
                    while (head != nullptr)
                    {
                        fout << head->data.No << ",";
                        fout << head->data.ID << ",";
                        fout << head->data.last_name << ",";
                        fout << head->data.first_name << ",";
                        fout << head->data.gender << ",";
                        fout << head->data.dob.day << "/" << head->data.dob.month << "/" << head->data.dob.year << ",";
                        fout << head->data.social_id << ",";

                        float x1 = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 - 5)));
                        float x2 = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 - 5)));
                        float x3 = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 - 5)));
                        float x4 = 0.3 * x1 + 0.5 * x2 + 0.2 * x3;
                        fout << fixed << setprecision(1) << x1 << "," << x2 << "," << x3 <<","<<x4<< "\n";
                        head = head->pNext;
                    }
                }
                else cout << "Scoreboard ok";
                fout.close();*/

                curCourse = curCourse->pNext;

            }
        }
        yy = yy->pNext;
    }
    if (!ok3) cout << "Successful.\n";
    else cout << "Failed.\n";
    
    exit = !(ok1 == false && ok2 == false && ok3 == false && exit == false);

    //Starting program....
    UserNode *logged_in = nullptr;
    while (exit == false && continueProgram(1)) // in Menu.h, Menu.cpp
    {
        system("cls");
        if (login(headUser, logged_in)) // in User.h, User.cpp
        {
            cout << ">>>Logged in successfully<<<\n";
            bool logout = false; // haven't logged out

            while (exit == false && logout == false && continueProgram(2)) // in Menu.h, Menu.cpp
            {
                // Output Menu
                if (logged_in->data.is_staff)
                {
                    menuForStaff(); // in Menu.h, Menu.cpp
                    int staffChoice;
                    while (!(cin >> staffChoice))
                    {
                        cout << ">>>>Wrong input. Staff choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (staffChoice)
                    {
                    case 1: //Checked
                        // Tương tự case 3
                        fout.open("DataFile/SchoolYear.txt", ios::trunc);
                        if (fout.is_open()) {
                            createASchoolYear(headYear, tailYear); // in Year.h, Year.cpp
                            exportSchoolYearData(headYear, fout); // in Year.h, Year.cpp
                            fout.close();
                        }
                        else cout << "Create school year failed.\n";
                        break;
                    case 2:
                        // Add class thì sau đó phải tạo một file csv tương ứng lớp đó
                        addNewClass(headYear, fout); // in Year.h, Year.cpp
                        break;
                    case 3: //checked
                        fout.open("DataFile/SchoolYear.txt", ios::trunc);
                        if (fout.is_open())
                        {
                            createSemester(headYear);
                            exportSchoolYearData(headYear, fout);
                        }
                        else
                            cout << "Create semester failed.\n";
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
                        } else cout << "Please choose semester first (option 4).\n";
                        break;
                    case 7: //checked
                        if (curYear && curSes) {
                            if (curSes->course)
                                viewListOfCourse(curSes->course);
                            else cout << "There is no course in the current semester.\n";
                        }
                        else cout << "Please choose semester first (option 4).\n";
                        break;
                    case 8: //checked
                        if (curYear && curSes) {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                updateCourseIn4(curCourse);
                                exportCourseToSemester(curYear, curSes, fout);
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Please choose semester first (option 4).\n";
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
                                else cout << "Export student in a course failed" << endl;
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Please choose semester first (option 4).\n";
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
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Please choose semester first (option 4).\n";
                        break;
                    case 11: //checked
                        if (curYear && curSes) {
                            deleteACourse(curYear, curSes, fout);
                        } else cout << "Please choose semester first (option 4).\n";
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
                        else cout << "Wrong option!!!\n";
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
                                cout<<"There is no course in semester " << tempSes->order << " of school year " << tempYear->data << ":\n";
                            else
                            {
                                cout << "List of courses in semester " << tempSes->order << " of school year " << tempYear->data << ":\n";
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
                            cout << "Change password failed.\n";
                        }
                        break;
                    case 18:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear)
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                            {
                                fout.open("DataFile/Export Files/" + yy->data + "-" + curCourse->data.ID + "-" + curCourse->data.class_name + ".csv");
                                if (fin.is_open())
                                {
                                    exportStudent(curCourse->student, fout);
                                    //NOTE: ghi note như nào để dẫn người dùng đến file đó??
                                }
                                else
                                    cout << "Export student in a course failed.\n" << endl;
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Wrong.\n";
                        break;
                    case 19:
                        curSes = chooseASemester(headYear, curYear);
                        
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
                                    else cout << "Can't export scoreboard file.\n";
                                }
                                else cout << "Can't open scoreboard file.\n";
                            }
                            else cout << "This course does not exist.\n";
                            cout << "Import scoreboard successfully.\n";
                        }   
                        else cout << "Please check semester and year again\n";
                        fin.close();
                        break;
                        
                    case 20:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear)
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse)
                                viewTheScoreboardOfCourse(curCourse);
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Wrong.\n";
                        break;
                    case 21:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear) 
                        {
                            curCourse = findCourse(curSes->course);
                            if (curCourse) 
                            {
                                string s;
                                cout << "Input student ID: " << endl;
                                cin >> s;
                                curStu = findStudentInACourse(s, curCourse);
                                if (curStu)
                                {
                                    updateAStudentResult(curStu);
                                }
                                else cout << "This student does not exist.\n";
                            }
                            else cout << "This course does not exist.\n";
                        }
                        else cout << "Wrong.\n";
                        break;
                    case 22:
                        viewScoreboardofClass(headClass);
                        break;
                    case 23:
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 24:
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
                else
                {
                    menuForStudent();
                    int studentChoice;
                    while (!(cin >> studentChoice))
                    {
                        cout << ">>>>Wrong input. Student choice: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    system("cls");
                    switch (studentChoice)
                    {
                    case 1:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear) 
                        {
                            viewStudentCourse(logged_in->data.username, curSes->course);
                        }
                        else cout << "Wrong.\n";
                        break;
                    case 2:
                        curSes = chooseASemester(headYear, curYear);
                        if (curSes && curYear)
                        {
                            viewStudentScoreboard(logged_in->data.username, curSes->course);
                        }
                        else cout << "Wrong.\n";
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
                            cout << "Change password failed.\n";
                        }
                        break;
                    case 5:
                        cout << "Logout successful. You have been logged out.\n";
                        logout = true;
                        break;
                    case 6:
                        exit = true;
                        break;
                    default:
                        cout << "You missed the instruction, please check the input and follow the instruction\n";
                        break;
                    }
                }
            }
        }
        else
            cout << "Login failed. Please check your username and password and try again.\n";
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