class Certificate
{
    int certId;
    char certName[30];
    char issuedTo[30];

public:

    void inDesign()
    {
        gotoxy(50,2);
        cout << "Add Certificate";

        gotoxy(40,4);
        cout << "Certificate ID";

        gotoxy(40,5);
        cout << "Certificate Name";

        gotoxy(40,6);
        cout << "Issued To";
    }

    void getCertificate()
    {
        gotoxy(60,4);
        cin >> certId;
        
        fflush(stdin);

        gotoxy(60,5);
        gets(certName);

        gotoxy(60,6);
        gets(issuedTo);
    }
};

