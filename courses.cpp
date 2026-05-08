class Course
{
    int courseId;
    char courseName[30];
    char duration[20];

public:

    void inDesign()
    {
        gotoxy(50,2);
        cout<<"Add Course";

        gotoxy(40,4);
        cout<<"Course ID";

        gotoxy(40,5);
        cout<<"Course Name";

        gotoxy(40,6);
        cout<<"Duration";
    }

    void getCourse()
    {
        gotoxy(60,4);
        cin >> courseId;

        gotoxy(60,5);
        fflush(stdin);
        gets(courseName);

        gotoxy(60,6);
        gets(duration);
    }
};
