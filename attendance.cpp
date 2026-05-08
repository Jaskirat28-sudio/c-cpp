class Attendance
{
    int roll;
    char date[20];
    char status[10]; // Present / Absent

public:

    void inDesign()
    {
        gotoxy(50,2);
        cout << "Add Attendance";

        gotoxy(40,4);
        cout << "Student Roll No";

        gotoxy(40,5);
        cout << "Date (DD-MM-YYYY)";

        gotoxy(40,6);
        cout << "Status (Present/Absent)";
    }

    void getAttendance()
    {
        gotoxy(60,4);
        cin >> roll;

        gotoxy(60,5);
        fflush(stdin);
        gets(date);

        gotoxy(60,6);
        gets(status);
    }
};
