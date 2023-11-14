#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;

// Variables
string password;
int ch,acno;
char fname[50];
double balance;
double amount;
char option1;

// Void
void login();
void login()
{
    loop:
    int verify1;
    string verify2;

    Sleep(300);
    system("cls");
    cout<<"\tBANK LOGIN\n";
    cout<<"Account Number: ";cin>>verify1;
    cout<<"Password: ";
    // Password Program
    while ( ( ch = getch() ) != '\r' ) {
        if ( ch == '\b' ) {
            // Process a destructive backspace
            if ( verify2.size() > 0 ) {
                verify2.erase( verify2.size() - 1, 1 );
                cout<<"\b \b";
            }
        }
        else {
            verify2.push_back( ch );
            cout.put ( '*' );
        }
    }
    cout.put ( '\n' ); // Password Program ends here

    if (acno==verify1&&password==verify2)
    {
        char option2;
        system("cls");
        cout<<endl;
        cout<<"\tWelcome "<<fname<<"!"<<endl;
        Sleep(700);
        accaccess:
        system("cls");
        cout<<"\tBANKING SYSTEM MENU\n";
        cout<<"[1] Account Balance"<<endl;
        cout<<"[2] Withdraw"<<endl;
        cout<<"[3] Deposit"<<endl;
        cout<<"[4] Logout Bank Account"<<endl;
        cout<<"Enter your choice: ";cin>>option2;
        Sleep(300);
        switch (option2)
        {
        case '1':
            system("cls");
            cout<<"Account Name: "<<fname<<endl;
            cout<<"Account Number: "<<acno<<endl;
            cout<<"Current Balance: "<<balance<<endl;
            system("pause");
            Sleep(500);
            goto accaccess;

        case '2':
            system("cls");
            cout<<"\tWithdraw\n\n";
            cout<<"Enter withdrawal amount: ";cin>>amount;
            if(amount>balance)
            {
                cout<<"Inufficient funds. Withdraw failed."<<endl;
            }else 
            {
                balance -=amount;
                cout<<"Withdraw successful. Current balance: "<<balance<<endl;
            }
            system("pause");
            Sleep(500);
            goto accaccess;
        
        case '3':
            system("cls");
            cout<<"Enter deposit amount: ";cin>>amount;
            balance+=amount;
            cout<<"Deposit successful. Current balance: "<<balance<<endl;
            system("pause");
            Sleep(500);
            goto accaccess;

        case '4':
            system("cls");
            cout<<"Thank you!";
            Sleep(500);
            return;
        
        default:
            system("cls");
            cout<<"INVALID INPUT!";
            Sleep(700);
            break;
        }
    }
    else
    {
        char answer;
        cout<<"Wrong credentials!\n";
        Sleep(300);
        cout<<"Would you like to try again?\n";
        cout<<"Input number (Yes = 1 / No = 0): ";cin>>answer;
        switch (answer)
        {
        case '1':
            goto loop;
        
        case '0':
            break;

        default:
            cout<<"Invalid input!";
            Sleep(300);
            system("cls");
        }
    }
}


void open_account();
void open_account()
{
    system("cls");
    cout<<"Enter Account Number: ";cin>>acno;
    cout<<"Enter Name: ";cin>>fname;
    cout<<"Enter your password: ";
    // Password Program
    while ( ( ch = getch() ) != '\r' ) {
        if ( ch == '\b' ) {
            // Process a destructive backspace
            if ( password.size() > 0 ) {
                password.erase( password.size() - 1, 1 );
                cout<<"\b \b";
            }
        }
        else {
            password.push_back( ch );
            cout.put ( '*' );
        }
    }
    cout.put ( '\n' ); // Password Program ends here

    cout<<"Enter Starting Balance: ";cin>>balance;
    cout<<"You have created an Account!";
    Sleep(500);   
}

// Main Program
main()
{
    system("cls");
    cout<<" _______________________________"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"| \tBANKING SYSTEM          |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|_______________________________|"<<endl<<endl;
    system("pause");
    system("cls");

    while (option1!=5)
    {
        system("cls");
        cout<<"\tBANKING SYSTEM MENU\n";
        cout<<"[1] Open an Account"<<endl;
        cout<<"[2] Login Bank Account"<<endl;
        cout<<"[3] EXIT"<<endl;
        cout<<"Enter your choice: ";cin>>option1;

        switch (option1)
        {
        case '1': // Case for Account Creation
            open_account();
            break;

        case '2': // Logged-in Account
            login();
            break;

        case '3':
            cout<<"Thank you!";
            Sleep(500);
            return 0;

        default:
            break;
        }
    }
}