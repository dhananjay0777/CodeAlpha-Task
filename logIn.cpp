#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string userName, eMail, Password;
    string searchName, searchPassword, searchMail;
    fstream file;

public:
    void login();
    void SignUp();
    void ForgetPassword();
} obj;

int main()
{
    char choice;
    cout << "-------------" << endl;
    cout << "1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forget Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.SignUp();
        break;
    case '3':
        obj.ForgetPassword();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Choice!";
    }
}

void temp::SignUp()
{
    cout << "\nEnter Your User Name :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, eMail);
    cout << "Enter Your Password :: ";
    getline(cin, Password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << eMail << "*" << Password << endl;
    file.close();
}

void temp::login()
{
    cout << "-----Login-----" << endl;
    cout << "Enter Your User Name :- ";
    getline(cin, searchName);
    cout << "Enter Your Password :- ";
    getline(cin, searchPassword);

    file.open("loginData.txt", ios::in);

    bool found = false;

    while (getline(file, userName, '*') &&
           getline(file, eMail, '*') &&
           getline(file, Password, '\n'))
    {
        if (userName == searchName)
        {
            found = true;
            if (Password == searchPassword)
            {
                cout << "\nLogin Successful..!!";
                cout << "\nUsername :- " << userName;
                cout << "\nEmail :- " << eMail << endl;
            }
            else
            {
                cout << "\nPassword Not Match !!";
            }
            break;
        }
    }

    if (!found)
        cout << "\nUser not found!";

    file.close();
}

void temp::ForgetPassword()
{
    cout << "\nEnter Your UserName :- ";
    getline(cin, searchName);
    cout << "\nEnter Your Email Address :- ";
    getline(cin, searchMail);

    file.open("loginData.txt", ios::in);

    bool found = false;

    while (getline(file, userName, '*') &&
           getline(file, eMail, '*') &&
           getline(file, Password, '\n'))
    {
        if (userName == searchName && eMail == searchMail)
        {
            cout << "\nAccount Found..." << endl;
            cout << "Your Password is :- " << Password << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Account not found!\n";

    file.close();
}