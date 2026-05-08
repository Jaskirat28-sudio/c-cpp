#include <fstream>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

/* ================= UTILITY FUNCTIONS ================= */

void gotoxy(int x,int y)
{
    COORD c = {short(x),short(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void border()
{
    int width = 160;  
    int height = 40;   

    // Top & Bottom borders
    for(int i = 1; i <= width; i++)
    {
        gotoxy(i, 1); cout << "*";       
        gotoxy(i, height); cout << "*";   
    }

    // Left & Right borders
    for(int i = 1; i <= height; i++)
    {
        gotoxy(1, i); cout << "*";        
        gotoxy(width, i); cout << "*";    
    }
}

void clearScreen()
{
    system("cls");
    border();
}

void pauseScreen()
{
    gotoxy(65,38);  	
    cout<<"Press any key to continue...";
    getch();
}

void wrongChoice()
{
    gotoxy(65,36);  
    cout<<"Wrong choice!";
    Sleep(700);
}

void exitApp()
{
    clearScreen();
    gotoxy(75,20);  
    cout<<"BYE BYE";
    gotoxy(70,22);  
    cout<<"SEE YOU AGAIN";
    Sleep(1000);
    exit(0);
}


/* ================= CLASSES ================= */

class Student
{
    int rollno;
    char name[20], address[30];

public:
    void inDesign()
    {
        gotoxy(50,2); cout<<"Add Student";
        gotoxy(40,4); cout<<"Roll No";
        gotoxy(40,5); cout<<"Name";
        gotoxy(40,6); cout<<"Address";
    }

    void getStudent()
    {
        gotoxy(60,4); cin >> rollno;
        cin.ignore();

        gotoxy(60,5); cin.getline(name,20);
        gotoxy(60,6); cin.getline(address,30);
    }

    void outDesign()
    {
        gotoxy(50,2); cout<<"Student List";
        gotoxy(20,4); cout<<"Roll No";
        gotoxy(40,4); cout<<"Name";
        gotoxy(60,4); cout<<"Address";
    }

    void putStudent(int row)
    {
        gotoxy(20,row); cout<<rollno;
        gotoxy(40,row); cout<<name;
        gotoxy(60,row); cout<<address;
    }

    bool searchByRollNo(int roll)
    {
        return rollno == roll;
    }
};

class Course
{
    int courseId;
    char courseName[30], duration[20];

public:
    void inDesign()
    {
        gotoxy(50,2); cout<<"Add Course";
        gotoxy(40,4); cout<<"Course ID";
        gotoxy(40,5); cout<<"Course Name";
        gotoxy(40,6); cout<<"Duration";
    }

    void getCourse()
    {
        gotoxy(60,4); cin>>courseId;
        cin.ignore();

        gotoxy(60,5); cin.getline(courseName,30);
        gotoxy(60,6); cin.getline(duration,20);
    }

    void outDesign()
    {
        gotoxy(50,2); cout<<"Course List";
        gotoxy(20,4); cout<<"ID";
        gotoxy(40,4); cout<<"Name";
        gotoxy(60,4); cout<<"Duration";
    }

    void putCourse(int row)
    {
        gotoxy(20,row); cout<<courseId;
        gotoxy(40,row); cout<<courseName;
        gotoxy(60,row); cout<<duration;
    }

    bool searchById(int id)
    {
        return courseId == id;
    }
};

class Attendance
{
    int roll;
    char date[20], status[10];

public:
    void inDesign()
    {
        gotoxy(50,2); cout<<"Add Attendance";
        gotoxy(40,4); cout<<"Roll No";
        gotoxy(40,5); cout<<"Date";
        gotoxy(40,6); cout<<"Status";
    }

    void getAttendance()
    {
        gotoxy(60,4); cin>>roll;
        cin.ignore();

        gotoxy(60,5); cin.getline(date,20);
        gotoxy(60,6); cin.getline(status,10);
    }

    void outDesign()
    {
        gotoxy(50,2); cout<<"Attendance List";
        gotoxy(20,4); cout<<"Roll";
        gotoxy(40,4); cout<<"Date";
        gotoxy(60,4); cout<<"Status";
    }

    void putAttendance(int row)
    {
        gotoxy(20,row); cout<<roll;
        gotoxy(40,row); cout<<date;
        gotoxy(60,row); cout<<status;
    }

    bool searchByRoll(int r)
    {
        return roll == r;
    }
};

class Project
{
    int projectId;
    char projectName[30], description[50];

public:
    void inDesign()
    {
        gotoxy(50,2); cout<<"Add Project";
        gotoxy(40,4); cout<<"Project ID";
        gotoxy(40,5); cout<<"Project Name";
        gotoxy(40,6); cout<<"Description";
    }

    void getProject()
    {
        gotoxy(60,4); cin>>projectId;
        cin.ignore();

        gotoxy(60,5); cin.getline(projectName,30);
        gotoxy(60,6); cin.getline(description,50);
    }

    void outDesign()
    {
        gotoxy(50,2); cout<<"Project List";
        gotoxy(20,4); cout<<"ID";
        gotoxy(40,4); cout<<"Name";
        gotoxy(60,4); cout<<"Description";
    }

    void putProject(int row)
    {
        gotoxy(20,row); cout<<projectId;
        gotoxy(40,row); cout<<projectName;
        gotoxy(60,row); cout<<description;
    }

    bool searchById(int id)
    {
        return projectId == id;
    }
};

class Certificate
{
    int certId;
    char certName[30];
    char issuedTo[30];

public:
    void inDesign()
    {
        gotoxy(50,2); cout<<"Add Certificate";
        gotoxy(40,4); cout<<"Certificate ID";
        gotoxy(40,5); cout<<"Certificate Name";
        gotoxy(40,6); cout<<"Issued To";
    }

    void getCertificate()
    {
        gotoxy(60,4); cin>>certId;
        cin.ignore();

        gotoxy(60,5); cin.getline(certName,30);
        gotoxy(60,6); cin.getline(issuedTo,30);
    }

    void outDesign()
    {
        gotoxy(50,2); cout<<"Certificate List";
        gotoxy(20,4); cout<<"ID";
        gotoxy(40,4); cout<<"Name";
        gotoxy(60,4); cout<<"Issued To";
    }

    void putCertificate(int row)
    {
        gotoxy(20,row); cout<<certId;
        gotoxy(40,row); cout<<certName;
        gotoxy(60,row); cout<<issuedTo;
    }

    bool searchById(int id)
    {
        if(certId==id)
            return true;
        else
            return false;
    }
};

    
/* ================= MENUS ================= */

void studentMenu()
{
	fstream f;
    Student s;
    int ch,row;
    char op;
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"STUDENT MENU";
        gotoxy(45,7); cout<<"1. Add Student";
        gotoxy(45,8); cout<<"2. View Students";
        gotoxy(45,9); cout<<"3. Search Student";
        gotoxy(45,10); cout<<"4. Delete Student";
        gotoxy(45,11); cout<<"5. Modify Student";
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,14); cin>>ch;

        switch(ch)
        {
            case 1: //add Student//
			
			f.open("student.dat",ios::out|ios::binary|ios::app);
			do
			{
			clearScreen(); 
			s.inDesign(); s.getStudent(); pauseScreen(); 
			f.write((char*)&s,sizeof(s));
			gotoxy(50,20);
			cout<<"Want to add more Y/N";
			op=getche();
			}while(op=='y'||op=='Y');
			f.close();
			break;
			
            case 2: clearScreen(); //view Student//
			f.open("student.dat",ios::in|ios::binary);
			s.outDesign();
			row=6;
			while(f.read((char*)&s,sizeof(s)))
			{
				s.putStudent(row);
				row++;
			}
			f.close();
			pauseScreen(); break;
			
            case 3: clearScreen(); //search Student//
			f.open("student.dat",ios::in|ios::binary);
			cout<<"Enter rollno";
			int roll;
			cin>>roll;
			clearScreen();
			s.outDesign();
			row=6;
			while(f.read((char*)&s,sizeof(s)))
			{
				if(s.searchByRollNo(roll)==true)
				{			
					s.putStudent(row);
					row++;
				}
			}
			f.close();pauseScreen(); break;
            case 4://delete student//
{
    Student s;
    fstream temp;
    int roll;
    bool found=false;

    clearScreen();
    cout<<"Enter Roll No to Delete: ";
    cin>>roll;

    f.open("student.dat",ios::in|ios::binary);
    temp.open("temp.dat",ios::out|ios::binary);

    while(f.read((char*)&s,sizeof(s)))
    {
        if(!s.searchByRollNo(roll))
            temp.write((char*)&s,sizeof(s));
        else
            found=true;
    }

    f.close();
    temp.close();

    remove("student.dat");
    rename("temp.dat","student.dat");

    if(found) cout<<"Deleted Successfully";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 5://modify student//
{
    Student s;  
    int roll;
    bool found=false;

    clearScreen();
    cout<<"Enter Roll No to Modify: ";
    cin>>roll;

    f.open("student.dat",ios::in|ios::out|ios::binary);

    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.searchByRollNo(roll))
        {
            found=true;

            clearScreen();
            s.inDesign();
            s.getStudent();

            int pos=(-1)*sizeof(s);
            f.seekp(pos,ios::cur);
            f.write((char*)&s,sizeof(s));
            break;
        }
    }

    f.close();

    if(found) cout<<"Modified Successfully";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

void courseMenu()
{
	fstream f;
    Course c;
    int ch,row;
    char op;     
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"COURSE MENU";
        gotoxy(45,7); cout<<"1. Add Course";
        gotoxy(45,8); cout<<"2. View Courses";
        gotoxy(45,9); cout<<"3. Search Course";
        gotoxy(45,10); cout<<"4. Delete Course";
        gotoxy(45,11); cout<<"5. Modify Course";
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,13); cin>>ch;

        switch(ch)
        {
         case 1://add course//
    f.open("course.dat", ios::out | ios::binary | ios::app);
    do
    {
        clearScreen();
        c.inDesign();
        c.getCourse();
        pauseScreen();

        f.write((char*)&c, sizeof(c));

        gotoxy(50,20);
        cout<<"Want to add more Y/N ";
        op = getche();

    } while(op=='y' || op=='Y');

    f.close();
    break;


           case 2://view course//
    clearScreen();
    f.open("course.dat", ios::in | ios::binary);
    c.outDesign();
    row = 6;
    while(f.read((char*)&c, sizeof(c)))
    {
        c.putCourse(row);
        row++;
    }
    f.close(); pauseScreen();
    
    break;

           case 3://search course//
    clearScreen();
    f.open("course.dat", ios::in | ios::binary);
    cout<<"Enter course id";
    int cid;
    cin>>cid;
    clearScreen();
    c.outDesign();
    row = 6;
    while(f.read((char*)&c, sizeof(c)))
    {
        if(c.searchById(cid)==true)
        {
            c.putCourse(row);
            row++;
        }
    }
    f.close();
    pauseScreen();
    break;

case 4:
{
    Course c;
    fstream temp;
    int id;
    bool found=false;

    clearScreen();
    cout<<"Enter Course ID: ";
    cin>>id;

    f.open("course.dat",ios::in|ios::binary);
    temp.open("temp.dat",ios::out|ios::binary);

    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.searchById(id)==false)
            temp.write((char*)&c,sizeof(c));
        else
            found=true;
    }

    f.close();
    temp.close();

    remove("course.dat");
    rename("temp.dat","course.dat");

    if(found) cout<<"Deleted";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

case 5:
{
    Course c;
    int id;
    bool found=false;
    clearScreen();
    cout<<"Enter Course ID: ";
    cin>>id;

    f.open("course.dat",ios::in|ios::out|ios::binary);

    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.searchById(id)==true)
        {
            found=true;

            clearScreen();
            c.inDesign();
            c.getCourse();

            f.seekp(-sizeof(c),ios::cur);
            f.write((char*)&c,sizeof(c));
            break;
        }
    }

    f.close();

    if(found) cout<<"Modified";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

void attendanceMenu()
{
	fstream f;
    Attendance a;
    int ch,row;
    char op; 
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"ATTENDANCE MENU";
        gotoxy(45,7); cout<<"1. Add Attendance";
        gotoxy(45,8); cout<<"2. View Attendance";
        gotoxy(45,9); cout<<"3. Search Attendance";
        gotoxy(45,10); cout<<"4. Delete Attendance";
        gotoxy(45,11); cout<<"5. Modify Attendance";
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,13); cin>>ch;

        switch(ch)
        {
            case 1://add attendance//
    f.open("attendance.dat", ios::out | ios::binary | ios::app);
    do
    {
        clearScreen();
        a.inDesign();
        a.getAttendance();
        pauseScreen();

        f.write((char*)&a, sizeof(a));

        gotoxy(50,20);
        cout<<"Want to add more Y/N ";
        op = getche();

    } while(op=='y' || op=='Y');

    f.close();
    break;

           case 2://view attendance//
    clearScreen();
    f.open("attendance.dat", ios::in | ios::binary);
    a.outDesign();
    row = 6;
    while(f.read((char*)&a, sizeof(a)))
    {
        a.putAttendance(row);
        row++;
    }
    f.close();
    pauseScreen();
    break;

           case 3://search attendance//
    clearScreen();
    f.open("attendance.dat", ios::in | ios::binary);
    cout<<"Enter attendance id";
    int aid;
    cin>>aid;
    clearScreen();
    a.outDesign();
    row = 6;
    while(f.read((char*)&a, sizeof(a)))
    {
        if(a.searchByRoll(aid)==true)
        {
            a.putAttendance(row);
            row++;
        }
    }
    f.close();
    pauseScreen();
    break;
            case 4:
{
    Attendance a;
    fstream temp;
    int roll;
    bool found=false;

    clearScreen();
    cout<<"Enter Roll No: ";
    cin>>roll;

    f.open("attendance.dat",ios::in|ios::binary);
    temp.open("temp.dat",ios::out|ios::binary);

    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.searchByRoll(roll)==false)
            temp.write((char*)&a,sizeof(a));
        else
            found=true;
    }

    f.close();
    temp.close();

    remove("attendance.dat");
    rename("temp.dat","attendance.dat");

    if(found) cout<<"Deleted";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 5:
{
    Attendance a;
    int roll;
    bool found=false;

    clearScreen();
    cout<<"Enter Roll No: ";
    cin>>roll;

    f.open("attendance.dat",ios::in|ios::out|ios::binary);

    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.searchByRoll(roll)==true)
        {
            found=true;

            clearScreen();
            a.inDesign();
            a.getAttendance();

            f.seekp(-sizeof(a),ios::cur);
            f.write((char*)&a,sizeof(a));
            break;
        }
    }

    f.close();

    if(found) cout<<"Modified";
    else cout<<"Not Found";

    pauseScreen();
    break;
}
            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

void projectMenu()
{
	fstream f;
    Project p;
    int ch,row;
    char op; 
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"PROJECT MENU";
        gotoxy(45,7); cout<<"1. Add Project";
        gotoxy(45,8); cout<<"2. View Projects";
        gotoxy(45,9); cout<<"3. Search Project";
        gotoxy(45,10); cout<<"4. Delete Project";
        gotoxy(45,11); cout<<"5. Modify Project";    
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,13); cin>>ch;

        switch(ch)
        {
           case 1://view project//
    f.open("project.dat", ios::out | ios::binary | ios::app);
    do
    {
        clearScreen();
        p.inDesign();
        p.getProject();
        pauseScreen();

        f.write((char*)&p, sizeof(p));

        gotoxy(50,20);
        cout<<"Want to add more Y/N ";
        op = getche();

    } while(op=='y' || op=='Y');

    f.close();
    break;
           case 2://view project//
    clearScreen();
    f.open("project.dat", ios::in | ios::binary);
    p.outDesign();
    row = 6;
    while(f.read((char*)&p, sizeof(p)))
    {
        p.putProject(row);
        row++;
    }
    f.close();
    pauseScreen();
    break;
            case 3://view project//
    clearScreen();
    f.open("project.dat", ios::in | ios::binary);
    cout<<"Enter project id";
    int pid;
    cin>>pid;
    clearScreen();
    p.outDesign();
    row = 6;
    while(f.read((char*)&p, sizeof(p)))
    {
        if(p.searchById(pid)==true)
        {
            p.putProject(row);
            row++;
        }
    }
    f.close();
    pauseScreen();
       break;
            case 4:
{
    Project p;
    fstream temp;
    int id;
    bool found=false;

    clearScreen();
    cout<<"Enter Project ID: ";
    cin>>id;

    f.open("project.dat",ios::in|ios::binary);
    temp.open("temp.dat",ios::out|ios::binary);

    while(f.read((char*)&p,sizeof(p)))
    {
        if(p.searchById(id)==false)
            temp.write((char*)&p,sizeof(p));
        else
            found=true;
    }

    f.close();
    temp.close();

    remove("project.dat");
    rename("temp.dat","project.dat");

    if(found) cout<<"Deleted";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 5:
{
    Project p;
    int id;
    bool found=false;

    clearScreen();
    cout<<"Enter Project ID: ";
    cin>>id;

    f.open("project.dat",ios::in|ios::out|ios::binary);

    while(f.read((char*)&p,sizeof(p)))
    {
        if(p.searchById(id)==true)
        {
            found=true;

            clearScreen();
            p.inDesign();
            p.getProject();

            f.seekp(-sizeof(p),ios::cur);
            f.write((char*)&p,sizeof(p));
            break;
        }
    }

    f.close();

    if(found) cout<<"Modified";
    else cout<<"Not Found";

    pauseScreen();
    break;
}
           case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

void certificateMenu()
{
	fstream f;
    Certificate c;
    int ch,row;
    char op;
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"CERTIFICATE MENU";
        gotoxy(45,7); cout<<"1. Add Certificate";
        gotoxy(45,8); cout<<"2. View Certificates";
        gotoxy(45,9); cout<<"3. Search Certificate";
        gotoxy(45,10); cout<<"4. Delete Certificate";
        gotoxy(45,11); cout<<"5. Modify Certificate";        
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,13); cin>>ch;

        switch(ch)
        {
            case 1://add certificate//
    f.open("certificate.dat", ios::out | ios::binary | ios::app
	);
    do
    {
        clearScreen();
        c.inDesign();
        c.getCertificate();
        pauseScreen();

        f.write((char*)&c, sizeof(c));

        gotoxy(50,20);
        cout<<"Want to add more Y/N ";
        op = getche();

    } while(op=='y' || op=='Y');

    f.close();
    break;
           case 2://view certificate//
    clearScreen();
    f.open("certificate.dat", ios::in | ios::binary);
    c.outDesign();
    row = 6;
    while(f.read((char*)&c, sizeof(c)))
    {
        c.putCertificate(row);
        row++;
    }
    f.close();
    pauseScreen();
    break;
           case 3://search certificate//
    clearScreen();
    f.open("certificate.dat", ios::in | ios::binary);
    cout<<"Enter certificate id";
    int cid;
    cin>>cid;
    clearScreen();
    c.outDesign();
    row = 6;
    while(f.read((char*)&c, sizeof(c)))
    {
        if(c.searchById(cid)==true)
        {
            c.putCertificate(row);
            row++;
        }
    }
    f.close();
    pauseScreen();
       break;
            case 4:
{
    Certificate c;
    fstream temp;
    int id;
    bool found = false;

    clearScreen();
    cout<<"Enter Certificate ID: ";
    cin>>id;

    f.open("certificate.dat", ios::in | ios::binary);
    temp.open("temp.dat", ios::out | ios::binary);

    while(f.read((char*)&c, sizeof(c)))
    {
        if(c.searchById(id) == false)
            temp.write((char*)&c, sizeof(c));
        else
            found = true;
    }

    f.close();
    temp.close();

    remove("certificate.dat");
    rename("temp.dat","certificate.dat");

    if(found) cout<<"Deleted";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

            case 5:
{
    Certificate c;
    int id;
    bool found = false;

    clearScreen();
    cout<<"Enter Certificate ID: ";
    cin>>id;

    f.open("certificate.dat", ios::in | ios::out | ios::binary);

    while(f.read((char*)&c, sizeof(c)))
    {
        if(c.searchById(id) == true)
        {
            found = true;

            clearScreen();
            c.inDesign();
            c.getCertificate();

            f.seekp(-sizeof(c), ios::cur);
            f.write((char*)&c, sizeof(c));
            break;
        }
    }

    f.close();

    if(found) cout<<"Modified";
    else cout<<"Not Found";

    pauseScreen();
    break;
}

    break;

            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

/* ================= SUPERVISOR MENU ================= */

void supervisorMenu()
{
    int ch;
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"SUPERVISOR MENU";
        gotoxy(45,7); cout<<"1. Student";
        gotoxy(45,8); cout<<"2. Course";
        gotoxy(45,9); cout<<"3. Attendance";
        gotoxy(45,10); cout<<"4. Project";
        gotoxy(45,11); cout<<"5. Certificate";
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,14); cin>>ch;

        switch(ch)
        {
            case 1: studentMenu(); break;
            case 2: courseMenu(); break;
            case 3: attendanceMenu(); break;
            case 4: projectMenu(); break;
            case 5: certificateMenu(); break;
            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

/* ================= ENQUIRY MENU ================= */

void enquiryMenu()
{
    int ch;
    do
    {
        clearScreen();
        gotoxy(45,5); cout<<"ENQUIRY MENU";
        gotoxy(45,7); cout<<"1. Student Details";
        gotoxy(45,8); cout<<"2. Course Details";
        gotoxy(45,9); cout<<"3. Attendance Details";
        gotoxy(45,10); cout<<"4. Project Details";
        gotoxy(45,11); cout<<"5. Certificate Details";
        gotoxy(45,12); cout<<"0. Back";
        gotoxy(45,14); cin>>ch;

        switch(ch)
        {
case 1://STUDENT DETAILS ENQUIRY
{
    fstream f;
    Student s;
    int roll, row=6;
    bool found=false;

    clearScreen();
    border();

    gotoxy(45,15); cout<<"Enter Roll No: ";
    cin>>roll;

    f.open("student.dat", ios::in | ios::binary);

    s.outDesign();

    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.searchByRollNo(roll)==true)
        {
            s.putStudent(row++);
            found=true;
        }
    }

    if(!found)
    {
        gotoxy(50,20);
        cout<<"Not Found";
    }

    f.close();
    pauseScreen();
    break;
}
case 2://COURSE DETAILS ENQUIRY
{
    fstream f;
    Course c;
    int id, row=6;
    bool found=false;

    clearScreen();
    border();

    gotoxy(45,15); cout<<"Enter Course ID: ";
    cin>>id;

    f.open("course.dat", ios::in | ios::binary);

    c.outDesign();

    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.searchById(id)==true)
        {
            c.putCourse(row++);
            found=true;
        }
    }

    if(!found)
    {
        gotoxy(50,20);
        cout<<"Not Found";
    }

    f.close();
    pauseScreen();
    break;
}
case 3://ATTENDANCE DETAILS ENQUIRY
{
    fstream f;
    Attendance a;
    int roll, row=6;
    bool found=false;

    clearScreen();
    border();

    gotoxy(45,15); cout<<"Enter Roll No: ";
    cin>>roll;

    f.open("attendance.dat", ios::in | ios::binary);

    a.outDesign();

    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.searchByRoll(roll)==true)
        {
            a.putAttendance(row++);
            found=true;
        }
    }

    if(!found)
    {
        gotoxy(50,20);
        cout<<"Not Found";
    }

    f.close();
    pauseScreen();
    break;
}
case 4:
{
    fstream f;
    Project p;
    int id, row=6;
    bool found=false;

    clearScreen();
    border();

    gotoxy(45,15); cout<<"Enter Project ID: ";
    cin>>id;

    f.open("project.dat", ios::in | ios::binary);

    p.outDesign();

    while(f.read((char*)&p,sizeof(p)))
    {
        if(p.searchById(id)==true)
        {
            p.putProject(row++);
            found=true;
        }
    }

    if(!found)
    {
        gotoxy(50,20);
        cout<<"Not Found";
    }

    f.close();
    pauseScreen();
    break;
}
case 5:
{
    fstream f;
    Certificate c;
    int id, row=6;
    bool found=false;

    clearScreen();
    border();

    gotoxy(45,15); cout<<"Enter Certificate ID: ";
    cin>>id;

    f.open("certificate.dat", ios::in | ios::binary);

    c.outDesign();

    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.searchById(id)==true)
        {
            c.putCertificate(row++);
            found=true;
        }
    }

    if(!found)
    {
        gotoxy(50,20);
        cout<<"Not Found";
    }

    f.close();
    pauseScreen();
    break;
}            case 0: return;
            default: wrongChoice();
        }

    } while(true);
}

/* ================= MAIN MENU ================= */

int main()
{
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);

    int ch;
    do
    {
        clearScreen();
        gotoxy(50,5); cout<<"WELCOME TO STUDENT MANAGEMENT SYSTEM";
        gotoxy(45,10); cout<<"1. Supervisor";
        gotoxy(45,11); cout<<"2. Enquiry";
        gotoxy(45,12); cout<<"0. Exit";
        gotoxy(45,14); cin>>ch;

        switch(ch)
        {
            case 1: supervisorMenu(); break;
            case 2: enquiryMenu(); break;
            case 0: exitApp(); break;
            default: wrongChoice();
        }

    } while(true);

    return 0;
}



