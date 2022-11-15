#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct voter_information
{
    char reg_no[20];
    char name[50];
    struct voter_information *next;
} node;

node *head;
node *space, *start = NULL;
node *search(char x[], char y[], node *, int *);
node *voter_insert(node *);
node *main_logs(node *);
void admin();
void winner();
void exi();
void voting();
void not_again();
void stop();
void show();

int count = 0, R = 3, vote = 0;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;
int main()
{
    while (1)
    {

        system("cls");
        cout << "\n\n\n";
        cout << "\t\t\t****** WELCOME TO THE ONLINE VOTING PORTAL ******\n\n";
        cout << "\t\t\t****** Please Enter 1 for logging vote main Logs ******    \n\n\n";
        int BB;

        cin >> BB;
        if (BB == 1)
        {
            start = main_logs(start);
        }
    }
    return 0;
}

node *main_logs(node *start)
{
    cout << "\n\n\n";
    cout << "\t\t\t\t\t1. FOR VOTE ENTRY     \n";
    cout << "\t\t\t\t\t2. FOR ADMIN PANEL    \n";
    cout << "\t\t\t\t\t3. FOR WINNER         \n\n";
    cout << "IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n";
    cout << "********Please Enter your choice********\n\n\n";
    int T;
    cin >> T;
    if (T == 1)
    {
        start = voter_insert(start);
    }
    if (T == 2)
    {
        admin();
    }
    if (T == 3)
    {
        winner();
    }
    if (T != 1 || T != 2 || T != 3)
    {
        main_logs(start);
    }

    return start;
}

node *voter_insert(node *start)
{
    int UNIVERSAL = 0;
    int *z;
    z = &UNIVERSAL;

    char name[50], reg_no[20];
    system("cls");
    cout << "\n\n\n\n";
    cout << "IF REGISTRATION NUMBER MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n";
    cout << "ATTEMPTS LEFT :" << R << "\n\n\n";
    cout << "Please enter your \n";
    cout << "\t\tRegistration  number : ";
    fflush(stdin);
    fflush(stdout);
    cin.get(reg_no, 20);
    cout << "\t\tNAME :  ";
    fflush(stdin);
    fflush(stdout);
    cin.get(name, 50);
    node *temp = new node();
    strcpy(temp->reg_no, aadhar);
    strcpy(temp->name, name);
    temp->next = NULL;
    head = temp;
    while (temp != NULL)
    {
        int regno = atoi(temp->reg_no);

        if ((regno >= 210968000) && (regno <= 210968999))
        {
            R = 3;
            start = search(temp->reg_no, temp->name, start, &UNIVERSAL);

            if (UNIVERSAL == 0)
            {
                voting();
            }
            else
            {
                not_again();
            }
        }
        else
        {
            R--;
            if (R == 0)
            {
                stop();
                break;
            }
            cout << "\n\n\n\n";
            cout << "\tYour Registration Number isn't valid \n\n";

            cout << "\tPlease Re-Enter\n\n";

            system("pause");
            start = main_logs(start);
        }
        temp = temp->next;
    }
    return start;
}

void voting()
{
    system("cls");

    cout << "\n\n\n\n";
    cout << "\t\t         * * * * * LIST OF CANDIDATES * * * * * \n\n\n";

    cout << "\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n";

    cout << "\t\t\t 1. Amarendra Baahubali      	   (1)Chariot\n";

    cout << "\t\t\t 2. Kattapa                       (2)Sword\n";

    cout << "\t\t\t 3. Bhallaladeva                  (3)Bull\n";

    cout << "\t\t\t 4. Sivagami                      (4)Albatross\n";

    cout << "\t\t\t 5. Devasena                      (5)Swan \n\n\n";

    int B, j;
    cout << "\t\t\t Enter Your Choice \n";
    for (j = 1; j <= 1; j++)
    {
        cin >> B;

        if (B == 1)
        {
            vote1++;
            cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO AMARENDRA BAHUBALI\n";
            break;
        }
        if (B == 2)
        {
            vote2++;
            cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO KATAPPA\n";
            break;
        }
        if (B == 3)
        {
            vote3++;
            cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO BHALLALADEVA\n";
            break;
        }
        if (B == 4)
        {
            vote4++;
            cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO SIVAGAMI\n";
            break;
        }
        if (B == 5)
        {
            vote5++;
            cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO DEVASENA\n";
            break;
        }
        if (B != 1 || B != 2 || B != 3 || B != 4 || B != 5)
        {
            cout << "\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n";
            cout << "\n\t\t\tENTER AGAIN\t\t\t\n";
        }
    }
    cout << "\n\n\t\t\t**************************THANK YOU***************************\n\n";
    cout << "Exiting in 3 seconds";
    Sleep(3000);
    system("cls");
}

void admin()
{
    int B;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n";
    cin >> B;
    if (B == 1234)
    {
        show();
    }
    else
    {
        cout << "Wrong Password\n";
    }
}

void show()
{
    int G;
    system("cls");

    cout << "\n\n\n\n";
    cout << "\t\t\tPresent Vote Count :\n\n";

    cout << "\t\t\t  Amarendra Bahubali is on " << vote1 << " Votes\n";

    cout << "\t\t\t  KATAPPA is on " << vote2 << " Votes\n";

    cout << "\t\t\t  Bhalladeva is on  " << vote3 << " Votes\n";

    cout << "\t\t\t  Sivagami  is on  " << vote4 << "Votes\n";

    cout << "\t\t\t  Devasena  is on " << vote5 << " Votes\n\n\n\n";

    cout << "\t\t\t\t\tEnter 1 for main logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL\n ";
    cin >> G;
    if (G == 1234)
        exi();
    else
        main_logs(start);
}

void winner()
{
    system("cls");

    cout << "\n\n\n\n";
    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1)
        cout << "\t\t\tThe present Winner is Amarendra Bahubali and he has got " << vote1 << " votes\n\n\n\n";

    else if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2)
        cout << "\t\t\tThe present Winner is KATAPPA and he has got " << vote2 << " votes\n\n\n\n";

    else if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3)
        cout << "\t\t\tThe present Winner is Bhallaladeva and he has got " << vote3 << " votes\n\n\n\n";

    else if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4)
        cout << "\t\t\tThe present Winner is Sivagami and she has got " << vote4 << " votes\n\n\n\n";

    else if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5)
        cout << "\t\t\tThe present Winner is Devasena and she has got " << vote5 << " votes\n\n\n\n";

    cout << "\t\t\t\tEnter Any Key for Main Log\n\n";
    cin.get();
    main_logs(start);
}

void stop()
{
    system("cls");

    cout << "\n\n\n\n";
    cout << "\t\t\tYOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW\n\n\n";
    Sleep(500);
    cout << "\t\t\tPlease try again later\n\n\n";
    Sleep(500);
    cout << "\t\t\t * * *Thank You* * *  \n\n\n";
    Sleep(500);
    cout << "Press any key";
    cin.get();
}

void not_again()
{
    int A;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n";
    Sleep(300);
    cout << "\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n";
    Sleep(300);
    cout << "\t\t\t If You want to see present winner Enter 1 or Enter Any Other Key for Main  Logs\n\n";
    Sleep(300);

    cin >> A;
    if (A == 1)
    {
        winner();
    }
    else
    {
        main_logs(start);
    }
}

void exi()
{
    system("cls");

    cout << "\n\n\n\n\n";
    Sleep(500);
    cout << "\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n";
    Sleep(1000);
    cout << "\t\t\t * * *Thank You For Using This Platform For VOTING* * *  \n\n\n";
    Sleep(1000);
    exit(0);
}
node *search(char x[], char y[], node *start, int *Y)
{
    *Y = 0;
    node *t, *space;
    if (start == NULL)
    {
        node *space = new node();
        strcpy(space->reg_no, x);
        strcpy(space->name, y);

        start = space;
        space->next = NULL;
    }
    else
    {
        t = start;
        while (t != NULL)
        {
            if ((strcmp(t->reg_no, x) == 0 && strcmp(t->name, y) == 0))
            {
                *Y = 1;

                break;
            }
            t = t->next;
        }

        if (*Y == 0)
        {

            node *space = new node();

            strcpy(space->reg_no, x);

            strcpy(space->name, y);

            t = space;
            space->next = NULL;
        }
    }
    return start;
}
