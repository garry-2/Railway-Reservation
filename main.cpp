#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

// void viewinfo();
void bookticket();
// void cancelticket();
void password();
void admin();
void addtrain();
void awrite();
void bookticket();
void bookticket_write();
void viewpassenger();
void viewinfo();
void dlttrain();
void cancelticket();

struct adddata
{
    char si[10];
    char train_number[10];
    char train_name[20];
    char intial[30];
    char destination[30];
    char price[10];
    int seat;
    char time[10];
} add[1000];

struct bookticket
{
    char train_number[10];
    char name[20];
    char phone[20];
    char date[20];
    int seat;
} book[1000];

int n, a;
int k = 0, u = 0;
char trn_nmbr[100], name[100], phn[100];

int main()
{
    int ch;
    cout << "\t\t\t------------RAILWAY RESERVATION SYSTEM--------------\n"
         << endl;
    cout << "\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
    cout << "\n\n\t\t\t\t*********MENU*********\n";
    cout << "\n\t\t\t 1.VIEW INFORMATION\n";
    cout << "\n\t\t\t 2.BOOK TICKET\n";
    cout << "\n\t\t\t 3.CANCEL TICKET\n";
    cout << "\n\t\t\t 4.ADMIN\n";
    cout << "\n\t\t\t 5.EXIT\n";
    cout << "\n\t\t\t**********************************";
    cout << "\n\t\t\tEnter YOUR CHOICE: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        viewinfo();
        break;
    case 2:
        bookticket();
        break;
    case 3:
        cancelticket();
        break;
    case 4:
        password();
        break;
    case 5:
        system("cls");
        break;
    default:
        cout << "<<<<<<<<<<<<< Yout entered wrong key >>>>>>>>>>>>>>>> " << endl;
    }
}

void password()
{

    int number = 1234;
    int pass;
    cout << "\n\t\t\tEnter password: ";
    cin >> pass;
    if (pass == number)
    {
        cout << "\n\n\t\t\t<<<<<login successfully>>>>>";
        getch();
        system("cls");
        admin();
    }
    else
    {
        cout << "\n\n\t\t\t\t   ERROR!!!!!";
        cout << "\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
        getch();
        system("cls");
        main();
    }
}

void admin()
{
    int chhh;
    system("cls");
    cout << "\n     ==================================================================";
    cout << "\n     ***************RAILWAY RESERVATION SYSTEM***************";
    cout << "\n     ====================================================================";
    cout << "\n\n";
    cout << "           <<<<<<<<<<<<<<<WELCOME ADMIN>>>>>>>>>>>>>>>\n";
    cout << "\n\n";
    cout << "              ***************************************\n";
    cout << "              ||      CHOOSE YOUR OPERATION     ||\n";
    cout << "              ||--------------------------------||\n";
    cout << "              ||      [1] VIEW PASSENGERS       ||\n";
    cout << "              ||      [2] ADD TRAIN             ||\n";
    cout << "              ||      [3] DELETE TRAIN          ||\n";
    cout << "              ||      [4] BACK                  ||\n";
    cout << "              ||                                ||\n";
    cout << "              ***************************************\n\n";
    cout << "     -------------------------------------------------\n";
    cout << "\n\t\tEnter YOUR CHOICE: ";
    cin >> chhh;

    switch (chhh)
    {
    case 1:
        viewpassenger();
        break;
    case 2:
        addtrain();
        break;
    case 3:
        dlttrain();
        break;
    case 4:
        system("cls");
        main();
        break;
    default:
        cout << "\n\t\t\tyou Entered wrong KEY!!!!";
        system("cls");
        main();
    }
}

void addtrain()
{
    system("cls");
    int ch;
    // aread();
    int i;
    cout << "\n\t\t     ============================================";
    cout << "\n\t\t     *********RAILWAY RESERVATION SYSTEM*********";
    cout << "\n\t\t     ============================================";
    cout << "\n\n\t\t\tHow many trains do you want to add: ";
    cin >> a;
    for (i = 0; i < a; i++)
    {
        cout << "\n\t\t\tEnter " << i + 1 << " train details: " << endl;
        cout << "\n\t\t\tEnter serial number: ";
        cin >> add[i].si;
        cout << "\n\t\t\tEnter train number: ";
        cin >> add[i].train_number;
        cout << "\n\t\t\tEnter train name: ";
        cin >> add[i].train_name;
        cin.ignore(1000, '\n');
        cout << "\n\t\t\tEnter Start place: ";
        cin >> add[i].intial;
        cout << "\n\t\t\tEnter destination place: ";
        cin >> add[i].destination;
        cout << "\n\t\t\t Enter price: ";
        cin >> add[i].price;
        cout << "\n\t\t\t Enter seat: ";
        cin >> add[i].seat;
        cout << "\n\t\t\t Enter time: ";
        cin >> add[i].time;
    }

    cout << "\n\n\t\t\tconfirm train: (y=1/n=0):- ";
    cin >> ch;
    if (ch == 1)
    {
        awrite();
        k = i;
        awrite();

        system("cls");
        cout << "\n\n\t\t\t====================================";
        cout << "\n\t\t\t*******RAILWAY RESERVATION SYSTEM*******";
        cout << "\n\t\t\t====================================";
        cout << "\n\n";
        cout << "\n\t\t\t\t   **********************************";
        cout << "\n\t\t\t\t   <<<<<train added successfully>>>>>";
        cout << "\n\t\t\t\t   **********************************";
        getch();
        system("cls");
        main();
    }
    if (ch == 0)
    {
        system("cls");
        admin();
    }
    if ((ch != 1) && (ch != 0))
    {
        system("cls");
        main();
    }
}

void awrite()
{
    int i;
    ofstream myfile("Railway_Traininfo.txt");
    myfile << "\n\t\t     -------------RAILWAY RESERVATION SYSTEM-------------" << endl;
    myfile << endl
           << endl
           << "--------------------------------------Train Information --------------------------------------" << endl
           << endl;
    myfile << "Sr.No \t Train No.   Train Name      Start   	 Destination 	 Price 	   Seat      Time  " << endl
           << endl;
    for (i = 0; i < a; i++)
    {
        myfile << add[i].si << "\t " << add[i].train_number << "	     " << add[i].train_name << "	     " << add[i].intial << "   	 " << add[i].destination << "	         " << add[i].price << "	   " << add[i].seat << "	     " << add[i].time << endl;
    }
    myfile.close();
}

void bookticket()
{
    int c, j, i, found = -1;
    char v, train_number[10];
    system("cls");
    // aread();
    cout << "\n\n\t\t\t============================================";
    cout << "\n\t\t\t*************RAILWAY RESERVATION SYSTEM*************\n";
    cout << "\t\t\t==================================================";
    cout << "\n\n\t\t\tHow many tickets do you want to buy: ";
    cin >> n;
    for (j = 0; j < n; j++)
    {
        cout << "\n\n\t\t\tEnter train number: ";
        cin >> book[j].train_number;
        for (i = 0; i < k; i++)
        {
            if (strcmp(book[j].train_number, add[i].train_number) == 0)
            {
                if (add[i].seat == 0)
                {
                    cout << "\n\n\t\t\tnot available seat";

                    system("cls");
                    main();
                }
                else
                {
                    found = 1;
                    cout << "\n\t\t\tEnter book " << j + 1 << " no ticket: ";
                    cout << "\n\t\t\tEnter date: ";
                    cin >> book[j].date;
                    cout << "\n\t\t\tEnter your name: ";
                    cin >> book[j].name;
                    cout << "\n\t\t\tEnter your phone number: ";
                    cin >> book[j].phone;
                    cout << "\n\t\t\tseat number : " << add[i].seat;
                    book[j].seat = add[i].seat;
                    bookticket_write();
                    add[i].seat--;
                }
            }
        }
        if (found == -1)
        {
            cout << "\n\n\t\t\ttrain not found!!!";

            system("cls");
            main();
        }
    }
    u = j;
    bookticket_write();
    cout << "\n\n\t\t\tEnter '1' for main menu & press any key to exit: ";
    cin >> c;
    if (c == 1)
    {
        system("cls");
        main();
    }
    if (c != 1)
    {
        exit;
    }
}

void bookticket_write()
{
    int j;
    ofstream filex("Railway_Passengersinfo.txt");
    filex << "\n\t\t     -------------RAILWAY RESERVATION SYSTEM-------------" << endl
          << endl;
    filex << "---------------------------Passengers Information---------------------------" << endl
          << endl;
    filex << "Sr.no. \t Date \t Name 	   Phone Number     Seat Number" << endl
          << endl;
    for (j = 0; j < n; j++)
    {
        filex << j + 1 << "\t" << book[j].date << "\t" << book[j].name << "	    " << book[j].phone << "     " << book[j].seat << endl;
    }
    filex.close();
}

void viewpassenger()
{
    int chhhh, j;
    system("cls");

    cout << "\n\t\t\t       ********************";
    cout << "\n\t\t\t       *******RAILWAY RESERVATION SYSTEM*******";
    cout << "\n\t\t\t       ********************";
    cout << "\n\n\t\t\ttrain number\t\tName\t\tphone number\t\tdate\t\tseat\n";
    cout << "\n\t\t\t****************************\n";
    for (j = 0; j < n; j++)
    {
        cout << "\n\t\t\t" << book[j].train_number << "\t\t\t" << book[j].name << "\t\t" << book[j].phone << "\t\t" << book[j].date << "\t\t" << book[j].seat << endl;
        book[j].seat++;
    }
    cout << "\n\t\t\t****************************\n";
    cout << "\n\n\t\t\tEnter '1' for main menu & Enter '0' for back: ";
    cin >> chhhh;
    if (chhhh == 1)
    {
        system("cls");
        main();
    }
    if (chhhh == 0)
    {
        system("cls");
        admin();
    }
}

void viewinfo()
{
    int ch, i;
    system("cls");

    cout << "\n\t\t     -------------RAILWAY RESERVATION SYSTEM-------------" << endl;
    cout << "--------------------------------------Train Information --------------------------------------" << endl
         << endl;
    cout << "Sr.No \t Train No.   Train Name      Start   	 Destination 	 Price 	   Seat      Time  " << endl;
    for (i = 0; i < a; i++)
    {
        cout << add[i].si << "\t " << add[i].train_number << "	     " << add[i].train_name << "	     " << add[i].intial << "   	 " << add[i].destination << "	         " << add[i].price << "	   " << add[i].seat << "	     " << add[i].time << endl;
    }

    cout << "    *********************************\n";
    cout << "\n\t\t\tpress '1' for main menu & press any key for exit:  ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        main();
        break;
    default:
        exit(0);
    }
}

void dlttrain()
{

    char train[100];
    int location = -1, f;
    printf("\n\n\tEnter train number: ");
    scanf("%s", train);
    for (f = 0; f < k; f++)
    {
        if (strcmp(train, add[f].train_number) == 0)
        {
            location = f;
            break;
        }
    }
    if (location == -1)
    {
        printf("\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");

        system("cls");
        admin();
    }
    else
    {
        int ch;
        for (f = location; f < k; f++)
        {
            strcpy(add[f].si, add[f + 1].si);
            strcpy(add[f].train_number, add[f + 1].train_number);
            strcpy(add[f].train_name, add[f + 1].train_name);
            strcpy(add[f].intial, add[f + 1].intial);
            strcpy(add[f].destination, add[f + 1].destination);
            strcpy(add[f].price, add[f + 1].price);

            strcpy(add[f].time, add[f + 1].time);
            awrite();
        }
        k--;
        awrite();
        system("cls");
        cout << "\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>" << endl;
        cout << "Press 1 for Admin Menu and other key for Main menu" << endl;
        cin >> ch;
        system("cls");
        if (ch == 1)
        {
            admin();
        }
        else
        {
            main();
        }
    }
}

void cancelticket()
{

    char pnnmbr[100];
    int location = -1, e;
    printf("\n\n\t\t\tEnter phone number: ");
    scanf("%s", pnnmbr);
    for (e = 0; e < u; e++)
    {
        if (strcmp(pnnmbr, book[e].phone) == 0)
        {
            location = e;
            break;
        }
    }
    if (location == -1)
    {
        printf("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e = location; e < u; e++)
        {
            strcpy(book[e].date, book[e + 1].date);
            strcpy(book[e].train_number, book[e + 1].train_number);
            strcpy(book[e].name, book[e + 1].name);
            strcpy(book[e].phone, book[e + 1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>";
        getch();
        system("cls");
        main();
    }
}
