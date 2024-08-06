#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class temp
{
    int accNo;
    char name[25];
    char Fname[25];
    char cnic[25];
    char P_no[25];
    char email[25];
    double amount;
    int newAmount;
    int searchNo;

    fstream file, file1;

public:
    int search;

    int login();
    int loginacc();
    void createAccount(void);  // declaration of create account function
    void depositAmount(void);  // declaration of depositAmount function
    void withdrawAmount(void); // declaration of withdrawAmount function
    void checkInfo(void);      // declaration of checkInfo function
};

int main()
{

    temp obj;
    char choice;

    cout << "\n\n\n\t\t.......:::Nova's Bank:::.......";
    cout << "\n\t\t:: press 1 to Login Account  :: ";
    cout << "\n\t\t:: press 2 to Create Account ::";
    cout << "\n\t\t:: press 0 to Exit           ::";
    cout << "\n\t\t:: ......................... ::\n\t\t\t\t";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;

    case '2':
        obj.createAccount();
        break;
    case '0':
        system("exit");
    default:
        cout << "\n Invalid Choice...!";
        break;
    }

    return 0;
}

int loginacc()
{

    temp obj;
    char choice;

    cout << "\n\n\n\t\t.......:::Nova's Bank:::.......";
    cout << "\n\t\t:: press 1 to Deposit Amount  :: ";
    cout << "\n\t\t:: press 2 to Withdraw Amount :: ";
    cout << "\n\t\t:: press 3 to Check Info     :: ";
    cout << "\n\t\t:: press 0 to Exit Menu       :: ";
    cout << "\n\t\t:: .......................... ::\n\t\t\t\t";
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj.depositAmount();
        break;
    case '2':
        obj.withdrawAmount();
        break;
    case '3':
        obj.checkInfo();
        break;
    case '0':
        break;
    default:
        cout << "Invalid Choice...!";
        break;
    }
    system("pause");
    system("cls");
}

int temp ::login()
{
    int choice;

    cout << "Enter your account no :: ";
    cin >> searchNo;

    file.open("data.txt", ios ::in);
    file << accNo << "\n";
    while (!file.eof())
    {
        if (accNo == searchNo)
        {
            cout << "\nAccount Login Succesfull...!";
            loginacc();
        }
        else
        {
            cout << "acc No is Incorrect...!";
        }

        file << accNo << "\n";
    }
    file.close();
}

// Defination of create account function
void temp ::createAccount()
{

    srand(time(0));
    accNo = rand() * rand() + rand() * rand();

    cout << "Enter your name :: ";
    cin >> name;

    cout << "Enter your father name :: ";
    cin >> Fname;

    cout << "Enter your cnic :: ";
    cin >> cnic;

    cout << "Enter your Phone number :: ";
    cin >> P_no;

    cout << "Enter Your email :: ";
    cin >> email;

    cout << "Enter your amount :: ";
    cin >> amount;

    cout << accNo << " This is your account number... \n";
    cout << "Please save it";

    file.open("data.txt", ios::out | ios::app);
    file << accNo << "\t" << name << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
    file.close();
}

// Defination of deposit amount function
void temp ::depositAmount()
{

    cout << "Enter amount to deposit :: ";
    cin >> newAmount;

    file.open("data.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount;

    while (!file.eof())
    {
        if (accNo == searchNo)
        {
            cout << "\ncurrent amount :: " << amount;
            amount = amount + newAmount;
            cout << "\nupdated amount :: " << amount;
            file1 << accNo << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
        }
        else
        {
            file1 << accNo << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
        }
        file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

// Defination of wihtdraw amount function
void temp ::withdrawAmount()
{

    cout << "Enter amount to withdraw :: ";
    cin >> newAmount;

    file.open("data.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount;

    while (!file.eof())
    {
        if (accNo == searchNo)
        {
            cout << "\ncurrent amount :: " << amount;
            amount = amount - newAmount;
            cout << "\nupdated amount :: " << amount << endl;
            file1 << accNo << "\t" << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
        }
        else
        {
            file1 << accNo << "\t" << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
        }
        file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

// Defination of check info function
void temp ::checkInfo()
{
    fstream file;
    file.open("data.txt", ios::in);
    if (!file)
    {
        cout << "File opening error !";
    }
    file >> accNo >> name >> cnic >> P_no >> email >> amount;
    while (!file.eof())
    {
        if (accNo == searchNo)
        {
            cout << "\n-------------------\n";
            cout << endl
                 << "\t::: account Number ::: ";
            cout << "\t   " << accNo << endl;
            cout << "\t::: User Name      ::: ";
            cout << "\t   " << name << "\n";
            cout << "\t::: Father Name    ::: ";
            cout << "\t   " << Fname << "\n";
            cout << "\t::: CNIC Number    ::: ";
            cout << "\t   " << cnic << "\n";
            cout << "\t::: Phone Number   ::: ";
            cout << "\t   " << P_no << "\n";
            cout << "\t::: Email Address  ::: ";
            cout << "\t   " << email << "\n";
            cout << "\t::: Current Amount ::: ";
            cout << "\t   " << amount << endl;
            cout << "\n-------------------\n\n";
        }
        file >> accNo >> name >> cnic >> P_no >> email >> amount;
    }

    file.close();
}