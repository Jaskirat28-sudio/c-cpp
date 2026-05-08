class Student
{
    int rollno;
    char name[20],address[30];
    public:
    void inDesign()
    {
        gotoxy(40,2);
        cout<<"Add Student";
        gotoxy(40,4);
        cout<<"Roll No";
        gotoxy(40,5);
        cout<<"Name";
        gotoxy(40,6);
        cout<<"Address";
    }
    void getStudent()
    {
        gotoxy(60,4);
        cin>>rollno;
        gotoxy(60,5);
        fflush(stdin);
        gets(name);
        gotoxy(60,6);
        gets(address);
    }
};
