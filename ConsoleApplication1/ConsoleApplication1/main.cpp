#include "Header.h"

int main()
{
    string username, password;
	ImportUserData("user.csv");

	while (true)
	{
		cout << "User name: " << endl;
		cin >> username;
		cout << "Password: " << endl;
		cin >> password;
		if (logIn(username, password))
		{
			cout << "MENU:";
			cout<<"";
		}
		int n;
		cout<<"All the function: Press a number to choose";
		cout<<"1. Create a school year"<<endl;
        cout<<"2. Create a semester"<<endl;
        cout<<"3. View a list of the course studied in the semester (Student)"<<endl;
        cout<<"4. View a list of classes"<<endl;
        cout<<"5. View a list of students in a class (for example, 20APCS1…)"<<endl;
        cout<<"6. View a list of courses"<<endl;
        cout<<"7. View a list of students in a course"<<endl;
        cout<<"8. Export a list of students in a course to a CSV file"<<endl;
        cout<<"9. Import the scoreboard of a course"<<endl;
        cout<<"10. View the scoreboard of a course"<<endl;
        cout<<"11. Update a student's result"<<endl;
        cout<<"12. View the scoreboard of a class"<<endl;
        cout<<"13. View the total scoreboard (Student)"<<endl;
        switch (n)
        {
            case 1:
            {

            }
            case 2:
            {

            }
            case 3:
            {

            }
            case 4:
            {

            }
            case 5:
            {

            }
            case 6:
            {

            }
            case 7:
            {

            }
            case 8:
            {

            }
            case 9:
            {

            }
            case 10:
            {

            }
            case 11:
            {

            }
            case 12:
            {

            }
            case 13:
            {
                
            }
        }
	}
    return 0;
}