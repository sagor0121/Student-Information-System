#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Student
{
private:
    char stuID[15];
    char stuName[50];
    char fatherName[30];
    char motherName[30];
    char department[25];
    char attendance[20];
    char session[20];
    char year[15];
    char ygpa[10];
    char bloodGroup[10];
    char phoneNumber[15];
    char email[30];
    char address[30];

public:
    Student () /// constructor
    {
        strcpy (stuID,"No Title");
        strcpy (stuName,"No Title");
        strcpy (fatherName,"No Title");
        strcpy (motherName,"No Title");
        strcpy (department,"No Title");
        strcpy (attendance,"No Title");
        strcpy (session,"No Title");
        strcpy (year,"No Title");
        strcpy (ygpa,"No Title");
        strcpy (bloodGroup,"No Title");
        strcpy (phoneNumber,"No Title");
        strcpy (email,"No Title");
        strcpy (address,"No Title");
    }

    void getStudentData() /// Input Data ///
    {
        cin.ignore();
        cout << "\n\n\n\t\t Please Enter Student Information";
        cout << "\n\t\t==================================\n";

        cout << "\n\tStudent ID : ";
        gets(stuID);

        cout << "\n\tStudent Name : ";
        gets(stuName);

        cout << "\n\tStudent Father Name : ";
        gets(fatherName);

        cout << "\n\tStudent Mother Name : ";
        gets(motherName);

        cout << "\n\tStudent Department : ";
        gets(department);

        cout << "\n\tStudent Attendance : ";
        gets(attendance);

        cout << "\n\tStudent Session : ";
        gets(session);

        cout << "\n\tStudent Current Year : ";
        gets(year);

        cout << "\n\tStudent Year GPA : ";
        gets(ygpa);

        cout << "\n\tStudent Blood Group : ";
        gets(bloodGroup);

        cout << "\n\tStudent Phone Number : ";
        gets(phoneNumber);

        cout << "\n\tStudent E-mail ID : ";
        gets(email);

        cout << "\n\tStudent Address : ";
        gets(address);


    }

     void showStudentdata() /// show data ///
    {
        cout <<"\n\t==============================\n";

        cout << "\n\tStudent ID   : " << stuID;
        cout << "\n\tStudent Name : " << stuName;
        cout << "\n\tStudent Father Name  : " << fatherName;
        cout << "\n\tStudent Mother Name  : " << motherName;
        cout << "\n\tStudent Department : " << department;
        cout << "\n\tStudent Attendance : " << attendance;
        cout << "\n\tStudent Session : " << session;
        cout << "\n\tStudent Current Year : " << year;
        cout << "\n\tStudent Year GPA : " << ygpa;
        cout << "\n\tStudent Blood Group  : " << bloodGroup;
        cout << "\n\tStudent Phone Number : " << phoneNumber;
        cout << "\n\tStudent E-mail ID  : " << email;
        cout << "\n\tStudent Address : " << address;

    }

    int storeStudent ()
    {
        if (stuID == 0 && stuName == "No Title")
        {
            cout<< "Student Data Not Initialized\n";
            return 0;
        }
        else
        {
            ofstream fout;
            fout.open("Student.txt", ios::app | ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();
            return (1);
        }
    }
    int viewAllstudent ()
    {
        ifstream fin;
        fin.open("Student.txt", ios::app | ios::binary);
        if (!fin)
        {
            cout<< "Data Not Found\n";
        }
        else
        {
            fin.read((char*)this, sizeof(*this));
            while (!fin.eof())
            {
                showStudentdata();
                fin.read((char*)this,sizeof(*this));
            }
            fin.close();
        }
    }

    int searchStudent(char *t)
    {
        int counter=0;
        ifstream fin;
        fin.open("Student.txt",ios::in | ios::binary);
        if(!fin)
        {
            cout << "Data Not Found\n";
        }
        else
        {
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(!strcmp(t,stuID))
                {
                    showStudentdata();
                    counter++;
                }
                fin.read((char*)this,sizeof(*this));
            }
            if(counter==0)
                cout <<"\n\n\n\n\t\t\"Record Not Found\"\n";
            fin.close ();
        }
    }


    int deleteStudent (char *t)
    {
        int counter = 0;
        ifstream fin;
        ofstream fout;
        fin.open("Student.txt",ios::in | ios::binary);
        if (!fin)
        {
           cout<< "File Not Found\n";
        }
        else
        {
           fout.open("tempfile.txt",ios::out | ios::binary);
           fin.read((char*)this, sizeof(*this));

           while(!fin.eof())
               {
                   if(strcmp(stuID,t))

                       fout.write((char*)this,sizeof(*this));

                   fin.read((char*)this,sizeof(*this));
               }
        fin.close();
        fout.close();
        remove("Student.txt");
        rename("tempfile.txt","Student.txt");
        cout << "\n\n\tRecord Deleted";
    }
}
    void updateStudent(char *t)
    {
        int counter = 0;
        fstream file;
        file.open("Student.txt",ios::in | ios::out | ios::ate | ios::binary);
        if(!file)
        {
            cout << "File Not Found\n";
        }

        file.seekg(0);

        file.read((char *)this, sizeof(*this));
        while(!file.eof())
        {
            if(!strcmp(t,stuID))
            {
                ++counter;
                getStudentData();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
        if(counter==0)
        {
            cout<< "\n\n\tGiver ID Does Not Found in The File\n\tSo That Updating Process Can't Happen";

        }
        else
        {
            cout << "\n\n\trecord Updated";
        }

    }

};

int menu ()
{
    int choice;


        cout <<"\t\t* * * * * * * * * * * * * * * * * * * * *\n";
        cout <<"\t\t*                                       *\n";
        cout <<"\t\t*     STUDENT INFORMATION MANAGEMENT    *\n" << endl;
        cout <<"\t\t*                                       *\n";
        cout <<"\t\t* * * * * * * * * * * * * * * * * * * * *\n";


        cout <<"\n\n\t\t1. Insert Student Record";
        cout <<"\n\n\t\t2. Entire Student Records";
        cout <<"\n\n\t\t3. Search Student Record";
        cout <<"\n\n\t\t4. Delete Student Record";
        cout <<"\n\n\t\t5. Update Student Record";
        cout <<"\n\n\t\t6. Exit";
        cout <<"\n\n\n\t\tEnter your choice : ";

        cin >> choice ;
        return (choice);
}

        int main()
        {
            Student S1;
            char title [50];
            while (1)
            {
                system ("cls");
                switch (menu())
                {
                case 1:
                    system("cls");
                    S1.getStudentData();
                    S1.storeStudent();
                    cout<<"\n\t\tRecord Inserted";
                    break;

                case 2:
                    system("cls");
                    cout <<"\n\t=============================";
        	        cout << "\n\t##  Student Information  ##";
                    S1.viewAllstudent();
                    cout <<"\n\t=============================";
                    cout <<"\n\t=============================";

                    break;

                case 3:
                    system("cls");
                    cout << "\n\tEnter Student ID to Search : ";
                    cin.ignore();
                    cin.getline(title,50);
                    S1.searchStudent(title);
                    break;

                case 4:
                    system("cls");
                    cout << "\n\tEnter Student ID to Delete : ";
                    cin.ignore();
                    cin.getline(title,50);
                    S1.deleteStudent(title);
                    break;

                case 5:
                    system("cls");
                    cout<<"\n\tEnter Student ID to Update : ";
                    cin.ignore();
                    cin.getline(title,50);
                    S1.updateStudent(title);
                    break;

                case 6:
                    system("cls");
                    cout << "\n\n\tThank You For Using This Application";
                    cout << "\n\n\tPress any Key to Exit";
                    getch();
                    system ("cls");
                    cout << "\n\n\n\tExiting......!\n\n\n";
                    getch();
                    exit(0);

                default:
                    cout << "\nInvalid Choice";

                }
                getch();
            }
            return 0;
        }
