class Project
{
    int projectId;
    char projectName[30];
    char description[50];

public:

    void inDesign()
    {
        gotoxy(50,2);
        cout << "Add Project";

        gotoxy(40,4);
        cout << "Project ID";

        gotoxy(40,5);
        cout << "Project Name";

        gotoxy(40,6);
        cout << "Description";
    }

    void getProject()
    {
        gotoxy(60,4);
        cin >> projectId;

        gotoxy(60,5);
        fflush(stdin);
        gets(projectName);

        gotoxy(60,6);
        gets(description);
    }
};

