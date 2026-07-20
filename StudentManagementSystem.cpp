#include <iostream>
#include <fstream>
using namespace std;
// Student class to store student information
class Student
{
public:
    // Student details
    string name, father_Name, gender, address, standard, phone_Number;
    int age, rollNo;
    // Funtion to take student input
    void input()
    {
        cin.ignore();
        cout << "Enter Your Name : ";
        getline(cin, name);

        cout << "Enter Your Father Name : ";
        getline(cin, father_Name);

        cout << "Enter Your Gender : ";
        getline(cin, gender);

        cout << "Enter Your Address : ";
        getline(cin, address);

        cout << "Enter Your Standard : ";
        getline(cin, standard);
        cout << "Enter Your Phone Number : ";
        getline(cin, phone_Number);

        cout << "Enter Age : ";
        cin >> age;
    }
    // Funtion to Display student details
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Father Name : " << father_Name << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "Gender : " << gender << endl;
        cout << "Address : " << address << endl;
        cout << "Standard : " << standard << endl;
        cout << "Age : " << age << endl;
        cout << "Phone : " << phone_Number << endl;
        cout << "-------------------" << endl;
    }
};
int main()
{
    // Menu choice
    int n;
    // Number of student currently stored
    int count = 0;
    // Roll Number uded to search , update and delete
    int search;
    // Dynamic array to store maximum 100 students
    Student *s = new Student[100];
    // Main menu loop
    while (true)
    {
        cout << "------------------------" << endl;
        cout << "WELCOME TO MENU!" << endl;
        cout << "------------------------" << endl
             << endl;

        cout << "1.Add Student" << endl;
        cout << "2.Display All Student" << endl;
        cout << "3.Search Student" << endl;
        cout << "4.File me Save Data "
             << endl;
        cout << "5.Update Student Details" << endl;
        cout << "6.Delete Student " << endl;
        cout << "7.Exit!" << endl
             << endl;
        cout << "Enter the No : " << endl;
        cin >> n;

        cout << "------------------------" << endl
             << endl;

        switch (n)
        {

        case 1:
            // Add a new Student
            s[count].rollNo = count + 1;
            s[count].input();
            count++;
            break;
        case 2:
            // Display all Students details
            for (int i = 0; i < count; i++)
            {
                s[i].display();
            }
            break;
        case 3:
        {
            // Search Student by roll No
            cout << "Enter the Roll No to Search : ";
            cin >> search;
            cout << endl;
            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (s[i].rollNo == search)
                {
                    s[i].display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student Not Found!";
            }

            break;
        }
        case 4:

        {
            // Save Student details to file
            if (count > 0)
            {
                // Save all students data into Student.txt
                ofstream file("Student.txt");
                for (int i = 0; i < count; i++)
                {
                    file << "Name : " << s[i].name << endl;
                    file << "Father Name : " << s[i].father_Name << endl;
                    file << "Roll No : " << s[i].rollNo << endl;
                    file << "Gender : " << s[i].gender << endl;
                    file << "Address : " << s[i].address << endl;
                    file << "Standard  : " << s[i].standard << endl;
                    file << "Age : " << s[i].age << endl;
                    file << "Phone Number : " << s[i].phone_Number << endl;
                    file << "--------------------------" << endl
                         << endl;
                    cout << "--------------------------" << endl;
                }
                cout << "-----Data Saved Successfully-----" << endl;

                file.close();
            }
            else
            {
                ofstream file("Student.txt");
                file.close();
                cout << "Empty!" << endl;
            }

            break;
        }
        case 5:
        {
            // Update existing student details
            cout << "Enter the Roll No : " << endl;
            cin >> search;
            cout << endl;
            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (s[i].rollNo == search)
                {
                    cout << "Details of Student" << endl;
                    s[i].display();
                    found = true;
                    cout << "Re-Enter The Details: " << endl;
                    s[i].input();
                    break;
                }
            }
            if (!found)
            {
                cout << "Student Not Found!";
            }
        }
        break;
        case 6:
        {
            // Delete Student record
            cout << "Enter the Roll No to Delete : ";
            cin >> search;
            cout << endl;
            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (s[i].rollNo == search)
                {
                    cout << "Student Details" << endl;
                    s[i].display();
                    found = true;
                    for (int j = i; j < count - 1; j++)
                    {
                        s[j] = s[j + 1];
                        count--;
                    }
                    cout << "Student Deleted Successfully!" << endl;
                    break;
                }
            }
            for (int i = 0; i < count; i++)
            {
                s[i].rollNo = i + 1;
            }
            if (!found)
            {
                cout << "Student Not Found!";
            }
        }
        break;
        // Exit the program and free the memory
        case 7:
            delete[] s;
            cout << "Thank You!";
            return 0;
            break;

        default:
            // Handle invalid menu choice
            cout << "Invalid Enter Valid No!" << endl
                 << endl;
            break;
        }
    }
}